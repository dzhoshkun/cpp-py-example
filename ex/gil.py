from pymycpp import Cimage, Cproc
from inheritance import Pimage


if __name__ == '__main__':
    proc = Cproc()
    cimg = Cimage(500, 300)
    pimg = Pimage(750, 450)
    proc.run(cimg)
    proc.run(pimg)
