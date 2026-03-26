import sys
input = sys.stdin.readline
output = sys.stdout.write


def main():
    tests = int(input().rstrip())
    for i in range(tests):
        list_ = list(map(int, input().rstrip().split()))
        coins = list_.pop(-1)
        list_.sort()
        dif = (list_[2] - list_[1]) + (list_[2] - list_[0])
        state = False
        if coins >= dif:
            dif_2 = dif - coins
            if dif_2 % 3 == 0:
                state = True
        if state:
            output('YES')
        else:
            output('NO')
        output('\n')


if __name__ == '__main__':
    main()
    