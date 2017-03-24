from pymycpp import Bitmap


class PyBitmap(Bitmap):

    def __init__(self, filepath):
        super(PyBitmap, self).__init__(filepath)

    def info(self):
        return 'PyBitmap ++ {} x {}'.format(
            self.get_width(), self.get_height())


if __name__ == '__main__':
    img = Bitmap('baboon.bmp')
    print(img.info())

    pimg = PyBitmap('baboon.bmp')
    print(pimg.info())
