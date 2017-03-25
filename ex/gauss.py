#!/usr/bin/env python3

from pymycpp import Bitmap
import scipy.ndimage as ndi


if __name__ == '__main__':
    img = Bitmap('baboon.bmp')

    data_np = img.data()

    ndi.gaussian_filter(input=data_np,
                        sigma=(5, 15, 0),
                        order=0,
                        output=data_np)

    img.save()
