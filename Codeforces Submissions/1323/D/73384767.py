import math
input_list =   lambda:  list(map(int, input().split()))


def main():
    n = int(input())
    a =  input_list()
    temp = []
    ans = 0
    for bit in range(26):
        temp.clear()
        
        value1 = 2**bit
        value2 = 2**(bit + 1) - 1
        value3 = 2**(bit + 1) + 2**bit
        value4 = 2**(bit + 2) - 1
        for i in range(n):
            temp.append(a[i]%(2**(bit+1)))
        f1, l1, f2, l2 = [n-1, n-1, n-1, n-1]
        temp.sort()
        noOfOnes = 0
        for i in range(n):
            while  f1>=0 and temp[f1]+temp[i]>=value1:
                f1 = f1 - 1
            while  l1>=0 and temp[l1] + temp[i]>value2:
                l1 = l1 - 1
            while f2>=0 and temp[f2] + temp[i]>=value3 :
                f2 = f2 - 1
            while  l2>=0 and temp[l2] + temp[i]>value4:
                l2 = l2 - 1
            noOfOnes = noOfOnes + max(0, l1 - max(i,f1))
            noOfOnes = noOfOnes + max(0, l2 - max(i, f2))
        if noOfOnes%2==1:
                ans = ans + 2**bit
    print(ans)





main()