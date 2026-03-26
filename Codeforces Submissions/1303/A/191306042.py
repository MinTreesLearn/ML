def main():
    t = int(input())
    for _ in range(t):
        s = input().strip()
        i = 0
        n = len(s)
        res = 0
        j = n-1

        while i < n and s[i] == '0':
            i += 1
        while j >= i and s[j] == '0':
            j -= 1

        while i <= j:
            if s[i] == '0':
                res += 1
            i += 1

        print(res)

if __name__ == '__main__':
    main()