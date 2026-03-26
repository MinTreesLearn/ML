t = int(input())
for i in range(t):
    s1 = input()
    s2 = input()
    s3 = input()
    ans ="YES"
    for i in range(len(s2)):
        if s3[i] != s2[i] and s3[i] != s1[i]:
            ans = "NO"

    print(ans)