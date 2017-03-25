from pymycpp import Bitmap, Cproc
from swap import SwappedBitmap
from time import sleep


if __name__ == '__main__':
    proc = Cproc()

    img = Bitmap('baboon.bmp')
    pimg = SwappedBitmap('baboon.bmp')

    proc.start(img)
    sleep(5)
    proc.stop()

    proc.start(pimg)
    sleep(5)
    proc.stop()
