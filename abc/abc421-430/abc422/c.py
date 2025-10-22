T = int(input())
testcase = [list(map(int, input().split())) for _ in range(T)]


def main(xss):
    for [a, b, c] in xss:
        print(min(a, c, (a + b + c) // 3))


main(testcase)
