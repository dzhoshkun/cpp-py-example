#!/usr/bin/env python3

from pymycpp import Proc


if __name__ == '__main__':
    print( 'Version: {}'.format(Proc.get_version()) )
