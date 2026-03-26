n=int(input())
s=input()
arr=[]
for i in range(n):
  arr.append((s[i],i))
arr.sort(key=lambda x:(x[0],x[1]))
# print(arr)
new=[0 for i in range(n)]
for i in range(n):
  new[arr[i][1]]=i
arr=new
color=[-1 for i in range(n)]
st=[]
fin=[]
i=0
index=0
yes=1
# print(arr)
colored={}
while(i<n):
  # print("itr",i,index)
  if index<n and arr[index]==i:
    color[index]=0
    colored[arr[index]]=1
    fin.append(arr[index])
    index+=1
  elif (st and st[0]==i):
    st.pop(0)
    fin.append(i)
  elif i in colored:
    yes=0
    print("no")
    break
  else:
    while(arr[index]!=i):
      # print("k",index,i)
      st.append(arr[index])
      color[index]=1
      colored[arr[index]]=1
      index+=1
    color[index]=0
    colored[arr[index]]=1
    fin.append(arr[index])
    index+=1
  i+=1
  # print(color)
  # print(fin)
  # print(st)
if yes:
  print("yes")
  color=[str(i) for i in color]
  print("".join(color))