def read_ints():
    return map(int, input().split())


n, = read_ints()
r_seq = tuple(read_ints())
b_seq = tuple(read_ints())

rb_pairs = tuple(zip(r_seq, b_seq))
r_win_n = rb_pairs.count((1, 0))
b_win_n = rb_pairs.count((0, 1))

if r_win_n == 0:
    max_p = -1
else:
    max_p = 1
    while r_win_n <= b_win_n:
        max_p += 1
        b_win_n -= r_win_n

print(max_p)
