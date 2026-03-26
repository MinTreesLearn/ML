t = int(input())
t_c = [tuple(map(int, input().split())) for _ in range(t)]
for i in t_c:
    l = None
    if i[1] < 9 :
        l = 0
    elif int((tmp := len(str(i[1]))) * '9') <= i[1]:
        l = tmp
    else:
        l = tmp - 1
    print(i[0] * l)