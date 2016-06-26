project('arduino cobol', 'c', 'cpp',
  default_options : ['buildtype=minsize'],
  license : 'GPLv3+',
  )

assert(meson.is_cross_build(), 'Arduino projects can only be built in a cross build environment.')

ardu_src_dir = '/usr/share/arduino/hardware/arduino/cores/arduino/'

ardu_lib_files = [
  'wiring_shift.c',
  'wiring_analog.c',
  'WInterrupts.c',
  'avr-libc/realloc.c',
  'avr-libc/malloc.c',
  'wiring_digital.c',
  'wiring_pulse.c',
  'wiring.c',
  'HID.cpp',
  'new.cpp',
  'Tone.cpp',
  'main.cpp',
  'WString.cpp',
  'CDC.cpp',
  'HardwareSerial.cpp',
  'IPAddress.cpp',
  'Print.cpp',
  'WMath.cpp',
  'Stream.cpp',
  'USBCore.cpp'
]

ardu_src = []
foreach f : ardu_lib_files
  ardu_src += ardu_src_dir + f
endforeach

arducore = static_library('arducore',
  ardu_src)

cobc = find_program('cobc')

cfile = custom_target('arduinoc',
  input : 'arduino.cob',
  output : ['arduinoc.c', 'arduinoc.c.h'],
  command : [cobc, '-C', '-o', '@OUTPUT0@', '@INPUT@'],
  )

exe = executable('arducob', cfile, 'cobmain.c', 'libcob.c', 'ardulib.cpp', 'LiquidCrystal.cpp',
  link_with : arducore,
  )


objcopy = find_program('avr-objcopy')
avrdude = find_program('avrdude')

eep = custom_target('arducob.eep',
  input : exe,
  output : 'arducob.eep',
  command : [objcopy, '-O', 'ihex', '-j', '.eeprom',
    '--set-section-flags=.eeprom=alloc,load',
    '--no-change-warnings', '--change-section-lma',
    '.eeprom=0', '@INPUT@', '@OUTPUT@',
  ]
)

hex = custom_target('arducob.hex',
  input : exe,
  output : 'arducob.hex',
  command : [objcopy, '-O', 'ihex', '-R', '.eeprom',
    '@INPUT@', '@OUTPUT@',
  ],
  depends : eep,
)

run_target('ardup',
  command : [avrdude,
  '-C/usr/share/arduino/hardware/tools/avrdude.conf',
  '-v', '-v', '-v', '-v',
  '-patmega328p', '-carduino', '-P/dev/ttyACM0', '-b115200',
  '-D', '-Uflash:w:@0@:i'.format(hex.full_path())],
  depends : hex,
)
  