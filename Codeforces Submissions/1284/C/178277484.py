from itertools import permutations

def solve(n):
  ans = [0 for i in range(n)]
  for p in permutations(range(n)):
    for st in range(n):
      mx = mn = p[st]
      for en in range(st, n):
        mx = max(mx, p[en])
        mn = min(mn, p[en])

        if mx - mn == en - st:
          ans[en - st] += 1

  return ans

def inv(a, mod):
  return pow(a, mod - 2, mod)

def real_solve(n, mod):
  fact = [1]
  for i in range(1, n + 2):
    fact.append(fact[-1] * i % mod)

  ans = 0
  for i in range(n):
    n_start_base = i + 1
    base_element = fact[i + 1]
    inc = n - n_start_base
    cur = fact[inc] * base_element

    cur *= (n - i) ** 2
    cur %= mod
    ans += cur

  return ans % mod


n, m = map(int, input().split())
print(real_solve(n, m))