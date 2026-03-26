# https://codeforces.com/problemset/problem/1305/E


def gen_sequence(size, balance):
    result = []
    for i in range(1, size + 1):
        triple_count = (i - 1) >> 1
        if triple_count <= balance:
            result.append(i)
            balance -= triple_count 
        else:
            break
    if len(result) == size and balance > 0:
        return [-1]
    if balance > 0:
        result.append(2 * (result[-1] - balance) + 1)
    delta = result[-1] + 1
    while len(result) < size:
        value = result[-1] + delta
        if value % 2 == 0:
            value += 1
        result.append(value)
    return result


if __name__ == '__main__':
    size, balance = map(int, input().split())
    for x in gen_sequence(size, balance):
        print(x, end=' ')
    print()