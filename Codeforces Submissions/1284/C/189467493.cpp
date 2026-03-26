#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long
#define ld long double
#define pb push_back
#define endl '\n'
#define mpp make_pair
#define go continue
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue
#define Ok cout<<"Ok"<<endl
#define Not cout<<"Not Ok"<<endl
#define sq_check(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define print(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define DBG(a) cerr<< "Line "<<__LINE__ <<" : "<< #a <<" = "<<(a)<<endl
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define str_to_int(a) atoi(a.c_str())
string int_to_str(int n) {stringstream rr;rr<<n;return rr.str();}
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll fact[300005];

int main()
{
    
    ll n,m;
    cin>>n>>m;
    ll a=1;
    for(ll i=1;i<=n;i++)
    {
        a*=i;
        a%=m;
        fact[i]=a;
    }

    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll l=i;
        ll r=n-i+1;
        ans+=(((fact[l]*fact[r])%m)*r)%m;
        ans%=m;
    }

    cout<<ans<<endl;

    return 0;
}