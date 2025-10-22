N = int(input())
S = {str(n + 1): input() for n in range(N)}
X, Y = input().split()


def main(dic, x, y):
    if dic[x] == y:
        print("Yes")
    else:
        print("No")


main(S, X, Y)
