/*
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
 */


#include<ardulib.h>

#include<LiquidCrystal.h>
#include<Arduino.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void sleeping() {
    delay(500);
}

void setlcd(const int *index, const int *offset, const char *msg) {
    lcd.setCursor(*offset, *index);
    lcd.print(msg);
}

void clearlcd() {
    lcd.clear();
}

void libsetup() {
    lcd.begin(16, 2);
}
