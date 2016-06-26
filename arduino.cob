        IDENTIFICATION DIVISION.
        PROGRAM-ID. arduino.
        DATA DIVISION.
            WORKING-STORAGE SECTION.
            01 CTXT PIC A(5) VALUE 'COBOL'.
            01 WS-CNT USAGE UNSIGNED-INT.

        PROCEDURE DIVISION.
            MOVE 0 TO WS-CNT.
            A-PARA.
            PERFORM B-PARA UNTIL WS-CNT>3.
            STOP RUN.

            DISPLAY "BOB".

            B-PARA.
            DISPLAY CTXT.
            ADD 1 TO WS-CNT.

