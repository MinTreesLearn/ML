import sys

MAX_DIGIT = 64


def solve():
    n, m = map(int, input().split())
    alist = map(int, sys.stdin.readline().split())

    digit_cnt = [0] * MAX_DIGIT
    ticket_cnt = [0] * MAX_DIGIT

    two_cnt_map = dict()
    for i in range(MAX_DIGIT):
        two_cnt_map[1 << i] = i

    for a in alist:
        digit_cnt[two_cnt_map[a]] += 1

    for i in range(MAX_DIGIT - 1):
        ticket_cnt[i + 1] += digit_cnt[i] // 2
        digit_cnt[i + 1] += digit_cnt[i] // 2
        digit_cnt[i] %= 2

    split = 0
    for d in range(MAX_DIGIT - 1, -1, -1):
        if n & (1 << d):
            if digit_cnt[d] > 0:
                digit_cnt[d] -= 1
            else:
                # TODO: d자릿수를 구성하기 위해 더 큰 숫자를 쪼개서 당겨온다.
                target_digit = -1
                for i in range(d + 1, MAX_DIGIT):
                    if digit_cnt[i] > 0:
                        target_digit = i
                        break

                if target_digit == -1:
                    print(-1)
                    return

                for i in range(target_digit, d, -1):
                    digit_cnt[i] -= 1
                    digit_cnt[i - 1] += 2
                    if ticket_cnt[i] > 0:
                        ticket_cnt[i] -= 1
                    else:
                        split += 1

                digit_cnt[d] -= 1
    print(split)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()