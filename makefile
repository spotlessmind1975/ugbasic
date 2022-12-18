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

.PHONY: paths toolchain compiler clean all

EXAMPLES := $(wildcard examples/*.bas)
COMPILED := $(subst examples/,generated/$(target)/asm/,$(EXAMPLES:.bas=.asm))
EXECUTABLES := $(subst /asm/,/exe/,$(COMPILED:.asm=.$(output)))

Z80ASM = ./modules/z88dk/src/z80asm/z88dk-z80asm
APPMAKE = ./modules/z88dk/src/appmake/z88dk-appmake
CL65 = ./modules/cc65/bin/cl65
ASM6809 = ./modules/asm6809/src/asm6809

all: paths toolchain compiler $(COMPILED) $(EXECUTABLES)

test:
	@cd ugbc && $(MAKE) target=$(target) test
	@echo "--- START TEST ---"
	@ugbc/exe-test/ugbc.$(target)
	@echo
	@echo "--- END TEST ---"

generated/c64/asm/%.asm:
	@ugbc/exe/ugbc.c64 -L $(@:.asm=.listing) -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c64/asm/,examples/,$(@:.asm=.bas)) $@

generated/c64/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c64 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c64/exe/%.d64:
	@ugbc/exe/ugbc.c64 -O d64 $(subst generated/c64/exe/,examples/,$(@:.d64=.bas)) -o $@

generated/c128/asm/%.asm:
	@ugbc/exe/ugbc.c128 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c128/asm/,examples/,$(@:.asm=.bas)) $@

generated/c128/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c128 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/vic20/asm/%.asm:
	@ugbc/exe/ugbc.vic20 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/vic20/asm/,examples/,$(@:.asm=.bas)) $@

generated/vic20/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t vic20 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/plus4/asm/%.asm:
	@ugbc/exe/ugbc.plus4 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/plus4/asm/,examples/,$(@:.asm=.bas)) $@

generated/plus4/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@$(CL65) -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -u __EXEHDR__ -t plus4 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/atari/asm/%.asm:
	@ugbc/exe/ugbc.atari -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atari/asm/,examples/,$(@:.asm=.bas)) $@

generated/atari/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@$(CL65) -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/atarixl/asm/%.asm:
	@ugbc/exe/ugbc.atarixl -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atarixl/asm/,examples/,$(@:.asm=.bas)) $@

generated/atarixl/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@$(CL65) -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -D __atarixl__ -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/zx/asm/%.asm:
	@ugbc/exe/ugbc.zx $(subst generated/zx/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/zx/exe/%.tap:
	@$(Z80ASM) -l -b $(subst /exe/,/asm/,$(@:.tap=.asm))
	@rm -f $(subst /exe/,/asm/,$(@:.tap=.o))
	@mv $(subst /exe/,/asm/,$(@:.tap=.bin)) $(@:.tap=.bin)
	@$(APPMAKE) +zx --org 32768 -b $(@:.tap=.bin)
	@rm -f $(@:.tap=.bin) $(@:.tap=_*.bin)

generated/d32/asm/%.asm: compiler
	@ugbc/exe/ugbc.d32 $(subst generated/d32/asm/,examples/,$(@:.asm=.bas)) $@

generated/d32/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/d64/asm/%.asm: compiler
	@ugbc/exe/ugbc.d64 $(subst generated/d64/asm/,examples/,$(@:.asm=.bas)) $@

generated/d64/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/pc128op/asm/%.asm: compiler
	@ugbc/exe/ugbc.pc128op -L generated/pc128op/asm/output.listing $(subst generated/pc128op/asm/,examples/,$(@:.asm=.bas)) $@

generated/pc128op/exe/%.k7: compiler
	@ugbc/exe/ugbc.pc128op -L generated/pc128op/asm/output.listing $(subst generated/pc128op/exe/,examples/,$(@:.k7=.bas)) -o $@

generated/pc128op/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/mo5/asm/%.asm: compiler
	@ugbc/exe/ugbc.mo5 $(subst generated/mo5/asm/,examples/,$(@:.asm=.bas)) $@

generated/mo5/exe/%.k7: compiler
	@ugbc/exe/ugbc.mo5 $(subst generated/mo5/exe/,examples/,$(@:.k7=.bas)) -o $@

generated/mo5/exe/%.bin: compiler
	@$(ASM6809) -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

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

generated/sc3000/asm/%.asm:
	@ugbc/exe/ugbc.sc3000 $(subst generated/sc3000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/sc3000/exe/%.rom:
	@$(Z80ASM) -D__sc3000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sc3000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

generated/sg1000/asm/%.asm:
	@ugbc/exe/ugbc.sg1000 $(subst generated/sg1000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/sg1000/exe/%.rom:
	@$(Z80ASM) -D__sg1000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sg1000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

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

generated/vg5000/asm/%.asm:
	@ugbc/exe/ugbc.vg5000 $(subst generated/vg5000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/vg5000/exe/%.bin: compiler
	@$(Z80ASM) -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))

generated/vg5000/exe/%.k7:
	@ugbc/exe/ugbc.vg5000 -L generated/vg5000/asm/output.listing $(subst generated/vg5000/exe/,examples/,$(@:.k7=.bas)) -o $@

paths:
	@mkdir -p generated
	@mkdir -p generated/$(target)/asm
	@mkdir -p generated/$(target)/cfg
	@mkdir -p generated/$(target)/exe
	@mkdir -p $(dir $(CL65))
	@mkdir -p $(dir $(Z80ASM))
	@mkdir -p $(dir $(APPMAKE))
	@mkdir -p $(dir $(ASM6809))

$(CL65): $(dir $(CL65))../src/ca65/*.c $(dir $(CL65))../src/ca65/*.h $(dir $(CL65))../src/cl65/*.c $(dir $(CL65))../src/cl65/*.h
	cd $(dir $(CL65)..).. && make

cc65: $(CL65)

$(Z80ASM): $(dir $(Z80ASM))src/c/*.c $(dir $(Z80ASM))src/c/*.h $(dir $(Z80ASM))src/cpp/*.cpp $(dir $(Z80ASM))src/cpp/*.h
	cd $(dir $(Z80ASM)) && make

$(Z80APPMAKE): $(dir $(Z80APPMAKE))src/c/*.c $(dir $(Z80APPMAKE))src/c/*.h $(dir $(Z80APPMAKE))src/cpp/*.cpp $(dir $(Z80APPMAKE))src/cpp/*.h
	cd $(dir $(Z80APPMAKE)) && make

z88dk: $(Z80ASM) $(Z80APPMAKE)

$(dir $(ASM6809))../configure: $(dir $(ASM6809))../autogen.sh
	cd $(dir $(ASM6809)).. && ./autogen.sh

$(dir $(ASM6809))../Makefile: $(dir $(ASM6809))../configure
	cd $(dir $(ASM6809)).. && ./configure

$(dir $(ASM6809)): $(dir $(ASM6809))../Makefile
	cd $(dir $(ASM6809)).. && make

asm6809: $(dir $(ASM6809))

toolchain.atari: cc65

toolchain.atarixl: cc65

toolchain.c128: cc65

toolchain.c64: cc65

toolchain.coleco: z88dk.coleco

toolchain.cpc: z88dk

toolchain.d32: asm6809

toolchain.d64: asm6809

toolchain.mo5: asm6809

toolchain.msx1: z88dk

toolchain.pc128op: asm6809

toolchain.plus4: cc65

toolchain.sc3000: z88dk

toolchain.sg1000: z88dk

toolchain.vg5000: z88dk

toolchain.vic20: cc65

toolchain.zx: z88dk

toolchain: toolchain.$(target)

compiler:
	@cd ugbc && $(MAKE) target=$(target) all

clean:
	@cd ugbc && $(MAKE) clean
	@rm -f -r generated

runc64: generated/c64/asm/$(example).asm generated/c64/exe/$(example).$(output)
	x64sc generated/c64/exe/$(example).$(output)

runzx: generated/zx/asm/$(example).asm generated/zx/exe/$(example).$(output)
	speccy generated/zx/exe/$(example).$(output)

runplus4: generated/plus4/asm/$(example).asm generated/plus4/exe/$(example).$(output)
	xplus4 generated/plus4/exe/$(example).$(output)

runyape: generated/plus4/asm/$(example).asm generated/plus4/exe/$(example).$(output)
	yape generated/plus4/exe/$(example).$(output)

runatari: generated/atari/asm/$(example).asm generated/atari/exe/$(example).$(output)
	altirra generated/atari/exe/$(example).$(output)

runatarixl: generated/atarixl/asm/$(example).asm generated/atarixl/exe/$(example).$(output)
	altirra generated/atarixl/exe/$(example).$(output)