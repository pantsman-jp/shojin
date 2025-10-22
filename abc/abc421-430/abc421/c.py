N = int(input())
S = input()


def main(s):
    pos = [i for [i, s] in enumerate(s) if s == "A"]
    abab = sum(abs(j - i * 2) for [i, j] in enumerate(pos))
    baba = sum(abs(j - (i * 2 + 1)) for [i, j] in enumerate(pos))
    return min(abab, baba)


print(main(S))
