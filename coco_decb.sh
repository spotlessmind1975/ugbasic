#!/bin/bash

DECB=$1
FILEIN=$2
FILEOUT=$3
DISKOUT=$4

FILESIZE=`wc -c $FILEIN | awk '{print $1;}'`

if (( FILESIZE < 22016 )); then

STANDARDSIZE=FILESIZE-5
ONDEMANDSIZE=0
BLOCK_SIZE=4096
BLOCKS=0
REMAINSIZE=0

else

STANDARDSIZE=22016
ONDEMANDSIZE=$((FILESIZE-STANDARDSIZE-10))
BLOCK_SIZE=4096
BLOCKS=$((((ONDEMANDSIZE/BLOCK_SIZE)+1)))
REMAINSIZE=$((ONDEMANDSIZE - ((BLOCKS-1) * BLOCK_SIZE)))-5

fi

dd if=$FILEIN skip=0 bs=$(($STANDARDSIZE+5)) count=1  status=noxfer 2>/dev/null >>"generated/coco/exe/program.exe"

hisize=$(((STANDARDSIZE) >> 8))
losize=$(((STANDARDSIZE) & 0xff))
printf "\x$(printf %x $hisize)\x$(printf %x $losize)" | dd of=generated/coco/exe/program.exe bs=1 seek=1 count=2 conv=notrunc 2>/dev/null

dd if=ugbc/data/coco/footer.bin skip=0 bs=5 count=1  status=noxfer 2>/dev/null >>"generated/coco/exe/program.exe"
dd if=$FILEIN skip=1 bs=$(($STANDARDSIZE+5)) status=noxfer 2>/dev/null >>"generated/coco/exe/program.tmp"

for (( block = 0; block < $BLOCKS; block += 1 ))
do
    extension=`printf %03d $block`
    dd if=ugbc/data/coco/header.bin skip=0 bs=5 count=1  status=noxfer 2>/dev/null >"generated/coco/exe/program.$extension"
    dd if=generated/coco/exe/program.tmp skip=$block bs=$BLOCK_SIZE count=1  status=noxfer 2>/dev/null >>"generated/coco/exe/program.$extension"
    if (( block < (BLOCKS-1) )); then
        dd if=ugbc/data/coco/footer.bin skip=0 bs=5 count=1  status=noxfer 2>/dev/null >>"generated/coco/exe/program.$extension"
    else
        hisize=$(((REMAINSIZE+5) >> 8))
        losize=$(((REMAINSIZE+5) & 0xff))
        printf "\x$(printf %x $hisize)\x$(printf %x $losize)" | dd of=generated/coco/exe/program.$extension bs=1 seek=1 count=2 conv=notrunc 2>/dev/null
    fi
done

$DECB dskini $DISKOUT

echo "1 REM ugBASIC loader"                           >generated/coco/exe/loader.bas
echo "2 REM --[ PROLOGUE ]--"                        >>generated/coco/exe/loader.bas
echo "3 DATA 26,80,52,16,52,6,142,14,0,159,31,31"  >>generated/coco/exe/loader.bas
echo "4 DATA 65,16,206,15,0,16,223,33,198,255,166"   >>generated/coco/exe/loader.bas
echo "5 DATA 133,167,229,90,38,249,53,6,53,16,28"    >>generated/coco/exe/loader.bas
echo "6 DATA 159,57,26,80,142,42,0,16,142,42,0"      >>generated/coco/exe/loader.bas
echo "7 DATA 183,255,223,206,16,0,166,128,167,160"   >>generated/coco/exe/loader.bas
echo "8 DATA 51,95,17,131,0,0,38,244,183,255,222"    >>generated/coco/exe/loader.bas
echo "9 DATA 28,159,57"                              >>generated/coco/exe/loader.bas
echo "11FORA=&HE00 TO &HE44:READX:POKEA,X:NEXTA"      >>generated/coco/exe/loader.bas
echo "12REM --[ MAIN ]--"                            >>generated/coco/exe/loader.bas
echo "13CLEAR 999: PRINT \"LOADING, PLEASE WAIT\";"  >>generated/coco/exe/loader.bas

for (( block = 0; block < $BLOCKS; block += 1 ))
do
    extension=`printf %03d $block`
    line=$((14+$block*2))
    echo "$line LOADM\"PROGRAM.$extension\":PRINT\".\";" >>generated/coco/exe/loader.bas
    line=$((15+$block*2))
    address=$((128+$block*16))
    echo "$line POKE 3627, $address: EXEC 3620" >>generated/coco/exe/loader.bas
done

echo "90 EXEC 3584: PRINT \"...\";: LOADM\"PROGRAM.EXE\": PRINT \"...\": EXEC" >>generated/coco/exe/loader.bas

$DECB copy -0 -t generated/coco/exe/loader.bas $DISKOUT,LOADER.BAS
$DECB copy -2 "generated/coco/exe/program.exe" $DISKOUT,PROGRAM.EXE
for (( block = 0; block < $BLOCKS; block += 1 ))
do
    extension=`printf %03d $block`
    $DECB copy -2 "generated/coco/exe/program.$extension" $DISKOUT,PROGRAM.$extension
done
