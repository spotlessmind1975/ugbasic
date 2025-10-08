#!/bin/bash

build () {

    echo -n $1
    echo -n ": "

    make target=$1 compiler >/dev/null 2>/dev/null

    status=$?
    [ $status -eq 0 ] && echo "built" || echo "ERROR"

}

make target=atari clean

build atari
build atarixl
build c128
build c128z
build c64
build c64reu
build coco
build cocob
build coco3
build coco3b
build coleco
build cpc
build d32
build d32b
build d64
build d64b
build gb
build mo5
build msx1
build pc128op
build pc1403
build plus4
build sc3000
build sg1000
build to8
build vg5000
build vic20
build zx

mkdir ugbc/compressed
rm ugbc/compressed/ugbc.zip
cd ugbc/exe
zip ../compressed/ugbc.zip ugbc.*
cd ../..
