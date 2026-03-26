t = int(input(""))

for test in range(t):
    s = int(input(""))
    spent = 0

    while s!= 0:
        if s >= 10:
            gain = s//10
            spent += gain*10
            s -= gain*10
            s += gain
        else:
            spent += s
            s = 0

    print(spent)