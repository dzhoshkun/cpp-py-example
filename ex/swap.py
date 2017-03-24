from pymycpp import Bitmap


class SwappedBitmap(Bitmap):

    def __init__(self, filepath):
        super(SwappedBitmap, self).__init__(filepath)

        _data = self.data()
        _data[:, :, 0], _data[:, :, 2] = _data[:, :, 2], _data[:, :, 0]


if __name__ == '__main__':

    simg = SwappedBitmap('baboon.bmp')
    simg.save()
