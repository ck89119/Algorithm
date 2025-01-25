#!/usr/bin/env python
# encoding: utf-8


def cal(n):
    if n <= 10000 and f[n] != -1:
        return f[n]
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i
    if n <= 10000:
        f[n] = sum
    return sum


f = [-1 for i in range(10001)]
s = [0 for i in range(10001)]
for i in range(1, 10000):
    x = cal(i)
    if x < 10000 and x != i and cal(x) == i:
        s[i] = 1
sum = 0
for i in range(1, 10000):
    if s[i]:
        sum += i
print(sum)
