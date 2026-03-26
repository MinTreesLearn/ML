for _ in range(int(input())):
    nish=int(input())
    girish=[int(x) for x in input().split()]
    girish.sort()
    print(girish[nish]-girish[nish-1])

