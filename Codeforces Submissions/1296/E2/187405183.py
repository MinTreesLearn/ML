n=int(input())
s=input()
ans=1
d=""
arr=["a"]
for i in range(n):
  # print(i,arr,d)
  if s[i]<arr[-1]:
    d+=str(len(arr)+1)+" "
    arr.append(s[i])
  else:
    for j in range(len(arr)):
      if s[i]>=arr[j]:
        d+=str(j+1)+" "
        arr[j]=s[i]
        break
      
print(len(arr))
print(d)