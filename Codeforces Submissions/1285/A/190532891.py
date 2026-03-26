n = input()
stepsmin = 0
stepsmax = 0
pozic = 0
s = input()
for i in range(int(n)):
    if s[i] == "L":
        stepsmin -= 1
    else:
        stepsmax += 1
for j in range(stepsmin, stepsmax + 1):
    pozic += 1
print(pozic)
