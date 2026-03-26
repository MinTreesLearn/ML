import pdb
s=input()
num1=[0 for i in range(26)]
num2=[[0 for i in range(26)] for j in range(26)]
for i in range(len(s)):
    for j in range(26):
        num2[j][(ord(s[i])-97)]+=num1[j]
    num1[(ord(s[i])-97)]+=1
    
result=max(num1)

# pdb.set_trace()
for i in range(26):
    for j in range(26):
        # if num2[i][j]!=0:
        #     print(i,j,num2[i][j])
        result=max(num2[i][j],result)

print(result)