from collections import defaultdict
s = input()
d = defaultdict(int)
for c in s:
	for a in range(97,123):
		a = chr(a)
		d[a+c]+=d[a]
	d[c]+=1
print(max(d.values()))