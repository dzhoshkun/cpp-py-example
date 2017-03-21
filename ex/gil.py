from pymycpp import Cimage, Cproc
from inheritance import Pimage
from time import sleep


if __name__ == '__main__':
    proc = Cproc()
    cimg = Cimage(500, 300)
    pimg = Pimage(750, 450)
    proc.run(cimg)
    sleep(5)
    proc.stop()
    proc.run(pimg)
    sleep(5)
    proc.stop()
