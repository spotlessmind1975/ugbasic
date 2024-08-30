# CCGMS rs232lib

This is `rs232lib`, a library for RS-232 communication on the Commodore 64. It is derived from the [CCGMS Future](https://github.com/mist64/ccgmsterm) driver code.

The following table summarizes the included drivers and their supported baud rates:

| Driver             | 300 | 1200 | 2400 | 4800 | 9600 | 19200 | 3400 |
|--------------------|-----|------|------|------|------|-------|------|
| User Port          | ✅  |  ✅  |  ✅  | ❌  | ❌   | ❌   | ❌   |
| UP9600             | ✅  |  ✅  |  ✅  | ✅  | ✅   | ❌   | ❌   |
| SwiftLink/Turbo232 | ✅  |  ✅  |  ✅  | ✅  | ✅   | ✅   | ✅   |

It uses a 256 byte input buffer and no output buffer.

## API

### `rs232_init`

Init the driver. This has to be called at least once to initialize the modem. This will evaluate the symbols `modem_type`, `baud_rate` and `is_pal_system`.

### `rs232_on`

Enable the driver. This has to be called at least once, and to re-enable the driver after `rs232_off`.

### `rs232_off`

Disable the driver. This needs to be called if the serial disk is supposed to be used.

### `rs232_get`

Get a byte.

### `rs232_put`

Send a byte.

### `rs232_dropdtr`

Drop the DTR line (hangup).

### `rs232_clear`

Clear the input buffer.


## Dependencies

The library requires the following symbols to be defined:

### `modem_type`

Must be set to the driver/config.

        MODEM_TYPE_USERPORT	= 0
        MODEM_TYPE_UP9600	= 1
        MODEM_TYPE_SWIFTLINK_DE	= 2
        MODEM_TYPE_SWIFTLINK_DF	= 3
        MODEM_TYPE_SWIFTLINK_D7	= 4

### `baud_rate`

        BAUD_300	= 0
        BAUD_1200	= 1
        BAUD_2400	= 2
        BAUD_4800	= 3
        BAUD_9600	= 4
        BAUD_19200	= 5
        BAUD_38400	= 6

### `is_pal_system`

        0: NTSC
        1: PAL

## `ribuf`

256 bytes of memory the driver can use for the input buffer.

## `revtabup`

128 bytes of memory the driver can use for temporary storage.

# Banking

rs232lib uses the $0314/$0315 and $0318/$0319 vectors to hook IRQs and NMIs. It also installs vectors at $FFFA/$FFFB and $FFFE/$FFFF to hook IRQs and NMIs even with the KERNAL off, and fowards them through the usual vectors.

This requires all software that turns off the KERNAL ROM to do this by storing #$34 in $01 instead of #$30. It is equivalent, but allows the timing-critical UP9600 code to switch I/O on and off with `inc $01` and `dec $01`.

# License

Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
This project is licensed under the BSD 3-Clause License.
