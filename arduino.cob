      *Copyright (C) 2016 Jussi Pakkanen
      *
      *This program is free software: you can redistribute it and/or modify
      *it under the terms of the GNU General Public License as published by
      *the Free Software Foundation, either version 3 of the License, or
      *(at your option) any later version.
      *
      *This program is distributed in the hope that it will be useful,
      *but WITHOUT ANY WARRANTY; without even the implied warranty of
      *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      *GNU General Public License for more details.
      *
      *You should have received a copy of the GNU General Public License
      *along with this program.  If not, see <http://www.gnu.org/licenses/>.

        IDENTIFICATION DIVISION.
        PROGRAM-ID. arduino.
        DATA DIVISION.
            WORKING-STORAGE SECTION.
            01 CTXT PIC A(5) VALUE 'COBOL'.
            01 WS-CNT USAGE UNSIGNED-INT.
            01 OFFSET1 USAGE UNSIGNED-INT.
            01 OFFSET2 USAGE UNSIGNED-INT.
            01 TICKS USAGE UNSIGNED-INT.
            01 INDEX1 USAGE UNSIGNED-INT VALUE 0.
            01 INDEX2 USAGE UNSIGNED-INT VALUE 1.

        PROCEDURE DIVISION.
            MOVE 0 TO TICKS.
            A-PARA.
            PERFORM B-PARA UNTIL WS-CNT>20.
            STOP RUN.

            B-PARA.
            CALL "sleeping".
            CALL "clearlcd".
            IF TICKS <= 11 THEN
                MOVE TICKS TO OFFSET1
            ELSE
                MOVE 22 TO OFFSET1
                SUBTRACT TICKS FROM OFFSET1
            END-IF.
            MOVE 11 TO OFFSET2.
            SUBTRACT OFFSET1 FROM OFFSET2.
            CALL "setlcd" USING INDEX1, OFFSET1, CTXT.
            CALL "setlcd" USING INDEX2, OFFSET2, CTXT.
            IF TICKS > 20 THEN
                MOVE 0 TO TICKS
            ELSE
                ADD 1 TO TICKS
            END-IF.

