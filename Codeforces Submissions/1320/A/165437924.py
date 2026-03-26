n = int(input())
beauty = list(map(int, input().split()))
dic = {}
for i in range(n):
	dic[i-beauty[i]] = dic.get(i-beauty[i], 0) + beauty[i]

print(max(dic.values()))