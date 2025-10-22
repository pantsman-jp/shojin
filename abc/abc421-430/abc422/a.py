i, j = list(map(int, input().split("-")))


def main(i, j):
    if j < 8:
        return str(i) + "-" + str(j + 1)
    if i < 8 and j == 8:
        return str(i + 1) + "-1"


print(main(i, j))
