#!/usr/bin/env python
# encoding: utf-8

ans = 1
for i in range(100):
    ans *= (i + 1)
    while (ans % 10 == 0):
        ans /= 10

sum = 0
while (ans > 0):
    sum += ans % 10
    ans /= 10
print(sum)
