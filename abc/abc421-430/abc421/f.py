Q = int(input())
query = [list(map(int, input().split())) for _ in range(Q)]


def main(query):
    A = [0]
    for [i, q] in enumerate(query, 1):
        if q[0] == 1:
            j = A.index(q[1])
            A = A[: j + 1] + [i] + A[j + 1 :]
        else:
            xy = [A.index(q[n]) for n in [1, 2]]
            j, k = min(xy), max(xy)
            print(sum(A[j + 1 : k]))
            A = A[: j + 1] + A[k:]
    return


main(query)
