[![ugBASIC](logo-ugbasic.png)](https://ugbasic.iwashere.eu/)

An **isomorphic BASIC** language compiler for retrocomputers by Marco Spedaletti (asimov@mclink.it)

## ABOUT THIS SOFTWARE

A cross compiler of BASIC dialect specialized in programs that are [very efficient "by design"](https://ugbasic.iwashere.eu/manual/isomorphism) on various [8-bit platforms](https://ugbasic.iwashere.eu/targets) (based on **[MOS 6502/6510](https://ugbasic.iwashere.eu/targets)**, **[Motorola 6809](https://ugbasic.iwashere.eu/targets)** and **[Zilog Z80](https://ugbasic.iwashere.eu/targets)**), without the need for "fine tuning" them and without compromises of other dev-kits.

<img align="right" width="200" height="284" src="https://ugbasic.iwashere.eu/assets/img/book01.jpg"> [**An user manual**](https://spotlessmind1975.itch.io/ugbasic-user-manual) is available to guide you into the language. 

The book starts from "basic" concepts, like variables, operators, control statements, subroutines, and explain how to do graphics and sound, images, sprites, and even write multitasking programs. You will discover how to create programs while taking advantage of the hardware limitations of retro computers.

**This book is updated frequently**, and it is interesting if you want to discover how to apply modern programming techniques to retro computers, and it is essential if you want to use **ugBASIC** to its fullest.

There is also an [online version](https://ugbasic.iwashere.eu/manual/isomorphism), and the [reference manual](https://ugbasic.iwashere.eu/docs/reference/), useful for those wishing to modify and/or to extend the language.

## WHY SHOULD I USE "ugBASIC"?

 * **Modern programming** - all the most modern BASIC constructs are available, like dynamic strings, procedures, constants, functions, inclusion of libraries, ....
 * **[Multitasking](https://retroprogramming.iwashere.eu/ugbasic:user:multitasking)** - procedures can be called on a parallel way.
 * **Fast execution** - BASIC source code, graphical and audio resources are compiled directly in assembly, and optimized for the specific CPU, and all calculations are done on integer numbers, moreover it does not use any stack.
 * **No ROM dependency** - the executable take care of all the hardware, with no dependency from installed ROM that will be swapped out, if possible.
 * **RAM optimizations** - all RAM is available for code and data, and it is available [a fast compression / decompression routine](https://retroprogramming.iwashere.eu/msc1) "out of the box".
 * **Cross development** - use your modern Linux or Windows PC to compile for about 20 different retro computers, from Commodore 64 to Amstrad CPC 664.
 * **[Modern IDE available](https://spotlessmind1975.itch.io/ugbasic-ide)** - you can also use a modern IDE to develop.

For more information please [look here](https://ugbasic.iwashere.eu/).

## SUPPORTED HARDWARE

The complete list of targets can be [found here](https://ugbasic.iwashere.eu/targets).

## WHAT DOES "ug" MEAN?

It is an acronym.

 * The letter **u** stands for "micro" because it is a "minimal" language, which is translated as linearly as possible into assembly without abstractions. Note that the nature of isomorphism is like that it may not be "minimal" in terms of syntax. There may be redundancies, but the concept remains.
 * The letter **g** stands for "game", because the language was designed to write video games, even advanced ones. It has a number of primitives that hook directly to hardware characteristics. For example, there are instructions to synchronize the execution to the vertical blank, to manage animations, background music and so on.

## LICENSE

Copyright 2021-2024 Marco Spedaletti

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

This program contains algorithms and software written
by [third parts](THIRD-PARTS.md). Please refer to the conditions present
in [that page](THIRD-PARTS.md) also, if you wish to reproduce or reuse this software.
 
