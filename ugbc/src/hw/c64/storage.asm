; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                         MASS STORAGE ROUTINE ON C=64                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; This routine will open a file using the KERNAL routines.
;   TMPPTR: filename, MATHPTR0: size of filename
;   flag C is set ? error!
C64STORAGEOPENFILE:
    ; Set file name parameters
    ; Input: A = File name length; X/Y = Pointer to file name.
    LDA MATHPTR0
    LDX TMPPTR
    LDY TMPPTR+1
    JSR $FFBD
    ; Set file parameters.
    ; Input: A = Logical number; X = Device number; Y = Secondary address.
    LDA #$02
    LDX #$08
    LDY #$00
    JSR $FFBA
    ; Open file
    JSR $FFC0
    RTS

; This routine will set the current file as default input.
C64STORAGEINPUT:
    ; Define file as default input.
    ; Input: X = Logical number.
    LDX #$02
    JSR $FFC6
    RTS

; This routine will check if the file is ended.
C64STORAGEISEOF:
    ; Fetch status of current input/output device, value of ST variable.
    ; Output: A = Device status.
    LDY #$00
    JSR $FFB7
    RTS

; This routine will read one char at a time.
C64STORAGELOADCHAR:
    ; Read byte from default input (for keyboard, read a line from the screen). (If not keyboard, must call OPEN and CHKIN beforehands.)
    ; Output: A = Byte read.
    JSR $FFCF
    RTS

; This routine will close the storage.
C64STORAGECLOSE:
    LDA #$02
    ; Close file.
    ; Input: A = Logical number.
    JSR $FFC3
    ; Close default input/output files;
    ; Restore default input/output to keyboard/screen.
    JSR $FFCC
    RTS

; Load the size of the given file. Note that, currently, the hardware
; is not able to calculate the size in a easy way. So it will be
; stored on the head of the file. In order to use the minimum size
; to store the byte, we will use the first byte to store the size in bytes:
;
;  +---+---+
;  | 0 | L | - 0 means a file from 0 to 255 bytes
;  +---+---+---+
;  |> 0| L | H | - >0 means a file from 256 to 65.535 bytes
;  +---+---+---+
; 
;    TMPPTR: filename, MATHPTR0: size of filename
;    MATHPTR2:MATHPTR1 : size of file
C64STORAGELOADSIZE:
    ; Re-enable KERNAL for using its routines.
    LDA #$36
    STA $01
    ; Open the file with the given filename.
    JSR C64STORAGEOPENFILE
    ; Exit if any error occurred.
    BCS C64STORAGELOADSIZEEOF
    ; Set the file as input for the following actions.
    JSR C64STORAGEINPUT
    ; Exit if the file is finished
    JSR C64STORAGEISEOF
    BNE C64STORAGELOADSIZEEOF
    ; Load the first character.
    JSR C64STORAGELOADCHAR
    CMP #0
    ; If it is not zero, the size is >= 256 bytes
    BNE C64STORAGELOADSIZE2
    ;
    ; Load the size as 1-byte
C64STORAGELOADSIZE1:
    JSR C64STORAGELOADCHAR
    STA MATHPTR1
    LDA #0
    STA MATHPTR2
    JMP C64STORAGELOADSIZEEOF
    ;
    ; Load the size as 2-byte
C64STORAGELOADSIZE2:
    JSR C64STORAGELOADCHAR
    STA MATHPTR1
    JSR C64STORAGELOADCHAR
    STA MATHPTR2
    JMP C64STORAGELOADSIZEEOF
    ;
    ; Finish the file and close it.
C64STORAGELOADSIZEEOF:
    JSR C64STORAGECLOSE
    ; Disable KERNAL again.
    LDA #$35
    STA $01
    ; Done!
    RTS

; Load a given file.
; 
;    TMPPTR: filename, MATHPTR0: size of filename
;    MATHPTR2:MATHPTR1 : size of file
;    TMPPTR2: where to put the content of the file
C64STORAGELOAD:
    ; Re-enable KERNAL for using its routines.
    LDA #$36
    STA $01
    ; Open the file with the given filename.
    JSR C64STORAGEOPENFILE
    ; Exit if any error occurred.
    BCS C64STORAGELOADEOF
    ; Set the file as input for the following actions.
    JSR C64STORAGEINPUT
    ; Exit if the file is finished
    JSR C64STORAGEISEOF
    BNE C64STORAGELOADEOF
    ; Load the size byte to detect the size of the head.
    LDA MATHPTR2
    CMP #0
    BNE C64STORAGELOAD2
    ; Load 2 bytes from the file, to skip the size.
C64STORAGELOAD1:
    JSR C64STORAGELOADCHAR
    JSR C64STORAGELOADCHAR
    JMP C64STORAGELOADDATA
    ; Load 3 bytes from the file, to skip the size.
C64STORAGELOAD2:
    JSR C64STORAGELOADCHAR
    JSR C64STORAGELOADCHAR
    JSR C64STORAGELOADCHAR
    JMP C64STORAGELOADDATA
    ; Load the rest of the file
C64STORAGELOADDATA:
    LDY #0
C64STORAGELOADDATALOOP:
    ; Exit if file is finished.
    JSR C64STORAGEISEOF
    BNE C64STORAGELOADEOF
    ; Load character to the TMPPTR2 memory area
    JSR C64STORAGELOADCHAR
    STA (TMPPTR2), Y
    ; Increment the pointer
    INC TMPPTR2
    BNE C64STORAGELOADDATALOOP2A
    INC TMPPTR2+1
C64STORAGELOADDATALOOP2A:
    ; Decrement the file size
    LDA MATHPTR1
    BNE C64STORAGELOADDATALOOP2
    LDA MATHPTR2
    BEQ C64STORAGELOADDATALOOP0
    DEC MATHPTR2
C64STORAGELOADDATALOOP2:
    DEC MATHPTR1
    JMP C64STORAGELOADDATALOOP
    ;
    ; Finish the file and close it.
C64STORAGELOADDATALOOP0:
C64STORAGELOADEOF:
    JSR C64STORAGECLOSE
    ; Disable KERNAL again.
    LDA #$35
    STA $01
    RTS
