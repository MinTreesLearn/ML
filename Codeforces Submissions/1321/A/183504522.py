count_of_ex = int(input())
rob1 = [int(x) for x in input().split()]
rob2 = [int(x) for x in input().split()]
rob1_dom = 0
rob2_dom = 0
i = 0
while i < count_of_ex:
	if rob2[i] > rob1[i]:
		rob2_dom += 1
	elif rob1[i] > rob2[i]:
		rob1_dom += 1
	i += 1
if rob1_dom == 0:
	print(-1)
else:
	if rob1_dom > rob2_dom:
		print(1)
	else:
		print(rob2_dom//rob1_dom + 1)