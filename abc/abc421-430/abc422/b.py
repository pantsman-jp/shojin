H, W = map(int, input().split())
S = [input() for _ in range(H)]


def count(xs):
    return len(list(filter(lambda c: c == "#", xs)))


def main(xs):
    for i in range(H):
        for j in range(W):
            if xs[i][j] == "#":
                ret = 0
                if i > 0 and xs[i - 1][j] == "#":
                    ret += 1
                if i < H - 1 and xs[i + 1][j] == "#":
                    ret += 1
                if j > 0 and xs[i][j - 1] == "#":
                    ret += 1
                if j < W - 1 and xs[i][j + 1] == "#":
                    ret += 1
                if ret not in [2, 4]:
                    return "No"
    return "Yes"


print(main(S))
