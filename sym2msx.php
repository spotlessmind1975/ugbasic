<?php

    $content = file( $argv[1] );

    foreach( $content as $line ) {
        $p = strpos($line, "=");
        if ( $p ) {
            $symbol = trim(substr( $line, 0, $p-1 ) );
            $offset = substr( $line, $p+3, 4 );
            if ( strpos( $line, "const") !== FALSE ) {
                echo $symbol.": equ ".dechex(hexdec($offset))."h\n";
            } else if ( strpos( $line, "data_user") !== FALSE ) {
                if ( hexdec($offset) < 0xe000 ) {
                    echo $symbol.": equ ".dechex(0xe000+hexdec($offset))."h\n";
                } else {
                    echo $symbol.": equ ".dechex(hexdec($offset))."h\n";
                }
            } else {
                echo $symbol.": equ ".dechex(0x4000+hexdec($offset))."h\n";
            }
        }
    }

