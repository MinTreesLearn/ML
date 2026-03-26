import sys

input = sys.stdin.readline
output = sys.stdout.write


def main():
    tests = int(input().rstrip())
    for i in range(tests):
        a, b = map(int, input().rstrip().split())
        cond1 = a % 2 == 1 and b % 2 == 1
        cond2 = a % 2 == 0 and b % 2 == 0
        res = 1
        if a == b:
            output('0')
            output('\n')
            continue
        elif a < b:
            if cond1 is True or cond2 is True:
                res += 1
        else:
            if (cond1 is True or cond2 is True) is False:
                res += 1
        output(str(res))
        output('\n')


if __name__ == '__main__':
    main()
