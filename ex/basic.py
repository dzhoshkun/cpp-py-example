from pymycpp import Cimage


img = Cimage(1920, 1080)
print('{} x {}'.format(img.width(), img.height()))
