#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define ll long long
#define fs first
#define sc second
#define ii pair<int,int>
#define pb push_back
#define iii pair<int,ii>
#define cong 1000001
#define ld long double
#define pb push_back
#define int ll

const int MAX_VAL=1e5;

int ans=0,n,ktr[N],a[N],dpt,nt[N],f[N],dp[N];
vector<int>uoc[N],uoc_nt[N];
vector<int>lis[N],pos[N];

void build(int u)
{
    f[0]=1;
    for(int mask=1;mask<(1<<uoc_nt[u].size());mask++)
        for(int i=0;i<uoc_nt[u].size();i++)
            if((mask>>i)&1)
                f[mask]=f[mask-(1<<i)]*uoc_nt[u][i];
    for(int mask=1;mask<(1<<uoc_nt[u].size());mask++)
        if(__builtin_popcount(mask)&1)
            lis[u].pb(f[mask]);
                else lis[u].pb(-f[mask]);
}

void them(int u,int val)
{
    for(auto v:lis[u])
        dp[abs(v)]+=val;
}

int get(int u)
{
    int res=0;
    for(auto v:lis[u])
        if(v>0)
            res+=dp[v];
                else res-=dp[-v];
    return res;
}

void tknp(int l,int r,int gcd)
{
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++)
        them(a[i],1);
    for(auto i:pos[mid])
    {
     //   cout<<a[i]<<" "<<mid<<" "<<get(a[i])<<endl;
        if(get(a[i])<mid)
        {
        //    cout<<a[i]<<" "<<mid<<" "<<a[mid]<<" "<<dp[35]<<endl;
            ans=max(ans,a[i]*a[mid]*gcd);
            if(l<mid)
                pos[(l+(mid-1))/2].pb(i);
        }else
        {
            if(mid<r)
                pos[(r+(mid+1))/2].pb(i);
        }
    }
    if(mid<r)
        tknp(mid+1,r,gcd);
     for(int i=l;i<=mid;i++)
        them(a[i],-1);
    if(l<mid)
        tknp(l,mid-1,gcd);
}

void solve(int gcd)
{
    //if(gcd!=7)
     //   return;
    for(int i=1;i*2<=n;i++)
        swap(a[i],a[n-i+1]);
    for(int i=1;i<=n;i++)
        pos[i].clear();
    for(int i=1;i<=n;i++)
        pos[(n+1)/2].pb(i);//,cout<<i<<endl;
    for(int i=1;i<=n;i++)
        for(auto v:lis[a[i]])
            dp[abs(v)]=0;
    tknp(1,n,gcd);
 //   cout<<gcd<<" "<<ans<<" "<<n<<endl;
}

int32_t main()
{
  //  freopen("A.inp","r",stdin);
 //   freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u;
       // u=i;
        cin>>u;
       // cout<<u<<endl;
        ktr[u]=1;
    }
    for(int i=1;i<=MAX_VAL;i++)
        for(int j=i;j<=MAX_VAL;j+=i)
            uoc[j].pb(i);
    for(int i=2;i*i<=MAX_VAL;i++)
        if(nt[i]==0)
        {
            for(int j=i*i;j<=MAX_VAL;j+=i)
                nt[j]=1;
        }
    for(int i=2;i<=MAX_VAL;i++)
        if(nt[i]==0)
        {
            for(int j=i;j<=MAX_VAL;j+=i)
                uoc_nt[j].pb(i);
        }
    for(int i=1;i<=MAX_VAL;i++)
        build(i);
    for(int gcd=1;gcd<=MAX_VAL;gcd++)
    {
        n=0;
        for(int j=gcd;j<=MAX_VAL;j+=gcd)
            if(ktr[j]==1)
                a[++n]=j/gcd;
        solve(gcd);
    }
    cout<<ans;
    return 0;
}

     		  			 	 			 	 		  	  		