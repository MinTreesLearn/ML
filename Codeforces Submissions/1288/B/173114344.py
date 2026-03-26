t = int(input())
for i in range(t):
    a,b = [i for i in input().split()]
    toadd = 0
    cmpr = '9'*len(b)
    if int(b) == int(cmpr):
        toadd = 1
    print(int(a)*(len(b)-1+toadd))
# count = 0
# for i in range(1,10001):
#     for j in range(1,1000):
#         if i+j+i*j == int(str(i)+str(j)):
#             s = str(j)
#             if s.count('9') != len(s):
#                 print(i,j)
#             count+=1
# print(count,)