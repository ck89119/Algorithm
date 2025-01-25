def f1(x):
    return ((x << 6) ^ x) & ((1 << 24) - 1)

def f2(x):
    return ((x >> 5) ^ x) & ((1 << 24) - 1)

def f3(x):
    return ((x << 11) ^ x) & ((1 << 24) - 1)

def f(x):
    return f3(f2(f1(x)))

ans = 0
with open('in.txt') as file:
    for line in file:
        #  print(line)
        x = int(line)
        #  print(x)

        for i in range(2000):
            x = f(x)
        #  print(x)
        ans += x

print(ans)
