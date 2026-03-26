class NextStringIndex:
    def __init__(self, string):
        self.INF = 10 ** 9
        self.alph = "abcdefghijklmnopqrstuvwxyz"
        self.kind = len(self.alph)
        self.to_ind = {char: ind for ind, char in enumerate(self.alph)}

        self.string = string
        self.len_s = len(string)
        self.next_ = self.make_next()

    def __getitem__(self, tup):
        ind, char = tup
        return self.next_[ind][self.to_ind[char]]

    def make_next(self):
        dp = [[self.INF] * self.kind for i in range(self.len_s + 1)]
        for i in range(len_s)[::-1]:
            for j, char in enumerate(self.alph):
                if s[i] == char:
                    dp[i][j] = i + 1
                else:
                    dp[i][j] = dp[i + 1][j]
        return dp


def solve(t1, t2, len_s):
    INF = 10 ** 9
    len_t1 = len(t1)
    len_t2 = len(t2)
    dp = [[INF] * (len_t2 + 1) for i in range(len_t1 + 1)]
    dp[0][0] = 0

    for i in range(len_t1 + 1):
        for j in range(len_t2 + 1):
            length = dp[i][j]
            if length > len_s:
                continue
            if i < len_t1 and s_next[length, t1[i]] < INF:
                dp[i + 1][j] = min(dp[i + 1][j], s_next[length, t1[i]])
            if j < len_t2 and s_next[length, t2[j]] < INF:
                dp[i][j + 1] = min(dp[i][j + 1], s_next[length, t2[j]])

    return dp[-1][-1] < INF


query = int(input())
for _ in range(query):
    s = input()
    t = input()
    len_s = len(s)
    len_t = len(t)

    s_next = NextStringIndex(s)
    
    flag = False
    for i in range(len_t + 1):
        flag |= solve(t[0:i], t[i:], len_s)
    if flag:
        print("YES")
    else:
        print("NO")