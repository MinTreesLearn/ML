t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    s = input()
    p = list(map(int, input().split()))
    mp = [0] * n
    for value in p:
        mp[value - 1] += 1
    for i in range(n - 1, 0, -1):
        mp[i - 1] += mp[i]
    occ = [0] * 26
    for i in range(len(s)):
        occ[ord(s[i]) - ord('a')] += mp[i]
        occ[ord(s[i]) - ord('a')] += 1
    print(' '.join(list(map(str, occ))))
			 	 	     