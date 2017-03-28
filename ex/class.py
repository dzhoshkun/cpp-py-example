#!/usr/bin/env python3

from pymycpp import Bitmap


if __name__ == '__main__':
    filepath = 'baboon.bmp'

    img = Bitmap(filepath)

    width = img.get_width()
    height = img.get_height()

    print( '{}x{} image read from {}'.format(
        width, height, filepath ) )

    new_filepath = img.save()
    print( 'Saving image to {}'.format(
        new_filepath ) )
