# include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

map<int,int>mp;
ll a[200000+10],n;
int pos[200000+10];
ll tree[200000*4+10],dp[200000+10],add[200000*4+10];

void build(int root,int l,int r)
{
    if(l==r)
    {
        tree[root]=dp[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);

    tree[root]=min(tree[root<<1],tree[root<<1|1]);
}

void pushdown(int root)
{
    if(add[root])
    {
        add[root<<1]+=add[root];
        add[root<<1|1]+=add[root];

        tree[root<<1]+=add[root];
        tree[root<<1|1]+=add[root];
        add[root]=0;
    }
}

void change(int root,int l,int r,int L,int R,ll val)
{
   // cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(L<=l&&r<=R)
    {
        tree[root]+=val;
        add[root]+=val;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(root);

    if(L<=mid)
        change(root<<1,l,mid,L,R,val);
    if(R>mid)
        change(root<<1|1,mid+1,r,L,R,val);

     tree[root]=min(tree[root<<1],tree[root<<1|1]);

}

int main ()
{

  cin>>n;

  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
      pos[a[i]]=i;
  }

  for(int i=1;i<=n;i++)
  {
      int x;
      cin>>x;
      mp[a[i]]=x;
  }


ll mid=1;
ll ans=mp[a[1]];
for(int i=1;i<=n;i++)
{
    if(pos[i]>mid)
    {
        ans+=mp[i];
        dp[i]=ans;
    }
    else
    {
        ans-=mp[i];
        dp[i]=ans;
    }

    //cout<<dp[i]<<" ";
}

//cout<<endl;

build(1,1,n);
ll ans1=tree[1];
for(mid=2;mid<n;mid++)
{

    change(1,1,n,a[mid],n,-mp[a[mid]]);
    if(a[mid]>1)
     change(1,1,n,1,a[mid]-1,mp[a[mid]]);

    ans1=min(ans1,tree[1]);

}

cout<<min(ans1,(ll)mp[a[1]]);
    return 0;
}
