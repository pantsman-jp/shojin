X, Y = map(int, input().split())


def f(x):
    return int(str(x)[::-1])


def a(i):
    global X, Y
    if i == 1:
        return X
    if i == 2:
        return Y
    return f(a(i - 1) + a(i - 2))


print(a(10))
