t = int(input())
for _ in range(t):
    s = input()
    consec = 0
    biggest = 0
    for i in range(len(s)):
        if s[i] == "R":
            consec = 0
        else:
            consec += 1
        if consec > biggest:
            biggest = consec
    print(biggest+1)