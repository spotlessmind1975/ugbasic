; CCGMS Terminal
;
; Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
; This project is licensed under the BSD 3-Clause License.
;
; RS232 Driver Include
;

MODEM_TYPE_USERPORT	= 0
MODEM_TYPE_UP9600	= 1
MODEM_TYPE_SWIFTLINK_DE	= 2
MODEM_TYPE_SWIFTLINK_DF	= 3
MODEM_TYPE_SWIFTLINK_D7	= 4

BAUD_300	= 0
BAUD_1200	= 1
BAUD_2400	= 2
BAUD_4800	= 3
BAUD_9600	= 4
BAUD_19200	= 5
BAUD_38400	= 6

; API
.global rs232_init
.global rs232_on
.global rs232_off
.global rs232_get
.global rs232_put
.global rs232_dropdtr
.global rs232_clear
