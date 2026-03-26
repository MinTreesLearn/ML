numTests = int(input())
for _ in range(numTests):
    n = int(input())
    bucket1 = []
    bucket2 = []
    skill = list(map(int, input().split()))
    skill.sort()
    print(abs(skill[n] - skill[n-1]))
