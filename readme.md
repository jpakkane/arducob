# Running COBOL code on Arduino with Meson

Who says COBOL is only for boring banking, insurance and paycheck
evaluation?  This project demonstrates how you can use it to do
embedded code on an Arduino microcontroller.

## Requirements

 - [Meson](http://mesonbuild.com)
 - [GNU COBOL](http://open-cobol.sourceforge.net/)
 - [Arduino toolchain](http://www.arduino.org/)

## Compile + upload

    mkdir build
    meson --cross-file arduino_uno_cross.txt build
    cd build
    ninja ardup

## Other things of note

Requires [a branch of
Meson](https://github.com/mesonbuild/meson/pull/618) that has not been
merged to master at the time of writing.

The scripts assume Linux and that your Arduino is in `/dev/ttyACM0`.

## Going deeper

How the system works is explained in detail in [this blog post](http://nibblestew.blogspot.com/2016/06/running-cobol-on-arduino-using-meson.html).
