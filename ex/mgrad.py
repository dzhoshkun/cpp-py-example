#!/usr/bin/env python3


def grad(arr):
    height, width, _ = arr.shape
    for j in range(height):
        j_slice = float(j + 1)
        for i in range(width):
            i_slice = float(i + 1)
            arr[j, i, 0] = int(i_slice / width * 255)
            arr[j, i, 1] = 255
            arr[j, i, 2] = int(j_slice / height * 255)
