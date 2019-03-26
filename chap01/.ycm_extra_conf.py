flags = [
'-Wall',
'-Wextra',
'-Werror',
'-Wno-long-long',
'-Wno-variadic-macros',
'-fexceptions',
'-DNDEBUG',
'-std=c99',
'-x',
'c',
'-I',
'/usr/include',
'-isystem',
'/usr/lib/gcc/x86_64-linux-gnu/5/include',
'-isystem',
'/usr/include/x86_64-linux-gnu',
'-isystem'
'/usr/include/c++/5',
'-isystem',
'/usr/include/c++/5/bits'
]
def FlagsForFile(filename):
    return {'flags': flags}
