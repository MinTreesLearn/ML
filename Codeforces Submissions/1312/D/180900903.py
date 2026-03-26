import math
import itertools
import datetime
from typing import List
from sys import stdin
input = stdin.readline

class Solution:
    def __init__(self):
        self.n, self.m = map(int, input().split())
        self.mod = 998244353


    def binpow(self, a: int, b: int = 998244353 - 2) -> int:
        ans = 1
        i = 1
        while i <= b:
            if b&i:
                ans = (ans * a) % mod
            a = (a * a) % mod
            i *= 2
        return ans

    def precompute(self, T: int) -> None:
        self.fac = [0 for i in range(T + 1)]
        self.fac[0] = 1
        self.ifac = [0 for i in range(T + 1)]
        for i in range(1, T + 1):
            self.fac[i] = (i * self.fac[i - 1]) % self.mod
        self.ifac[T] = self.binpow(self.fac[T])
        for i in range(T, 0, -1):
            self.ifac[i - 1] = i * self.ifac[i] % self.mod
        assert self.ifac[0] == self.fac[0]

    def choose(self, a: int, b: int):
        if b < 0 or a - b < 0: return 0
        return self.fac[a] * self.ifac[b] % self.mod * self.ifac[a - b] % self.mod

    #returns if array satisfies the strictly increasing then decreasing property
    def is_valid(self, a: List[int]) -> bool:
        if len(a) <= 1: return True
        increasing = True
        for i in range(1, len(a)):
            if a[i] == a[i - 1]:
                return False
            if increasing:
                if a[i] < a[i - 1]:
                    increasing = False
                    continue
            else:
                if a[i] > a[i - 1]:
                    return False

        return True if not increasing else False

    def slow_comp(self) -> int:
        #initially choose m - 1 numbers
        init_choices = math.comb(self.m, self.n - 1)
        ans = 0
        for repeat in range(1, self.n - 1):
            a = [i for i in range(1, self.n)] + [repeat]
            for perm in set(itertools.permutations(a)):
                if self.is_valid(list(perm)): ans += 1

        ans *= init_choices

        return ans
        

    def fast_comp(self):
        return int(self.choose(self.m, self.n - 1) * (self.n - 2) * 2 ** (self.n - 3))

mod = 998244353
solution_obj = Solution()
solution_obj.precompute(200000)
print(solution_obj.fast_comp() % mod)





