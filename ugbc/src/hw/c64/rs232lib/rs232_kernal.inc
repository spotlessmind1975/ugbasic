; CCGMS Terminal
;
; Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
; This project is licensed under the BSD 3-Clause License.
;
; RS232 Driver Internal Include
;

; KERNAL
STATUS	= $90
RIDBE   = $029b
RIDBS   = $029c
RODBS   = $029d
RODBE   = $029e
ENABL	= $02a1
rtail	= RIDBE ; friendlier name
rhead	= RIDBS ; friendlier name
rfree	= RODBS ; re-purposed; SwiftLink only

JIFFIES	= $a2	; TIME+2
