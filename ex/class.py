from pymycpp import Bitmap


filepath = 'baboon.bmp'

img = Bitmap(filepath)
print( '{}x{} image read'
       ' from {}'.format( img.get_width(),
                          img.get_height(),
                          filepath ) )

print( 'Saving image to {}'.format(img.save()) )
