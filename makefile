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

.PHONY: paths compiler clean all

EXAMPLES := $(wildcard examples/texts_print_00.bas)
COMPILED := $(subst examples/,generated/$(target)/asm/,$(EXAMPLES:.bas=.asm))
EXECUTABLES := $(subst /asm/,/exe/,$(COMPILED:.asm=.$(output)))

all: paths compiler $(COMPILED) $(EXECUTABLES)

test:
	@cd ugbc && $(MAKE) target=$(target) test
	@echo "--- START TEST ---"
	@ugbc/exe-test/ugbc.$(target)
	@echo
	@echo "--- END TEST ---"

generated/c64/asm/%.asm:
	@ugbc/exe/ugbc.c64 -L $(@:.asm=.listing) -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c64/asm/,examples/,$(@:.asm=.bas)) $@

generated/c64/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@cl65 -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c64 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/c64/exe/%.d64:
	ugbc/exe/ugbc.c64 -O d64 $(subst generated/c64/exe/,examples/,$(@:.d64=.bas)) -o $@

generated/c128/asm/%.asm:
	@ugbc/exe/ugbc.c128 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c128/asm/,examples/,$(@:.asm=.bas)) $@

generated/c128/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@cl65 -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t c128 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/vic20/asm/%.asm:
	@ugbc/exe/ugbc.vic20 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/vic20/asm/,examples/,$(@:.asm=.bas)) $@

generated/vic20/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@cl65 -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -t vic20 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/plus4/asm/%.asm:
	@ugbc/exe/ugbc.plus4 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/plus4/asm/,examples/,$(@:.asm=.bas)) $@

generated/plus4/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@cl65 -Ln $(@:.prg=.lbl) --listing $(@:.prg=.lst) -g -o $@ --mapfile $(@:.prg=.map) -u __EXEHDR__ -t plus4 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/atari/asm/%.asm:
	@ugbc/exe/ugbc.atari -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atari/asm/,examples/,$(@:.asm=.bas)) $@

generated/atari/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@cl65 -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/atarixl/asm/%.asm:
	@ugbc/exe/ugbc.atarixl -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/atarixl/asm/,examples/,$(@:.asm=.bas)) $@

generated/atarixl/exe/%.xex: $(subst /exe/,/asm/,$(@:.xex=.asm))
	@cl65 -Ln $(@:.xex=.lbl) --listing $(@:.xex=.lst) -g -o $@ --mapfile $(@:.xex=.map) -t atari -D __atarixl__ -C $(subst /exe/,/cfg/,$(@:.xex=.cfg)) $(subst /exe/,/asm/,$(@:.xex=.asm))
	@rm -f $(@:.xex=.o)

generated/zx/asm/%.asm:
	@ugbc/exe/ugbc.zx $(subst generated/zx/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/zx/exe/%.tap:
	@z88dk-z80asm -l -b $(subst /exe/,/asm/,$(@:.tap=.asm))
	@rm -f $(subst /exe/,/asm/,$(@:.tap=.o))
	@mv $(subst /exe/,/asm/,$(@:.tap=.bin)) $(@:.tap=.bin)
	@z88dk-appmake +zx --org 32768 -b $(@:.tap=.bin)
	@rm -f $(@:.tap=.bin) $(@:.tap=_*.bin)

generated/d32/asm/%.asm: compiler
	@ugbc/exe/ugbc.d32 $(subst generated/d32/asm/,examples/,$(@:.asm=.bas)) $@

generated/d32/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@asm6809 -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/d64/asm/%.asm: compiler
	@ugbc/exe/ugbc.d64 $(subst generated/d64/asm/,examples/,$(@:.asm=.bas)) $@

generated/d64/exe/%.bin: $(subst /exe/,/asm/,$(@:.bin=.asm))
	@asm6809 -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/pc128op/asm/%.asm: compiler
	@ugbc/exe/ugbc.pc128op -L generated/pc128op/asm/output.listing $(subst generated/pc128op/asm/,examples/,$(@:.asm=.bas)) $@

generated/pc128op/exe/%.k7: compiler
	@ugbc/exe/ugbc.pc128op -L generated/pc128op/asm/output.listing $(subst generated/pc128op/exe/,examples/,$(@:.k7=.bas)) -o $@

generated/pc128op/exe/%.bin: compiler
	@asm6809 -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/mo5/asm/%.asm: compiler
	@ugbc/exe/ugbc.mo5 $(subst generated/mo5/asm/,examples/,$(@:.asm=.bas)) $@

generated/mo5/exe/%.k7: compiler
	@ugbc/exe/ugbc.mo5 $(subst generated/mo5/exe/,examples/,$(@:.k7=.bas)) -o $@

generated/mo5/exe/%.bin: compiler
	@asm6809 -l $(@:.bin=.lis) -s $(@:.bin=.lbl) -D -e 10240 -o $@ $(subst /exe/,/asm/,$(@:.bin=.asm))

generated/msx1/asm/%.asm:
	@ugbc/exe/ugbc.msx1 $(subst generated/msx1/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/msx1/exe/%.rom:
	@z88dk-z80asm -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2msx.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.rom=.o))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@:.rom=.bin)
	@rm $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin)
	@z88dk-appmake +msxrom -b $(@:.rom=.bin) 2>/dev/null
	@rm -f $(@:.rom=.bin) $(@:.rom=_*.bin)

generated/coleco/asm/%.asm:
	@ugbc/exe/ugbc.coleco $(subst generated/coleco/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/coleco/exe/%.rom:
	@z88dk-z80asm -D__coleco__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2coleco.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@rm -f $(subst /exe/,/asm/,$(@:.rom=.o))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@:.rom=.bin)
	@rm $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin)
	@z88dk-appmake +msxrom -b $(@:.rom=.bin) 2>/dev/null
	@rm -f $(@:.rom=.bin) $(@:.rom=_*.bin)

generated/sc3000/asm/%.asm:
	@ugbc/exe/ugbc.sc3000 $(subst generated/sc3000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/sc3000/exe/%.rom:
	@z88dk-z80asm -D__sc3000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sc3000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

generated/sg1000/asm/%.asm:
	@ugbc/exe/ugbc.sg1000 $(subst generated/sg1000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/sg1000/exe/%.rom:
	@z88dk-z80asm -D__sg1000__ -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))
	@mv $(subst /exe/,/asm/,$(@:.rom=.sym)) $(subst /exe/,/asm/,$(@:.rom=.osym))
	@php sym2sg1000.php $(subst /exe/,/asm/,$(@:.rom=.osym)) >$(subst /exe/,/asm/,$(@:.rom=.sym))
	@mv $(subst /exe/,/asm/,$(@:.rom=_code_user.bin)) $(@:.rom=_code_user.bin)
	@mv $(subst /exe/,/asm/,$(@:.rom=_data_user.bin)) $(@:.rom=_data_user.bin)
	@cat $(@:.rom=_code_user.bin) $(@:.rom=_data_user.bin) >$(@)

generated/vg5000/asm/%.asm:
	@ugbc/exe/ugbc.vg5000 $(subst generated/vg5000/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/vg5000/exe/%.bin: compiler
	@z88dk-z80asm -l -m -s -g -b $(subst /exe/,/asm/,$(@:.rom=.asm))

generated/vg5000/exe/%.k7:
	@ugbc/exe/ugbc.vg5000 -L generated/vg5000/asm/output.listing $(subst generated/vg5000/exe/,examples/,$(@:.k7=.bas)) -o $@

paths:
	@mkdir -p generated
	@mkdir -p generated/$(target)/asm
	@mkdir -p generated/$(target)/cfg
	@mkdir -p generated/$(target)/exe

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