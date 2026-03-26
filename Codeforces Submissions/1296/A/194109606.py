import sys
input = sys.stdin.readline
output = sys.stdout.write


def main():
    tests = int(input().rstrip())
    for i in range(tests):
        length_ = int(input().rstrip())
        list_ = list(map(int, input().rstrip().split()))
        if length_ % 2 == 0:
            i = 0
            for num in list_:
                if num % 2 == 1:
                    i += 1
            if not (0 < i < length_) is True:
                output('NO')
            else:
                output('YES')
        else:
            state = False
            for num in list_:
                if num % 2 == 1:
                    state = True
                    break
            if state:
                output('YES')
            else:
                output('NO')
        output('\n')


if __name__ == '__main__':
    main()
