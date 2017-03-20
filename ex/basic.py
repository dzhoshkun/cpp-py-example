from pymycpp import Cimage


if __name__ == '__main__':
    img = Cimage(1920, 1080)
    print( '{} x {} image'.format( img.width(), img.height() ) )
