from pymycpp import Cimage


if __name__ == '__main__':
    width = 1920
    height = 1080
    num_bytes = Cimage.how_many_bytes(width, height)
    print( '{} bytes needed to store {} x {} '
           'image'.format( num_bytes, width, height ) )
