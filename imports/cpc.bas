' /*****************************************************************************
'  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
'  *****************************************************************************
'  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
'  *
'  * Licensed under the Apache License, Version 2.0 (the "License");
'  * you may not use this file except in compliance with the License.
'  * You may obtain a copy of the License at
'  *
'  * http://www.apache.org/licenses/LICENSE-2.0
'  *
'  * Unless required by applicable law or agreed to in writing, software
'  * distributed under the License is distributed on an "AS IS" BASIS,
'  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
'  * See the License for the specific language governing permissions and
'  * limitations under the License.
'  *----------------------------------------------------------------------------
'  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
'  * (la "Licenza"); è proibito usare questo file se non in conformità alla
'  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
'  *
'  * http://www.apache.org/licenses/LICENSE-2.0
'  *
'  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
'  * il software distribuito nei termini della Licenza è distribuito
'  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
'  * implicite. Consultare la Licenza per il testo specifico che regola le
'  * autorizzazioni e le limitazioni previste dalla medesima.
'  ****************************************************************************/
'  ****************************************************************************
'  *** IMPORT DECLARES FOR TARGET cpc (Amstrad CPC 664/6128)
'  ****************************************************************************
'  ****************************************************************************
'  ** Informations from: https://www.cpcwiki.eu/index.php/BIOS_Function_Summary
'  ****************************************************************************
'  * Tested with ugBASIC v1.14.1
'  ****************************************************************************

' Kernel RST Vectors
'  0000 RESET (RST0/RESET)
'  0008 KL_LO_JUMP (RST1)
'  000B KL_LO_CALL_HL
'  000E KL_JP_BC                 ;in: BC=addr
'  0010 KL_SIDE_CALL_SP (RST2)
'  0013 KL_SIDE_CALL_HL
'  0016 KL_JP_DE                 ;in: DE=addr
'  0018 KL_FAR_CALL_SP (RST3)
'  001B KL_FAR_CALL_C_HL
'  001E KL_JP_HL                 ;in: HL=addr
'  0020 KL_RAM_LD_A_HL (RST4)    ;in: HL=src, out: A=[HL]
'  0023 KL_FAR_CALL_HL
'  0028 KL_FIRM_JUMP (RST5)
'  002B DATA (OLD C' WHEN RST 30h OCCURRED WITH LO_ROM ENABLED)
'  0030 FREE_FOR_USER (RST6)
'  0038 INTERRUPT (RST7/IRQ)
'  003B EXT_INTERRUPT_VECTOR
'  0066 GARBAGE (THERE'S NO NMI HANDLER IN ROM)

' Kernel RAM Functions
'  B900 KL_U_ROM_ENABLE    ;out: A=old C'
'  B903 KL_U_ROM_DISABLE   ;out: A=old C'
'  B906 KL_L_ROM_ENABLE    ;out: A=old C'
'  B909 KL_L_ROM_DISABLE   ;out: A=old C'
'  B90C KL_ROM_RESTORE     ;in: A=new C' (Bit2,3)
'  B90F KL_ROM_SELECT      ;in: C=upper ROM bank (select, and enable that bank)
'  B912 KL_CURR_SELECTION  ;out: A=upper ROM bank
'  B915 KL_PROBE_ROM       ;in: C=upper ROM bank, out: A=[C000h], HL=[C001h]
'  B918 KL_ROM_DESELECT    ;in: B=new C', C=upper ROM bank, out: B=A, C=old bank
'  B91B KL_RAM_LDIR        ;in: HL=src, DE=dest, BC=len
'  B91E KL_RAM_LDDR        ;in: HL=src_end, DE=dest_end, BC=len
'  B921 KL_POLL_SYNCHRONOUS
'  664 and up only:
'  B92A KL_SCAN_NEEDED_664

' Keyboard Manager
'  BB00 KM_INITIALIZE
DECLARE SYSTEM PROC km_initialize AT $BB00 ON CPC

'  BB03 KM_RESET
DECLARE SYSTEM PROC km_reset AT $BB03 ON CPC

'  BB06 KM_WAIT_CHAR     out: A=char (waits until valid char)
DECLARE SYSTEM FUNCTION km_wait_char AT $BB06 RETURN REG(A) AS BYTE ON CPC

'  BB09 KM_READ_CHAR     out: A=char, cy=1=valid char
DECLARE SYSTEM FUNCTION km_read_char AT $BB09 ( OUT valid AS BYTE ON REG(CARRY) ) RETURN REG(A) AS BYTE ON CPC

'  BB0C KM_CHAR_RETURN   in: A=char (writeback max one char to keybuf)
DECLARE SYSTEM PROC km_char_return AT $BB0C ( char AS BYTE ON REG(A) ) ON CPC

'  BB0F KM_SET_EXPAND    in: B=code, HL=ptr to new string, C=length
DECLARE SYSTEM PROC km_set_expand AT $BB0F ( code AS BYTE ON REG(B), newstring AS ADDRESS ON REG(HL), len AS BYTE ON REG(C) ) ON CPC

'  BB12 KM_GET_EXPAND    in: A=code (0-1F,80-9F), L=index, out:A=char, cy,zf
DECLARE SYSTEM FUNCTION km_get_expand AT $BB12 ( code AS BYTE ON REG(A), index AS BYTE ON REG(L) ) RETURN REG(A) AS BYTE ON CPC

'  BB15 KM_EXP_BUF_RESET in: de=begin, hl=length of buffer, out: cy: 1=okay
DECLARE SYSTEM FUNCTION km_exp_buf_reset AT $BB15 ( begin AS BYTE ON REG(DE), len AS WORD ON REG(HL) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BB18 KM_WAIT_KEY      out: A=char (waits until key pressed)
DECLARE SYSTEM FUNCTION km_wait_key AT $BB18 RETURN REG(A) AS BYTE ON CPC

'  BB1B KM_READ_KEY      out: cy:0=none, cy:1=key pressed, A=char
DECLARE SYSTEM FUNCTION km_read_key AT $BB18 (OUT pressed AS BYTE ON REG(CARRY) ) RETURN REG(A) AS BYTE ON CPC

'  BB1E KM_TEST_KEY      in: A=keyno, out: nz=pressed, C=ctrl/shift flags
DECLARE SYSTEM FUNCTION km_read_key AT $BB18 (OUT pressed AS BYTE ON REG(CARRY) ) RETURN REG(A) AS BYTE ON CPC

'  BB21 KM_GET_LOCKS     out: H=caps lock (caps), L=shift lock (ctrl+caps)
DECLARE SYSTEM PROC km_get_locks AT $BB21 (OUT caps AS BYTE ON REG(H), OUT ctrlcaps AS BYTE ON REG(L) ) ON CPC

'  BB24 KM_GET_JOYSTICK  out: H=joystick 0, L=joystick 1
DECLARE SYSTEM PROC km_get_joystick AT $BB24 (OUT joy0 AS BYTE ON REG(H), OUT joy1 AS BYTE ON REG(L) ) ON CPC

'  BB27 KM_SET_TRANSLATE in: A=keyno, B=char (normal)
DECLARE SYSTEM FUNCTION km_set_translate AT $BB27 (keyno AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BB2A KM_GET_TRANSLATE in: A=keyno, out: A=char (normal)
DECLARE SYSTEM FUNCTION km_get_translate AT $BB2A (keyno AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BB2D KM_SET_SHIFT     in: A=keyno, B=char (with shift)
DECLARE SYSTEM PROC km_set_shift AT $BB2D (keyno AS BYTE ON REG(A), char AS BYTE ON REG(B) ) ON CPC

'  BB30 KM_GET_SHIFT     in: A=keyno, out: A=char (with shift)
DECLARE SYSTEM FUNCTION km_get_shift AT $BB30 (keyno AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BB33 KM_SET_CTRL      in: A=keyno, B=char (with control)
DECLARE SYSTEM PROC km_set_ctrl AT $BB33 (keyno AS BYTE ON REG(A), char AS BYTE ON REG(B) ) ON CPC

'  BB36 KM_GET_CTRL      in: A=keyno, out: A=char (with control)
DECLARE SYSTEM FUNCTION km_get_ctrl AT $BB36 (keyno AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BB39 KM_SET_REPEAT    in: A=keyno, B=repeat flag (FFh=on)
POSITIVE CONST setRepeatEnable = $ff
POSITIVE CONST setRepeatDisable = 0
DECLARE SYSTEM PROC km_set_repeat AT $BB39 (keyno AS BYTE ON REG(A), flag AS BYTE ON REG(B) ) ON CPC
DECLARE SYSTEM PROC km_set_repeat_enable AT $BB39 (keyno AS BYTE ON REG(A), #setRepeatEnable ON REG(B) ) ON CPC
DECLARE SYSTEM PROC km_set_repeat_disable AT $BB39 (keyno AS BYTE ON REG(A), #setRepeatDisable ON REG(B) ) ON CPC

'  BB3C KM_GET_REPEAT    in: A=keyno, out: nz=repeat
DECLARE SYSTEM FUNCTION km_get_repeat AT $BB3C (keyno AS BYTE ON REG(A) ) RETURN REG(ZERO) AS BYTE ON CPC

'  BB3F KM_SET_DELAY     in: H=1st delay, L=repeat delay
DECLARE SYSTEM PROC km_set_delay AT $BB3F (first AS BYTE ON REG(H), repeat AS BYTE ON REG(L) ) ON CPC

'  BB42 KM_GET_DELAY     out: H=1st delay, L=repeat delay
DECLARE SYSTEM PROC km_get_delay AT $BB42 (OUT first AS BYTE ON REG(H), OUT repeat AS BYTE ON REG(L) ) ON CPC

'  BB45 KM_ARM_BREAK     in: de=procedure, c=ROM config
DECLARE SYSTEM PROC km_arm_break AT $BB45 (procedure AS WORD ON REG(DE), rom AS BYTE ON REG(C) ) ON CPC

'  BB48 KM_DISARM_BREAK  in: none
DECLARE SYSTEM PROC km_disarm_break AT $BB48 ON CPC

'  BB4B KM_BREAK_EVENT
DECLARE SYSTEM PROC km_break_event AT $BB4B ON CPC

'  BB5A TXT_OUTPUT        in: A=char ;display 20h..FFh, or handle 00h..1Fh
DECLARE SYSTEM PROC txt_output AT $BB5A (char AS BYTE ON REG(A) ) ON CPC

'  BB5D TXT_WR_CHAR       in: A=char ;display 00h..FFh
DECLARE SYSTEM PROC txt_wr_char AT $BB5D (char AS BYTE ON REG(A) ) ON CPC

'  BB60 TXT_RD_CHAR       out: A=char, Z=space, cy=1=okay
DECLARE SYSTEM FUNCTION txt_rd_char AT $BB60 (OUT space AS BYTE ON REG(ZERO), OUT okay AS BYTE ON REG(CARRY) ) RETURN REG(A) AS BYTE ON CPC

'  BB63 TXT_SET_GRAPHIC   in: A=0=normal text position, A>0=graphics position
DECLARE SYSTEM PROC txt_set_graphic AT $BB63 (position AS BYTE ON REG(A) ) ON CPC

'  BB66 TXT_SET_WINDOW    in: H=x1, L=y1, D=x2, E=y2 (x=0..79, y=0..24)
DECLARE SYSTEM PROC txt_set_window AT $BB66 (x1 AS BYTE ON REG(H), y1 AS BYTE ON REG(L), x2 AS BYTE ON REG(D), y2 AS BYTE ON REG(E) ) ON CPC

'  BB69 TXT_GET_WINDOW    out: H=x1, L=y1, D=x2, E=y2, cy=0=hardware scrolling
DECLARE SYSTEM FUNCTION txt_get_window AT $BB69 (OUT x1 AS BYTE ON REG(H), OUT y1 AS BYTE ON REG(L), OUT x2 AS BYTE ON REG(D), OUT y2 AS BYTE ON REG(E) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BB6C TXT_CLEAR_WINDOW  fill window by PAPER color
DECLARE SYSTEM PROC txt_clear_window AT $BB6C ON CPC

'  BB6F TXT_SET_COLUMN    in: A=x
DECLARE SYSTEM PROC txt_set_column AT $BB6F( x AS BYTE ON REG(A) ) ON CPC

'  BB72 TXT_SET_ROW       in: A=y
DECLARE SYSTEM PROC txt_set_row AT $BB72( y AS BYTE ON REG(A) ) ON CPC

'  BB75 TXT_SET_CURSOR    in: H=x, L=y
DECLARE SYSTEM PROC txt_set_cursor AT $BB75( x AS BYTE ON REG(H), y AS BYTE ON REG(L) ) ON CPC

'  BB78 TXT_GET_CURSOR    out: H=x, L=y
DECLARE SYSTEM PROC txt_get_cursor AT $BB78( OUT x AS BYTE ON REG(H), OUT y AS BYTE ON REG(L) ) ON CPC

'  BB7B TXT_CUR_ENABLE
DECLARE SYSTEM PROC txt_cur_enable AT $BB7B ON CPC

'  BB7E TXT_CUR_DISABLE
DECLARE SYSTEM PROC txt_cur_disable AT $BB7E ON CPC

'  BB81 TXT_CUR_ON
DECLARE SYSTEM PROC txt_cur_on AT $BB81 ON CPC

'  BB84 TXT_CUR_OFF
DECLARE SYSTEM PROC txt_cur_off AT $BB84 ON CPC

'  BB87 TXT_VALIDATE      io: H=x, L=y, out: cy: 1=position ok, 0=scroll
DECLARE SYSTEM FUNCTION txt_validate AT $BB87 (x AS BYTE ON REG(H), y AS BYTE ON REG(L) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BB8A TXT_PLACE_CURSOR
DECLARE SYSTEM PROC txt_place_cursor AT $BB8A ON CPC

'  BB8D TXT_REMOVE_CURSOR
DECLARE SYSTEM PROC txt_remove_cursor AT $BB8D ON CPC

'  BB90 TXT_SET_PEN       in: A=foreground color 0..15
DECLARE SYSTEM PROC txt_set_pen AT $BB90 (pen AS BYTE ON REG(A) ) ON CPC

'  BB93 TXT_GET_PEN       out: A=foreground color 0..15
DECLARE SYSTEM FUNCTION txt_get_pen AT $BB93 RETURN REG(A) AS BYTE ON CPC

'  BB96 TXT_SET_PAPER     in: A=background color 0..15
DECLARE SYSTEM PROC txt_set_paper AT $BB96 (paper AS BYTE ON REG(A) ) ON CPC

'  BB99 TXT_GET_PAPER     out: A=background color 0..15
DECLARE SYSTEM FUNCTION txt_get_paper AT $BB99 RETURN REG(A) AS BYTE ON CPC

'  BB9C TXT_INVERSE       exchange foreground and background colors
DECLARE SYSTEM PROC txt_inverse AT $BB9C ON CPC

'  BB9F TXT_SET_BACK      in: A=0=normal, A=1=transparent/OR
POSITIVE CONST txt_set_back_normal = 0
POSITIVE CONST txt_set_back_transparent = 1
DECLARE SYSTEM PROC txt_set_back AT $BB9F (mode AS BYTE ON REG(A) ) ON CPC
DECLARE SYSTEM PROC txt_set_back_normal AT $BB9F (#txt_set_back_normal ON REG(A) ) ON CPC
DECLARE SYSTEM PROC txt_set_back_transparent AT $BB9F (#txt_set_back_transparent ON REG(A) ) ON CPC

'  BBA2 TXT_GET_BACK      out: Z=normal, NZ=transparent/OR
DECLARE SYSTEM FUNCTION txt_get_back AT $BBA2 RETURN REG(ZERO) ON CPC

'  BBA5 TXT_GET_MATRIX    in: A=char, out: HL=char bitmap ptr, cy:0=ROM,1=RAM
DECLARE SYSTEM FUNCTION txt_get_matrix AT $BBA5 (char AS BYTE ON REG(A), OUT ram AS BYTE ON REG(CARRY) ) RETURN REG(HL) AS ADDRESS ON CPC

'  BBA8 TXT_SET_MATRIX    in: A=char, HL=ptr to 8x8 char bitmap
DECLARE SYSTEM PROC txt_set_matrix AT $BBA8 (char AS BYTE ON REG(A), bitmap AS ADDRESS ON REG(HL) ) ON CPC

'  BBAB TXT_SET_M_TABLE   in: D=00h=RAM, E=1st char, HL=RAM chars, out: cy,A,HL
DECLARE SYSTEM PROC txt_set_m_table AT $BBAB (memory AS BYTE ON REG(D), first AS BYTE ON REG(E), bitmap AS ADDRESS ON REG(HL) ) ON CPC

'  BBAE TXT_GET_M_TABLE   out: cy=1=RAM, A=1st char, HL=RAM chars
DECLARE SYSTEM PROC txt_get_m_table AT $BBAE (ram AS BYTE ON REG(CARRY), first AS BYTE ON REG(A), bitmap AS ADDRESS ON REG(HL) ) ON CPC

'  BBB1 TXT_GET_CONTROLS  out: HL=ptr to table of control characters
DECLARE SYSTEM FUNCTION txt_get_controls AT $BBB1 RETURN REG(HL) AS ADDRESS ON CPC

'  BBB4 TXT_STR_SELECT    in: A=new window number, out: A=old (# 0..7)
DECLARE SYSTEM FUNCTION txt_str_select AT $BBB4 ( win AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BBB7 TXT_SWAP_STREAMS  in: B,C=window numbers to be exchanged
DECLARE SYSTEM PROC txt_swap_streams AT $BBB7 ( win1 AS BYTE ON REG(B), win2 AS BYTE ON REG(B) ) ON CPC

' Graphics Functions
'  BBBA GRA_INITIALIZE
DECLARE SYSTEM PROC gra_initialize AT $BBBA ON CPC

'  BBBD GRA_RESET_HOOKS   ;out: [BDDC+00h..0Ah]=Default jump opcodes/addresses
'                TODO: missing return value?
DECLARE SYSTEM PROC gra_reset_hooks AT $BBBD ON CPC

'  BBC0 GRA_MOVE_ABSOLUTE ;in: de=x, hl=y  ;\set current coordinate
DECLARE SYSTEM PROC gra_move_absolute AT $BBC0 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) ON CPC

'  BBC3 GRA_MOVE_RELATIVE ;in: de=x, hl=y  ;/
DECLARE SYSTEM PROC gra_move_relative AT $BBC3 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) ON CPC

'  BBC6 GRA_ASK_CURSOR    ;out: de=x, hl=y ;-get current coordinate
DECLARE SYSTEM PROC gra_ask_cursor AT $BBC6 ( OUT x AS WORD ON REG(DE), OUT y AS WORD ON REG(HL) ) ON CPC

'  BBC9 GRA_SET_ORIGIN    ;in: de=x, hl=y (also does MOVE 0,0)
DECLARE SYSTEM PROC gra_set_origin AT $BBC9 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) ON CPC

'  BBCC GRA_GET_ORIGIN    ;out: de=x, hl=y
DECLARE SYSTEM PROC gra_get_origin AT $BBCC ( OUT x AS WORD ON REG(DE), OUT y AS WORD ON REG(HL) ) ON CPC

'  BBCF GRA_SET_WIN_WIDTH ;in: de=x1/left, hl=x2/right
DECLARE SYSTEM PROC gra_set_win_width AT $BBCF ( x1left AS WORD ON REG(DE), x2right AS WORD ON REG(HL) )  ON CPC

'  BBD2 GRA_SET_WIN_HEIGHT;in: de=y1/top, hl=y2/bottom
DECLARE SYSTEM PROC gra_set_win_height AT $BBD2 ( y1top AS WORD ON REG(DE), y2bottom AS WORD ON REG(HL) ) ON CPC

'  BBD5 GRA_GET_WIN_WIDTH ;out: de=x1/left, hl=x2/right
DECLARE SYSTEM PROC gra_set_win_width AT $BBD5 ( OUT x1left AS WORD ON REG(DE), OUT x2right AS WORD ON REG(HL) )  ON CPC

'  BBD8 GRA_GET_WIN_HEIGHT;out: de=y1/top, hl=y2/bottom
DECLARE SYSTEM PROC gra_get_win_height AT $BBD8 ( OUT y1top AS WORD ON REG(DE), OUT y2bottom AS WORD ON REG(HL) ) ON CPC

'  BBDB GRA_CLEAR_WINDOW  ;fill window by PAPER (also does MOVE 0,0)
DECLARE SYSTEM PROC gra_clear_window AT $BBDB ON CPC

'  BBDE GRA_SET_PEN       ;in: A=color (0..15) for PLOT/LINE/WR_CHAR
DECLARE SYSTEM PROC gra_set_pen AT $BBDE ( color AS BYTE ON REG(A) ) ON CPC

'  BBE1 GRA_GET_PEN       ;out: A=color (0..15)
DECLARE SYSTEM FUNCTION gra_get_pen AT $BBE1 RETURN REG(A) AS BYTE ON CPC

'  BBE4 GRA_SET_PAPER     ;in: A=color (0..15) for CLEAR_WINDOW/WR_CHAR
DECLARE SYSTEM FUNCTION gra_set_paper AT $BBE4 ( color AS BYTE ON REG(A) ) ON CPC

'  BBE7 GRA_GET_PAPER     ;out: A=color (0..15
DECLARE SYSTEM FUNCTION gra_get_paper AT $BBE7 RETURN REG(A) AS BYTE ON CPC

'  BBEA GRA_PLOT_ABSOLUTE ;in: de=x, hl=y  ;\draw pixel at specified coordinate
DECLARE SYSTEM PROC gra_plot_absolute AT $BBEA ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) )  ON CPC

'  BBED GRA_PLOT_RELATIVE ;in: de=x, hl=y  ;/
DECLARE SYSTEM PROC gra_plot_relative AT $BBED ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) )  ON CPC

'  BBF0 GRA_TEST_ABSOLUTE ;in: de=x, hl=y, out: A=color (0..15) of pixel
DECLARE SYSTEM FUNCTION gra_test_absolute AT $BBF0 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) RETURN REG(A) AS BYTE ON CPC

'  BBF3 GRA_TEST_RELATIVE ;in: de=x, hl=y, out: A=color (0..15) of pixel
DECLARE SYSTEM FUNCTION gra_test_relative AT $BBF3 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) RETURN REG(A) AS BYTE ON CPC

'  BBF6 GRA_LINE_ABSOLUTE ;in: de=x, hl=y  ;\draw line from current coordinate
DECLARE SYSTEM PROC gra_line_absolute AT $BBF6 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) ON CPC

'  BBF9 GRA_LINE_RELATIVE ;in: de=x, hl=y  ;/to specified target coordinate
DECLARE SYSTEM PROC gra_line_relative AT $BBF9 ( x AS WORD ON REG(DE), y AS WORD ON REG(HL) ) ON CPC

'  BBFC GRA_WR_CHAR       ;in: A=char      ;-draw char at current coordinate
DECLARE SYSTEM PROC gra_wr_char AT $BBFC ( char AS BYTE ON REG(A) ) ON CPC

' Screen Functions
'  BBFF SCR_INITIALIZE
DECLARE SYSTEM PROC scr_initialize AT $BBFF ON CPC

'  BC02 SCR_RESET
DECLARE SYSTEM PROC scr_reset AT $BC02 ON CPC

'  BC05 SCR_SET_OFFSET    ;in: HL.bit10..0 = vram offset 0..7FFh
DECLARE SYSTEM PROC scr_set_offset AT $BC05( vram AS ADDRESS ON REG(HL) ) ON CPC

'  BC08 SCR_SET_BASE      ;in: A.bit7-6 = vram block 0..3
DECLARE SYSTEM PROC scr_set_base AT $BC08( vram AS BYTE ON REG(A) ) ON CPC

'  BC0B SCR_GET_LOCATION  ;out: A.bit7-6=block, HL.bit10..0=offset
DECLARE SYSTEM FUNCTION scr_get_location AT $BC0B( OUT block AS BYTE ON REG(A) ) RETURN REG(HL) AS ADDRESS ON CPC

'  BC0E SCR_SET_MODE      ;in: A=mode (0=160x200x16, 1=320x200x4, 2=640x200x2)
POSITIVE CONST scrMode120x200x16 = 0
POSITIVE CONST scrMode320x200x4 = 1
POSITIVE CONST scrMode640x200x2 = 2
DECLARE SYSTEM PROC scr_set_mode AT $BC0E( mode AS BYTE ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_set_mode_120x200x16 AT $BC0E( #scrMode120x200x16 ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_set_mode_320x200x4 AT $BC0E( #scrMode320x200x4 ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_set_mode_640x200x2 AT $BC0E( #scrMode640x200x2 ON REG(A) ) ON CPC

'  BC11 SCR_GET_MODE      ;out: A=mode (cy=mode0, z=mode1, ie. cmp mode,1)
DECLARE SYSTEM PROC scr_get_mode AT $BC11( OUT mode0 AS BYTE ON REG(CARRY), OUT mode1 AS BYTE ON REG(ZERO) ) ON CPC

'  BC14 SCR_MODE_CLEAR    ;clear vram, set offset=0000h, update inks
DECLARE SYSTEM PROC scr_mode_clear AT $BC14 ON CPC

'  BC17 SCR_CHAR_LIMITS   ;out: B=max_x(19,39,79), C=max_y(24)
DECLARE SYSTEM PROC scr_chars_limits AT $BC14 ( max_x AS BYTE ON REG(B), OUT max_y AS BYTE ON REG(C) ) ON CPC

'  BC1A SCR_CHAR_POSITION ;in: H=x, L=y, out: HL=vram addr, B=bytes/char
DECLARE SYSTEM FUNCTION scr_char_position AT $BC1A ( x AS BYTE ON REG(H), y AS BYTE ON REG(L), OUT bytes AS BYTE ON REG(B) ) RETURN REG(HL) AS ADDRESS ON CPC

'  BC1D SCR_DOT_POSITION  ;in: DE=x, HL=y, out: HL=vram addr, C=mask, DE, B
DECLARE SYSTEM FUNCTION scr_dot_position AT $BC1D ( x AS WORD ON REG(DE), y AS WORD ON REG(HL), OUT mask AS BYTE ON REG(C) ) RETURN REG(HL) AS ADDRESS ON CPC

'  BC20 SCR_NEXT_BYTE     ;out: HL=HL+1 (wrapped within 800h-byte block)
DECLARE SYSTEM FUNCTION scr_next_byte AT $BC20 RETURN REG(HL) AS ADDRESS ON CPC

'  BC23 SCR_PREV_BYTE     ;out: HL=HL-1 (wrapped within 800h-byte block)
DECLARE SYSTEM FUNCTION scr_prev_byte AT $BC23 RETURN REG(HL) AS ADDRESS ON CPC

'  BC26 SCR_NEXT_LINE     ;out: HL=HL+800h, or HL=HL+50h-3800h (or so)
DECLARE SYSTEM FUNCTION scr_next_line AT $BC26 RETURN REG(HL) AS ADDRESS ON CPC

'  BC29 SCR_PREV_LINE     ;out: HL=HL-800h, or HL=HL-50h+3800h (or so)
DECLARE SYSTEM FUNCTION scr_prev_line AT $BC29 RETURN REG(HL) AS ADDRESS ON CPC

'  BC2C SCR_INK_ENCODE    ;in: A=color, out: A=color_mask
DECLARE SYSTEM FUNCTION scr_ink_encode AT $BC2C ( color AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BC2F SCR_INK_DECODE    ;in: A=color_mask, out: A=color
DECLARE SYSTEM FUNCTION scr_ink_decode AT $BC2F ( mask AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BC32 SCR_SET_INK       ;in: A=index, B=color1, C=color2
DECLARE SYSTEM PROC scr_set_ink AT $BC32 ( index AS BYTE ON REG(A), color1 AS BYTE ON REG(B), color2 AS BYTE ON REG(C) ) ON CPC

'  BC35 SCR_GET_INK       ;in: A=index, out: B=color1, C=color2
DECLARE SYSTEM PROC scr_get_ink AT $BC35 ( index AS BYTE ON REG(A), OUT color1 AS BYTE ON REG(B), OUT color2 AS BYTE ON REG(C) ) ON CPC

'  BC38 SCR_SET_BORDER    ;in: B=color1, C=color2
DECLARE SYSTEM PROC scr_set_border AT $BC38 ( color1 AS BYTE ON REG(B), color2 AS BYTE ON REG(C) ) ON CPC

'  BC3B SCR_GET_BORDER    ;out: B=color1, C=color2
DECLARE SYSTEM PROC scr_get_border AT $BC3B ( OUT color1 AS BYTE ON REG(B), OUT color2 AS BYTE ON REG(C) ) ON CPC

'  BC3E SCR_SET_FLASHING  ;in: H=count1, L=count2
DECLARE SYSTEM PROC scr_set_flashing AT $BC3E ( color1 AS BYTE ON REG(H), color2 AS BYTE ON REG(L) ) ON CPC

'  BC41 SCR_GET_FLASHING  ;out: H=count1, L=count2
DECLARE SYSTEM PROC scr_set_flashing AT $BC41 ( OUT color1 AS BYTE ON REG(H), OUT color2 AS BYTE ON REG(L) ) ON CPC

'  BC44 SCR_FILL_BOX      ;in: A=fillbyte, H=x1, L=y1, D=x2, E=y2
DECLARE SYSTEM PROC scr_fill_box AT $BC44 ( fill AS BYTE ON REG(A), x1 AS BYTE ON REG(H), y1 AS BYTE ON REG(L), x2 AS BYTE ON REG(D), y2 AS BYTE ON REG(E) ) ON CPC

'  BC47 SCR_FLOOD_BOX     ;in: A=fillbyte, HL=vram addr, D=xsiz, E=ysiz
DECLARE SYSTEM PROC scr_flood_box AT $BC47 ( fill AS BYTE ON REG(A), vram AS ADDRESS ON REG(HL), x_size AS BYTE ON REG(D), y_size AS BYTE ON REG(E) ) ON CPC

'  BC4A SCR_CHAR_INVERT   ;in: H=x, L=y, B=paper, C=pen
DECLARE SYSTEM PROC scr_char_invert AT $BC4A ( x AS BYTE ON REG(H), y AS BYTE ON REG(L), paper AS BYTE ON REG(B), pen AS BYTE ON REG(C) ) ON CPC

'  BC4D SCR_HARDWARE_ROLL ;in: A=paper, B=dir(0=down, FFh=up)
POSITIVE CONST rollDirectionDown = 0
POSITIVE CONST rollDirectionUp = $ff
DECLARE SYSTEM PROC scr_hardware_roll AT $BC4D ( paper AS BYTE ON REG(A), direction AS BYTE ON REG(B) ) ON CPC
DECLARE SYSTEM PROC scr_hardware_roll_down AT $BC4D ( paper AS BYTE ON REG(A), #rollDirectionDown ON REG(B) ) ON CPC
DECLARE SYSTEM PROC scr_hardware_roll_up AT $BC4D ( paper AS BYTE ON REG(A), #rollDirectionUp ON REG(B) ) ON CPC

'  BC50 SCR_SOFTWARE_ROLL ;in: A=paper, B=dir(""), H=x1, L=y1, D=x2, E=y2
DECLARE SYSTEM PROC scr_software_roll AT $BC50 ( paper AS BYTE ON REG(A), direction AS BYTE ON REG(B), x1 AS BYTE ON REG(H), y1 AS BYTE ON REG(L), x2 AS BYTE ON REG(D), y2 AS BYTE ON REG(E) ) ON CPC
DECLARE SYSTEM PROC scr_software_roll_down AT $BC50 ( paper AS BYTE ON REG(A), #rollDirectionDown ON REG(B), x1 AS BYTE ON REG(H), y1 AS BYTE ON REG(L), x2 AS BYTE ON REG(D), y2 AS BYTE ON REG(E) ) ON CPC
DECLARE SYSTEM PROC scr_software_roll_up AT $BC50 ( paper AS BYTE ON REG(A), #rollDirectionUp ON REG(B), x1 AS BYTE ON REG(H), y1 AS BYTE ON REG(L), x2 AS BYTE ON REG(D), y2 AS BYTE ON REG(E) ) ON CPC

'  BC53 SCR_UNPACK        ;in: HL=src, DE=dest (mono 8x8 char to colored 8x8)
DECLARE SYSTEM PROC scr_unpack AT $BC53 ( src AS ADDRESS ON REG(HL), dest AS ADDRESS ON REG(DE) ) ON CPC

'  BC56 SCR_REPACK        ;in: H=x, L=y, A=pen, DE=dest (colored 8x8 to mono)
DECLARE SYSTEM PROC scr_repack AT $BC56 ( x AS BYTE ON REG(H), y AS BYTE ON REG(L), pen AS BYTE ON REG(A), dest AS ADDRESS ON REG(DE) ) ON CPC

'  BC59 SCR_ACCESS        ;in: A=drawmode (0=Normal, 1=XOR, 2=AND, 3=OR)
POSITIVE CONST accessModeNormal = 0
POSITIVE CONST accessModeXor = 1
POSITIVE CONST accessModeAnd = 2
POSITIVE CONST accessModeOr = 3
DECLARE SYSTEM PROC scr_access AT $BC59 ( draw_mode AS BYTE ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_access_normal AT $BC59 ( #accessModeNormal ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_access_xor AT $BC59 ( #accessModeXor ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_access_and AT $BC59 ( #accessModeAnd ON REG(A) ) ON CPC
DECLARE SYSTEM PROC scr_access_or AT $BC59 ( #accessModeOr ON REG(A) ) ON CPC

'  BC5C SCR_PIXELS        ;in: HL=vram addr, C=xmask, B=color
DECLARE SYSTEM PROC scr_pixels AT $BC5C ( vram AS ADDRESS ON REG(HL), xmask AS BYTE ON REG(C), color AS BYTE ON REG(B) ) ON CPC

'  BC5F SCR_HORIZONTAL    ;in: A=pen, DE=x1, BC=x2, HL=y
DECLARE SYSTEM PROC scr_horizontal AT $BC5F ( pen AS BYTE ON REG(A), x1 AS WORD ON REG(DE), x2 AS WORD ON REG(BC), y AS WORD ON REG(HL) ) ON CPC

'  BC62 SCR_VERTICAL      ;in: A=pen, HL=y1, BC=y2, DE=x
DECLARE SYSTEM PROC scr_vertical AT $BC62 ( pen AS BYTE ON REG(A), y1 AS WORD ON REG(HL), y2 AS WORD ON REG(BC), x AS WORD ON REG(DE) ) ON CPC

' Cassette (or Diskette) Functions
'  BC65 CAS_INITIALIZE
DECLARE SYSTEM PROC cas_initialize AT $BC65 ON CPC

'  BC68 CAS_SET_SPEED     ;in: HL=upper16bit, A=lower8bit
DECLARE SYSTEM PROC cas_set_speed AT $BC68 ( speed AS DWORD ON REG(HLA) ) ON CPC

'  BC6B CAS_NOISY         ;in: A=output cassette messages (0=yes, >0=no)
POSITIVE CONST noisyYes = 0
POSITIVE CONST noisyNo = 1
DECLARE SYSTEM PROC cas_noisy AT $BC6B ( output AS BYTE ON REG(A) ) ON CPC
DECLARE SYSTEM PROC cas_noisy_yes AT $BC6B ( #noisyYes ON REG(A) ) ON CPC
DECLARE SYSTEM PROC cas_noisy_no AT $BC6B ( #noisyNo ON REG(A) ) ON CPC

'  BC6E CAS_START_MOTOR   ;out: A.bit4 old motor status (0=off, 1=on), cy=0, z=1
'               TODO: missing return value?
DECLARE SYSTEM PROC cas_start_motor AT $BC6E ON CPC

'  BC71 CAS_STOP_MOTOR    ;out: A.bit4 old motor status (0=off, 1=on), cy=0, z=1
'               TODO: missing return value?
DECLARE SYSTEM PROC cas_stop_motor AT $BC71 ON CPC

'  BC74 CAS_RESTORE_MOTOR ;in: A.bit4 new motor status (0=off, 1=on), cy=0, z=1
'               TODO: missing return value?
DECLARE SYSTEM PROC cas_restore_motor AT $BC74 ON CPC

'  BC77 CAS_IN_OPEN       ;in: HL=fname, B=fnamelen, DE=workbuf,
'                         ;out: HL=header, DE=dest, BC=siz, A=type, cy=err, zf
DECLARE SYSTEM FUNCTION cas_in_open AT $BC77 ( filename AS ADDRESS ON REG(HL), filename_len AS ADDRESS ON REG(B), buffer AS ADDRESS ON REG(DE), OUT header AS ADDRESS ON REG(HL), OUT dest AS ADDRESS ON REG(DE), OUT size AS WORD ON REG(BC), OUT type AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC7A CAS_IN_CLOSE      ;out: DE=workbuf, cy=0=failed (no open file)
DECLARE SYSTEM FUNCTION cas_in_close AT $BC7A ( OUT buffer AS ADDRESS ON REG(DE) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC7D CAS_IN_ABANDON    ;out: DE=workbuf, cy=1, z=0, A=all_closed (FFh=yes)
POSITIVE CONST abandonAllCloseNo = 0
POSITIVE CONST abandonAllCloseYes = $ff
DECLARE SYSTEM FUNCTION cas_in_abandon AT $BC7D ( OUT buffer AS ADDRESS ON REG(DE), all_closed AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC
DECLARE SYSTEM FUNCTION cas_in_abandon_all_close AT $BC7D ( OUT buffer AS ADDRESS ON REG(DE), #abandonAllCloseYes ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC80 CAS_IN_CHAR       ;out: A=char, cy=0=error, zf=errtype
DECLARE SYSTEM FUNCTION cas_in_char AT $BC80 ( OUT status AS BYTE ON REG(CARRY) ) RETURN REG(A) AS BYTE ON CPC

'  BC83 CAS_IN_DIRECT     ;in: HL=dest, out: HL=entrypoint, cy=0=err, zf=errtype
DECLARE SYSTEM FUNCTION cas_in_direct AT $BC83 ( destination AS ADDRESS ON REG(HL), OUT status AS BYTE ON REG(CARRY) ) RETURN REG(HL) AS ADDRESS ON CPC

'  BC86 CAS_RETURN        ;in: A=char (undo CAS_IN_CHAR, char back to buffer)
DECLARE SYSTEM PROC cas_retuirn AT $BC86 ( char AS BYTE ON REG(A) ) ON CPC

'  BC89 CAS_TEST_EOF      ;out: CY=0=eof (end of file)
DECLARE SYSTEM FUNCTION cas_return AT $BC89 RETURN REG(CARRY) AS BYTE ON CPC

'  BC8C CAS_OUT_OPEN      ;in: HL=fname, B=fnamelen, DE=workbuf, out: HL,cy,zf
DECLARE SYSTEM FUNCTION cas_out_copen AT $BC8C ( filename AS ADDRESS ON REG(HL), filename_len AS BYTE ON REG(B), buffer AS ADDRESS ON REG(DE), OUT buffer2 AS ADDRESS ON REG(HL) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC8F CAS_OUT_CLOSE     ;out: DE=workbuf, cy=0=failed (zf=errtype)
DECLARE SYSTEM FUNCTION cas_out_close AT $BC8F ( OUT buffer AS ADDRESS ON REG(DE) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC92 CAS_OUT_ABANDON   ;out: DE=workbuf, cy=1, z=0, A=all_closed (FFh=yes)
DECLARE SYSTEM FUNCTION cas_out_abandon AT $BC92( OUT buffer AS ADDRESS ON REG(HL), all_closed AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC
DECLARE SYSTEM FUNCTION cas_out_abandon_all_close AT $BC92 ( OUT buffer AS ADDRESS ON REG(HL), all_closed AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC95 CAS_OUT_CHAR      ;in: A=char, out: cy=0=error, zf=errtype
DECLARE SYSTEM FUNCTION cas_out_char AT $BC95 ( char AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC98 CAS_OUT_DIRECT    ;in: HL=src, DE=len, BC=entrypoint, A=type, out: cy/zf
DECLARE SYSTEM FUNCTION cas_out_char AT $BC95 ( char AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC9B CAS_CATALOG       ;in: DE=workbuf, out: DE=workbuf, cy=0=error
DECLARE SYSTEM FUNCTION cas_out_char AT $BC95 ( char AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BC9E CAS_WRITE         ;in: HL=src, DE=len, A=ID(2Ch=header, 16h=data), out?
DECLARE SYSTEM FUNCTION cas_out_char AT $BC95 ( char AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BCA1 CAS_READ          ;in: HL=dest, DE=len, A=ID(2Ch=header, 16h=data), out?
DECLARE SYSTEM FUNCTION cas_read AT $BCA1 ( dest AS ADDRESS ON REG(HL), len AS WORD ON REG(DE), type AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

'  BCA4 CAS_CHECK         ;in: HL=src, DE=len, A=ID(2Ch=header, 16h=data), out?
DECLARE SYSTEM FUNCTION cas_check AT $BCA4 ( source AS ADDRESS ON REG(HL), dest AS ADDRESS ON REG(HL), len AS WORD ON REG(DE), type AS BYTE ON REG(A) ) RETURN REG(CARRY) AS BYTE ON CPC

' Sound Functions
'  BCA7 SOUND_RESET
DECLARE SYSTEM PROC sound_reset AT $BCA7 ON CPC

'  BCAA SOUND_QUEUE     ;in: HL=dat ;ch,env,ent,freq(lo,hi,noise),vol,len(lo,hi)
DECLARE SYSTEM PROC sound_queue AT $BCAA ( dat AS ADDRESS ON REG(HL) ) ON CPC

'  BCAD SOUND_CHECK     ;in: A=channel mask, out: A=channel status
DECLARE SYSTEM FUNCTION sound_check AT $BCAD ( mask AS BYTE ON REG(A) ) RETURN REG(A) AS BYTE ON CPC

'  BCB0 SOUND_ARM_EVENT
DECLARE SYSTEM PROC sound_arm_event AT $BCB0 ON CPC

'  BCB3 SOUND_RELEASE   ;in: A=channel mask
DECLARE SYSTEM PROC sound_release AT $BCB3 ( mask AS BYTE ON REG(A) ) ON CPC

'  BCB6 SOUND_PAUSE
DECLARE SYSTEM PROC sound_pause AT $BCB6 ON CPC

'  BCB9 SOUND_UNPAUSE
DECLARE SYSTEM PROC sound_pause AT $BCB9 ON CPC

'  BCBC SOUND_SET_ENV   ;in: A=number (1..15), HL=data (must be >3FFFh)
DECLARE SYSTEM PROC sound_set_env AT $BCBC ( number AS BYTE ON REG(A), data AS WORD ON REG(HL) ) ON CPC

'  BCBF SOUND_SET_ENT   ;in: A=number (1..15), HL=data (must be >3FFFh)
DECLARE SYSTEM PROC sound_set_ent AT $BCBF ( number AS BYTE ON REG(A), data AS WORD ON REG(HL) ) ON CPC

'  BCC2 SOUND_GET_ENV   ;in: A=number (1..15), out: HL=data
DECLARE SYSTEM FUNCTION sound_get_env AT $BCBC ( number AS BYTE ON REG(A) ) RETURN REG(HL) AS WORD ON CPC

'  BCC5 SOUND_GET_ENT   ;in: A=number (1..15), out: HL=data
DECLARE SYSTEM FUNCTION sound_get_ent AT $BCBC ( number AS BYTE ON REG(A) ) RETURN REG(HL) AS WORD ON CPC

' Kernel ROM Functions
'  BCC8 KL_CHOKE_OFF
'  BCCB KL_ROM_WALK
'  BCCE KL_INIT_BACK
'  BCD1 KL_LOG_EXT
'  BCD4 KL_FIND_COMMAND

' Kernel Timer/Event Functions
'  BCD7 KL_NEW_FRAME_FLY
'  BCDA KL_ADD_FRAME_FLY
'  BCDD KL_DELETE_FRAME_FLY
'  BCE0 KL_NEW_FAST_TICKER
'  BCE3 KL_ADD_FAST_TICKER
'  BCE6 KL_DELETE_FAST_TICKER
'  BCE9 KL_ADD_TICKER
'  BCEC KL_DELETE_TICKER
'  BCEF KL_INIT_EVENT
'  BCF2 KL_EVENT
'  BCF5 KL_SYNC_RESET
'  BCF8 KL_DEL_SYNCHRONOUS
'  BCFB KL_NEXT_SYNC
'  BCFE KL_DO_SYNC
'  BD01 KL_DONE_SYNC
'  BD04 KL_EVENT_DISABLE
'  BD07 KL_EVENT_ENABLE
'  BD0A KL_DISARM_EVENT
'  BD0D KL_TIME_PLEASE     ;out: hl=low, de=high (64bit, incremented at 300Hz)
'  BD10 KL_TIME_SET        ;in:  hl=low, de=high (64bit, incremented at 300Hz)

' Machine Pack
'  BD13 MC_BOOT_PROGRAM    ;in: HL=loader_callback, out: starts program
'  BD16 MC_START_PROGRAM   ;in: HL=entrypoint (0000h=BASIC), C=ROMcfg
'  BD19 MC_WAIT_FLYBACK    ;wait until/unless PIO.Port B bit0=1 (vsync)
'  BD1C MC_SET_MODE        ;in: A=video mode (0..2) (for C' and gate array)
'  BD1F MC_SCREEN_OFFSET   ;in: A=base, HL=offset   (for CRTC)
'  BD22 MC_CLEAR_INKS      ;in: DE=ptr to border and 1 ink
'  BD25 MC_SET_INKS        ;in: DE=ptr to border and 16 inks
'  BD28 MC_RESET_PRINTER   ;out: [BDF1]=default jp opcode
'  BD2B MC_PRINT_CHAR      ;in: A=char, out: CY=1=okay, CY=0=busy/timeout
'  BD2E MC_BUSY_PRINTER    ;out: CY=1=busy, CY=0=ready
'  BD31 MC_SEND_PRINTER    ;in: A=char, out: CY=1
'  BD34 MC_SOUND_REGISTER  ;in: A=PSG index, C=PSG data
'  BD37 JUMP_RESTORE       ;out: [BB00..BDCC]=defaults

' Edit and Floating Point Functions (Addresses changed in each version)
'  464  664  6128
'  BD3A BD5B BD5E EDIT  ;io: HL=input buffer, out: CY=0=ESC (also Z=1=ESC)
'  BD3D BD5E BD61 FLO_COPY [HL]=[DE], A=exponent
'  BD40 BD61 BD64 FLO_int to real  ;DE=dest, HL=unsigned16bit, A.7=sign
'  BD43 BD64 BD67 FLO_ 4-byte to real
'  BD46 BD67 BD6A FLO_ real to int
'  BD49 BD6A BD6D FLO_ round
'  BD4C BD6D BD70 FLO_ FIX
'  BD4F BD70 BD73 FLO_ INT
'  BD52 BD73 BD76 FLO_ prepare for decimal
'  BD55 BD76 BD79 FLO_ mul 10^A
'  BD58 BD79 BD7C FLO_ ADD [HL]=[HL]+[DE]
'  BD5B N/A  N/A  FLO_PROC1  [HL]=[HL]-[DE]
'  BD5E BD7F BD82 FLO_PROC2  [HL]=[DE]-[HL] (swapped operands)
'  BD61 BD82 BD85 FLO_MUL   [HL]=[HL]*[DE]
'  BD64 BD85 BD88 FLO_DIV   [HL]=[HL]/[DE]
'  BD67 N/A  N/A  FLO_SHIFT [HL]=[HL]*2^A
'  BD6A BD8B BD8E FLO_COMPARE [HL]-[DE]
'  BD6D BD8E BD91 FLO_NEG
'  BD70 BD91 BD94 FLO_SGN
'  BD73 BD94 BD97 FLO_DEG/RAD  ;in: A=00h=RAD, FFh=DEG
'  BD76 BD97 BD9A FLO_PI    [HL]=PI
'  BD79 BD9A BD9D FLO_SQRT  [HL]=[HL]^0.5
'  BD7C BD9D BDA0 FLO_POT   [HL]=[HL]^[DE]
'  BD7F BDA0 BDA3 FLO_LOG   [HL]=LOG([HL])
'  BD82 BDA3 BDA6 FLO_LOG10 [HL]=LOG10([HL])
'  BD85 BDA6 BDA9 FLO_EXP   [HL]=EXP([HL])
'  BD88 BDA9 BDAC FLO_SIN   [HL]=SIN([HL])
'  BD8B BDAC BDAF FLO_COS   [HL]=COS([HL])
'  BD8E BDAF BDB2 FLO_TAN   [HL]=TAN([HL])
'  BD91 BDB2 BDB5 FLO_ATN   [HL]=ATN([HL])
'  BD94 BDB5 BDB8 FLO_5-byte to REAL
'  BD97 BDB8 BDBB FLO_RND_INIT        ;seed=89656C07h
'  BD9A BDBB BDBE FLO_RND_SEED        ;seed=89656C07h xor [HL]
'  BD9D BD7C BD7F FLO_RND              ;\on 664/6128 these are "inserted"
'  BDA0 BD88 BD8B FLO_RND last value   ;/in the above "N/A" locations

' Integer Functions - 464 only (moved/replaced by other stuff on 664 and up)
'  464  664  6128
'  BDA3 N/A  N/A  INT_ABS  HL=ABS(HL), B.7=SIGN(HL), C=2=Mantisse, E=0=Int
'  BDA6 N/A  N/A  INT_POS  HL=HL, B.7=0=Positive, C=2=Mantisse, E=0=Int
'  BDA9 N/A  N/A  INT_UNDO in: HL=unsigned, B.7=sign, out: HL=signed, cy,zf
'  BDAC N/A  N/A  INT_ADD  HL=HL+DE, Z=1=zero, CY=1=signed_overflow
'  BDAF N/A  N/A  INT_PROC1 HL=HL-DE, Z=1=zero, CY=0=signed_overflow
'  BDB2 N/A  N/A  INT_PROC2 HL=DE-HL, Z=1=zero, CY=0=signed_overflow
'  BDB5 N/A  N/A  INT_MUL  HL=HL*DE
'  BDB8 N/A  N/A  INT_DIV  HL=HL/DE
'  BDBB N/A  N/A  INT_MOD  HL=HL MOD DE
'  BDBE N/A  N/A  INT_UMUL HL=HL*DE, CY=1=unsigned_overflow
'  BDC1 N/A  N/A  INT_UDIV HL=HL/DE, DE=HL MOD DE, Z=1=error (div0)
'  BDC4 N/A  N/A  INT_CMP  A=SGN(HL-DE) ;00h=zero, 01h=pos, FFh=neg
'  BDC7 N/A  N/A  INT_NEG  HL=-HL       ;cy=0=overflow (HL=+8000h)
'  BDCA N/A  N/A  INT_SGN  A=SGN(HL)    ;00h=zero, 01h=pos, FFh=neg

' Additional 664/6128 Functions
'  664 and up only...
'  BD3A KM_SET_LOCKS_664 ;in: H=caps lock (caps), L=shift lock (ctrl caps)
'  BD3D KM_FLUSH_664     ;calls KM_READ_CHAR until cy=0
'  BD40 TXT_ASK_STATE_664
'  BD43 GRA_DEFAULT_664       ;SCR_WRITE=?, BACK=00h,FIRST=FFh,MASK=FFh
'  BD46 GRA_SET_BACK_664      ;A=background mode (FFh=transparent)
'  BD49 GRA_SET_FIRST_664     ;in: A=flag (00h,FFh;1st pix of LINE)
'  BD4C GRA_SET_LINE_MASK_664 ;in: A=mask
'  BD4F GRA_FROM_USER_664     ;in: de=x, hl=y, out: de,hl=real x,y
'  BD52 GRA_FILL_664          ;in: A=color,hl=buf,de=bufsize, out:cy=0=err
'  BD55 SCR_SET_POSITION_664  ;in: A=BASE,HL=OFFSET, out: A AND C0h, HL AND 7FEh
'  BD58 MC_PRINT_TRANSLATION_664

'  6128 and up only...
'  BD5B KL_RAM_SELECT_6128  --6128 only--
' Indirections (List of JUMPs into BIOS area -- LO ROM must be enabled!)
'  BDCD HOOK_TXT_DRAW_CURSOR
'  BDD0 HOOK_TXT_UNDRAW_CURSOR
'  BDD3 HOOK_TXT_WRITE_CHAR    ;in: H=x, L=y, A=char
'  BDD6 HOOK_TXT_UNWRITE       ;in: H=x, L=y, out: A=char, Z=space, cy=1=okay
'  BDD9 HOOK_TXT_OUT_ACTION    ;in: A=char
'  BDDC HOOK_GRA_PLOT          ;in: de=x, hl=y
'  BDDF HOOK_GRA_TEST          ;in: de=x, hl=y, out: A=color
'  BDE2 HOOK_GRA_LINE          ;in: de=x, hl=y
'  BDE5 HOOK_SCR_READ          ;in: HL=vram addr, C=xmask, out: A=color
'  BDE8 HOOK_SCR_WRITE         ;in: HL=vram addr, C=xmask, B=color
'  BDEB HOOK_SCR_MODE_CLEAR    ;clear vram, etc. (same as BC14)
'  BDEE HOOK_KM_TEST_BREAK
'  BDF1 HOOK_MC_PRINT_CHAR     ;in: A=char, out: CY=1=okay, CY=0=busy/timeout
'  664 and up only:
'  BDF4 HOOK_KM_SCAN_KEYS_664
' RSX Functions (Resident System Extensions)
'  C000 (ROM Header)
'  C004 Pointer to RSX Function Names ;Names end with bit7=1, list ends with 00h
'  C006 List of 16bit RSX Function Addresses
' Note: RSX function 3-byte FAR addresses can be retrieved via KL_FIND_COMMAND.

' BASIC RSX Functions
'  ;RSX Name: "BASIC"+80h ;io: DE=LORAM, HL=HIRAM
' AMSDOS RSX Functions
'  CPM           ;in: A=00h (no params) ;start boot sector
'  DISC          ;in: A=00h (no params)
'  DISC.IN       ;in: A=00h (no params) ;not supported by CPC+
'  DISC.OUT      ;in: A=00h (no params) ;not supported by CPC+
'  TAPE          ;in: A=00h (no params) ;not supported by VDOS
'  TAPE.IN       ;in: A=00h (no params) ;not supported by VDOS and CPC+
'  TAPE.OUT      ;in: A=00h (no params) ;not supported by VDOS and CPC+
'  A             ;in: A=00h (no params) ;set default drive = A
'  B             ;in: A=00h (no params) ;set default drive = B
'  DRIVE         ;in: A=01h, [IX+0]=ptr to "A","a","B","b"     ;\not supported
'  USER          ;in: A=01h, [IX+0]=user number (0000h..000Fh) ;/by VDOS
'  DIR           ;in: A=00h, or A=01h, [IX+0]=ptr to "filename"
'  ERA           ;in: A=01h, [IX+0]=ptr to "filename"
'  REN           ;in: A=02h, [IX+0]=ptr to "oldname",[IX+2]=to "newname"
' AMSDOS Hidden RSX Functions
'  [C006h]  INIT             ;in/out: DE=LORAM, HL=HIRAM, CY=?
'  chr(81h) MESSAGE_ON_OFF   ;in: A=flag(00h=on, >=01h=off) (R,I,C) ;out:A=old
'  chr(82h) SET_DRIVE_SPEED  ;in: HL=ptr to 9 bytes
'  chr(83h) SET_DISK_TYPE    ;in: A=type (0xh=IBM, 4xh=CPM, Cxh=DATA)
'  chr(84h) READ_SECTOR      ;in: E=drv, D=trk, C=sec, HL=dest
'  chr(85h) WRITE_SECTOR     ;in: E=drv, D=trk, C=sec, HL=src
'  chr(86h) FORMAT_TRACK     ;in: E=drv, D=trk, C=sec1, HL=ptr to 9x4 byte
'  chr(87h) SEEK_TRACK       ;in: E=drv, D=trk, out: cy=1=okay
'  chr(88h) TEST_DRIVE       ;in: A=drv, out: cy=1=okay
'  chr(89h) SET_RETRY_COUNT  ;in: A=retry count (default=10) (01h..(1)00h)
