project('arduino cobol', 'c', 'cpp')

cobc = find_program('cobc')

cfile = custom_target('helloc',
  input : 'hello.cob',
  output : ['hello.c', 'hello.c.h'],
  command : [cobc, '-C', '-o', '@OUTPUT0@', '@INPUT@'],
  )

executable('hello', cfile, 'cobmain.c', 'libcob.c')
