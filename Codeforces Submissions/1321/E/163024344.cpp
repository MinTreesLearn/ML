#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
vector<int>e[N];
int d[N];
int tr[N<<2];
int lazy[N<<2];
void pushdown(int root){
      tr[root<<1]+=lazy[root];
      tr[root<<1|1]+=lazy[root];
      lazy[root<<1]+=lazy[root];
      lazy[root<<1|1]+=lazy[root];
      lazy[root]=0;
}
void update(int root,int l,int r,int L,int R,int val)
{
    if(L<=l&&R>=r)
    {
        if(L==R)
        {
            tr[root]=max(val,tr[root]);
            return;
        }
        tr[root]+=val;
        lazy[root]+=val;
        return;
    }
    int mid=l+r>>1;
    pushdown(root);
    if(L<=mid)update(root<<1,l,mid,L,R,val);
    if(R>mid)update(root<<1|1,mid+1,r,L,R,val);
    tr[root]=max(tr[root<<1],tr[root<<1|1]);
}
void solve()
{
    memset(tr,-0x3f3f,sizeof(tr));
    int n,m,p;
    cin>>n>>m>>p;
    vector<pair<int,int>>a(n);
    for(int i=0; i<n; i++)cin>>a[i].first>>a[i].second;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        update(1,1,1e6+2,x,x,-y);
    }
    vector<array<int,3>>mo(p);
    sort(a.begin(),a.end());
    for(int i=0; i<p; i++)cin>>mo[i][0]>>mo[i][1]>>mo[i][2];
    sort(mo.begin(),mo.end());
    int j=0;
    int ans=-1e18;
    for(int i=0; i<n; i++)
    {
//        cout<<mo[p][0]<<' '<<a[i].first<<'\n';
        while(j<p&&mo[j][0]<a[i].first)
        {
            update(1,1,1e6+2,mo[j][1]+1,1e6+2,mo[j][2]);
            j++;
//            cout<<"???\n";
        }
        ans=max(ans,tr[1]-a[i].second);
//        cout<<i<<' '<<ans<<' '<<tr[1]<<'\n';
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

  			 		    		     	 			 	   		