def output_ans(ans):
    print('YES')
    print(len(ans))
    for x in ans:
        print(x[0], x[1])


if __name__ == '__main__':
    n, m, k = [int(x) for x in input().split(' ')]

    ans_list = list()
    ans_list.append((m - 1, 'R'))
    ans_list.append((m - 1, 'L'))
    for _ in range(n - 1):
        ans_list.append((1, 'D'))
        ans_list.append((m - 1, 'RUD'))
        ans_list.append((m - 1, 'L'))
    ans_list.append((n - 1, 'U'))

    count = 0
    ans = list()
    for op in ans_list:
        if op[0] == 0:
            continue
        for x in range(op[0]):
            for j in range(len(op[1])):
                count += 1
                if count == k:
                    if x > 0:
                        ans.append((x, op[1]))
                    ans.append((1, op[1][0:j + 1]))
                    output_ans(ans)
                    exit(0)
        ans.append((op[0], op[1]))

    if k > count:
        print('NO')
        exit(0)
    output_ans(ans)
