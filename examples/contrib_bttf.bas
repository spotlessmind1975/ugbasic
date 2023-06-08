REM @english
REM OTHER CONTRIBUTIONS BACK TO THE SLIDESHOW
REM
REM This is a small program that demonstrates the possibility of using more than 
REM the 32KB available on the TRS-80 Color Computer ("coco" target). It's an 
REM "in memory" slideshow, with four high-resolution frames.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI RITORNO ALLO SLIDESHOW
REM
REM Questo è un piccolo programma che dimostra la possibilità di usare più dei 
REM 32KB disponibili sul computer TRS-80 Color Computer ("coco" target). E' 
REM uno slideshow "in memoria", con ben quattro fotogrammi ad alta risoluzione.
REM 

BITMAP ENABLE

COLOR #0, #5

p1 := LOAD IMAGE("examples/bttf_frame_01.png")
p2 := LOAD IMAGE("examples/bttf_frame_02.png")
p3 := LOAD IMAGE("examples/bttf_frame_03.png")
p4 := LOAD IMAGE("examples/bttf_frame_04.png")

PUT IMAGE p1 AT 0,0:WAIT KEY
PUT IMAGE p2 AT 0,0:WAIT KEY
PUT IMAGE p3 AT 0,0:WAIT KEY
PUT IMAGE p4 AT 0,0:WAIT KEY



