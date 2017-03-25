#!/usr/bin/env python3

from pymycpp import Bitmap


if __name__ == '__main__':
    mem = Bitmap.get_memory(1920, 1080)
    print( 'Allocated memory has shape {}'.format(mem.shape) )
