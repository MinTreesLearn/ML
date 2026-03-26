if __name__ == '__main__':
    n = input()
    a = input()
    ll = a.split(' ')
    l = [int(x) for x in ll]
    # max_val = max(l)
    # max_bit = 0
    # while max_val:
    #     max_val >>= 1
    #     max_bit += 1


    def solve(arr: list, bit: int) -> int:
        if not arr or bit < 0:
            return 0
        zero = []
        one = []
        for x in arr:
            if (x >> bit) & 1:
                one.append(x)
            else:
                zero.append(x)
        if not one:
            return solve(zero, bit - 1)
        if not zero:
            return solve(one, bit - 1)
        return min(solve(zero, bit - 1), solve(one, bit - 1)) + (1 << bit)

    ans = solve(l, 30)
    print(ans)
