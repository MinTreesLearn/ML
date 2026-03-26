#include <iostream>
char a[1000010];
using namespace std;
int main() {
int t,i,k,j,n;
scanf("%d",&n);
scanf("%s",a);
int sum=0;
int minn=0;
int cnt=0;
j=k=0;
for(i=0;i<=n-1;i++)
{
if(a[i]=='(')
{
sum++;
j++;
}
else
{
k++;
sum--;
}
if(sum==0)
{
if(minn!=0)
cnt+=minn+1;
minn=0;
}
else if(sum<0)
minn++;
}
if(j==k)
printf("%d\n",cnt);
else
printf("-1\n");
return 0;
}
