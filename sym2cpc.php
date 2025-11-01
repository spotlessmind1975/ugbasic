<?php

    $content = file( $argv[1] );

    foreach( $content as $line ) {
        $p = strpos($line, "=");
        if ( $p ) {
            $symbol = trim(substr( $line, 0, $p-1 ) );
            $offset = substr( $line, $p+3, 4 );
            if ( strpos( $line, "const") !== FALSE ) {
                echo $symbol.": equ ".dechex(hexdec($offset))."h\n";
            } else {
                echo $symbol.": equ ".dechex(0x1200+hexdec($offset))."h\n";
            }
        }
    }

