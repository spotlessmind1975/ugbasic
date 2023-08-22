#!/bin/bash

build () {

    echo -n $1
    echo -n ": "

    make target=$1 compiler >/dev/null 2>/dev/null

    status=$?
    [ $status -eq 0 ] && echo "built" || echo "ERROR"

}

make clean

build atari 
build atarixl
build c128
build c64
build coleco
build cpc
build d32
build d64
build mo5
build msx1
build pc128op
build plus4
build sc3000
build sg1000
build vg5000
build vic20
build zx
build coco
build c128z
