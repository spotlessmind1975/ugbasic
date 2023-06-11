REM @english
REM SPRITE MANAGEMENT ASSEMBLING A MULTICOLOR SPRITE (1)
REM
REM This example shows how to manually assembly a multicolor sprite,
REM in order to have more than one color. You can have sprites with
REM up to SPRITE COUNT independent colors.
REM
REM @italian
REM GESTIONE DEGLI SPRITE ASSEMBLARE UNO SPRITE MULTICOLORE (1)
REM
REM Questo esempio mostra come assemblare manualmente uno sprite multicolore,
REM per avere più di un colore. Puoi avere sprite con fino a SPRITE COUNT
REM colori indipendenti.

BITMAP ENABLE (2)

spriteImageColor1 := LOAD IMAGE("sprite_color1.png")
spriteImageColor2 := LOAD IMAGE("sprite_color2.png")
spriteImageColor3 := LOAD IMAGE("sprite_color3.png")

spriteColor1 = SPRITE(spriteImageColor1)
spriteColor2 = SPRITE(spriteImageColor2)
spriteColor3 = SPRITE(spriteImageColor3)

SPRITE spriteColor1 ENABLE
SPRITE spriteColor2 ENABLE
SPRITE spriteColor3 ENABLE

SPRITE spriteColor1 AT 100,100
SPRITE spriteColor2 AT 100,100
SPRITE spriteColor3 AT 100,100
