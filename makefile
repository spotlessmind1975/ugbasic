#/*****************************************************************************
# * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
# *****************************************************************************
# * Copyright 2020-2024 Marco Spedaletti (asimov@mclink.it)
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# * http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *----------------------------------------------------------------------------
# * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
# * (la "Licenza"); è proibito usare questo file se non in conformità alla
# * Licenza. Una copia della Licenza è disponibile all'indirizzo:
# *
# * http://www.apache.org/licenses/LICENSE-2.0
# *
# * Se non richiesto dalla legislazione vigente o concordato per iscritto,
# * il software distribuito nei termini della Licenza è distribuito
# * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
# * implicite. Consultare la Licenza per il testo specifico che regola le
# * autorizzazioni e le limitazioni previste dalla medesima.
# ****************************************************************************/

.PHONY: paths toolchain compiler clean all built so

ifndef target
$(error missing 'target' (valid values: atari atarixl c128 c128z c64 c64reu coco coco3 coleco cpc d32 d64 gb mo5 msx1 pc128op pc1403 plus4 sc3000 sg1000 to8 vg5000 vic20 zx))
endif

ifdef 10liner
OPTIONS=-1 -R512
else
OPTIONS=-R512 -v
endif

ifdef examples
EXAMPLESDIR=$(examples)
else
EXAMPLESDIR=examples
endif

ifdef example
EXAMPLESFILEMASK=$(example)
else
EXAMPLESFILEMASK=*.bas
endif

ifndef output
ifeq ($(target),atari)
  output=xex
endif
ifeq ($(target),atarixl)
  output=xex
endif
ifeq ($(target),c128)
  output=prg
endif
ifeq ($(target),c128z)
  output=prg
endif
ifeq ($(target),c64)
  output=prg
endif
ifeq ($(target),c64reu)
  output=d64
endif
ifeq ($(target),coco)
  output=dsk
endif
ifeq ($(target),coco3)
  output=dsk
endif
ifeq ($(target),coleco)
  output=rom
endif
ifeq ($(target),cpc)
  output=dsk
endif
ifeq ($(target),d32)
  output=bin
endif
ifeq ($(target),d64)
  output=bin
endif
ifeq ($(target),gb)
  output=gb
endif
ifeq ($(target),mo5)
  output=k7
endif
ifeq ($(target),msx1)
  output=rom
endif
ifeq ($(target),pc128op)
  output=k7
endif
ifeq ($(target),to8)
  output=k7
endif
ifeq ($(target),plus4)
  output=prg
endif
ifeq ($(target),sc3000)
  output=rom
endif
ifeq ($(target),sg1000)
  output=rom
endif
ifeq ($(target),vg5000)
  output=k7
endif
ifeq ($(target),vic20)
  output=prg
endif
ifeq ($(target),zx)
  output=tap
endif
ifeq ($(target),pc1403)
  output=ram
endif
endif

ifndef threads
  threads=4
endif

#-----------------------------------------------------------------------------
#--- MAKEFILE's ENVIRONMENT
#-----------------------------------------------------------------------------

BETA=$(shell cat .git/HEAD | grep beta)

# Check if the compilation is for a BETA version or not.
# In this case, the ".beta" suffix will be added to the executable.
ifeq ($(BETA),)
  BETASUFFIX =
else
  BETASUFFIX = .beta
  CFLAGS += -D__BETA__
endif

ifeq ($(OS),Windows_NT)
  EXESUFFIX = .exe
  UGBCEXESUFFIX = $(BETASUFFIX).exe
else
  EXESUFFIX =
  UGBCEXESUFFIX = $(BETASUFFIX)
endif

ifndef debug
debug = 0
endif

#-----------------------------------------------------------------------------
#--- MAKEFILE's VARIABLES
#-----------------------------------------------------------------------------

#------------------------------------------------ 
# CPU MOS 6502/6510/7501/8501/8502
#------------------------------------------------ 
CL65 = ./modules/cc65/bin/cl65$(EXESUFFIX)
DIR2ATR = ./modules/atarisio/tools/dir2atr$(EXESUFFIX)

#------------------------------------------------ 
# CPU ZILOG Z80
#------------------------------------------------ 
Z80ASM = ./modules/z88dk/src/z80asm/z88dk-z80asm$(EXESUFFIX)
Z80APPMAKE = ./modules/z88dk/src/appmake/z88dk-appmake$(EXESUFFIX)
CPTODSK = ./modules/dsktools/bin/cptodsk$(EXESUFFIX)

#------------------------------------------------ 
# CPU MOTOROLA 6809
#------------------------------------------------ 
ASM6809 = ./modules/asm6809/src/asm6809$(EXESUFFIX)
DECB = ./modules/toolshed/build/unix/decb/decb$(EXESUFFIX)
COCODECB = ./coco_decb.sh
COCO3DECB = ./coco3_decb.sh

#------------------------------------------------ 
# CPU HITACHI SC61860 
#------------------------------------------------ 
AS61860 = ./modules/asxv5pxx/asxmak/linux/exe/as61860$(EXESUFFIX)
ASLINK = ./modules/asxv5pxx/asxmak/linux/exe/aslink$(EXESUFFIX)
COCOBIN2RAM = ./modules/cocobin2ram/cocobin2ram$(EXESUFFIX)

#------------------------------------------------ 
# Examples
#------------------------------------------------ 

# List of examples to compile
EXAMPLES := $(wildcard $(EXAMPLESDIR)/$(EXAMPLESFILEMASK))

# List of assembled files of examples
COMPILED := $(subst $(EXAMPLESDIR)/,generated/$(target)/asm/,$(EXAMPLES:.bas=.asm))

# List of binary files of examples (compiled with makefile)
EXECUTABLES := $(subst /asm/,/exe/,$(COMPILED:.asm=.$(output)))

# List of binary files of examples (compiled with ugbasic stand alone)
EXECUTABLESSO := $(subst /asm/,/exeso/,$(COMPILED:.asm=.$(output)))

#-----------------------------------------------------------------------------
#--- MAKEFILES's RULES
#-----------------------------------------------------------------------------

#------------------------------------------------ 
# all:
#    CATCH ALL RULE
#------------------------------------------------ 
# 
all: paths toolchain compiler $(COMPILED) $(EXECUTABLES) $(EXECUTABLESSO)

#------------------------------------------------ 
# built:
#    COMPILE EXAMPLES with makefile
#------------------------------------------------ 
# 
built: paths toolchain compiler $(COMPILED) $(EXECUTABLES)

#------------------------------------------------ 
# so:
#    COMPILE EXAMPLES stand alone
#------------------------------------------------ 
# 
so: paths toolchain compiler $(EXECUTABLESSO)

#------------------------------------------------ 
# so:
#    COMPILE EXAMPLES stand alone w/o compilers
#------------------------------------------------ 
# 
sonc: paths $(EXECUTABLESSO)

#------------------------------------------------ 
# verify:
#    COMPILE EXAMPLES both and compare
#------------------------------------------------ 
# 
verify: paths toolchain compiler $(COMPILED) $(EXECUTABLES) $(EXECUTABLESSO) compare

#------------------------------------------------ 
# compare:
#    Binary compare of examples
#------------------------------------------------ 
# 
compare: $(COMPILED) $(EXECUTABLES) $(EXECUTABLESSO)
	@diff generated/$(target)/exe generated/$(target)/exeso | grep .$(output) || true

#------------------------------------------------ 
# paths: 
#    PATH GENERATION RULE
#------------------------------------------------ 
# 
# This rule generates all the paths needed to compile the sources. In 
# particular, those are generated where to place the generated assembly and
# binary files, as well as the cross compiler executables.
#
paths:
	@mkdir -p generated
	@mkdir -p generated/$(target)/asm
	@mkdir -p generated/$(target)/cfg
	@mkdir -p generated/$(target)/exe
	@mkdir -p generated/$(target)/exeso
	@mkdir -p $(dir $(CL65))
	@mkdir -p $(dir $(Z80ASM))
	@mkdir -p $(dir $(Z80APPMAKE))
	@mkdir -p $(dir $(ASM6809))

#------------------------------------------------ 
# toolchain: 
#    TOOL CHAIN GENERATOR RULE
#------------------------------------------------ 
# 
# This rule generates the specific toolchain
# for the given target. It is a shortcut to the
# real rule, inside the target.
#
toolchain: toolchain.$(target)

#------------------------------------------------ 
# compiler: 
#    ugBASIC GENERATOR RULE
#------------------------------------------------ 
# 
# This rule generates the ugBASIC compiler
# for the specific target.
#
compiler:
	@cd ugbc && $(MAKE) -j $(threads) target=$(target) debug=$(debug) all

#------------------------------------------------ 
# test: 
#    TEST SUITE EXECUTION RULE
#------------------------------------------------ 
# 
# This rule generates the executable needed
# for automatic rule application.
#
test:
	@cd ugbc && $(MAKE) target=$(target) test
	@echo "--- START TEST ---"
	@ugbc/exe-test/ugbc.$(target)$(UGBCEXESUFFIX)
	@echo
	@echo "--- END TEST ---"

#------------------------------------------------ 
# clean: 
#    CLEAN THE EXECUTABLES
#------------------------------------------------ 
# 
# This rule cleans the executables.
#
clean:
	@cd ugbc && $(MAKE) clean
	@rm -f -r generated

#------------------------------------------------ 
# cc65:
#    CC65 C/ASSEMBLER
#------------------------------------------------ 
# 
# cc65 is a complete cross development package for 65(C)02 systems, 
# including a powerful macro assembler, a C compiler, linker, 
# librarian and several other tools.
#
$(CL65): $(dir $(CL65))../src/ca65/*.c $(dir $(CL65))../src/ca65/*.h \
			$(dir $(CL65))../src/cl65/*.c $(dir $(CL65))../src/cl65/*.h
	cd $(dir $(CL65)..).. && make

cc65: paths $(CL65)

#------------------------------------------------ 
# z88dk:
#    Z88DK C/ASSEMBLER
#------------------------------------------------ 
# 
# z88dk is the only C and assembler development kit that comes ready 
# out-of-the-box to create programs for over 100 z80-family machines.
#
$(Z80ASM): 
	cd $(dir $(Z80ASM)) && make

$(Z80APPMAKE): 
	cd $(dir $(Z80APPMAKE)) && make

z88dk: paths $(Z80ASM) $(Z80APPMAKE)

#------------------------------------------------ 
# as61860:
#    ASxxxxx Assembler & linker
#------------------------------------------------ 
# 
# The  ASxxxx  assemblers are a series of microprocessor assem-
# blers written in the C programming  language.

$(AS61860): 
	cd $(dir $(AS61860))/../build && make

$(ASLINK): 
	cd $(dir $(ASLINK))/../build && make

as61860: paths $(AS61860)
aslink: paths $(ASLINK)

#------------------------------------------------ 
# cocobin2ram:
#    Tandy CoCo Disk BASIC binary convertor
#------------------------------------------------ 
# 

$(COCOBIN2RAM): 
	cd $(dir $(COCOBIN2RAM)) && make

cocobin2ram: paths $(COCOBIN2RAM)

#------------------------------------------------ 
# disktools:
#    MSXDOS DISK IMAGE MANIPULATION
#------------------------------------------------ 
# 
$(CPTODSK): 
	cd $(dir $(CPTODSK))../src && make

cptodsk: paths $(CPTODSK)

#------------------------------------------------ 
# asm6809:
#    ASM6809 ASSEMBLER
#------------------------------------------------ 
# 
# asm6809 is a portable cross assembler targeting 
# the Motorola 6809 and Hitachi 6309.
#
$(dir $(ASM6809))../configure: $(dir $(ASM6809))../autogen.sh
	cd $(dir $(ASM6809)).. && ./autogen.sh

$(dir $(ASM6809))../Makefile: $(dir $(ASM6809))../configure
	cd $(dir $(ASM6809)).. && ./configure

$(dir $(ASM6809)): $(dir $(ASM6809))../Makefile
	cd $(dir $(ASM6809)).. && make

asm6809: paths $(dir $(ASM6809))

#------------------------------------------------ 
# decb:
#    TOOL FOR DECB DISK IMAGES
#------------------------------------------------ 
# 
# decb from Toolshed 2.2
#
$(DECB): $(dir $(DECB))./*.o
	cd $(dir $(DECB))../../.. && make -C build/unix install CC=gcc

decb: paths $(DECB)

#------------------------------------------------ 
# dir2atr:
#    TOOL FOR CREATING ATARI DISK IMAGES
#------------------------------------------------ 
# 
# dir2atr from AtariSIO V0.30
#
$(DIR2ATR): $(dir $(DIR2ATR))./*.o
	cd $(dir $(DIR2ATR)) && make dir2atr

dir2atr: paths $(DIR2ATR)

#------------------------------------------------ 
# atari:
#    ATARI 400/800 (6502)
#------------------------------------------------ 
# 
toolchain.atari: cc65 dir2atr

generated/atari/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.atari$(UGBCEXESUFFIX) $(OPTIONS) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atari/asm/,,$(@:.asm=.bas)) ../$@

generated/atari/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@$(CL65) -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/atari/exe/%.atr: $(subst /generated/atari/exe/,/$(EXAMPLESDIR)/,$(@:.atr=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.atari$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O atr $(subst generated/atari/exe/,,$(@:.atr=.bas))

generated/atari/exeso/%.xex: $(subst /generated/atari/exeso/,/$(EXAMPLESDIR)/,$(@:.xex=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.atari$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O xex $(subst generated/atari/exeso/,,$(@:.xex=.bas))

generated/atari/exeso/%.atr: $(subst /generated/atari/exeso/,/$(EXAMPLESDIR)/,$(@:.atr=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.atari$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O atr $(subst generated/atari/exeso/,,$(@:.atr=.bas))

#------------------------------------------------ 
# atarixl:
#    ATARI 1200XL (6502)
#    ATARI 600XL/800XL (6502)
#    ATARI XE VGS (6502)
#------------------------------------------------ 
# 
toolchain.atarixl: cc65 dir2atr

generated/atarixl/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.atarixl$(UGBCEXESUFFIX) $(OPTIONS) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atarixl/asm/,,$(@:.asm=.bas)) ../$@

generated/atarixl/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@$(CL65) -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -D __atarixl__ -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/atarixl/exeso/%.xex: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.xex=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.atarixl$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O xex $(subst generated/atarixl/exeso/,,$(@:.xex=.bas))

#------------------------------------------------ 
# c128:
#    COMMODORE 128 (8510)
#------------------------------------------------ 
# 
toolchain.c128: cc65

generated/c128/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c128$(UGBCEXESUFFIX) $(OPTIONS) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c128/asm/,,$(@:.asm=.bas)) ../$@

generated/c128/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c128 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c128/exe/%.d64:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c128$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/c128/exe/,,$(@:.d64=.bas))

generated/c128/exeso/%.prg: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.prg=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c128$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O prg $(subst generated/c128/exeso/,,$(@:.prg=.bas))

generated/c128/exeso/%.d64: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.d64=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c128$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/c128/exeso/,,$(@:.d64=.bas))

#------------------------------------------------ 
# c128z:
#    COMMODORE 128 (Z80)
#------------------------------------------------ 
# 
toolchain.c128z: z88dk

generated/c128z/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c128z$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/c128z/asm/,,$(@:.asm=.bas)) ../$@ 

generated/c128z/exe/%.prg:
	@$(Z80ASM) -D__c128z__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.prg=.asm))
	@mv $(subst /exe/,/asm/,$(@:.prg=.sym)) $(subst /exe/,/asm/,$(@:.prg=.osym))
	@php sym2c128z.php $(subst /exe/,/asm/,$(@:.prg=.osym)) >$(subst /exe/,/asm/,$(@:.prg=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.prg=.o))
	@mv $(subst /exe/,/asm/,$(@:.prg=.bin)) $@
	@rm -f $(@:.prg=.bin) $(@:.prg=_*.bin) $(@:.prg=.) $(@:.prg=_*.)

generated/c128z/exeso/%.prg: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.prg=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c128z$(UGBCEXESUFFIX) $(OPTIONS) -d -D ../$(@:.prg=.info) -o ../$@ -O prg $(subst generated/c128z/exeso/,,$(@:.prg=.bas))

#------------------------------------------------ 
# c64:
#    COMMODORE 64 (6502)
#------------------------------------------------ 
# 
toolchain.c64: cc65

generated/c64/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.asm=.listing) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c64/asm/,,$(@:.asm=.bas)) ../$@

generated/c64/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c64 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c64/exe/%.d64:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/c64/exe/,,$(@:.d64=.bas))

generated/c64/exeso/%.prg: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.prg=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O prg $(subst generated/c64/exeso/,,$(@:.prg=.bas))

generated/c64/exeso/%.d64: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.d64=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/c64/exeso/,,$(@:.d64=.bas))

#------------------------------------------------ 
# c64reu:
#    COMMODORE 64 (6502) + REU
#------------------------------------------------ 
# 
toolchain.c64reu: cc65

generated/c64reu/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64reu$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.asm=.listing) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c64reu/asm/,,$(@:.asm=.bas)) ../$@

generated/c64reu/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c64 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c64reu/exe/%.d64:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64reu$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.d64=.lst) -o ../$@ -O d64 $(subst generated/c64reu/exe/,,$(@:.d64=.bas))

generated/c64reu/exe/%.reu:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64reu$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.reu=.lst) -o ../$@ -O reu $(subst generated/c64reu/exe/,,$(@:.reu=.bas))

generated/c64reu/exeso/%.prg: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.prg=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64reu$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O prg $(subst generated/c64reu/exeso/,,$(@:.prg=.bas))

generated/c64reu/exeso/%.d64: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.d64=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64reu$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/c64reu/exeso/,,$(@:.d64=.bas))

generated/c64reu/exeso/%.reu: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.reu=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.c64reu$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O reu $(subst generated/c64reu/exeso/,,$(@:.reu=.bas))

#------------------------------------------------ 
# coleco:
#    COLECOVISION (Z80)
#------------------------------------------------ 
# 
toolchain.coleco: z88dk

generated/coleco/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coleco$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/coleco/asm/,,$(@:.asm=.bas)) ../$@ 

generated/coleco/exe/%.rom:
	@$(Z80ASM) -D__coleco__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2coleco.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.rom=.o))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@:.rom=.bin)
	@rm $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin)
	@$(Z80APPMAKE) +msxrom -b $(@:.rom=.bin) 2>/dev/null
	@rm -f $(@:.rom=.bin) $(@:.rom=_*.bin)

generated/coleco/exeso/%.rom: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.rom=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coleco$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O rom $(subst generated/coleco/exeso/,,$(@:.rom=.bas))

#------------------------------------------------ 
# cpc:
#    AMSTRAD CPC 664 (Z80)
#------------------------------------------------ 
# 
toolchain.cpc: z88dk

generated/cpc/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.cpc$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/cpc/asm/,,$(@:.asm=.bas)) ../$@ 

generated/cpc/exe/%.dsk:
	@$(Z80ASM) -D__cpc__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.dsk=.asm))
	@mv $(subst /exe/,/asm/,$(@:.dsk=.sym)) $(subst /exe/,/asm/,$(@:.dsk=.osym))
	@php sym2cpc.php $(subst /exe/,/asm/,$(@:.dsk=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.dsk=.o))
	@mv $(subst /exe/,/asm/,$(@:.dsk=.bin)) $(@:.dsk=.)
	@rm -f $(@:.dsk=.bin) $(@:.dsk=_*.bin) $(@:.dsk=.) $(@:.dsk=_*.) $(dir $@)main.
#	@$(Z80APPMAKE) +cpc --org 256 --exec 256 --disk -b $(@:.dsk=.) -o $(dir $@)main. 2>/dev/null
#	@rm -f $(@:.dsk=.bin) $(@:.dsk=_*.bin) $(@:.dsk=.) $(@:.dsk=_*.) $(dir $@)main.

generated/cpc/exeso/%.dsk: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.dsk=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.cpc$(UGBCEXESUFFIX) $(OPTIONS) -D ../$(@:.dsk=.info) -o ../$@ -O dsk $(subst generated/cpc/exeso/,,$(@:.dsk=.bas))

#------------------------------------------------ 
# coco:
#    TRS-80 Color Computer (6809)
#------------------------------------------------ 
# 
toolchain.coco: asm6809 decb

generated/coco/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coco$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/coco/asm/,,$(@:.asm=.bas)) ../$@

generated/coco/exe/%.dsk: $(subst /exe/,/asm/,$(@:.dsk=.asm))
	@$(ASM6809) -l $(@:.dsk=.lis) -s $(@:.dsk=.lbl) -C -e 10752 -o $(@:.dsk=.bin) $(subst /exe/,/asm/,$(@:.dsk=.asm))
	@$(COCODECB) $(DECB) $(@:.dsk=.bin) $(@:.dsk=) $(@) 

generated/coco/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -C -e 10752 -o $(@) $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/coco/exeso/%.dsk: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.dsk=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coco$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.dsk=.lis) -o ../$@ -O dsk $(subst generated/coco/exeso/,,$(@:.dsk=.bas))

generated/coco/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coco$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O bin $(subst generated/coco/exeso/,,$(@:.bin=.bas))

#------------------------------------------------ 
# coco3:
#    TRS-80 Color Computer (6809)
#------------------------------------------------ 
# 
toolchain.coco3: asm6809 decb

generated/coco3/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coco3$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/coco3/asm/,,$(@:.asm=.bas)) ../$@

generated/coco3/exe/%.dsk: $(subst /exe/,/asm/,$(@:.dsk=.asm))
	@$(ASM6809) -l $(@:.dsk=.lis) -s $(@:.dsk=.lbl) -C -e 10752 -o $(@:.dsk=.bin) $(subst /exe/,/asm/,$(@:.dsk=.asm))
	@$(COCO3DECB) $(DECB) $(@:.dsk=.bin) $(@:.dsk=) $(@) 

generated/coco3/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -C -e 10752 -o $(@) $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/coco3/exeso/%.dsk: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.dsk=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coco3$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.dsk=.lis) -o ../$@ -O dsk $(subst generated/coco3/exeso/,,$(@:.dsk=.bas))

generated/coco3/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.coco3$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.dsk=.lis) -o ../$@ -O bin $(subst generated/coco3/exeso/,,$(@:.bin=.bas))

#------------------------------------------------ 
# d32:
#    DRAGON 32 (6809)
#------------------------------------------------ 
# 
toolchain.d32: asm6809

generated/d32/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.d32$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/d32/asm/,,$(@:.asm=.bas)) ../$@

generated/d32/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/d32/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.d32$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O bin $(subst generated/d32/exeso/,,$(@:.bin=.bas))

#------------------------------------------------ 
# d64:
#    DRAGON 64 (6809)
#------------------------------------------------ 
# 
toolchain.d64: asm6809

generated/d64/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.d64$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/d64/asm/,,$(@:.asm=.bas)) ../$@

generated/d64/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/d64/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.d64$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -l ../$(@:.bin=.lis) -O bin $(subst generated/d64/exeso/,,$(@:.bin=.bas))

#------------------------------------------------ 
# gb:
#    Gameboy (Z80)
#------------------------------------------------ 
# 
toolchain.gb: z88dk

generated/gb/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.gb$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/gb/asm/,,$(@:.asm=.bas)) ../$@ 

generated/gb/exe/%.gb: compiler
	$(Z80ASM) -l -m=gbz80 -s -g -b $(subst /exe/,/asm/,$(@:.gb=.asm))
	@mv $(subst /exe/,/asm/,$(@:.gb=.sym)) $(subst /exe/,/asm/,$(@:.gb=.osym))
	@php sym2gb.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.gb=.o))
	@mv $(subst /exe/,/asm/,$(@:.gb=_code.bin)) $(@:.gb=_code.bin)
	@mv $(subst /exe/,/asm/,$(@:.gb=_data.bin)) $(@:.gb=_data.bin)
	@cat $(@:.gb=_code.bin) $(@:.gb=_data.bin) >$(@:.gb=.bin)
	@$(Z80APPMAKE) +gb -b $(@:.gb=.bin) 
	@rm -f $(@:.gb=.bin) $(@:.gb=_*.bin)

generated/gb/exeso/%.gb: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.gb=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.gb$(UGBCEXESUFFIX) $(OPTIONS) -D ../$(@:.gb=.info) -o ../$@ -O gb $(subst generated/gb/exeso/,,$(@:.gb=.bas))

#------------------------------------------------ 
# mo5:
#    THOMSON MO5 (6809)
#------------------------------------------------ 
# 
toolchain.mo5: asm6809

generated/mo5/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.mo5$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/mo5/asm/,,$(@:.asm=.bas)) ../$@

generated/mo5/exe/%.k7: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.mo5$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/mo5/exe/,,$(@:.k7=.bas)) -o ../$@

generated/mo5/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/mo5/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.mo5$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.bin=.lis) -o ../$@ -O bin $(subst generated/mo5/exeso/,,$(@:.bin=.bas))

generated/mo5/exeso/%.k7: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.k7=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.mo5$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.k7=.lis) -o ../$@ -O k7 $(subst generated/mo5/exeso/,,$(@:.k7=.bas))

#------------------------------------------------ 
# msx1:
#    MSX 1 (Z80)
#------------------------------------------------ 
# 
toolchain.msx1: z88dk cptodsk

generated/msx1/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.msx1$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/msx1/asm/,,$(@:.asm=.bas)) ../$@ 

generated/msx1/exe/%.rom:
	@$(Z80ASM) -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2msx.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.rom=.o))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@:.rom=.bin)
	@rm $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin)
	@$(Z80APPMAKE) +msxrom -b $(@:.rom=.bin)
	@rm -f $(@:.rom=.bin) $(@:.rom=_*.bin)

generated/msx1/exe/%.dsk:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.msx1$(UGBCEXESUFFIX) $(OPTIONS) -D ../$(@:.dsk=.info) -o ../$@ -O dsk $(subst generated/msx1/exe/,,$(@:.dsk=.bas))

generated/msx1/exeso/%.rom: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.rom=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.msx1$(UGBCEXESUFFIX) $(OPTIONS) -D ../$(@:.rom=.info) -o ../$@ -O rom $(subst generated/msx1/exeso/,,$(@:.rom=.bas))

generated/msx1/exeso/%.dsk: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.dsk=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.msx1$(UGBCEXESUFFIX) $(OPTIONS) -D ../$(@:.dsk=.info) -o ../$@ -O dsk $(subst generated/msx1/exeso/,,$(@:.dsk=.bas))

#------------------------------------------------ 
# pc128:
#    OLIVETTI PRODEST PC128 (6809)
#------------------------------------------------ 
# 
toolchain.pc128op: asm6809

generated/pc128op/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.pc128op$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.k7=.lis) $(subst generated/pc128op/asm/,,$(@:.asm=.bas)) ../$@

generated/pc128op/exe/%.k7: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.pc128op$(UGBCEXESUFFIX) $(OPTIONS) -O k7 -L ../$(@:.k7=.lis) $(subst generated/pc128op/exe/,,$(@:.k7=.bas)) -o ../$@

generated/pc128op/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/pc128op/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.pc128op$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O bin $(subst generated/pc128op/exeso/,,$(@:.bin=.bas))

generated/pc128op/exeso/%.k7: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.k7=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.pc128op$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O k7 -L ../$(@:.k7=.lis) $(subst generated/pc128op/exeso/,,$(@:.k7=.bas))

#------------------------------------------------ 
# pc1403:
#    Sharp PC-1403/PC-1403h (sc61860)
#------------------------------------------------ 
#
toolchain.pc1403: as61860 aslink cocobin2ram

generated/pc1403/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.pc1403$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/pc1403/asm/,,$(@:.asm=.bas)) ../$@ 

generated/pc1403/exe/%.ram:
	@$(AS61860) -gloaxsff $(subst /exe/,/asm/,$(@:.ram=.asm))
	@mv $(subst /exe/,/asm/,$(@:.ram=.rel)) $(@:.ram=.rel)
	@$(ASLINK) -t $(@:.ram=.rel)
	@$(COCOBIN2RAM) $(@:.ram=.bin) $(@)

generated/pc1403/exeso/%.ram: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.ram=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.pc1403$(UGBCEXESUFFIX) $(OPTIONS) -D ../$(@:.ram=.info) -o ../$@ -O ram $(subst generated/pc1403/exeso/,,$(@:.ram=.bas))

#------------------------------------------------ 
# plus4:
#    COMMODORE PLUS/4 (7501/8501)
#------------------------------------------------ 
# 
toolchain.plus4: cc65

generated/plus4/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.plus4$(UGBCEXESUFFIX) $(OPTIONS) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/plus4/asm/,,$(@:.asm=.bas)) ../$@

generated/plus4/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -u __EXEHDR__ -t plus4 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/plus4/exeso/%.prg: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.prg=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.plus4$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O prg $(subst generated/plus4/exeso/,,$(@:.prg=.bas))

#------------------------------------------------ 
# sc3000:
#    SEGA SC-3000 (Z80)
#------------------------------------------------ 
# 
toolchain.sc3000: z88dk

generated/sc3000/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.sc3000$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/sc3000/asm/,,$(@:.asm=.bas)) ../$@ 

generated/sc3000/exe/%.rom:
	@$(Z80ASM) -D__sc3000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sc3000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)
	@rm $(@:.rom=_data_user.bin) $(@:.rom=_code_user.bin)

generated/sc3000/exeso/%.rom: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.rom=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.sc3000$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O rom $(subst generated/sc3000/exeso/,,$(@:.rom=.bas))

#------------------------------------------------ 
# sg1000:
#    SEGA SG-1000 (Z80)
#------------------------------------------------ 
# 
toolchain.sg1000: z88dk

generated/sg1000/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.sg1000$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/sg1000/asm/,,$(@:.asm=.bas)) ../$@ 

generated/sg1000/exe/%.rom:
	@$(Z80ASM) -D__sg1000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sg1000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

generated/sg1000/exeso/%.rom: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.rom=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.sg1000$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O rom $(subst generated/sg1000/exeso/,,$(@:.rom=.bas))

#------------------------------------------------ 
# to8:
#    THOMSON TO8
#------------------------------------------------ 
# 
toolchain.to8: asm6809

generated/to8/asm/%.asm: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.to8$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.k7=.lis) $(subst generated/to8/asm/,,$(@:.asm=.bas)) ../$@

generated/to8/exe/%.k7: compiler
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.to8$(UGBCEXESUFFIX) $(OPTIONS) -L ../$(@:.k7=.lis) $(subst generated/to8/exe/,,$(@:.k7=.bas)) -o ../$@

generated/to8/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/to8/exeso/%.bin: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.bin=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.to8$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O bin $(subst generated/to8/exeso/,,$(@:.bin=.bas))

generated/to8/exeso/%.k7: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.k7=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.to8$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O k7 $(subst generated/to8/exeso/,,$(@:.k7=.bas))


#------------------------------------------------ 
# vg5000:
#    PHILIPS VG5000 (Z80)
#------------------------------------------------ 
# 
toolchain.vg5000: z88dk

generated/vg5000/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vg5000$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/vg5000/asm/,,$(@:.asm=.bas)) ../$@ 

generated/vg5000/exe/%.bin: compiler
	@$(Z80ASM) -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))

generated/vg5000/exe/%.k7:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vg5000$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -L generated/vg5000/asm/output.listing $(subst generated/vg5000/exe/,,$(@:.k7=.bas))

generated/vg5000/exeso/%.k7: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.rom=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vg5000$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O rom $(subst generated/vg5000/exeso/,,$(@:.k7=.bas))

#------------------------------------------------ 
# vic20:
#    COMMODORE VIC-20 (6502)
#------------------------------------------------ 
# 
toolchain.vic20: cc65

generated/vic20/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vic20$(UGBCEXESUFFIX) $(OPTIONS) -c ../$(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/vic20/asm/,,$(@:.asm=.bas)) ../$@

generated/vic20/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t vic20 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/vic20/exe/%.d64: $(subst /generated/exe/,/$(EXAMPLESDIR)/,$(@:.d64=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vic20$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/vic20/exe/,,$(@:.d64=.bas))

generated/vic20/exeso/%.prg: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.prg=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vic20$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O prg $(subst generated/vic20/exeso/,,$(@:.prg=.bas))

generated/vic20/exeso/%.d64: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.d64=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.vic20$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -O d64 $(subst generated/vic20/exeso/,,$(@:.d64=.bas))

#------------------------------------------------ 
# zx:
#    ZX SPECTRUM 48K (Z80)
#------------------------------------------------ 
# 
toolchain.zx: z88dk

generated/zx/asm/%.asm:
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.zx$(UGBCEXESUFFIX) $(OPTIONS) $(subst generated/zx/asm/,,$(@:.asm=.bas)) ../$@ 

generated/zx/exe/%.tap:
	@$(Z80ASM) -l -b $(subst /exe/,/asm/,$(@:.tap=.asm))
	@mv $(subst /exe/,/asm/,$(@:.tap=.lis)) $(@:.tap=.lis)
	@rm -f $(subst /exe/,/asm/,$(@:.tap=.o))
	@mv $(subst /exe/,/asm/,$(@:.tap=.bin)) $(@:.tap=.bin)
	@$(Z80APPMAKE) +zx --org 32768 -b $(@:.tap=.bin)
	@rm -f $(@:.tap=.bin) $(@:.tap=_*.bin)

generated/zx/exeso/%.tap: $(subst /generated/exeso/,/$(EXAMPLESDIR)/,$(@:.tap=.bas))
	@cd $(EXAMPLESDIR) && ../ugbc/exe/ugbc.zx$(UGBCEXESUFFIX) $(OPTIONS) -o ../$@ -L ../$(@:.tap=.lst) -O tap $(subst generated/zx/exeso/,,$(@:.tap=.bas))
