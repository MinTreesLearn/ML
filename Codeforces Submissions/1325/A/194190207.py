import sys
input = sys.stdin.readline
output = sys.stdout.write


def main():
    tests = int(input().rstrip())
    for i in range(tests):
        num = int(input().rstrip())
        output(str(num - 1) + ' ' + '1')
        output('\n')


if __name__ == '__main__':
    main()

