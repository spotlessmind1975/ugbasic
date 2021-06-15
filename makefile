#/*****************************************************************************
# * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
# *****************************************************************************
# * Copyright 2020-2021 Marco Spedaletti (asimov@mclink.it)
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

EXAMPLES := $(wildcard examples/*.bas)
COMPILED := $(subst examples/,generated/$(target)/asm/,$(EXAMPLES:.bas=.asm))
EXECUTABLES := $(subst /asm/,/exe/,$(COMPILED:.asm=.$(output)))

all: paths compiler $(COMPILED) $(EXECUTABLES)

test:
	@cd ugbc; make target=$(target) test
	@ugbc/exe-test/ugbc.$(target)

generated/c64/asm/%.asm:
	@ugbc/exe/ugbc.c64 -c $(subst /asm/,/cfg/,$(@:.asm=.cfg)) $(subst generated/c64/asm/,examples/,$(@:.asm=.bas)) $@

generated/c64/exe/%.prg: $(subst /exe/,/asm/,$(@:.prg=.asm))
	@cl65 -Ln $(@:.prg=.lbl) -o $@ --mapfile $(@:.prg=.map) -u __EXEHDR__ -t c64 -C $(subst /exe/,/cfg/,$(@:.prg=.cfg)) $(subst /exe/,/asm/,$(@:.prg=.asm))
	@rm -f $(@:.prg=.o)

generated/zx/asm/%.asm:
	@ugbc/exe/ugbc.zx $(subst generated/zx/asm/,examples/,$(@:.asm=.bas)) $@ 

generated/zx/exe/%.tap:
	@z88dk-z80asm -b $(subst /exe/,/asm/,$(@:.tap=.asm))
	@rm -f $(subst /exe/,/asm/,$(@:.tap=.o))
	@mv $(subst /exe/,/asm/,$(@:.tap=.bin)) $(@:.tap=.bin)
	@z88dk-appmake +zx --org 32768 -b $(@:.tap=.bin)
	@rm -f $(@:.tap=.bin) $(@:.tap=_*.bin)

paths:
	@mkdir -p generated
	@mkdir -p generated/$(target)/asm
	@mkdir -p generated/$(target)/cfg
	@mkdir -p generated/$(target)/exe

compiler:
	@cd ugbc; make target=$(target) all

clean:
	@cd ugbc; make clean
	@rm -f -r generated

runc64: generated/c64/asm/$(example).asm generated/c64/exe/$(example).$(output)
	x64sc generated/c64/exe/$(example).$(output)

runzx: generated/zx/asm/$(example).asm generated/zx/exe/$(example).$(output)
	speccy generated/zx/exe/$(example).$(output)
