#/*****************************************************************************
# * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
# *****************************************************************************
# * Copyright 2020-2022 Marco Spedaletti (asimov@mclink.it)
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
$(error missing 'target' (valid values: atari atarixl c128 c64 coleco cpc d32 d64 mo5 msx1 pc128 plus4 sc3000 sg1000 vg5000 vic20 zx))
endif

#-----------------------------------------------------------------------------
#--- MAKEFILE's ENVIRONMENT
#-----------------------------------------------------------------------------

ifeq ($(OS),Windows_NT)
  EXESUFFIX = .exe
else
  EXESUFFIX = 
endif

#-----------------------------------------------------------------------------
#--- MAKEFILE's VARIABLES
#-----------------------------------------------------------------------------

#------------------------------------------------ 
# CPU MOS 6502/6510/7501/8501/8502
#------------------------------------------------ 
CL65 = ./modules/cc65/bin/cl65$(EXESUFFIX)

#------------------------------------------------ 
# CPU ZILOG Z80
#------------------------------------------------ 
Z80ASM = ./modules/z88dk/src/z80asm/z88dk-z80asm$(EXESUFFIX)
APPMAKE = ./modules/z88dk/src/appmake/z88dk-appmake$(EXESUFFIX)

#------------------------------------------------ 
# CPU MOTOROLA 6809
#------------------------------------------------ 
ASM6809 = ./modules/asm6809/src/asm6809$(EXESUFFIX)

#------------------------------------------------ 
# Examples
#------------------------------------------------ 

# List of examples to compile
EXAMPLES := $(wildcard examples/*.bas)

# List of assembled files of examples
COMPILED := $(subst examples/,generated/$(target)/asm/,$(EXAMPLES:.bas=.asm))

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
	@mkdir -p $(dir $(APPMAKE))
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
	@cd ugbc && $(MAKE) target=$(target) all

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
	@ugbc/exe-test/ugbc.$(target)
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
$(Z80ASM): $(dir $(Z80ASM))src/c/*.c $(dir $(Z80ASM))src/c/*.h $(dir $(Z80ASM))src/cpp/*.cpp $(dir $(Z80ASM))src/cpp/*.h
	cd $(dir $(Z80ASM)) && make

$(Z80APPMAKE): $(dir $(Z80APPMAKE))src/c/*.c $(dir $(Z80APPMAKE))src/c/*.h $(dir $(Z80APPMAKE))src/cpp/*.cpp $(dir $(Z80APPMAKE))src/cpp/*.h
	cd $(dir $(Z80APPMAKE)) && make

z88dk: paths $(Z80ASM) $(Z80APPMAKE)

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
# atari:
#    ATARI 400/800 (6502)
#------------------------------------------------ 
# 
toolchain.atari: cc65

generated/atari/asm/%.asm:
	@ugbc/exe/ugbc.atari -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atari/asm/,examples/,$(@:.asm=.bas)) $@

generated/atari/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@$(CL65) -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/atari/exeso/%.xex: $(subst /generated/exeso/,/examples/,$(@:.xex=.bas))
	@ugbc/exe/ugbc.atari -o $@ -O xex $(subst generated/atari/exeso/,examples/,$(@:.xex=.bas))

#------------------------------------------------ 
# atarixl:
#    ATARI 1200XL (6502)
#    ATARI 600XL/800XL (6502)
#    ATARI XE VGS (6502)
#------------------------------------------------ 
# 
toolchain.atarixl: cc65

generated/atarixl/asm/%.asm:
	@ugbc/exe/ugbc.atarixl -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atarixl/asm/,examples/,$(@:.asm=.bas)) $@

generated/atarixl/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@$(CL65) -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -D __atarixl__ -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/atarixl/exeso/%.xex: $(subst /generated/exeso/,/examples/,$(@:.xex=.bas))
	@ugbc/exe/ugbc.atarixl -o $@ -O xex $(subst generated/atarixl/exeso/,examples/,$(@:.xex=.bas))

#------------------------------------------------ 
# c128:
#    COMMODORE 128 (8502)
#------------------------------------------------ 
# 
toolchain.c128: cc65

generated/c128/asm/%.asm:
	@ugbc/exe/ugbc.c128 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c128/asm/,examples/,$(@:.asm=.bas)) $@

generated/c128/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c128 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c128/exeso/%.prg: $(subst /generated/exeso/,/examples/,$(@:.prg=.bas))
	@ugbc/exe/ugbc.c128 -o $@ -O prg $(subst generated/c128/exeso/,examples/,$(@:.prg=.bas))

#------------------------------------------------ 
# c64:
#    COMMODORE 64 (6502)
#------------------------------------------------ 
# 
toolchain.c64: cc65

generated/c64/asm/%.asm:
	@ugbc/exe/ugbc.c64 -L $(@:.asm=.listing) -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c64/asm/,examples/,$(@:.asm=.bas)) $@

generated/c64/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c64 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c64/exe/%.d64:
	@ugbc/exe/ugbc.c64 -o $@ -O d64 $(subst generated/c64/exe/,examples/,$(@:.d64=.bas))

generated/c64/exeso/%.prg: $(subst /generated/exeso/,/examples/,$(@:.prg=.bas))
	@ugbc/exe/ugbc.c64 -o $@ -O prg $(subst generated/c64/exeso/,examples/,$(@:.prg=.bas))

generated/c64/exeso/%.d64: $(subst /generated/exeso/,/examples/,$(@:.d64=.bas))
	@ugbc/exe/ugbc.c64 -o $@ -O d64 $(subst generated/c64/exeso/,examples/,$(@:.d64=.bas))

#------------------------------------------------ 
# coleco:
#    COLECOVISION (Z80)
#------------------------------------------------ 
# 
toolchain.coleco: z88dk

generated/coleco/asm/%.asm:
	@ugbc/exe/ugbc.coleco $(subst generated/coleco/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/coleco/exe/%.rom:
	@$(Z80ASM) -D__coleco__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2coleco.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.rom=.o))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@:.rom=.bin)
	@rm $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin)
	@$(APPMAKE) +msxrom -b $(@:.rom=.bin) 2>/dev/null
	@rm -f $(@:.rom=.bin) $(@:.rom=_*.bin)

generated/coleco/exeso/%.rom: $(subst /generated/exeso/,/examples/,$(@:.rom=.bas))
	@ugbc/exe/ugbc.coleco -o $@ -O rom $(subst generated/coleco/exeso/,examples/,$(@:.rom=.bas))

#------------------------------------------------ 
# cpc:
#    AMSTRAD CPC 664 (Z80)
#------------------------------------------------ 
# 
toolchain.cpc: z88dk

generated/cpc/asm/%.asm:
	@ugbc/exe/ugbc.cpc $(subst generated/cpc/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/cpc/exe/%.dsk:
	@$(Z80ASM) -D__cpc__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.dsk=.asm))
	@mv $(subst /exe/,/asm/,$(@:.dsk=.sym)) $(subst /exe/,/asm/,$(@:.dsk=.osym))
	@php sym2cpc.php $(subst /exe/,/asm/,$(@:.dsk=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.dsk=.o))
	@mv $(subst /exe/,/asm/,$(@:.dsk=.bin)) $(@:.dsk=.bin)
	@$(APPMAKE) +cpc --org $1200 --disk -b $(@:.dsk=.bin) -o $(dir $@)main.com
	@rm -f $(@:.dsk=.bin) $(@:.dsk=_*.bin) $(dir $@)main.com

generated/cpc/exeso/%.dsk: $(subst /generated/exeso/,/examples/,$(@:.dsk=.bas))
	@ugbc/exe/ugbc.cpc -o $@ -O dsk $(subst generated/cpc/exeso/,examples/,$(@:.dsk=.bas))

#------------------------------------------------ 
# d32:
#    DRAGON 32 (6809)
#------------------------------------------------ 
# 
toolchain.d32: asm6809

generated/d32/asm/%.asm: compiler
	@ugbc/exe/ugbc.d32 $(subst generated/d32/asm/,examples/,$(@:.asm=.bas)) $@

generated/d32/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/d32/exeso/%.bin: $(subst /generated/exeso/,/examples/,$(@:.bin=.bas))
	@ugbc/exe/ugbc.d32 -o $@ -O bin $(subst generated/d32/exeso/,examples/,$(@:.bin=.bas))

#------------------------------------------------ 
# d64:
#    DRAGON 64 (6809)
#------------------------------------------------ 
# 
toolchain.d64: asm6809

generated/d64/asm/%.asm: compiler
	@ugbc/exe/ugbc.d64 $(subst generated/d64/asm/,examples/,$(@:.asm=.bas)) $@

generated/d64/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/d64/exeso/%.bin: $(subst /generated/exeso/,/examples/,$(@:.bin=.bas))
	@ugbc/exe/ugbc.d64 -o $@ -l $(@:.bin=.lis) -O bin $(subst generated/d64/exeso/,examples/,$(@:.bin=.bas))

#------------------------------------------------ 
# mo5:
#    THOMSON MO5 (6809)
#------------------------------------------------ 
# 
toolchain.mo5: asm6809

generated/mo5/asm/%.asm: compiler
	@ugbc/exe/ugbc.mo5 $(subst generated/mo5/asm/,examples/,$(@:.asm=.bas)) $@

generated/mo5/exe/%.k7: compiler
	@ugbc/exe/ugbc.mo5 $(subst generated/mo5/exe/,examples/,$(@:.k7=.bas)) -o $@

generated/mo5/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/mo5/exeso/%.bin: $(subst /generated/exeso/,/examples/,$(@:.bin=.bas))
	@ugbc/exe/ugbc.mo5 -o $@ -O bin $(subst generated/mo5/exeso/,examples/,$(@:.bin=.bas))

generated/mo5/exeso/%.k7: $(subst /generated/exeso/,/examples/,$(@:.k7=.bas))
	@ugbc/exe/ugbc.mo5 -o $@ -O k7 $(subst generated/mo5/exeso/,examples/,$(@:.k7=.bas))

#------------------------------------------------ 
# msx1:
#    MSX 1 (Z80)
#------------------------------------------------ 
# 
toolchain.msx1: z88dk

generated/msx1/asm/%.asm:
	@ugbc/exe/ugbc.msx1 $(subst generated/msx1/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/msx1/exe/%.rom:
	@$(Z80ASM) -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2msx.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.rom=.o))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@:.rom=.bin)
	@rm $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin)
	@$(APPMAKE) +msxrom -b $(@:.rom=.bin) 2>/dev/null
	@rm -f $(@:.rom=.bin) $(@:.rom=_*.bin)

generated/msx1/exeso/%.rom: $(subst /generated/exeso/,/examples/,$(@:.rom=.bas))
	@ugbc/exe/ugbc.msx1 -o $@ -O rom $(subst generated/msx1/exeso/,examples/,$(@:.rom=.bas))

#------------------------------------------------ 
# pc128:
#    OLIVETTI PRODEST PC128 (6809)
#------------------------------------------------ 
# 
toolchain.pc128op: asm6809

generated/pc128op/asm/%.asm: compiler
	@ugbc/exe/ugbc.pc128op -L generated/pc128op/asm/output.listing $(subst generated/pc128op/asm/,examples/,$(@:.asm=.bas)) $@

generated/pc128op/exe/%.k7: compiler
	@ugbc/exe/ugbc.pc128op -L generated/pc128op/asm/output.listing $(subst generated/pc128op/exe/,examples/,$(@:.k7=.bas)) -o $@

generated/pc128op/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/pc128op/exeso/%.bin: $(subst /generated/exeso/,/examples/,$(@:.bin=.bas))
	@ugbc/exe/ugbc.pc128op -o $@ -O bin $(subst generated/pc128op/exeso/,examples/,$(@:.bin=.bas))

generated/pc128op/exeso/%.k7: $(subst /generated/exeso/,/examples/,$(@:.k7=.bas))
	@ugbc/exe/ugbc.pc128op -o $@ -O k7 $(subst generated/pc128op/exeso/,examples/,$(@:.k7=.bas))

#------------------------------------------------ 
# plus4:
#    COMMODORE PLUS/4 (7501/8501)
#------------------------------------------------ 
# 
toolchain.plus4: cc65

generated/plus4/asm/%.asm:
	@ugbc/exe/ugbc.plus4 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/plus4/asm/,examples/,$(@:.asm=.bas)) $@

generated/plus4/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -u __EXEHDR__ -t plus4 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/plus4/exeso/%.prg: $(subst /generated/exeso/,/examples/,$(@:.prg=.bas))
	@ugbc/exe/ugbc.plus4 -o $@ -O prg $(subst generated/plus4/exeso/,examples/,$(@:.prg=.bas))

#------------------------------------------------ 
# sc3000:
#    SEGA SC-3000 (Z80)
#------------------------------------------------ 
# 
toolchain.sc3000: z88dk

generated/sc3000/asm/%.asm:
	@ugbc/exe/ugbc.sc3000 $(subst generated/sc3000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/sc3000/exe/%.rom:
	@$(Z80ASM) -D__sc3000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sc3000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

generated/sc3000/exeso/%.rom: $(subst /generated/exeso/,/examples/,$(@:.rom=.bas))
	@ugbc/exe/ugbc.sc3000 -o $@ -O rom $(subst generated/sc3000/exeso/,examples/,$(@:.rom=.bas))

#------------------------------------------------ 
# sg1000:
#    SEGA SG-1000 (Z80)
#------------------------------------------------ 
# 
toolchain.sg1000: z88dk

generated/sg1000/asm/%.asm:
	@ugbc/exe/ugbc.sg1000 $(subst generated/sg1000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/sg1000/exe/%.rom:
	@$(Z80ASM) -D__sg1000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sg1000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

generated/sg1000/exeso/%.rom: $(subst /generated/exeso/,/examples/,$(@:.rom=.bas))
	@ugbc/exe/ugbc.sg1000 -o $@ -O rom $(subst generated/sg1000/exeso/,examples/,$(@:.rom=.bas))

#------------------------------------------------ 
# vg5000:
#    PHILIPS VG5000 (Z80)
#------------------------------------------------ 
# 
toolchain.vg5000: z88dk

generated/vg5000/asm/%.asm:
	@ugbc/exe/ugbc.vg5000 $(subst generated/vg5000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/vg5000/exe/%.bin: compiler
	@$(Z80ASM) -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))

generated/vg5000/exe/%.k7:
	@ugbc/exe/ugbc.vg5000 -o $@ -L generated/vg5000/asm/output.listing $(subst generated/vg5000/exe/,examples/,$(@:.k7=.bas))

generated/vg5000/exeso/%.rom: $(subst /generated/exeso/,/examples/,$(@:.rom=.bas))
	@ugbc/exe/ugbc.vg5000 -o $@ -O rom $(subst generated/vg5000/exeso/,examples/,$(@:.rom=.bas))

#------------------------------------------------ 
# vic20:
#    COMMODORE VIC-20 (6502)
#------------------------------------------------ 
# 
toolchain.vic20: cc65

generated/vic20/asm/%.asm:
	@ugbc/exe/ugbc.vic20 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/vic20/asm/,examples/,$(@:.asm=.bas)) $@

generated/vic20/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t vic20 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/vic20/exeso/%.prg: $(subst /generated/exeso/,/examples/,$(@:.prg=.bas))
	@ugbc/exe/ugbc.vic20 -o $@ -O rom $(subst generated/vic20/exeso/,examples/,$(@:.prg=.bas))

#------------------------------------------------ 
# zx:
#    ZX SPECTRUM 48K (Z80)
#------------------------------------------------ 
# 
toolchain.zx: z88dk

generated/zx/asm/%.asm:
	@ugbc/exe/ugbc.zx $(subst generated/zx/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/zx/exe/%.tap:
	@$(Z80ASM) -l -b $(subst /exe/,/asm/,$(@:.tap=.asm))
	@mv $(subst /exe/,/asm/,$(@:.tap=.lis)) $(@:.tap=.lis)
	@rm -f $(subst /exe/,/asm/,$(@:.tap=.o))
	@mv $(subst /exe/,/asm/,$(@:.tap=.bin)) $(@:.tap=.bin)
	@$(APPMAKE) +zx --org 32768 -b $(@:.tap=.bin)
	@rm -f $(@:.tap=.bin) $(@:.tap=_*.bin)

generated/zx/exeso/%.tap: $(subst /generated/exeso/,/examples/,$(@:.tap=.bas))
	@ugbc/exe/ugbc.zx -o $@ -L $(@:.tap=.lst) -O tap $(subst generated/zx/exeso/,examples/,$(@:.tap=.bas))
