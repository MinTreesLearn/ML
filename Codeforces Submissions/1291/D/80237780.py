import string


def solve():
  s = input()
  n = int(input())

  alphabets = len(string.ascii_lowercase)
  count = [[0] * alphabets for _ in range(len(s) + 1)]

  for i, c in enumerate(s, 1):
      count[i][ord(c) - ord('a')] += 1
      for c in range(alphabets):
        count[i][c] += count[i - 1][c]

  def query(l, r):
      if l == r:
          return 'Yes'
      if s[l - 1] != s[r - 1]:
          return 'Yes'

      unique = 0
      for x, y in zip(count[l - 1], count[r]):
          if y - x > 0:
              unique += 1
              if unique > 2:
                  return 'Yes'

      return 'No'

  for _ in range(n):
      print(query(*map(int, input().split())))


solve()
