REM @english
REM SPRITE MANAGEMENT ASSEMBLING A MULTICOLOR SPRITE (2)
REM
REM This example shows how to automatically create a multicolor sprite,
REM in order to have more than one color. You can have sprites with
REM up to SPRITE COUNT independent colors.
REM
REM @italian
REM GESTIONE DEGLI SPRITE ASSEMBLARE UNO SPRITE MULTICOLORE (2)
REM
REM Questo esempio mostra come creare in automatico uno sprite multicolore,
REM per avere più di un colore. Puoi avere sprite con fino a SPRITE COUNT
REM colori indipendenti.
REM
REM @include coleco,sg1000,sc3000

BITMAP ENABLE (16)

spriteImageColor := LOAD IMAGE("sprite_color.png")

spriteColor = CSPRITE(spriteImageColor)

SPRITE spriteColor ENABLE

SPRITE spriteColor AT 100,100
