n = int(input())
ar = list(input())
for i in range(ord('z'), ord('a'), -1):
    for z in range(100):
        kek = []
        for j in range(len(ar) - 1):
            if ar[j] == chr(i) and ar[j + 1] == chr(i - 1):
                pass
            else:
                kek.append(ar[j])
        kek.append(ar[-1])
        ar = kek.copy()
        kek = [ar[0]]
        for j in range(1, len(ar)):
            if ar[j] == chr(i) and ar[j - 1] == chr(i - 1):
                pass
            else:
                kek.append(ar[j])
        ar = kek.copy()
print(n - len(ar))