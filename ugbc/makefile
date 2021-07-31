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

FLEX_OPTIONS=-8 
BISON_OPTIONS=--locations -d -Wcounterexamples

.PHONY: paths clean all

all: paths compiler

test: paths-test tester

src-generated/ugbc.yy.c: src/ugbc.lex src/ugbc.y
	@flex ${FLEX_OPTIONS} -o src-generated/ugbc.yy.c src/ugbc.lex

src-generated/ugbc.tab.c: src/ugbc.lex src/ugbc.y
	@bison ${BISON_OPTIONS} --file-prefix=src-generated/ugbc src/ugbc.y

SOURCES := $(wildcard src/*.c)
SOURCES += $(wildcard src/targets/*.c)
SOURCES += $(wildcard src/hw/*.c)
SOURCES += $(wildcard src/targets/common/*.c)
SOURCES += $(wildcard src/targets/$(target)/*.c)
SOURCES += src-generated/ugbc.yy.c src-generated/ugbc.tab.c

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
	@rm -f src-generated/ugbc.yy.c
	@rm -f src-generated/ugbc.tab.c
	@rm -f exe-test/ugbc.*

