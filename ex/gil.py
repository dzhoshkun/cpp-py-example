#!/usr/bin/env python3

from pymycpp import Bitmap, Proc
from over import PyBitmap
from time import sleep


if __name__ == '__main__':
    proc = Proc()

    img = Bitmap('baboon.bmp')
    pimg = PyBitmap('baboon.bmp')

    proc.start(img)
    sleep(5)
    proc.stop()

    proc.start(pimg)
    sleep(5)
    proc.stop()
