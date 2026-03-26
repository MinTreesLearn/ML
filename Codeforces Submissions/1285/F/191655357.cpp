#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxN=2e5+10;
#define pb push_back
#define int ll
#define pli pair<ll,ll>
#define fi first
#define se second
#define task "danang"
#define plii pair<ll,pli>
ll ct[maxN];
bool check(ll x)
{
    ll s=x;
    for(int i=2;i*i<=x;i++)
    {
        ll cnt=0;
        while(x%i==0)
        {
            cnt++;
            x/=i;
        }
        if(cnt>0) ct[s]++;
        if(cnt>1) return false;
    }
    if(x>1) ct[s]++;
    return true;
}
vector<ll> d[maxN];
ll cnt[maxN];
void add(ll x)
{
    for(auto zz:d[x])
    {
        cnt[zz]++;
    }
}
void del(ll x)
{
    for(auto zz:d[x])
    {
        cnt[zz]--;
    }
}
ll cal(ll x)
{
    ll ans=0;
    for(auto zz:d[x])
    {
        if(ct[zz]%2==0) ans+=cnt[zz];
        else ans-=cnt[zz];
    }
    return ans;
}
ll n,a[maxN];
vector<ll> vec[maxN];
bool c[maxN];
void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        vec[a[i]].pb(i);
    }
    for(int i=1;i<=1e5;i++)
    {
        c[i]=check(i);
    }
    for(int i=1;i<=1e5;i++)
    {
        if(c[i])
        {
            for(int j=i;j<=1e5;j+=i)
            {
                d[j].pb(i);
            }
        }
    }
    vector<ll> x;
    deque<ll> dq;
    ll ans=0;
    for(int i=1;i<=1e5;i++)
    {
        x.clear();
        for(int j=i;j<=1e5;j+=i)
        {
            for(int k=0;k<min(2ll,(int)vec[j].size());k++)
            {
                x.pb(j/i);
            }
        }
        dq.clear();
        for(int j=(int)x.size()-1;j>=0;j--)
        {
            if(cal(x[j])>=1)
            {
                ll cc=cal(x[j]);
                while(dq.size()>0)
                {
                    if(__gcd(x[j],dq.back())==1)
                    {
                        cc--;
                        if(cc==0) break;
                    }
                    del(dq.back());
                    dq.pop_back();
                }
                ans=max(ans,i*x[j]*dq.back());
            }
            dq.pb(x[j]);
            add(x[j]);
        }
        for(int j=0;j<x.size();j++)
        {
            for(auto zz:d[x[j]])
            {
                cnt[zz]=0;
            }
        }
    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    solve();
}

  	 	      			  	   					  	 		