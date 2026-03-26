#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1000;
double a[N],st[N],len[N];
int n;
int main()
{
scanf("%d",&n);
for(int i=0;i<n;i++) scanf("%lf",&a[i]);
int p=0;
for(int i=0;i<n;i++)
{
st[++p]=a[i];len[p]=1;//st[i]保存平均数，len保存st[i]这个平均数有多少个数
while(p>1&&st[p]<st[p-1])//更新后面的数
{
st[p-1]=(st[p]*len[p]+st[p-1]*len[p-1])/(len[p]+len[p-1]);
len[p-1]+=len[p];//更新长度，因为又多了一部分进来
p--;
}
}
for(int i=1;i<=p;i++) //一共p块区域
{
for(int j=1;j<=len[i];j++) //每块区域的个数
printf("%.8lf\n",st[i]);
}
}
