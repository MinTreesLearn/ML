#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define mod 1000000007

int sum[300000*2+10],minn[300000+10],maxx[300000+10],pos[300000+10],n,m;
int lowbit(int x)
{
    return x&-x;
}
void change(int x,int val)
{
    while(x<=n+m)
    {
        sum[x]+=val;
        x+=lowbit(x);
    }
}

int getsum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{

  cin>>n>>m;

  for(int i=1;i<=n;i++)
  {
      minn[i]=maxx[i]=i;
      change(i+m,1);
      pos[i]=i+m;
  }
  int now=m;

  for(int i=1;i<=m;i++)
  {
      int x;
      cin>>x;
      minn[x]=1;
      int pre=getsum(pos[x]);
      maxx[x]=max(maxx[x],pre);
      change(pos[x],-1);
      pos[x]=now;
      now--;
      change(pos[x],1);

  }

  for(int i=1;i<=n;i++)
  {
      maxx[i]=max(maxx[i],getsum(pos[i]));

      cout<<minn[i]<<" "<<maxx[i]<<endl;
  }
    return 0;
}


