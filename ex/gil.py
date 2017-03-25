from pymycpp import Bitmap, Proc
from swap import SwappedBitmap
from time import sleep


if __name__ == '__main__':
    proc = Proc()

    img = Bitmap('baboon.bmp')
    pimg = SwappedBitmap('baboon.bmp')

    proc.start(img)
    sleep(5)
    proc.stop()

    proc.start(pimg)
    sleep(5)
    proc.stop()
