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
