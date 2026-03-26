#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(i,x,y) for(ll i=x;i<y;i++)
#define vl vector<ll>
#define vp vector<pair<ll,ll>>
#define mapl map<ll,ll>
#define mapc map<char,ll>
#define all(v) v.begin(), v.end()
#define backk(v) v.rbegin(), v.rend()
#define llrp(x,y) (ll)(round(pow(x,y)))
#define pb push_back
#define pf push_front
#define fr first
#define sc second
#define endl '\n'
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define pl pair<ll,ll>
using namespace std;
void print(vl &a)
{
    f(i,0,a.size()) cout<<a[i]<<' ';
    cout<<endl;
}
ll func(ll a,ll b)
{
    return (a|b)-b;
}
void solve(){
    ll n;
    cin>>n;
    vl a(n),cnt(35,0);
    f(i,0,n)
    {
       cin>>a[i];
       f(j,0,35)
       {
         if(a[i] & (1<<j)) cnt[j]++;
       }
    }
    ll ans=-1,idx=-1;
    f(i,0,n)
    {
        ll temp=0;
        f(j,0,35)
        {
            if(a[i] & (1<<j))
            {
                if(cnt[j]==1) temp+=(1<<j);
            }
        }
        if(ans<temp)
        {
            ans=temp;
            idx=i;
        }
    }
    cout<<a[idx]<<' ';
    f(i,0,n) if(i!=idx) cout<<a[i]<<' ';
    cout<<endl;
    
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t=1;
// cin>>t;
while(t--){
solve();
}
return 0;
}