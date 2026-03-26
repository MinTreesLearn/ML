testcase=int(input())
for _ in range(testcase):
    n=int(input())
    arr=[int(num) for num in input().split()]
    deleted=set()
    remaining_nums=set(range(1,2*n+1))
    doable=True
    
    for num in arr:
        deleted.add(num)
        remaining_nums.remove(num)
    



    remaining_nums=sorted(list(remaining_nums))
    ans=[0]*(2*n)
    for ind1,num1 in enumerate(arr):
        for ind2,num2 in enumerate(remaining_nums):
            if num2>num1:
                ans[ind1*2]=min(num2,num1)
                ans[ind1*2+1]=max(num2,num1)
                remaining_nums.pop(ind2)
                break
            if ind2==len(remaining_nums)-1:
                doable=False
                break
        if not doable:
            break
    print(" ".join(map(str,ans)) if doable else -1)