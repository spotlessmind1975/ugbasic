/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

#ifdef HAVE_ERR_H
#include <err.h>
#endif

#ifndef HAVE_ERR
#include <errno.h>
#endif

#ifndef HAVE_CONFIG_H
#define RELEASE "1.0"
#endif

/////////////////////////////////////////////////////////////////////////////
//// reloc.h
/////////////////////////////////////////////////////////////////////////////

/* Represent bytes as 8-bit values tagged with meta-information. */
/* List nodes (struct source) are arena-allocated; no need to track the references. */

struct source {
	struct source	*next;
	uint16_t	offset;
	uint8_t		used;
};

typedef struct {
	uint8_t		value;
	struct source	*src;
} value_t;

struct core {
	value_t		memory[65536];
	uint8_t		read[65536];		// These (read/written) are booleans, but
	uint8_t		written[65536];		// kept separate for performance reasons.
};

struct progbyte {
	uint8_t			flags;
	uint8_t			zpaddr[32];	// one bit per address, little-endian
	struct constraintlist	*constr;
};

#define PBF_DONT_RELOC	0x01
#define PBF_RELOC	0x02
#define PBF_USED_IN_ZP	0x04
#define PBF_USED_IN_MSB	0x08

enum {
	RET_SUCCESS,
	RET_HEADER,
	RET_RSID,
	RET_MUS,
	RET_BASIC,
	RET_PSID,
	RET_PARAM,
	RET_IO,
	RET_CONSTR,
	RET_ZPFULL,
	RET_VERIFY,
	RET_PLAYADDR,
	RET_RANGE,
	RET_CYCLES,
};

enum {
	ERR_OK,
	ERR_BRK,
	ERR_INTERNAL,
	ERR_ILLEGAL,
	ERR_CYCLES,
};

// moved here:
static int progsize;
static struct progbyte *progbytes;
static int add_constraints;

static char lastErrorString[1024];

#ifndef HAVE_ERRX
/*  Some posix has not this standard, function (for ex. Haiku)
	so, we define a roughly equivalente */
static void errx(int eval, const char *fmt, ...){
	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(lastErrorString, fmt, argptr);
	va_end(argptr);
}
#endif

#ifndef HAVE_ERR
/*  Some posix has not this standard, function (for ex. Haiku)
	so, we define a roughly equivalente */
static void err(int eval, const char *fmt, ...){
	fprintf(stderr, " %s: ", "sidreloc");
	va_list argptr;
	va_start(argptr,fmt);
	vfprintf(stderr, fmt, argptr);
	va_end(argptr);
	fprintf(stderr, ": %s\n", strerror(errno));
}
#endif

static struct source *cons_src(uint16_t car, struct source *cdr);
static void check_reloc_range(uint16_t addr, struct source *lsb1, struct source *lsb2, struct source *msb);
static void reloc_alike(value_t v1, value_t v2);
static void used_for_zp_addr(struct source *src1, struct source *src2, uint8_t zpaddr);
static void init_progbytes(uint16_t loadaddr, uint16_t loadsize);
static int trivially_inconsistent();
static int solver();
static void free_arena();
static void gc_arena(struct core *core);
static void reloc_map(struct core *oldcore, uint16_t reloc_offs);
static int emulate(struct core *core, uint16_t start_addr, uint8_t acc, int max_cycles);
static void finalise_constraints(struct core *core);
static void prealloc_cons_cells();

static inline void dont_reloc_at(uint16_t offset) {
	assert(offset != 1);
	assert(offset < progsize + 2);
	progbytes[offset].flags |= PBF_DONT_RELOC;
}

static inline void dont_reloc(struct source *src) {
	if(add_constraints) {
		while(src) {
			dont_reloc_at(src->offset);
			assert(src);
			src = src->next;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
//// sidreloc.c
/////////////////////////////////////////////////////////////////////////////

/* Copyright (c) 2012 Linus Akesson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
struct sidheader {
	uint8_t			rsid;
	uint8_t			nsubtune;
	uint8_t			defsubtune;
	uint16_t		version;
	uint16_t		dataoffset;
	uint16_t		loadaddr;
	uint16_t		loadsize;
	uint16_t		initaddr;
	uint16_t		playaddr;
	char			title[32];
	char			author[32];
	char			released[32];
};

static struct zeropage {
	uint8_t			link;
	uint8_t			reloc;
	uint8_t			free;
} zeropage[256];

#define RETF_OUTOFBOUNDS 0x20
#define RETF_TOLERANCE 0x40

static int cycles_init = 1000000;
static int cycles_play = 20000;
static int play_calls = 100000;
static int nmi_calls = 200;
static int cycles_nmi = 1000;

static int do_zp_reloc = 1;
static int verbose = 0;
static int quiet = 0;
static int force = 0;

static uint16_t reloc_start;
static uint16_t reloc_end;

static int exitbits;
static int nmi_reported;

static struct core oldcore, newcore;

/////////////////////////////////////////////////////////////////////////////
//// cpu.c
/////////////////////////////////////////////////////////////////////////////

/* Specialized 6510 emulator by Marco Spedaletti.
 *
 * Based on heavily modified 6510 emulator by Linus Akesson and
 * on a proper 6502 emulator by Ian Piumarta, with the original copyright
 * notice below. My modifications to this file are hereby provided under the
 * same license, and the integration with ugBASIC is provided under the
 * Apache License 2.0.
 */

/* Copyright (c) 2005 Ian Piumarta
 * 
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the 'Software'),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that both the
 * above copyright notice(s) and this permission notice appear in supporting
 * documentation.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS'.  USE ENTIRELY AT YOUR OWN RISK.
 */

typedef uint8_t  byte;
typedef uint16_t word;

enum {
	flagN= (1<<7),	/* negative	*/
	flagV= (1<<6),	/* overflow 	*/
	flagX= (1<<5),	/* unused	*/
	flagB= (1<<4),	/* irq from brk	*/
	flagD= (1<<3),	/* decimal mode	*/
	flagI= (1<<2),	/* irq disable	*/
	flagZ= (1<<1),	/* zero		*/
	flagC= (1<<0)	/* carry	*/
};

char *emulate_err[] = {
	"BRK instruction",
	"Internal CPU emulator error",
	"Illegal opcode",
	"Max cycles exhausted (infinite loop?)",
};

#define getN()	(P & flagN)
#define getV()	(P & flagV)
#define getB()	(P & flagB)
#define getD()	(P & flagD)
#define getI()	(P & flagI)
#define getZ()	(P & flagZ)
#define getC()	(P & flagC)

#define setNVZC(N,V,Z,C)	(P= (P & ~(flagN | flagV | flagZ | flagC)) | (N) | ((V)<<6) | ((Z)<<1) | (C))
#define setNZC(N,Z,C)		(P= (P & ~(flagN |         flagZ | flagC)) | (N) |            ((Z)<<1) | (C))
#define setNZ(N,Z)		(P= (P & ~(flagN |         flagZ        )) | (N) |            ((Z)<<1)      )
#define setZ(Z)			(P= (P & ~(                flagZ        )) |                  ((Z)<<1)      )
#define setC(C)			(P= (P & ~(                        flagC)) |                             (C))

#define tick(n) if(max_cycles < n) return ERR_CYCLES; max_cycles -= n
#ifdef ACCURATE_TIMING
#define tickIf(p) if(p) { tick(1); }
#else
#define tickIf(p)
#endif

/* memory access -- ARGUMENTS ARE EVALUATED MORE THAN ONCE! */

#define putMemory(ADDR, VALUE)		\
	memory[ADDR] = (VALUE);		\
	core->written[ADDR] = 1;

#define getMemory(ADDR)	(core->read[ADDR] = 1, memory[ADDR])

/* stack access (always direct) */

#define push(VALUE)	(memory[0x0100 + S--] = (VALUE))
#define pop()		(memory[++S + 0x0100])

/* adressing modes (memory access direct) */

#define implied(ticks)				\
  tick(ticks);

#define immediate(ticks)			\
  tick(ticks);					\
  src_ea_msb = src_pc_msb;			\
  ea = PC++;

#define abs(ticks)					\
  tick(ticks);						\
  core->read[PC] = 1;					\
  core->read[PC + 1] = 1;				\
  src_ea_msb = memory[PC + 1].src;			\
  ea = memory[PC].value + (memory[PC + 1].value << 8);	\
  check_reloc_range(ea, memory[PC].src, 0, src_ea_msb);	\
  PC += 2;

#define relative(ticks)				\
  tick(ticks);					\
  core->read[PC] = 1;				\
  dont_reloc(memory[PC].src);			\
  src_ea_msb = src_pc_msb;			\
  ea = memory[PC++].value;			\
  if (ea & 0x80) ea -= 0x100;			\
  tickIf((ea >> 8) != (PC >> 8));

#define indirect(ticks)							\
  tick(ticks);								\
  {									\
    word tmp;								\
    core->read[PC] = 1;							\
    core->read[PC + 1] = 1;						\
    tmp = memory[PC].value + (memory[PC + 1].value << 8);		\
    check_reloc_range(tmp, memory[PC].src, 0, memory[PC + 1].src);	\
    core->read[tmp] = 1;						\
    core->read[tmp + 1] = 1;						\
    src_ea_msb = memory[tmp + 1].src;					\
    ea = memory[tmp].value + (memory[tmp + 1].value << 8);		\
    check_reloc_range(ea, memory[tmp].src, 0, src_ea_msb);		\
    PC += 2;								\
  }

#define absx(ticks)							\
  tick(ticks);								\
  core->read[PC] = 1;							\
  core->read[PC + 1] = 1;						\
  src_ea_msb = memory[PC + 1].src;					\
  ea = memory[PC].value + (memory[PC + 1].value << 8);			\
  tickIf((ticks == 4) && ((ea >> 8) != ((ea + X.value) >> 8)));		\
  ea += X.value;							\
  check_reloc_range(ea, memory[PC].src, X.src, src_ea_msb);		\
  PC += 2;

#define absy(ticks)							\
  tick(ticks);								\
  core->read[PC] = 1;							\
  core->read[PC + 1] = 1;						\
  src_ea_msb = memory[PC + 1].src;					\
  ea = memory[PC].value + (memory[PC + 1].value << 8);			\
  tickIf((ticks == 4) && ((ea >> 8) != ((ea + Y.value) >> 8)));		\
  ea += Y.value;							\
  check_reloc_range(ea, memory[PC].src, Y.src, src_ea_msb);		\
  PC += 2;

#define zp(ticks)					\
  tick(ticks);						\
  core->read[PC] = 1;					\
  src_ea_msb = 0;					\
  ea = memory[PC].value;				\
  used_for_zp_addr(memory[PC].src, 0, ea);		\
  PC++;

#define zpx(ticks)					\
  tick(ticks);						\
  core->read[PC] = 1;					\
  src_ea_msb = 0;					\
  ea = memory[PC].value + X.value;			\
  ea &= 0x00ff;						\
  used_for_zp_addr(memory[PC].src, X.src, ea);		\
  PC++;

#define zpy(ticks)					\
  tick(ticks);						\
  core->read[PC] = 1;					\
  src_ea_msb = 0;					\
  ea = memory[PC].value + Y.value;			\
  ea &= 0x00ff;						\
  used_for_zp_addr(memory[PC].src, Y.src, ea);		\
  PC++;

#define indx(ticks)							\
  tick(ticks);								\
  {									\
    byte tmp = memory[PC].value + X.value;				\
    core->read[PC] = 1;							\
    used_for_zp_addr(memory[PC].src, X.src, tmp);			\
    used_for_zp_addr(memory[PC].src, X.src, tmp + 1);			\
    core->read[tmp] = 1;						\
    core->read[tmp + 1] = 1;						\
    src_ea_msb = memory[tmp + 1].src;					\
    ea = memory[tmp].value + (memory[tmp + 1].value << 8);		\
    check_reloc_range(ea, memory[tmp].src, 0, src_ea_msb);		\
    PC++;								\
  }

#define indy(ticks)							\
  tick(ticks);								\
  {									\
    byte tmp = memory[PC].value;					\
    core->read[PC] = 1;							\
    used_for_zp_addr(memory[PC].src, 0, tmp);				\
    used_for_zp_addr(memory[PC].src, 0, tmp + 1);			\
    PC++;								\
    core->read[tmp] = 1;						\
    core->read[tmp + 1] = 1;						\
    src_ea_msb = memory[tmp + 1].src;					\
    ea = memory[tmp].value + (memory[tmp + 1].value << 8);		\
    tickIf((ticks == 5) && ((ea >> 8) != ((ea + Y.value) >> 8)));	\
    ea += Y.value;							\
    check_reloc_range(ea, memory[tmp].src, Y.src, src_ea_msb);		\
  }

/* insns */

#define adc(ticks, adrmode)											\
  adrmode(ticks);												\
  {														\
    value_t B = getMemory(ea);											\
    if (!getD())												\
      {														\
        struct source *src;											\
	int c = A.value + B.value + getC();									\
	int v = (int8_t) A.value + (int8_t) B.value + getC();							\
	fetch();												\
	A.value = c;												\
	for(src = B.src; src; src = src->next) A.src = cons_src(src->offset, A.src);				\
	setNVZC((A.value & 0x80), (((A.value & 0x80) > 0) ^ (v < 0)), (A.value == 0), ((c & 0x100) > 0));	\
	goto_next();												\
      }														\
    else													\
      {														\
	int l, h, s;												\
	/* inelegant & slow, but consistent with the hw for illegal digits */					\
	l = (A.value & 0x0F) + (B.value & 0x0F) + getC();							\
	h = (A.value & 0xF0) + (B.value & 0xF0);								\
	if (l >= 0x0A) { l -= 0x0A;  h += 0x10; }								\
	if (h >= 0xA0) { h -= 0xA0; }										\
	fetch();												\
	s = h | (l & 0x0F);											\
	/* only C is valid on NMOS 6502 */									\
	setNVZC(s & 0x80, !(((A.value ^ B.value) & 0x80) && ((A.value ^ s) & 0x80)), !s, !!(h & 0x80));		\
	A.value = s;												\
	A.src = 0;												\
	tick(1);												\
	goto_next();												\
      }														\
  }

#define sbc(ticks, adrmode)										\
  adrmode(ticks);											\
  {													\
    value_t B = getMemory(ea);										\
    if (!getD())											\
      {													\
	int b = 1 - (P &0x01);										\
	int c = A.value - B.value - b;									\
	int v = (int8_t) A.value - (int8_t) B.value - b;						\
	fetch();											\
	A.value = c;											\
	setNVZC(A.value & 0x80, ((A.value & 0x80) > 0) ^ ((v & 0x100) != 0), A.value == 0, c >= 0);	\
	goto_next();											\
      }													\
    else												\
      {													\
	/* this is verbatim ADC, with a 10's complemented operand */					\
	int l, h, s;											\
	B.value = 0x99 - B.value;									\
	l = (A.value & 0x0F) + (B.value & 0x0F) + getC();						\
	h = (A.value & 0xF0) + (B.value & 0xF0);							\
	if (l >= 0x0A) { l -= 0x0A;  h += 0x10; }							\
	if (h >= 0xA0) { h -= 0xA0; }									\
	fetch();											\
	s = h | (l & 0x0F);										\
	/* only C is valid on NMOS 6502 */								\
	setNVZC(s & 0x80, !(((A.value ^ B.value) & 0x80) && ((A.value ^ s) & 0x80)), !s, !!(h & 0x80));	\
	A.value = s;											\
	A.src = 0;											\
	tick(1);											\
	goto_next();											\
      }													\
  }

#define cmpR(ticks, adrmode, R)			\
  adrmode(ticks);				\
  fetch();					\
  {						\
    value_t B = getMemory(ea);			\
    byte d = R.value - B.value;			\
    reloc_alike(B, R);				\
    setNZC(d & 0x80, !d, R.value >= B.value);	\
  }						\
  goto_next();

#define cmp(ticks, adrmode)	cmpR(ticks, adrmode, A)
#define cpx(ticks, adrmode)	cmpR(ticks, adrmode, X)
#define cpy(ticks, adrmode)	cmpR(ticks, adrmode, Y)

#define dec(ticks, adrmode)			\
  adrmode(ticks);				\
  fetch();					\
  {						\
    value_t B = getMemory(ea);			\
    --B.value;					\
    putMemory(ea, B);				\
    setNZ(B.value & 0x80, !B.value);		\
  }						\
  goto_next();

#define decR(ticks, adrmode, R)			\
  fetch();					\
  tick(ticks);					\
  --R.value;					\
  setNZ(R.value & 0x80, !R.value);		\
  goto_next();

#define dex(ticks, adrmode)	decR(ticks, adrmode, X)
#define dey(ticks, adrmode)	decR(ticks, adrmode, Y)

#define inc(ticks, adrmode)			\
  adrmode(ticks);				\
  fetch();					\
  {						\
    value_t B = getMemory(ea);			\
    ++B.value;					\
    putMemory(ea, B);				\
    setNZ(B.value & 0x80, !B.value);		\
  }						\
  goto_next();

#define incR(ticks, adrmode, R)			\
  fetch();					\
  tick(ticks);					\
  ++R.value;					\
  setNZ(R.value & 0x80, !R.value);		\
  goto_next();

#define inx(ticks, adrmode)	incR(ticks, adrmode, X)
#define iny(ticks, adrmode)	incR(ticks, adrmode, Y)

#define bit(ticks, adrmode)					\
  adrmode(ticks);						\
  fetch();							\
  {								\
    value_t B = getMemory(ea);					\
    P = (P & ~(flagN | flagV | flagZ))				\
      | (B.value & (0xC0)) | (((A.value & B.value) == 0) << 1);	\
  }								\
  goto_next();

#define eor(ticks, adrmode)			\
  adrmode(ticks);				\
  fetch();					\
  {						\
    value_t b = getMemory(ea);			\
    reloc_alike(A, b);				\
    A.value ^= b.value;				\
    A.src = 0;					\
  }						\
  setNZ(A.value & 0x80, !A.value);		\
  goto_next();

#define bitwise(ticks, adrmode, op)		\
  adrmode(ticks);				\
  fetch();					\
  {						\
    value_t b = getMemory(ea);			\
    A.value op##= b.value;			\
    A.src = 0;					\
  }						\
  setNZ(A.value & 0x80, !A.value);		\
  goto_next();

#define and(ticks, adrmode)	bitwise(ticks, adrmode, &)
#define ora(ticks, adrmode)	bitwise(ticks, adrmode, |)

#define asl(ticks, adrmode)			\
  adrmode(ticks);				\
  {						\
    value_t b = getMemory(ea);			\
    unsigned int i = b.value << 1;		\
    b.value = i;				\
    b.src = 0;					\
    putMemory(ea, b);				\
    fetch();					\
    setNZC(i & 0x80, !i, i >> 8);		\
  }						\
  goto_next();

#define asla(ticks, adrmode)			\
  tick(ticks);					\
  fetch();					\
  {						\
    int c = A.value >> 7;			\
    A.value <<= 1;				\
    A.src = 0;					\
    setNZC(A.value & 0x80, !A.value, c);	\
  }						\
  goto_next();

#define lsr(ticks, adrmode)			\
  adrmode(ticks);				\
  {						\
    value_t b = getMemory(ea);			\
    int c= b.value & 1;				\
    fetch();					\
    b.value >>= 1;				\
    b.src = 0;					\
    putMemory(ea, b);				\
    setNZC(0, !b.value, c);			\
  }						\
  goto_next();

#define lsra(ticks, adrmode)			\
  tick(ticks);					\
  fetch();					\
  {						\
    int c = A.value & 1;			\
    A.value >>= 1;				\
    A.src = 0;					\
    setNZC(0, !A.value, c);			\
  }						\
  goto_next();

#define rol(ticks, adrmode)			\
  adrmode(ticks);				\
  {						\
    value_t v = getMemory(ea);			\
    word b = (v.value << 1) | getC();		\
    v.value = b;				\
    v.src = 0;					\
    fetch();					\
    putMemory(ea, v);				\
    setNZC(b & 0x80, !(b & 0xFF), b >> 8);	\
  }						\
  goto_next();

#define rola(ticks, adrmode)			\
  tick(ticks);					\
  fetch();					\
  {						\
    word b = (A.value << 1) | getC();		\
    A.value = b;				\
    A.src = 0;					\
    setNZC(A.value & 0x80, !A.value, b >> 8);	\
  }						\
  goto_next();

#define ror(ticks, adrmode)			\
  adrmode(ticks);				\
  {						\
    int c = getC();				\
    value_t m = getMemory(ea);			\
    value_t n;					\
    byte b = (c << 7) | (m.value >> 1);		\
    fetch();					\
    n.value = b;				\
    n.src = 0;					\
    putMemory(ea, n);				\
    setNZC(b & 0x80, !b, m.value & 1);		\
  }						\
  goto_next();

#define rora(ticks, adrmode)			\
  adrmode(ticks);				\
  {						\
    int ci = getC();				\
    int co = A.value & 1;			\
    fetch();					\
    A.value = (ci << 7) | (A.value >> 1);	\
    A.src = 0;					\
    setNZC(A.value & 0x80, !A.value, co);	\
  }						\
  goto_next();

#define tRS(ticks, adrmode, R1, R2)		\
  fetch();					\
  tick(ticks);					\
  R2 = R1;					\
  setNZ(R2.value & 0x80, !R1.value);		\
  goto_next();

#define tax(ticks, adrmode)	tRS(ticks, adrmode, A, X)
#define txa(ticks, adrmode)	tRS(ticks, adrmode, X, A)
#define tay(ticks, adrmode)	tRS(ticks, adrmode, A, Y)
#define tya(ticks, adrmode)	tRS(ticks, adrmode, Y, A)

#define tsx(ticks, adrmode)			\
  fetch();					\
  tick(ticks);					\
  X.value = S;					\
  X.src = 0;					\
  setNZ(S & 0x80, !S);				\
  goto_next();

#define txs(ticks, adrmode)			\
  fetch();					\
  tick(ticks);					\
  dont_reloc(X.src);				\
  S = X.value;					\
  goto_next();

#define ldR(ticks, adrmode, R)			\
  adrmode(ticks);				\
  fetch();					\
  R = getMemory(ea);				\
  setNZ(R.value & 0x80, !R.value);		\
  goto_next();

#define lda(ticks, adrmode)	ldR(ticks, adrmode, A)
#define ldx(ticks, adrmode)	ldR(ticks, adrmode, X)
#define ldy(ticks, adrmode)	ldR(ticks, adrmode, Y)

#define stR(ticks, adrmode, R)			\
  adrmode(ticks);				\
  fetch();					\
  putMemory(ea, R);				\
  goto_next();

#define sta(ticks, adrmode)	stR(ticks, adrmode, A)
#define stx(ticks, adrmode)	stR(ticks, adrmode, X)
#define sty(ticks, adrmode)	stR(ticks, adrmode, Y)

#define branch(ticks, adrmode, cond)		\
  if (cond)					\
    {						\
      adrmode(ticks);				\
      PC += ea;					\
      tick(1);					\
    }						\
  else						\
    {						\
      tick(ticks);				\
      PC++;					\
    }						\
  fetch();					\
  goto_next();

#define bcc(ticks, adrmode)	branch(ticks, adrmode, !getC())
#define bcs(ticks, adrmode)	branch(ticks, adrmode,  getC())
#define bne(ticks, adrmode)	branch(ticks, adrmode, !getZ())
#define beq(ticks, adrmode)	branch(ticks, adrmode,  getZ())
#define bpl(ticks, adrmode)	branch(ticks, adrmode, !getN())
#define bmi(ticks, adrmode)	branch(ticks, adrmode,  getN())
#define bvc(ticks, adrmode)	branch(ticks, adrmode, !getV())
#define bvs(ticks, adrmode)	branch(ticks, adrmode,  getV())

#define jmp(ticks, adrmode)			\
  adrmode(ticks);				\
  PC = ea;					\
  src_pc_msb = src_ea_msb;			\
  fetch();					\
  goto_next();

#define jsr(ticks, adrmode)			\
  PC++;						\
  {						\
    value_t v;					\
    v.src = src_pc_msb;				\
    v.value = PC >> 8;				\
    push(v);					\
    v.src = 0;					\
    v.value = PC & 0xff;			\
    push(v);					\
  }						\
  PC--;						\
  adrmode(ticks);				\
  PC = ea;					\
  src_pc_msb = src_ea_msb;			\
  fetch();					\
  goto_next();

#define rts(ticks, adrmode)				\
  tick(ticks);						\
  if(S >= 0xfe) return ERR_OK;				\
  {							\
    value_t lsb = pop();				\
    value_t msb = pop();				\
    PC = lsb.value | (msb.value << 8);			\
    src_pc_msb = msb.src;				\
    check_reloc_range(PC, lsb.src, 0, msb.src);		\
  }							\
  PC++;							\
  fetch();						\
  goto_next();

#define brk(ticks, adrmode)			\
  tick(ticks);					\
  return ERR_BRK;

#define rti(ticks, adrmode)				\
  tick(ticks);						\
  if(S >= 0xfd) return ERR_OK;				\
  {							\
    value_t status = pop();				\
    value_t lsb = pop();				\
    value_t msb = pop();				\
    P = status.value;					\
    PC = lsb.value | (msb.value << 8);			\
    src_pc_msb = msb.src;				\
    dont_reloc(status.src);				\
    check_reloc_range(PC, lsb.src, 0, msb.src);		\
  }							\
  fetch();						\
  goto_next();

#define nop(ticks, adrmode)			\
  adrmode(ticks);				\
  fetch();					\
  goto_next();

#define ill(ticks, adrmode)			\
  goto illegal_instr;

#define pha(ticks, adrmode)			\
  fetch();					\
  tick(ticks);					\
  push(A);					\
  goto_next();

#define php(ticks, adrmode)			\
  fetch();					\
  tick(ticks);					\
  {						\
    value_t v;					\
    v.value = P;				\
    v.src = 0;					\
    push(v);					\
  }						\
  goto_next();

#define pla(ticks, adrmode)			\
  fetch();					\
  tick(ticks);					\
  if(S >= 0xff) return ERR_OK;			\
  A = pop();					\
  setNZ(A.value & 0x80, !A.value);		\
  goto_next();

#define plp(ticks, adrmode)			\
  fetch();					\
  tick(ticks);					\
  if(S >= 0xff) return ERR_OK;			\
  {						\
    value_t v = pop();				\
    dont_reloc(v.src);				\
    P = v.value;				\
  }						\
  goto_next();

#define clF(ticks, adrmode, F)			\
  fetch();					\
  tick(ticks);					\
  P &= ~F;					\
  goto_next();

#define clc(ticks, adrmode)	clF(ticks, adrmode, flagC)
#define cld(ticks, adrmode)	clF(ticks, adrmode, flagD)
#define cli(ticks, adrmode)	clF(ticks, adrmode, flagI)
#define clv(ticks, adrmode)	clF(ticks, adrmode, flagV)

#define seF(ticks, adrmode, F)			\
  fetch();					\
  tick(ticks);					\
  P |= F;					\
  goto_next();

#define sec(ticks, adrmode)	seF(ticks, adrmode, flagC)
#define sed(ticks, adrmode)	seF(ticks, adrmode, flagD)
#define sei(ticks, adrmode)	seF(ticks, adrmode, flagI)

/* Beware! Instruction timing is wrong for the undocumented nops. */

#define do_insns(_)												\
  _(00, brk, implied,   7);  _(01, ora, indx,      6);  _(02, ill, implied,   2);  _(03, ill, implied, 2);      \
  _(04, nop, zp,        3);  _(05, ora, zp,        3);  _(06, asl, zp,        5);  _(07, ill, implied, 2);      \
  _(08, php, implied,   3);  _(09, ora, immediate, 3);  _(0a, asla,implied,   2);  _(0b, ill, implied, 2);      \
  _(0c, nop, abs,       4);  _(0d, ora, abs,       4);  _(0e, asl, abs,       6);  _(0f, ill, implied, 2);      \
  _(10, bpl, relative,  2);  _(11, ora, indy,      5);  _(12, ill, implied,   3);  _(13, ill, implied, 2);      \
  _(14, nop, zpx,       3);  _(15, ora, zpx,       4);  _(16, asl, zpx,       6);  _(17, ill, implied, 2);      \
  _(18, clc, implied,   2);  _(19, ora, absy,      4);  _(1a, nop, implied,   2);  _(1b, ill, implied, 2);      \
  _(1c, nop, absx,      4);  _(1d, ora, absx,      4);  _(1e, asl, absx,      7);  _(1f, ill, implied, 2);      \
  _(20, jsr, abs,       6);  _(21, and, indx,      6);  _(22, ill, implied,   2);  _(23, ill, implied, 2);      \
  _(24, bit, zp,        3);  _(25, and, zp,        3);  _(26, rol, zp,        5);  _(27, ill, implied, 2);      \
  _(28, plp, implied,   4);  _(29, and, immediate, 3);  _(2a, rola,implied,   2);  _(2b, ill, implied, 2);      \
  _(2c, bit, abs,       4);  _(2d, and, abs,       4);  _(2e, rol, abs,       6);  _(2f, ill, implied, 2);      \
  _(30, bmi, relative,  2);  _(31, and, indy,      5);  _(32, ill, implied,   3);  _(33, ill, implied, 2);      \
  _(34, nop, zpx,       4);  _(35, and, zpx,       4);  _(36, rol, zpx,       6);  _(37, ill, implied, 2);      \
  _(38, sec, implied,   2);  _(39, and, absy,      4);  _(3a, nop, implied,   2);  _(3b, ill, implied, 2);      \
  _(3c, nop, absx,      4);  _(3d, and, absx,      4);  _(3e, rol, absx,      7);  _(3f, ill, implied, 2);      \
  _(40, rti, implied,   6);  _(41, eor, indx,      6);  _(42, ill, implied,   2);  _(43, ill, implied, 2);      \
  _(44, nop, zp,        2);  _(45, eor, zp,        3);  _(46, lsr, zp,        5);  _(47, ill, implied, 2);      \
  _(48, pha, implied,   3);  _(49, eor, immediate, 3);  _(4a, lsra,implied,   2);  _(4b, ill, implied, 2);      \
  _(4c, jmp, abs,       3);  _(4d, eor, abs,       4);  _(4e, lsr, abs,       6);  _(4f, ill, implied, 2);      \
  _(50, bvc, relative,  2);  _(51, eor, indy,      5);  _(52, ill, implied,   3);  _(53, ill, implied, 2);      \
  _(54, nop, zpx,       2);  _(55, eor, zpx,       4);  _(56, lsr, zpx,       6);  _(57, ill, implied, 2);      \
  _(58, cli, implied,   2);  _(59, eor, absy,      4);  _(5a, nop, implied,   3);  _(5b, ill, implied, 2);      \
  _(5c, nop, absx,      2);  _(5d, eor, absx,      4);  _(5e, lsr, absx,      7);  _(5f, ill, implied, 2);      \
  _(60, rts, implied,   6);  _(61, adc, indx,      6);  _(62, ill, implied,   2);  _(63, ill, implied, 2);      \
  _(64, nop, zp,        3);  _(65, adc, zp,        3);  _(66, ror, zp,        5);  _(67, ill, implied, 2);      \
  _(68, pla, implied,   4);  _(69, adc, immediate, 3);  _(6a, rora,implied,   2);  _(6b, ill, implied, 2);      \
  _(6c, jmp, indirect,  5);  _(6d, adc, abs,       4);  _(6e, ror, abs,       6);  _(6f, ill, implied, 2);      \
  _(70, bvs, relative,  2);  _(71, adc, indy,      5);  _(72, ill, implied,   3);  _(73, ill, implied, 2);      \
  _(74, nop, zpx,       4);  _(75, adc, zpx,       4);  _(76, ror, zpx,       6);  _(77, ill, implied, 2);      \
  _(78, sei, implied,   2);  _(79, adc, absy,      4);  _(7a, nop, implied,   4);  _(7b, ill, implied, 2);      \
  _(7c, nop, absx,      6);  _(7d, adc, absx,      4);  _(7e, ror, absx,      7);  _(7f, ill, implied, 2);      \
  _(80, nop, immediate, 2);  _(81, sta, indx,      6);  _(82, nop, immediate, 2);  _(83, ill, implied, 2);      \
  _(84, sty, zp,        2);  _(85, sta, zp,        2);  _(86, stx, zp,        2);  _(87, ill, implied, 2);      \
  _(88, dey, implied,   2);  _(89, nop, immediate, 2);  _(8a, txa, implied,   2);  _(8b, ill, implied, 2);      \
  _(8c, sty, abs,       4);  _(8d, sta, abs,       4);  _(8e, stx, abs,       4);  _(8f, ill, implied, 2);      \
  _(90, bcc, relative,  2);  _(91, sta, indy,      6);  _(92, ill, implied,   3);  _(93, ill, implied, 2);      \
  _(94, sty, zpx,       4);  _(95, sta, zpx,       4);  _(96, stx, zpy,       4);  _(97, ill, implied, 2);      \
  _(98, tya, implied,   2);  _(99, sta, absy,      5);  _(9a, txs, implied,   2);  _(9b, ill, implied, 2);      \
  _(9c, ill, implied,   4);  _(9d, sta, absx,      5);  _(9e, ill, implied,   5);  _(9f, ill, implied, 2);      \
  _(a0, ldy, immediate, 3);  _(a1, lda, indx,      6);  _(a2, ldx, immediate, 3);  _(a3, ill, implied, 2);      \
  _(a4, ldy, zp,        3);  _(a5, lda, zp,        3);  _(a6, ldx, zp,        3);  _(a7, ill, implied, 2);      \
  _(a8, tay, implied,   2);  _(a9, lda, immediate, 3);  _(aa, tax, implied,   2);  _(ab, ill, implied, 2);      \
  _(ac, ldy, abs,       4);  _(ad, lda, abs,       4);  _(ae, ldx, abs,       4);  _(af, ill, implied, 2);      \
  _(b0, bcs, relative,  2);  _(b1, lda, indy,      5);  _(b2, ill, implied,   3);  _(b3, ill, implied, 2);      \
  _(b4, ldy, zpx,       4);  _(b5, lda, zpx,       4);  _(b6, ldx, zpy,       4);  _(b7, ill, implied, 2);      \
  _(b8, clv, implied,   2);  _(b9, lda, absy,      4);  _(ba, tsx, implied,   2);  _(bb, ill, implied, 2);      \
  _(bc, ldy, absx,      4);  _(bd, lda, absx,      4);  _(be, ldx, absy,      4);  _(bf, ill, implied, 2);      \
  _(c0, cpy, immediate, 3);  _(c1, cmp, indx,      6);  _(c2, nop, immediate, 2);  _(c3, ill, implied, 2);      \
  _(c4, cpy, zp,        3);  _(c5, cmp, zp,        3);  _(c6, dec, zp,        5);  _(c7, ill, implied, 2);      \
  _(c8, iny, implied,   2);  _(c9, cmp, immediate, 3);  _(ca, dex, implied,   2);  _(cb, ill, implied, 2);      \
  _(cc, cpy, abs,       4);  _(cd, cmp, abs,       4);  _(ce, dec, abs,       6);  _(cf, ill, implied, 2);      \
  _(d0, bne, relative,  2);  _(d1, cmp, indy,      5);  _(d2, ill, implied,   3);  _(d3, ill, implied, 2);      \
  _(d4, nop, zpx,       2);  _(d5, cmp, zpx,       4);  _(d6, dec, zpx,       6);  _(d7, ill, implied, 2);      \
  _(d8, cld, implied,   2);  _(d9, cmp, absy,      4);  _(da, nop, implied,   3);  _(db, ill, implied, 2);      \
  _(dc, nop, absx,      2);  _(dd, cmp, absx,      4);  _(de, dec, absx,      7);  _(df, ill, implied, 2);      \
  _(e0, cpx, immediate, 3);  _(e1, sbc, indx,      6);  _(e2, nop, immediate, 2);  _(e3, ill, implied, 2);      \
  _(e4, cpx, zp,        3);  _(e5, sbc, zp,        3);  _(e6, inc, zp,        5);  _(e7, ill, implied, 2);      \
  _(e8, inx, implied,   2);  _(e9, sbc, immediate, 3);  _(ea, nop, implied,   2);  _(eb, ill, implied, 2);      \
  _(ec, cpx, abs,       4);  _(ed, sbc, abs,       4);  _(ee, inc, abs,       6);  _(ef, ill, implied, 2);      \
  _(f0, beq, relative,  2);  _(f1, sbc, indy,      5);  _(f2, ill, implied,   3);  _(f3, ill, implied, 2);      \
  _(f4, nop, zpx,       2);  _(f5, sbc, zpx,       4);  _(f6, inc, zpx,       6);  _(f7, ill, implied, 2);      \
  _(f8, sed, implied,   2);  _(f9, sbc, absy,      4);  _(fa, nop, implied,   4);  _(fb, ill, implied, 2);      \
  _(fc, nop, absx,      2);  _(fd, sbc, absx,      4);  _(fe, inc, absx,      7);  _(ff, ill, implied, 2);

static int emulate(struct core *core, uint16_t start_addr, uint8_t acc, int max_cycles)
{
	static void *itab[256] = {
		&&_00, &&_01, &&_02, &&_03, &&_04, &&_05, &&_06, &&_07, &&_08, &&_09, &&_0a, &&_0b, &&_0c, &&_0d, &&_0e, &&_0f,
		&&_10, &&_11, &&_12, &&_13, &&_14, &&_15, &&_16, &&_17, &&_18, &&_19, &&_1a, &&_1b, &&_1c, &&_1d, &&_1e, &&_1f,
		&&_20, &&_21, &&_22, &&_23, &&_24, &&_25, &&_26, &&_27, &&_28, &&_29, &&_2a, &&_2b, &&_2c, &&_2d, &&_2e, &&_2f,
		&&_30, &&_31, &&_32, &&_33, &&_34, &&_35, &&_36, &&_37, &&_38, &&_39, &&_3a, &&_3b, &&_3c, &&_3d, &&_3e, &&_3f,
		&&_40, &&_41, &&_42, &&_43, &&_44, &&_45, &&_46, &&_47, &&_48, &&_49, &&_4a, &&_4b, &&_4c, &&_4d, &&_4e, &&_4f,
		&&_50, &&_51, &&_52, &&_53, &&_54, &&_55, &&_56, &&_57, &&_58, &&_59, &&_5a, &&_5b, &&_5c, &&_5d, &&_5e, &&_5f,
		&&_60, &&_61, &&_62, &&_63, &&_64, &&_65, &&_66, &&_67, &&_68, &&_69, &&_6a, &&_6b, &&_6c, &&_6d, &&_6e, &&_6f,
		&&_70, &&_71, &&_72, &&_73, &&_74, &&_75, &&_76, &&_77, &&_78, &&_79, &&_7a, &&_7b, &&_7c, &&_7d, &&_7e, &&_7f,
		&&_80, &&_81, &&_82, &&_83, &&_84, &&_85, &&_86, &&_87, &&_88, &&_89, &&_8a, &&_8b, &&_8c, &&_8d, &&_8e, &&_8f,
		&&_90, &&_91, &&_92, &&_93, &&_94, &&_95, &&_96, &&_97, &&_98, &&_99, &&_9a, &&_9b, &&_9c, &&_9d, &&_9e, &&_9f,
		&&_a0, &&_a1, &&_a2, &&_a3, &&_a4, &&_a5, &&_a6, &&_a7, &&_a8, &&_a9, &&_aa, &&_ab, &&_ac, &&_ad, &&_ae, &&_af,
		&&_b0, &&_b1, &&_b2, &&_b3, &&_b4, &&_b5, &&_b6, &&_b7, &&_b8, &&_b9, &&_ba, &&_bb, &&_bc, &&_bd, &&_be, &&_bf,
		&&_c0, &&_c1, &&_c2, &&_c3, &&_c4, &&_c5, &&_c6, &&_c7, &&_c8, &&_c9, &&_ca, &&_cb, &&_cc, &&_cd, &&_ce, &&_cf,
		&&_d0, &&_d1, &&_d2, &&_d3, &&_d4, &&_d5, &&_d6, &&_d7, &&_d8, &&_d9, &&_da, &&_db, &&_dc, &&_dd, &&_de, &&_df,
		&&_e0, &&_e1, &&_e2, &&_e3, &&_e4, &&_e5, &&_e6, &&_e7, &&_e8, &&_e9, &&_ea, &&_eb, &&_ec, &&_ed, &&_ee, &&_ef,
		&&_f0, &&_f1, &&_f2, &&_f3, &&_f4, &&_f5, &&_f6, &&_f7, &&_f8, &&_f9, &&_fa, &&_fb, &&_fc, &&_fd, &&_fe, &&_ff
	};

	value_t	*memory = core->memory;

	void	**itabp = itab;
	void	*tpc;

#if 0
#define dump()	if(dump_enabled) fprintf(stderr, "pc=%04x op=%02x\n", PC, v.value)
#else
#define dump()
#endif

# define fetch()	{ value_t v = memory[PC]; core->read[PC] = 1; dump(); PC++; dont_reloc(v.src); opcode = v.value; tpc = itabp[opcode]; }
# define goto_next()				goto *tpc
# define dispatch(num, name, mode, cycles)	_##num: name(cycles, mode) return ERR_INTERNAL;

	word	PC;
	word	ea;
	value_t	A, X, Y;
	byte	P, S;
	byte	opcode;

	struct source *src_pc_msb = cons_src(1, 0);
	struct source *src_ea_msb;

	PC = start_addr;
	A.value = acc;
	A.src = 0;
	X.value = 0;
	X.src = 0;
	Y.value = 0;
	Y.src = 0;
	P = 0;
	S = 0xff;

	fetch();
	goto_next();

	do_insns(dispatch);

illegal_instr:
	// fprintf(stderr, "Illegal opcode: $%02x (PC = $%04x)\n", opcode, PC);
	return ERR_ILLEGAL;
}

/////////////////////////////////////////////////////////////////////////////
//// solver.c
/////////////////////////////////////////////////////////////////////////////

/* Copyright (c) 2012 Linus Akesson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#define HASHSIZE 8192

#define C_EXACTLY_ONE	1
#define C_ALIKE		2

struct constraint {
	uint8_t			check_needed;
	uint8_t			kind;
	uint16_t		n1, n2;
	uint16_t		vars[];
};

struct constraintlist {
	struct constraintlist	*next;
	struct constraint	*c;
};

// static struct progbyte *progbytes;
// static int progsize;
static uint16_t progbyte_org;

// static int add_constraints;

static struct constraintlist *hashconstr[HASHSIZE], *zpconstr[0x100];

#define ARENASIZE	32768
static struct arena {
	struct arena	*next;
	struct source	data[ARENASIZE];
} *arena;
static int arena_index = ARENASIZE;

static struct source prealloc[0x10000];

static int cmp_offset(const void *avoid, const void *bvoid) {
	const uint16_t *a = (const uint16_t *) avoid;
	const uint16_t *b = (const uint16_t *) bvoid;
	return *a - *b;
}

static void print_constraint(struct constraint *constr) {
	int i;

	if(constr->kind == C_EXACTLY_ONE) {
		fprintf(stderr, "Exactly one reloc: {");
		for(i = 0; i < constr->n1; i++) {
			fprintf(stderr, "%s$%04x", (i? ", " : ""), constr->vars[i] + progbyte_org);
		}
		fprintf(stderr, "}\n");
	} else if(constr->kind == C_ALIKE) {
		fprintf(stderr, "Reloc alike: {");
		for(i = 0; i < constr->n1; i++) {
			fprintf(stderr, "%s$%04x", (i? ", " : ""), constr->vars[i] + progbyte_org);
		}
		fprintf(stderr, "}, {");
		for(i = 0; i < constr->n2; i++) {
			fprintf(stderr, "%s$%04x", (i? ", " : ""), constr->vars[constr->n1 + i] + progbyte_org);
		}
		fprintf(stderr, "}\n");
	} else {
		fprintf(stderr, "Unknown constraint!\n");
	}
}

static void add_constraint_ref(uint16_t offset, struct constraint *c) {
	struct progbyte *pb = &progbytes[offset];
	struct constraintlist *cl = malloc(sizeof(struct constraintlist));

	cl->c = c;
	cl->next = pb->constr;
	pb->constr = cl;
}

static int constrainthash(struct constraint *c) {
	int i, h = 0;

	for(i = 0; i < c->n1 + c->n2; i++) {
		h += c->vars[i];
		h %= HASHSIZE;
	}
	return h;
}

static void add_or_free_constraint(struct constraintlist **list, struct constraint *constr) {
	struct constraintlist *cl;
	int for_real = 0;
	int h;

	if(constr->n1 > 1) qsort(constr->vars, constr->n1, sizeof(uint16_t), cmp_offset);
	if(constr->n2 > 1) qsort(constr->vars + constr->n1, constr->n2, sizeof(uint16_t), cmp_offset);

	if(!list) {
		h = constrainthash(constr);
		list = &hashconstr[h];
		for_real = 1;
	}

	for(cl = *list; cl; cl = cl->next) {
		if(cl->c->kind == constr->kind
		&& cl->c->n1 == constr->n1
		&& cl->c->n2 == constr->n2) {
			if(!memcmp(
				cl->c,
				constr,
				sizeof(struct constraint) + sizeof(uint16_t) * (constr->n1 + constr->n2)))
			{
				free(constr);
				return;
			}
		}
	}

	if(for_real && verbose >= 2) {
		fprintf(stderr, "Adding constraint: ");
		print_constraint(constr);
	}

	cl = malloc(sizeof(struct constraintlist));
	cl->c = constr;
	cl->next = *list;
	*list = cl;
}

static void finalise_constraints(struct core *core) {
	int i, zp, h;
	struct constraintlist *cl, *nextcl;
	struct constraint *constr;

	for(zp = 0; zp < 0x100; zp++) {
		if(core->written[zp]) {
			for(cl = zpconstr[zp]; cl; cl = nextcl) {
				nextcl = cl->next;
				add_or_free_constraint(0, cl->c);
				free(cl);
			}
		} else {
			for(cl = zpconstr[zp]; cl; cl = nextcl) {
				nextcl = cl->next;
				free(cl->c);
				free(cl);
			}
		}
	}

	for(h = 0; h < HASHSIZE; h++) {
		for(cl = hashconstr[h]; cl; cl = cl->next) {
			constr = cl->c;
			for(i = 0; i < constr->n1 + constr->n2; i++) {
				add_constraint_ref(constr->vars[i], constr);
			}
		}
	}
}

static int enforce_dont(uint16_t offset) {
	struct constraintlist *cl;

	if(progbytes[offset].flags & PBF_RELOC) {
		return 1;
	} else if(!(progbytes[offset].flags & PBF_DONT_RELOC)) {
		progbytes[offset].flags |= PBF_DONT_RELOC;
		for(cl = progbytes[offset].constr; cl; cl = cl->next) {
			cl->c->check_needed = 1;
		}
	}
	return 0;
}

static int enforce_do(uint16_t offset) {
	struct constraintlist *cl;

	if(progbytes[offset].flags & PBF_DONT_RELOC) {
		return 1;
	} else if(!(progbytes[offset].flags & PBF_RELOC)) {
		progbytes[offset].flags |= PBF_RELOC;
		for(cl = progbytes[offset].constr; cl; cl = cl->next) {
			cl->c->check_needed = 1;
		}
	}
	return 0;
}

static int propagate(struct constraint *c) {
	c->check_needed = 0;

	if(c->kind == C_EXACTLY_ONE) {
		int i, n_do = 0, n_dont = 0, n_unknown = 0;
		int last_do = 0, last_unknown = 0;

		for(i = 0; i < c->n1; i++) {
			struct progbyte *pb = &progbytes[c->vars[i]];

			if(pb->flags & PBF_RELOC) {
				n_do++;
				last_do = i;
			} else if(pb->flags & PBF_DONT_RELOC) {
				n_dont++;
			} else {
				n_unknown++;
				last_unknown = i;
			}
		}

		if(n_do == 1) {
			for(i = 0; i < c->n1; i++) {
				if(i != last_do) {
					if(enforce_dont(c->vars[i])) return 1;
				}
			}
			return 0;
		} else if(n_do > 1) {
			return 1;
		} else {
			// n_do == 0, exactly one of the unknown vars must be reloced
			if(n_unknown == 0) {
				return 1;
			} else if(n_unknown == 1) {
				return enforce_do(c->vars[last_unknown]);
			} else {
				// We cannot propagate; leave the rest to search.
				return 0;
			}
		}
	} else if(c->kind == C_ALIKE) {
		int i, n1_do = 0, n2_do = 0;

		for(i = 0; i < c->n1; i++) {
			struct progbyte *pb = &progbytes[c->vars[i]];

			if(pb->flags & PBF_RELOC) {
				n1_do++;
			}
		}

		for(i = 0; i < c->n2; i++) {
			struct progbyte *pb = &progbytes[c->vars[i]];

			if(pb->flags & PBF_RELOC) {
				n2_do++;
			}
		}

		if(n1_do > 1 || n2_do > 1) return 1;
		return n1_do != n2_do;
	} else {
		return 1;
	}
}

static int trivially_inconsistent() {
	int i;

	for(i = 0; i < progsize + 2; i++) {
		struct progbyte *pb = &progbytes[i];

		if((pb->flags & (PBF_USED_IN_ZP | PBF_USED_IN_MSB)) == (PBF_USED_IN_ZP | PBF_USED_IN_MSB)) {
			// If a byte contributes to both a zero-page address and an msb, it cannot
			// be relocatable.
			pb->flags |= PBF_DONT_RELOC;
		}

		if((pb->flags & (PBF_RELOC | PBF_DONT_RELOC)) == (PBF_RELOC | PBF_DONT_RELOC)) {
			fprintf(stderr,
				"Inconsistency detected! Byte at $%04x can't be both relocated and not relocated at the same time.\n",
				i + progbyte_org);
			return 1;
		}
	}

	return 0;
}

static int solver() {
	struct constraintlist *cl;
	struct constraint *c;
	int done;
	int h, i, j;
	struct progbyte *pb = 0;
	int pboffs = 0;

	/* Propagate. */

	do {
		done = 1;
		for(h = 0; h < HASHSIZE; h++) {
			for(cl = hashconstr[h]; cl; cl = cl->next) {
				c = cl->c;
				if(c->check_needed) {
					done = 0;
					if(propagate(c)) return 1;
				}
			}
		}
	} while(!done);

	/* Search -- select a variable */

	for(h = 0; h < HASHSIZE && !pb; h++) {
		for(cl = hashconstr[h]; cl && !pb; cl = cl->next) {
			c = cl->c;
			for(i = 0; i < c->n1 + c->n2; i++) {
				if(!(progbytes[c->vars[i]].flags & (PBF_RELOC | PBF_DONT_RELOC))) {
					pboffs = c->vars[i];
					pb = &progbytes[pboffs];
					break;
				}
			}
		}
	}

	if(pb) {
		/* Search -- select a value */

		int btsize = progsize + 2;
		uint8_t *backtrack = malloc(btsize);

		for(j = 0; j < btsize; j++) {
			backtrack[j] = progbytes[j].flags;
		}

		if(verbose >= 2) {
			fprintf(stderr,
				"Guessing that $%04x should not be relocated.\n",
				pboffs + progbyte_org);
		}

		if(enforce_dont(pboffs) || solver()) {
			if(verbose >= 2) {
				fprintf(stderr, "Backtracking.\n");
			}
			for(j = 0; j < btsize; j++) {
				progbytes[j].flags = backtrack[j];
			}
			free(backtrack);
			if(verbose >= 2) {
				fprintf(stderr,
					"Assuming that $%04x should be relocated.\n",
					pboffs + progbyte_org);
			}
			return enforce_do(pboffs) || solver();
		} else {
			free(backtrack);
			return 0;
		}
	} else return 0;
}

/* Fast routines that are called during analysis (emulation). Contradictions are not
 * checked at this stage. */

#if 0
void dont_reloc_at(uint16_t offset) {
	assert(offset < progsize + 2);
	progbytes[offset].flags |= PBF_DONT_RELOC;
}

void dont_reloc(struct source *src) {
	if(add_constraints) {
		while(src) {
			dont_reloc_at(src->offset);
			assert(src);
			src = src->next;
		}
	}
}
#endif

static void do_reloc_at(uint16_t offset) {
	progbytes[offset].flags |= PBF_RELOC;
}

static void progbyte_for_zp(uint16_t offset, uint8_t zpaddr) {
	progbytes[offset].flags |= PBF_USED_IN_ZP;
	progbytes[offset].zpaddr[zpaddr >> 3] |= 1 << (zpaddr & 7);
}

static void progbyte_for_msb(uint16_t offset) {
	progbytes[offset].flags |= PBF_USED_IN_MSB;
}

static void prealloc_cons_cells() {
	int i;

	for(i = 0; i < 0x10000; i++) {
		prealloc[i].offset = i;
		prealloc[i].next = 0;
	}
}

static struct source *cons_src(uint16_t offset, struct source *cdr) {
	struct source *s;

	if(add_constraints) {
		if(progbytes[offset].flags & PBF_DONT_RELOC) {
			// This progbyte can't possibly be relocatable, so
			// there's no need to add it to the list.
			return cdr;
		}

		if(!cdr) {
			return &prealloc[offset];
		}

		for(s = cdr; s; s = s->next) {
			if(s->offset == offset) {
				for(s = s->next; s; s = s->next) {
					if(s->offset == offset) {
						// No need to add the same program byte more
						// than twice to a list.
						return cdr;
					}
				}
				break;
			}
		}

		if(arena_index >= ARENASIZE) {
			struct arena *a = calloc(sizeof(struct arena), 1);
			a->next = arena;
			arena = a;
			arena_index = 0;
		}
		s = &arena->data[arena_index++];

		s->offset = offset;
		s->next = cdr;
		return s;
	} else {
		return 0;
	}
}

static void gc_arena(struct core *core) {
	struct arena *a, **aptr;
	struct source *s;
	int i, count = 0;

	if(arena) {
		for(a = arena->next; a; a = a->next) {
			for(i = 0; i < ARENASIZE; i++) {
				a->data[i].used = 0;
			}
		}

		for(i = 0; i < 65536; i++) {
			for(s = core->memory[i].src; s; s = s->next) {
				s->used = 1;
			}
		}

		for(aptr = &arena->next; *aptr; ) {
			a = *aptr;
			for(i = 0; i < ARENASIZE; i++) {
				if(a->data[i].used) break;
			}
			if(i == ARENASIZE) {
				count++;
				*aptr = a->next;
				free(a);
			} else {
				aptr = &a->next;
			}
		}
	}

	if(verbose >= 3) {
		fprintf(stderr, "Reclaimed %d arenas.\n", count);
	}
}

static void free_arena() {
	struct arena *a;
	int count = 0;

	while((a = arena)) {
		arena = a->next;
		free(a);
		count++;
	}
	arena_index = ARENASIZE;
	if(verbose >= 3) fprintf(stderr, "Freed %d arenas.\n", count);
}

static void reloc_exactly_one(struct source *src, uint8_t zpaddr) {
	int n_unknown = 0, n_dont = 0, n_do = 0;
	struct source *s, *s2;
	uint16_t last_do = 0, last_unknown = 0;

	for(s = src; s; s = s->next) {
		for(s2 = s->next; s2; s2 = s2->next) {
			if(s->offset == s2->offset) {
				// The same progbyte contributes more than
				// once. It cannot be relocated.
				if(verbose >= 2) {
					fprintf(stderr,
						"Byte at $%04x contributes more than once to a sum and won't be relocated.\n",
						s->offset + progbyte_org);
				}
				dont_reloc_at(s->offset);
			}
		}
	}

	for(s = src; s; s = s->next) {
		if(progbytes[s->offset].flags & PBF_DONT_RELOC) {
			n_dont++;
		} else if(progbytes[s->offset].flags & PBF_RELOC) {
			n_do++;
			last_do = s->offset;
		} else {
			n_unknown++;
			last_unknown = s->offset;
		}
	}

	if(zpaddr) {
		struct constraint *constr;
		int pos = 0;

		constr = malloc(sizeof(struct constraint) + sizeof(uint16_t) * (n_do + n_unknown));
		constr->check_needed = 1;
		constr->kind = C_EXACTLY_ONE;
		constr->n1 = n_do + n_unknown;
		constr->n2 = 0;
		for(s = src; s; s = s->next) {
			if(!(progbytes[s->offset].flags & PBF_DONT_RELOC)) {
				constr->vars[pos++] = s->offset;
			}
		}
		assert(pos == n_do + n_unknown);

		add_or_free_constraint(&zpconstr[zpaddr], constr);
	} else {
		if(n_do) {
			// n_do is typically 1 here.
			// If n_do > 1, this will introduce an inconsistency which we can detect later.
			for(s = src; s; s = s->next) {
				if(s->offset != last_do) dont_reloc_at(s->offset);
			}
		} else {
			// n_do is 0, so one of the unknown vars must be relocated.
			if(n_unknown == 1) {
				do_reloc_at(last_unknown);
			} else if(n_unknown == 0) {
				fprintf(stderr, "Inconsistency: Want to relocate one of {");
				for(s = src; s; s = s->next) {
					fprintf(stderr, "$%04x%s", s->offset + progbyte_org, s->next? ", " : "");
				}
				fprintf(stderr, "} but this would contradict other equations.\n");
				// exit(RET_CONSTR);
			} else {
				struct constraint *constr;
				int pos = 0;

				constr = malloc(sizeof(struct constraint) + sizeof(uint16_t) * n_unknown);
				constr->check_needed = 1;
				constr->kind = C_EXACTLY_ONE;
				constr->n1 = n_unknown;
				constr->n2 = 0;
				for(s = src; s; s = s->next) {
					if(!(progbytes[s->offset].flags & (PBF_RELOC | PBF_DONT_RELOC))) {
						constr->vars[pos++] = s->offset;
					}
				}
				assert(pos == n_unknown);

				add_or_free_constraint(0, constr);
			}
		}
	}
}

static void reloc_alike(value_t v1, value_t v2) {
	struct source *s;

	if(add_constraints) {
		if(v1.value >= (reloc_start >> 8) && v1.value <= (reloc_end >> 8)
		&& v2.value >= (reloc_start >> 8) && v2.value <= (reloc_end >> 8)) {
			struct constraint *constr;
			int n1 = 0, n2 = 0;
			int pos = 0;

			for(s = v1.src; s; s = s->next) n1++;
			for(s = v2.src; s; s = s->next) n2++;
			constr = malloc(sizeof(struct constraint) + sizeof(uint16_t) * (n1 + n2));

			constr->check_needed = 1;
			constr->kind = C_ALIKE;
			constr->n1 = n1;
			constr->n2 = n2;
			for(s = v1.src; s; s = s->next) {
				constr->vars[pos++] = s->offset;
			}
			for(s = v2.src; s; s = s->next) {
				constr->vars[pos++] = s->offset;
			}
			assert(pos == n1 + n2);

			add_or_free_constraint(0, constr);
		}
	}
}

static void used_for_zp_addr(struct source *src1, struct source *src2, uint8_t zpaddr) {
	struct source *s, *list;

	if(add_constraints) {
		for(s = src1; s; s = s->next) progbyte_for_zp(s->offset, zpaddr);
		for(s = src2; s; s = s->next) progbyte_for_zp(s->offset, zpaddr);

		if(do_zp_reloc) {
			list = src1;
			for(s = src2; s; s = s->next) list = cons_src(s->offset, list);
			reloc_exactly_one(list, zpaddr);
		}
	}
}

static void check_reloc_range(uint16_t addr, struct source *lsb1, struct source *lsb2, struct source *msb) {
	if(add_constraints) {
		struct source *s;

		for(s = msb; s; s = s->next) {
			progbyte_for_msb(s->offset);
		}
		if(addr >= reloc_start && addr <= reloc_end) {
			dont_reloc(lsb1);
			if(lsb2) dont_reloc(lsb2);
			reloc_exactly_one(msb, 0);
		} else if(addr < 0x100) {
			dont_reloc(msb);
			used_for_zp_addr(lsb1, lsb2, addr);
		} else {
			dont_reloc(msb);
			dont_reloc(lsb1);
			if(lsb2) dont_reloc(lsb2);
		}
	}
}

static void init_progbytes(uint16_t loadaddr, uint16_t loadsize) {
	progbyte_org = loadaddr - 2;
	progsize = loadsize;
	progbytes = calloc(sizeof(struct progbyte), progsize + 2);
	progbytes[0].flags = PBF_DONT_RELOC;
	progbytes[1].flags = PBF_RELOC | PBF_USED_IN_MSB;
}

static void reloc_map(struct core *oldcore, uint16_t reloc_offs) {
	int n_reloc = 0, n_zp = 0, n_dont = 0, n_unused = 0, n_unknown = 0;
	int i;
	int addr;
	uint16_t org;

	fprintf(stderr, "Program map:");
	org = progbyte_org + 2;
	for(addr = org & 0xffc0; addr <= ((org + progsize - 1) | 0x003f); addr++) {
		if(!(addr & 0x3f)) {
			fprintf(stderr, "\n%04x, %04x:  ", addr, (addr + reloc_offs) & 0xffff);
		}
		if(addr < org || addr >= org + progsize) {
			fprintf(stderr, " ");
		} else {
			i = addr - progbyte_org;
			if(progbytes[i].flags & PBF_RELOC) {
				if(progbytes[i].flags & PBF_USED_IN_MSB) {
					fprintf(stderr, "R");
					n_reloc++;
				} else if(progbytes[i].flags & PBF_USED_IN_ZP) {
					fprintf(stderr, "Z");
					n_zp++;
				} else {
					fprintf(stderr, "e");	// internal error
				}
			} else if(progbytes[i].flags & PBF_DONT_RELOC) {
				fprintf(stderr, "=");
				n_dont++;
			} else if(!(oldcore->read[addr] | oldcore->written[addr])) {
				fprintf(stderr, ".");
				n_unused++;
			} else {
				fprintf(stderr, "?");
				n_unknown++;
			}
		}
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "MSB relocations       (R): %d\n", n_reloc);
	fprintf(stderr, "Zero-page relocations (Z): %d\n", n_zp);
	fprintf(stderr, "Static bytes          (=): %d\n", n_dont);
	fprintf(stderr, "Status undetermined   (?): %d\n", n_unknown);
	fprintf(stderr, "Unused bytes          (.): %d\n", n_unused);
}

/////////////////////////////////////////////////////////////////////////////
//// sidreloc.c
/////////////////////////////////////////////////////////////////////////////

static int readheader(struct sidheader *head, uint8_t *data, int filesize) {
	if(filesize <= 0x80) return 1;
	if(data[0] == 'P') {
		head->rsid = 0;
	} else if(data[0] == 'R') {
		head->rsid = 1;
	} else return 1;
	if(data[1] != 'S') return 1;
	if(data[2] != 'I') return 1;
	if(data[3] != 'D') return 1;
	head->version = (data[4] << 8) | data[5];
	if(head->version < 1 || head->version > 2) return 1;
	head->dataoffset = (data[6] << 8) | data[7];
	if(head->version == 1 && head->dataoffset != 0x76) return 1;
	if(head->version == 2 && head->dataoffset != 0x7c) return 1;
	head->loadaddr = (data[8] << 8) | data[9];
	if(!head->loadaddr) {
		head->loadaddr = data[head->dataoffset] | (data[head->dataoffset + 1] << 8);
		head->dataoffset += 2;
	}
	head->loadsize = filesize - head->dataoffset;
	if(head->loadaddr < 0x7e8 && head->rsid) errx(RET_RSID, "RSID standard violation");
	head->initaddr = (data[0x0a] << 8) | data[0x0b];
	if(!head->initaddr) head->initaddr = head->loadaddr;
	head->playaddr = (data[0x0c] << 8) | data[0x0d];
	head->nsubtune = (data[0x0e] << 8) | data[0x0f];
	head->defsubtune = (data[0x10] << 8) | data[0x11];
	memcpy(head->title, &data[0x16], sizeof(head->title));
	memcpy(head->author, &data[0x36], sizeof(head->author));
	memcpy(head->released, &data[0x56], sizeof(head->released));
	head->title[31] = 0;
	head->author[31] = 0;
	head->released[31] = 0;
	if(head->version > 1) {
		uint16_t flags = (data[0x76] << 8) | data[0x77];
		if(flags & 1) errx(RET_MUS, "MUS format not supported");
		if(head->rsid && (flags & 2)) errx(RET_BASIC, "BASIC tunes not supported");
		if(!head->rsid && (flags & 2)) errx(RET_PSID, "PSID tunes not supported");
	}
	return 0;
}

static void init_core(struct core *core, uint8_t *data, uint16_t loadaddr, uint16_t loadsize) {
	int i;

	memset(core->memory, 0, sizeof(core->memory));

	for(i = 0xea31; i <= 0xea86; i++) {
		core->memory[i].value = 0x68;	// pla
	}

	for(i = 0; i < loadsize; i++) {
		core->memory[loadaddr + i].value = data[i];
		core->memory[loadaddr + i].src = cons_src(i + 2, 0);
	}
}

static uint16_t get_from_vector(struct core *core, uint16_t fallback, uint16_t vaddr) {
	uint16_t vector = core->memory[vaddr].value | (core->memory[vaddr + 1].value << 8);
	if(vector) {
		check_reloc_range(vector, core->memory[vaddr].src, 0, core->memory[vaddr + 1].src);
		return vector;
	} else return fallback;
}

static void init_tune(struct core *core, uint16_t initaddr, int tune) {
	int errcode = emulate(core, initaddr, tune, cycles_init);
	if(errcode == ERR_CYCLES) errx(RET_CYCLES | exitbits, "Max cycles exhausted during init routine. Infinite loop?");
	if(errcode) fprintf(stderr, "%s\n", emulate_err[errcode - 1]);
}

static int play_step(struct core *core, uint16_t playaddr, char *errprefix) {
	int errcode;
	uint16_t digiaddr;
	int i;
	int allow_digi = 1;

	playaddr = get_from_vector(core, playaddr, 0x0314);
	playaddr = get_from_vector(core, playaddr, 0xfffe);

	if(!playaddr) {
		playaddr = get_from_vector(core, playaddr, 0x0318);
		playaddr = get_from_vector(core, playaddr, 0xfffa);
		allow_digi = 0;
	}

	if(!playaddr) errx(RET_PLAYADDR, "%sCouldn't determine address of playroutine.", errprefix);

	errcode = emulate(core, playaddr, 0, cycles_play);
	if(errcode == ERR_CYCLES && !force) {
		errx(RET_CYCLES | exitbits, "Max cycles exhausted during playroutine. Infinite loop?");
	}
	if(errcode) {
		fprintf(stderr, "%s%s\n", errprefix, emulate_err[errcode - 1]);
	} else if(allow_digi) {
		digiaddr = get_from_vector(core, 0, 0x0318);
		digiaddr = get_from_vector(core, digiaddr, 0xfffa);
		if(digiaddr) {
			if(!nmi_reported) {
				fprintf(stderr, "Use of digis detected. NMI routine will also be relocated.\n");
				nmi_reported = 1;
			}
			for(i = 0; i < nmi_calls; i++) {
				errcode = emulate(core, digiaddr, 0, cycles_nmi);
				if(errcode == ERR_CYCLES && !force) {
					errx(RET_CYCLES | exitbits, "Max cycles exhausted during NMI routine. Infinite loop?");
				}
				if(errcode) break;
			}
		}
	}

	return errcode;
}

static int verify_sidstate(value_t *oldmem, value_t *newmem, int frame, int *n_badpitch, int *n_badpw) {
	int i;
	int badp[3] = {0, 0, 0}, badpw[3] = {0, 0, 0};

	for(i = 0; i < 29; i++) {
		if(oldmem[0xd400 + i].value != newmem[0xd400 + i].value) {
			if(i < 21 && (i % 7) < 2) {
				badp[i / 7] = 1;
			} else if(i < 21 && (i % 7) < 4) {
				badpw[i / 7] = 1;
			} else {
				fprintf(stderr, "Wrong SID state! ");
				if(frame >= 0) {
					fprintf(stderr, "At time %d, ", frame); 
				} else {
					fprintf(stderr, "After the init routine, ");
				}
				fprintf(stderr, "$d4%02x should be $%02x, but the relocated code has written $%02x.\n",
					i,
					oldmem[0xd400 + i].value,
					newmem[0xd400 + i].value);
				if(!force) {
					return 0;	
				}
			}
		}
	}
	*n_badpitch += badp[0] + badp[1] + badp[2];
	*n_badpw += badpw[0] + badpw[1] + badpw[2];
	return 1;
}

static void zeropage_map() {
	int i;

	fprintf(stderr, "Old zero-page addresses:  ");
	for(i = 2; i < 256; i++) {
		if(oldcore.written[i]) fprintf(stderr, " %02x", i);
	}
	fprintf(stderr, "\nNew zero-page addresses:  ");
	for(i = 2; i < 256; i++) {
		if(oldcore.written[i]) fprintf(stderr, " %02x", (i + zeropage[i].reloc) & 0xff);
	}
	fprintf(stderr, "\n");
}

static void version() {
	printf("sidreloc " RELEASE "\n");
	printf("Created in 2012 by Linus Akesson.\n");
	printf("Contains a 6510 emulator based on lib6502 by Ian Piumarta.\n");
	printf("Project homepage: http://www.linusakesson.net/software/sidreloc/\n");
}

static void usage() {
	printf("sidreloc " RELEASE " by Linus Akesson\n");
	printf("\n");
	printf("Usage: sidreloc [OPTIONS] input.sid output.sid\n");
	printf("\n");
	printf("Options:\n");
	printf("Short name  Long name      Default     Description\n");
	printf("\n");
	printf("  -p        --page         10          First memory page (in hex) to be occupied by\n");
	printf("                                       the relocated SID.\n");
	printf("  -z        --zp-reloc     80-ff       Range of free zero-page addresses that the\n");
	printf("                                       relocated SID can use.\n");
	printf("  -k        --no-zp-reloc              Keep all zero-page addresses as they appear\n");
	printf("                                       in the original SID.\n");
	printf("  -r        --reloc        (from SID)  Range to relocate, e.g. \"50-5f\" for a 4 kB\n");
	printf("                                       SID originally located at $5000. Must include\n");
	printf("                                       the entire loading range of the SID.\n");
	printf("\n");
	printf("  -t        --tolerance    2           Tolerance (in percent) for wrong pitches.\n");
	printf("  -s        --strict                   Verify pulse widths.\n");
	printf("  -f        --force                    Write output file even if verification fails.\n");
	printf("\n");
	printf("  -v        --verbose                  Output some statistics and a nice map of all\n");
	printf("                                       the relocations.\n");
	printf("  -q        --quiet                    Don't whine about writing out of bounds.\n");
	printf("\n");
	printf("            --frames       100000      Number of times to call the playroutine of\n");
	printf("                                       each subtune. The default corresponds to\n");
	printf("                                       approximately 33 minutes of a PAL tune.\n");
	printf("            --nmi-calls    200         Number of times to call the NMI routine per\n");
	printf("                                       frame (the CIA2 timer setting is ignored).\n");
	printf("            --init-cycles  1000000     Max number of clock cycles for init routine.\n");
	printf("            --play-cycles  20000       Max number of clock cycles for playroutine.\n");
	printf("            --nmi-cycles   1000        Max number of clock cycles for NMI routine.\n");
	printf("\n");
	printf("  -h        --help                     Display this information.\n");
	printf("  -V        --version                  Display brief version information and credits.\n");
	printf("\n");
	printf("Project homepage: http://www.linusakesson.net/software/sidreloc/\n");
	exit(0);
}

static int readfile(uint8_t *data, char *filename) {
	int filesize;
	FILE *f = fopen(filename, "rb");
	if(!f) err(RET_IO, "%s", filename);
	filesize = fread(data, 1, 65536, f);
	fclose(f);
	return filesize;
}

static void writefile(uint8_t *data, char *filename, int filesize) {
	FILE *f = fopen(filename, "wb");
	if(!f) err(RET_IO | exitbits, "%s", filename);
	if(fwrite(data, 1, filesize, f) != filesize) err(RET_IO | exitbits, "fwrite");
	fclose(f);
}

static void report_oob(uint16_t first, uint16_t last) {
	if(!quiet && first != 0xd400) {
		if(first == last) {
			if ( verbose > 0 ) {
				fprintf(stderr, "Warning: Write out of bounds at address $%04x\n", first);
			}
		} else {
			if ( verbose > 0 ) {
				fprintf(stderr, "Warning: Write out of bounds at address $%04x-$%04x\n", first, last);
			}
		}
	}
}

enum {
	OPT_FRAMES = 256,
	OPT_NMI_CALLS,
	OPT_INIT_CYCLES,
	OPT_PLAY_CYCLES,
	OPT_NMI_CYCLES
};

static int first_zp = 0x80, last_zp = 0xff;
static int given_reloc_start = -1, given_reloc_end = -1;
static int dest_page = 0x10;
static int tolerance = 2;
static int strictpw = 0;

char * sidreloc_get_lasterror_string( ) {
	return lastErrorString;
}

int sidreloc_set_page( int _page ) {
	if ( _page >= 0x00 && dest_page <= 0xff) {
		dest_page = _page;
		return 1;
	} else {
		errx(RET_PARAM, "SID relocation: invalid page number (should be in the range $00-$ff, 0..255)");
		return 0;
	}
}

int sidreloc_set_page0( int _first, int _last ) {
	if ( _first >= 0x02 && _first <= 0xff && 
		 _last >= 0x02 && _last <= 0xff && 
		_first <= _last ) {
			first_zp = _first;
			last_zp = _last;
		return 1;
	} else {
		errx(RET_PARAM, "Invalid zero-page address range (should be in the range $02-$ff, 0..255)");
		return 0;
	}
}

int sidreloc_set_nopage0( ) {
	do_zp_reloc = 0;
	return 1;
}

int sidreloc_set_reloc( int _start, int _end ) {
	if( _start >= 0x01 && _start <= 0xff &&
		_end >= 0x01 && _end <= 0xff &&
		_start <= _end ) {
		given_reloc_start = _start;
		given_reloc_end = _end;
		return 1;
	} else {
		errx(RET_PARAM, "Invalid relocation range (should be in the range $01-$ff, 2..255)");
		return 0;
	}
}

int sidreloc_set_tolerance( int _tolerance ) {
	if ( _tolerance >= 0 && _tolerance < 100) {
		tolerance = _tolerance;
		return 1;
	} else {
		errx(RET_PARAM, "Invalid tolerance percentage (should be in the range 0-100)");
		return 0;
	}
}

int sidreloc_set_strict( ) {
	strictpw = 1;
	return 1;
}

int sidreloc_set_force( ) {
	force = 1;
	return 1;
}

int sidreloc_set_verbosity( int _verbose ) {
	verbose = _verbose;
	return 1;
}

int sidreloc_set_quiet( ) {
	quiet = 1;
	return 1;
}

int sidreloc_set_frames( int _frames ) {
	if ( _frames >= 0 ) {
		play_calls = _frames;		
		return 1;
	} else {
		errx(RET_PARAM, "Invalid number of calls to the playroutine.");
		return 0;
	}
}

int sidreloc_set_init_cycles( int _cycles ) {
	if ( _cycles >= 0 ) {
		cycles_init = _cycles;		
		return 1;
	} else {
		errx(RET_PARAM, "Invalid cycle limit for the init routine.");
		return 0;
	}
}

int sidreloc_set_play_cycles( int _cycles ) {
	if ( _cycles >= 0 ) {
		cycles_play = _cycles;		
		return 1;
	} else {
		errx(RET_PARAM, "Invalid cycle limit for the playroutine.");
		return 0;
	}
}

int sidreloc_set_nmi_cycles( int _cycles ) {
	if ( _cycles >= 0 ) {
		cycles_nmi = _cycles;		
		return 1;
	} else {
		errx(RET_PARAM, "Invalid cycle limit for the NMI routine.");
		return 0;
	}
}

int sidreloc_set_nmi_calls( int _cycles ) {
	if ( _cycles >= 0 ) {
		nmi_calls = _cycles;		
		return 1;
	} else {
		errx(RET_PARAM, "Invalid number of calls to the NMI routine.");
		return 0;
	}
}

static uint8_t * data;
static uint8_t * newdata;
static int filesize;

int sidreloc_set_input_data( unsigned char * _data, int _size ) {
	data = _data;
	filesize = _size;
	return 0;
}

int sidreloc_set_output_data( unsigned char * _data ) {
	newdata = _data;
	return 0;
}

int sidreloc_main() {
	int i, j, k, errcode, opt;
	struct sidheader head;
	uint16_t reloc_offset;
	uint8_t page_used[256];
	int n_check = 0, n_badpitch = 0, n_badpw = 0;
	int perc_badpitch, perc_badpw;
	uint16_t ooblast, oobchunk;

	/* Read the SID file. */

	// filesize = readfile(data, filename);
	if(readheader(&head, data, filesize)) {
		errx(RET_HEADER, "Bad SID file header");
		return 0;
	}
	if(verbose > 0) {
		fprintf(stdout, "%s, %s, %s, $%04x-$%04x, %d subtunes\n",
			head.title,
			head.author,
			head.released,
			head.loadaddr,
			head.loadaddr + head.loadsize - 1,
			head.nsubtune);
	}

	/* Determine the relocation area. */

	reloc_start = head.loadaddr & 0xff00;
	reloc_end = (head.loadaddr + head.loadsize - 1) | 0x00ff;

	for(i = 0; i < 64 && reloc_end != 0xcfff && reloc_end != 0xffff; i++) {
		reloc_end += 0x100;
	}

	if(given_reloc_start >= 0) {
		reloc_start = given_reloc_start << 8;
		reloc_end = (given_reloc_end << 8) | 0xff;
		if(reloc_start > head.loadaddr
		|| reloc_end < (head.loadaddr + head.loadsize - 1)) {
			errx(RET_RANGE,
				"Relocation range (-r) must contain all the SID data! (SID loads at $%04x-$%04x)",
				head.loadaddr,
				head.loadaddr + head.loadsize - 1);
				return 0;
		}
	}

	reloc_offset = (dest_page << 8) - reloc_start;

	if ( verbose > 0 ) {
		fprintf(stdout, "Relocating from $%04x-$%04x to $%04x-$%04x\n",
			reloc_start,
			reloc_end,
			(reloc_start + reloc_offset) & 0xffff,
			(reloc_end + reloc_offset) & 0xffff);
	}

	if(reloc_start < 0x100 || reloc_end < reloc_start
	|| ((reloc_start + reloc_offset) & 0xffff) < 0x100
	|| ((reloc_end + reloc_offset) & 0xffff) < ((reloc_start + reloc_offset) & 0xffff)) {
		errx(RET_RANGE, "Neither the source nor the destination relocation range may overlap with the zero-page.");
		return 0;
	}

	prealloc_cons_cells();

	/* Visit all subtunes. */

	init_progbytes(head.loadaddr, head.loadsize);
	add_constraints = 1;

	for(i = 0; i < head.nsubtune; i++) {
		if ( verbose > 0 ) {
			fprintf(stderr, "Analysing subtune %d\n", i + 1);
		}
		nmi_reported = 0;
		init_core(&oldcore, &data[head.dataoffset], head.loadaddr, head.loadsize);
		init_tune(&oldcore, head.initaddr, i);
		for(j = 0; j < play_calls; j++) {
			if(play_step(&oldcore, head.playaddr, "")) break;
		}
		gc_arena(&oldcore);
	}

	/* Report bad memory accesses, possibly remove some zero-page addresses from the constraints. */

	oobchunk = ooblast = 0xd400;
	for(i = 0; i < 65536; i++) {
		if(i >= head.loadaddr && i < head.loadaddr + head.loadsize) {
			/* Inside tune, ok */
		} else if(i >= 0xd400 && i <= 0xd41f) {
			/* SID register area, ok */
		} else if(i >= 2 && i < 0x100) {
			if(oldcore.read[i] && !oldcore.written[i]) {
				if(!quiet) {
					if ( verbose > 0 ) {
						fprintf(stderr,
							"Warning: Zero-page address $%02x read but never written.%s\n",
							i,
							(do_zp_reloc? " Not relocating it." : ""));
					}
				}
				for(j = 0; j < progsize; j++) {
					struct progbyte *pb = &progbytes[j + 2];
					if((pb->flags & PBF_USED_IN_ZP) && pb->zpaddr[i >> 3] & (1 << (i & 7))) {
						pb->zpaddr[i >> 3] &= ~(1 << (i & 7)); 
						for(k = 0; k < 32; k++) if(pb->zpaddr[k]) break;
						if(k == 32) pb->flags &= ~(PBF_RELOC | PBF_USED_IN_ZP);
					}
				}
			}
		} else {
			if(oldcore.written[i]) {
				exitbits |= RETF_OUTOFBOUNDS;
				if(ooblast != i - 1) {
					report_oob(oobchunk, ooblast);
					oobchunk = i;
				}
				ooblast = i;
			}
		}
	}
	report_oob(oobchunk, ooblast);

	finalise_constraints(&oldcore);

	/* Find a solution to the set of constraints. */

	if(trivially_inconsistent() || solver()) {
		errx(RET_CONSTR | exitbits, "No solution found");
		return 0;
	}

	/* Map the zero-page addresses to new locations. */

	for(i = 0; i < 256; i++) {
		zeropage[i].link = i;
		zeropage[i].free = (i >= first_zp && i <= last_zp);
	}

	for(i = 0; i < progsize; i++) {
		struct progbyte *pb = &progbytes[i + 2];
		if((pb->flags & (PBF_RELOC | PBF_USED_IN_ZP)) == (PBF_RELOC | PBF_USED_IN_ZP)) {
			int first = -1;
			for(j = 0; j < 256; j++) {
				if(pb->zpaddr[j >> 3] & (1 << (j & 7))) {
					if(first != -1) {
						// One relocated program byte contributes to
						// several zero-page addresses. Link them.
						if(zeropage[j].link > zeropage[first].link) {
							zeropage[j].link = zeropage[first].link;
						} else {
							zeropage[first].link = zeropage[j].link;
						}
					} else {
						first = j;
					}
				}
			}
		}
	}

	for(i = 0; i < 256; i++) {
		if(zeropage[i].link != zeropage[zeropage[i].link].link) {
			zeropage[i].link = zeropage[zeropage[i].link].link;
		}
	}

	if(do_zp_reloc) {
		int chunk, dest;

		for(chunk = 2; chunk < 0x100; chunk++) {
			if(oldcore.written[chunk] && (zeropage[chunk].link == chunk)) {
				// We have a chunk to place somewhere.
				for(dest = first_zp; dest <= last_zp; dest++) {
					// Try to put it at dest.
					for(i = chunk; i < 0x100; i++) {
						if(zeropage[i].link == chunk) {
							if(!zeropage[(dest + i - chunk) & 0xff].free) {
								break;
							}
						}
					}
					if(i == 0x100) {
						// It fits!
						for(i = chunk; i < 0x100; i++) {
							if(zeropage[i].link == chunk) {
								zeropage[i].reloc = dest - chunk;
								zeropage[dest + i - chunk].free = 0;
							}
						}
						break;
					}
				}
				if(dest > last_zp) {
					errx(RET_ZPFULL | exitbits,
						"Can't fit all zero-page addresses into specified range ($%02x-$%02x).",
						first_zp,
						last_zp);
					return 0;
				}
			}
		}
	}

	/* Draw a map. */

	if(verbose >= 1) {
		reloc_map(&oldcore, reloc_offset);
		zeropage_map();
	}

	/* Perform the relocation. */

	memcpy(newdata, data, filesize);
	for(i = 0; i < progsize; i++) {
		struct progbyte *pb = &progbytes[i + 2];
		if(pb->flags & PBF_RELOC) {
			if(pb->flags & PBF_USED_IN_MSB) {
				newdata[head.dataoffset + i] += reloc_offset >> 8;
			} else {
				for(j = 2; j < 256; j++) {
					if(pb->zpaddr[j / 8] & (1 << (j & 7))) {
						break;
					}
				}
				if(j < 256) {
					newdata[head.dataoffset + i] += zeropage[j].reloc;
				}
			}
		}
	}

	/* Verify the relocated subtunes. */

	free_arena();
	free(progbytes);
	progbytes = 0;
	add_constraints = 0;

	for(i = 0; i < head.nsubtune; i++) {
		if ( verbose > 0 ) {
			fprintf(stderr, "Verifying relocated subtune %d\n", i + 1);
		}
		init_core(&oldcore, &data[head.dataoffset], head.loadaddr, head.loadsize);
		init_core(&newcore, &newdata[head.dataoffset], (head.loadaddr + reloc_offset) & 0xffff, head.loadsize);

		init_tune(&oldcore, head.initaddr, i);

		reloc_start += reloc_offset;
		reloc_end += reloc_offset;

		init_tune(&newcore, (head.initaddr + reloc_offset) & 0xffff, i);

		n_check += 3;
		if ( !verify_sidstate(oldcore.memory, newcore.memory, -1, &n_badpitch, &n_badpw) ) {
			return 0;
		}

		for(j = 0; j < play_calls; j++) {
			reloc_start -= reloc_offset;
			reloc_end -= reloc_offset;

			errcode = play_step(&oldcore, head.playaddr, "Old version: ");
			if(errcode) break;

			reloc_start += reloc_offset;
			reloc_end += reloc_offset;

			errcode = play_step(&newcore, (head.playaddr? ((head.playaddr + reloc_offset) & 0xffff) : 0), "New version: ");
			if(errcode) {
				if(force) {
					break;
				} else {
					errx(RET_VERIFY | exitbits, "Verification failed");
					return 0;
				}
			}

			n_check += 3;
			if ( ! verify_sidstate(oldcore.memory, newcore.memory, j, &n_badpitch, &n_badpw) ) {
				return 0;
			}
		}

		reloc_start -= reloc_offset;
		reloc_end -= reloc_offset;
	}

	if(!n_check) n_check = 1;
	perc_badpitch = round(n_badpitch * 100.0 / n_check);
	perc_badpw = round(n_badpw * 100.0 / n_check);
	if ( verbose > 0 ) {
		fprintf(stderr, "Bad pitches:               %d, %d%%\n", n_badpitch, perc_badpitch);
		fprintf(stderr, "Bad pulse widths:          %d, %d%%\n", n_badpw, perc_badpw);
	}
	if(n_badpitch || n_badpw) {
		exitbits |= RETF_TOLERANCE;
		if(!force) {
			if(n_badpitch && (!tolerance || (perc_badpitch > tolerance))) {
				errx(RET_VERIFY | exitbits, "Relocation failed; too many mismatching pitches.\n");
				return 0;
			} else if(n_badpw && strictpw) {
				errx(RET_VERIFY | exitbits, "Relocation failed; mismatching pulse widths and strict flag given.\n");
				return 0;
			}
		}
	}
	// if(n_badpitch) {
	// 	fprintf(stderr, "Relocation successful with some mismatching pitches.\n");
	// } else if(n_badpw) {
	// 	fprintf(stderr, "Relocation successful with some mismatching pulse widths.\n");
	// } else {
	// 	fprintf(stderr, "Relocation successful.\n");
	// }

	/* Relocate all pointers in the header. */

	if(newdata[0x08] | newdata[0x09]) {
		newdata[0x08] += reloc_offset >> 8;
	} else {
		newdata[head.dataoffset - 1] += reloc_offset >> 8;
	}
	if(newdata[0x0a] | newdata[0x0b]) {
		newdata[0x0a] += reloc_offset >> 8;
	}
	if(newdata[0x0c] | newdata[0x0d]) {
		newdata[0x0c] += reloc_offset >> 8;
	}

	/* Determine where replayer code could go. */

	memset(page_used, 0, sizeof(page_used));
	if(head.version > 1) {
		int best_start, best_n, curr_start, curr_n;

		for(i = 0; i < 256; i++) {
			if((i >= 0x00 && i <= 0x03)
			|| (i >= 0xa0 && i <= 0xbf)
			|| (i >= 0xd0 && i <= 0xff)
			|| (i >= (((head.loadaddr + reloc_offset) & 0xffff) >> 8)
			&& i <= (((head.loadaddr + head.loadsize - 1 + reloc_offset) & 0xffff) >> 8))) {
				page_used[i] = 1;
			} else {
				for(j = 0; j < 256; j++) {
					if(newcore.read[(i << 8) | j]
					|| newcore.written[(i << 8) | j]) {
						page_used[i] = 1;
						break;
					}
				}
			}
		}
		best_start = curr_start = 0;
		best_n = curr_n = 0;
		for(i = 0; i < 256; i++) {
			if(page_used[i]) {
				if(curr_n > best_n) {
					best_start = curr_start;
					best_n = curr_n;
				}
				curr_start = i + 1;
				curr_n = 0;
			} else {
				curr_n++;
			}
		}
		if(curr_n > best_n) {
			best_start = curr_start;
			best_n = curr_n;
		}
		if(best_n) {
			if(verbose >= 1) {
				fprintf(stdout,
					"Largest unused region:     $%02x00-$%02xff\n",
					best_start,
					best_start + best_n - 1);
			}
			newdata[0x78] = best_start;
			newdata[0x79] = best_n;
		} else {
			if(verbose >= 1) {
				fprintf(stdout, "No space left for replay routine!\n");
			}
			newdata[0x78] = 0xff;
			newdata[0x79] = 0;
		}
	}

	/* Write the relocated SID file. */

	//writefile(newdata, outputname, filesize);

	// return RET_SUCCESS | exitbits;

	return 1;

}

// #ifndef HAVE_ERRX
// /*  Some posix has not this standard, function (for ex. Haiku)
// 	so, we define a roughly equivalente */
// static void errx(int eval, const char *fmt, ...){
// 	fprintf(stderr,"%s: ", "sidreloc");
// 	fprintf(stderr,fmt, ...);
// 	fprintf(stderr,"\n");
// 	exit(eval);
// }
// #endif

// #ifndef HAVE_ERR
// /*  Some posix has not this standard, function (for ex. Haiku)
// 	so, we define a roughly equivalente */
// static void err(int eval, const char *fmt, ...){
// 	fprintf(stderr, " %s: ", "sidreloc");
// 	fprintf(stderr, fmt, ...);
// 	fprintf(stderr, ": %s\n", strerror(errno));
// 	exit(eval);
// }
// #endif

