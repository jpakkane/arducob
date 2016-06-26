project('arduino cobol', 'c', 'cpp')

cobc = find_program('cobc')

cfile = custom_target('arduinoc',
  input : 'arduino.cob',
  output : ['arduinoc.c', 'arduinoc.c.h'],
  command : [cobc, '-C', '-o', '@OUTPUT0@', '@INPUT@'],
  )

executable('arducob', cfile, 'cobmain.c', 'libcob.c')
