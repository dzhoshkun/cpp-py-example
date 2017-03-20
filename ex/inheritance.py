from pymycpp import Cimage


class Pimage(Cimage):

    def __init__(self, width, height):
        super(Pimage, self).__init__(width, height)

    def info(self):
        print('Pimage (Python)')


if __name__ == '__main__':
    cimg = Cimage(500, 300)
    pimg = Pimage(750, 450)

    cimg.info()
    pimg.info()
