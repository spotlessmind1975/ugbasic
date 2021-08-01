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

FLEX_OPTIONS=--8bit 
BISON_OPTIONS=--locations -d -Wcounterexamples

.PHONY: paths clean all

all: paths compiler

test: paths-test tester

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
# MODULES SECTION - embed ASM for each specific target
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Components and chipsets
# ----------------------------------------------------------------------------

# MOS Technology 6502/6510

MODULES_6502 := $(wildcard src/hw/6502/*.asm)
SOURCES_6502 := $(subst src/hw/6502/,src-generated/6502_,$(MODULES_6502:.asm=.c))

src-generated/6502_%.c: $(MODULES_6502)
	@xxd -i $(subst src-generated/6502_,src/hw/6502/,$(@:.c=.asm)) >$@

# Alphanumeric Television Interface Controller (ANTIC)

MODULES_ANTIC := $(wildcard src/hw/antic/*.asm)
SOURCES_ANTIC := $(subst src/hw/antic/,src-generated/antic_,$(MODULES_ANTIC:.asm=.c))

src-generated/antic_%.c: $(MODULES_ANTIC)
	@xxd -i $(subst src-generated/antic_,src/hw/antic/,$(@:.c=.asm)) >$@

# Color Television Interface Adaptor (CTIA) 
# Graphic Television Interface Adaptor[1] (GTIA) 

MODULES_GTIA := $(wildcard src/hw/gtia/*.asm)
SOURCES_GTIA := $(subst src/hw/gtia/,src-generated/gtia_,$(MODULES_GTIA:.asm=.c))

src-generated/gtia_%.c: $(MODULES_GTIA)
	@xxd -i $(subst src-generated/gtia_,src/hw/gtia/,$(@:.c=.asm)) >$@

# MOS Technology VIC-II

MODULES_VIC2 := $(wildcard src/hw/vic2/*.asm)
SOURCES_VIC2 := $(subst src/hw/vic2/,src-generated/vic2_,$(MODULES_VIC2:.asm=.c))

src-generated/vic2_%.c: $(MODULES_VIC2)
	@xxd -i $(subst src-generated/vic2_,src/hw/vic2/,$(@:.c=.asm)) >$@

# MOS Technology TED

MODULES_TED := $(wildcard src/hw/ted/*.asm)
SOURCES_TED := $(subst src/hw/ted/,src-generated/ted_,$(MODULES_TED:.asm=.c))

src-generated/ted_%.c: $(MODULES_TED)
	@xxd -i $(subst src-generated/ted_,src/hw/ted/,$(@:.c=.asm)) >$@

# Zilog Z80

MODULES_Z80 := $(wildcard src/hw/z80/*.asm)
SOURCES_Z80 := $(subst src/hw/z80/,src-generated/z80_,$(MODULES_Z80:.asm=.c))

src-generated/z80_%.c: $(MODULES_Z80)
	@xxd -i $(subst src-generated/z80_,src/hw/z80/,$(@:.c=.asm)) >$@

# ----------------------------------------------------------------------------
# Computers and targets
# ----------------------------------------------------------------------------

# ATARI computer family

MODULES_ATARI := $(wildcard src/hw/atari/*.asm)
SOURCES_ATARI := $(subst src/hw/atari/,src-generated/atari_,$(MODULES_ATARI:.asm=.c))

src-generated/atari_%.c: $(MODULES_ATARI)
	@xxd -i $(subst src-generated/atari_,src/hw/atari/,$(@:.c=.asm)) >$@

src-generated/modules_atari.c: $(SOURCES_6502) $(SOURCES_ANTIC) $(SOURCES_ATARI) $(SOURCES_GTIA)
	@cat $(SOURCES_6502) $(SOURCES_ANTIC) $(SOURCES_ATARI) $(SOURCES_GTIA) >src-generated/modules_atari.c
	@grep "src" src-generated/modules_atari.c | awk -f modules.awk >src-generated/modules_atari.h

src-generated/modules_atarixl.c: $(SOURCES_6502) $(SOURCES_ANTIC) $(SOURCES_ATARI) $(SOURCES_GTIA)
	@cat $(SOURCES_6502) $(SOURCES_ANTIC) $(SOURCES_ATARI) $(SOURCES_GTIA) >src-generated/modules_atarixl.c
	@grep "src" src-generated/modules_atarixl.c | awk -f modules.awk >src-generated/modules_atarixl.h

# Commodore 64

MODULES_C64 := $(wildcard src/hw/c64/*.asm)
SOURCES_C64 := $(subst src/hw/c64/,src-generated/c64_,$(MODULES_C64:.asm=.c))

src-generated/c64_%.c: $(MODULES_C64)
	@xxd -i $(subst src-generated/c64_,src/hw/c64/,$(@:.c=.asm)) >$@

src-generated/modules_c64.c: $(SOURCES_6502) $(SOURCES_C64) $(SOURCES_VIC2)
	@cat $(SOURCES_6502) $(SOURCES_C64) $(SOURCES_VIC2) >src-generated/modules_c64.c
	@grep "src" src-generated/modules_c64.c | awk -f modules.awk >src-generated/modules_c64.h

# Commodore PLUS/4

MODULES_PLUS4 := $(wildcard src/hw/plus4/*.asm)
SOURCES_PLUS4 := $(subst src/hw/plus4/,src-generated/plus4_,$(MODULES_PLUS4:.asm=.c))

src-generated/plus4_%.c: $(MODULES_PLUS4)
	@xxd -i $(subst src-generated/plus4_,src/hw/plus4/,$(@:.c=.asm)) >$@

src-generated/modules_plus4.c: $(SOURCES_6502) $(SOURCES_PLUS4) $(SOURCES_TED)
	@cat $(SOURCES_6502) $(SOURCES_PLUS4) $(SOURCES_TED) >src-generated/modules_plus4.c
	@grep "src" src-generated/modules_plus4.c | awk -f modules.awk >src-generated/modules_plus4.h

# ZX Spectrum

MODULES_ZX := $(wildcard src/hw/zx/*.asm)
SOURCES_ZX := $(subst src/hw/zx/,src-generated/zx_,$(MODULES_ZX:.asm=.c))

src-generated/zx_%.c: $(MODULES_ZX)
	@xxd -i $(subst src-generated/zx_,src/hw/zx/,$(@:.c=.asm)) >$@

src-generated/modules_zx.c: $(SOURCES_Z80) $(SOURCES_ZX)
	@cat $(SOURCES_Z80) $(SOURCES_ZX) >src-generated/modules_zx.c
	@grep "src" src-generated/modules_zx.c | awk -f modules.awk >src-generated/modules_zx.h

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
# LEXER/PARSER SECTION
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------

src-generated/ugbc.yy.c: src/ugbc.lex src/ugbc.y
	@flex ${FLEX_OPTIONS} --outfile=src-generated/ugbc.yy.c src/ugbc.lex

src-generated/ugbc.tab.c: src/ugbc.lex src/ugbc.y
	@bison ${BISON_OPTIONS} --file-prefix=src-generated/ugbc src/ugbc.y

# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------
# COMPILATION RULES
# ----------------------------------------------------------------------------
# ----------------------------------------------------------------------------

SOURCES := $(wildcard src/*.c)
SOURCES += $(wildcard src/targets/*.c)
SOURCES += $(wildcard src/hw/*.c)
SOURCES += $(wildcard src/targets/common/*.c)
SOURCES += $(wildcard src/targets/$(target)/*.c)
SOURCES += src-generated/ugbc.yy.c src-generated/ugbc.tab.c src-generated/modules_$(target).c

SOURCESTEST := $(wildcard src/*.c)
SOURCESTEST += $(wildcard src/targets/*.c)
SOURCESTEST += $(wildcard src/hw/*.c)
SOURCESTEST += $(wildcard src/targets/common/*.c)
SOURCESTEST += $(wildcard src/targets/$(target)/*.c)
SOURCESTEST += $(wildcard src-test/suites/*.c)
SOURCESTEST += src-test/tester.c src-test/tester_c64.c src-test/tester_plus4.c src-test/tester_atari.c src-test/tester_atarixl.c src-test/tester_zx.c

paths:
	@mkdir -p src-generated
	@mkdir -p exe

paths-test:
	@mkdir -p exe-test

compiler: $(SOURCES)
	@cc -D__$(target)__ -g $(SOURCES) -o exe/ugbc.$(target) -lm

tester: $(SOURCESTEST)
	@cc -D__$(target)__ -g $(SOURCESTEST) -o exe-test/ugbc.$(target) -lm

clean:
	@rm -f exe/ugbc.*
	@rm -f src-generated/*.c
	@rm -f src-generated/*.h
	@rm -f exe-test/ugbc.*

