#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef std::vector<ll> vll;
typedef map<ll,ll>mll;
const ll mod =1000000007,inf = 1e18;
#define in(n)          ll n;cin>>n;
#define inp(a,n)        vll a(n);for(ll i = 0;i<n;i++) cin>>a[i];
#define rep(i,s,e)  for(__typeof(e) i = s;i<e;i++) 
#define sz(a)           ll(a.size())
#define nl              cout<<endl;
#define pb              push_back
#define vec(a)          (a).begin(),(a).end()
#define len(a) ((ll)(a).size())
const int N = 5e5 + 100;
void print(ll a){cout<<a;nl;}
void print(vll a){for(auto i : a)cout<<i<<" ";nl;}
void print(string s){cout<<s<<endl;}
const long long SIZE = 1e18+10;

void solve()
{
    in(n);
    inp(a,n);

    for(ll i=0;i<n-2;i++){
        for(ll j=i+2;j<n;j++){
            if(a[i]==a[j]){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;

};
signed main()
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    
    // cout<<fixed<<setprecision(x)<<endl;
    for(ll i = 1;i<=t;i++)
    {
        // cout << "Case #"<<i<<": ";
        solve();
    }
}