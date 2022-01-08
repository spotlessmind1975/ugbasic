REM @english
REM STATIC IMAGES LOADING (3)
REM
REM This small example will show how to load a real image.
REM Photo by [[https://pixabay.com/it/users/danielhannah-8058574/?utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=image&amp;utm_content=4997724|Daniel Hannah]] da [[https://pixabay.com/it/?utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=image&amp;utm_content=4997724|Pixabay]]
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO (2)
REM
REM Questo piccolo esempio mostra come caricare una immagine reale.
REM Foto di [[https://pixabay.com/it/users/danielhannah-8058574/?utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=image&amp;utm_content=4997724|Daniel Hannah]] da [[https://pixabay.com/it/?utm_source=link-attribution&amp;utm_medium=referral&amp;utm_campaign=image&amp;utm_content=4997724|Pixabay]]
REM
REM @exclude coleco

BITMAP ENABLE (2)

eye = IMAGE LOAD("examples/eye2.png" )

PUT IMAGE eye AT 0, 0

HALT



