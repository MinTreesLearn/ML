#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int n,m;
int f[4*maxn],lazy[4*maxn];

void down(int x, int lx, int rx)
{
    f[x]+=(rx-lx+1)*lazy[x];
    if (lx!=rx)
    {
        lazy[2*x]+=lazy[x];
        lazy[2*x+1]+=lazy[x];
    }
    lazy[x]=0;
}

void add(int x, int lx, int rx, int l, int r, int val)
{
    if (lazy[x]!=0) down(x,lx,rx);
    if (lx>r||rx<l) return;
    if (lx>=l&&rx<=r)
    {
        lazy[x]+=val;
        down(x,lx,rx);
        return;
    }
    int mid=(lx+rx)/2;
    add(2*x,lx,mid,l,r,val);
    add(2*x+1,mid+1,rx,l,r,val);
    f[x]=f[2*x]+f[2*x+1];
}

int get(int x, int lx, int rx, int l, int r)
{
    if (lazy[x]!=0) down(x,lx,rx);
    if (lx>r||rx<l) return 0;
    if (lx>=l&&rx<=r) return f[x];
    int mid=(lx+rx)/2;
    return get(2*x,lx,mid,l,r)+get(2*x+1,mid+1,rx,l,r);
}

vector <int> zfunction(string s)
{
    int n=s.length();
    vector <int> z(n,0);
    int l,r;
    l=r=0;
    z[0]=0;
    for (int i=1; i<n; i++)
    {
        z[i]=0;
        if (i<=r) z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if (i+z[i]-1>r)
        {
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    string a,b,s; cin>>a>>b>>s;
    vector <int> z=zfunction(s+'$'+a);
    vector <int> za(n+1), zb(n+1);
    for (int i=1; i<=n; i++) za[i]=z[i+m];
    reverse(s.begin(),s.end());
    reverse(b.begin(),b.end());
    z=zfunction(s+'$'+b);
    for (int i=n; i>=1; i--) zb[n-i+1]=z[i+m];
    int ans=0;
    for (int i=n; i>=1; i--)
    {
        add(1,1,m,1,zb[i],1);
        if (i+m-1<=n) add(1,1,m,1,zb[i+m-1],-1);
        ans+=get(1,1,m,m-za[i],m-1);
    }
    cout<<ans<<'\n';

}

  		 	  				   			  		 		  				