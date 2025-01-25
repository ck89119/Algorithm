#!/usr/bin/env python
# encoding: utf-8

import math

a = 1
b = 1
i = 3
while True:
    a, b = b, a+b
    if int(math.log10(b)) + 1 >= 2:
        print('{}, {}'.format(i, b))
        break
    i += 1
