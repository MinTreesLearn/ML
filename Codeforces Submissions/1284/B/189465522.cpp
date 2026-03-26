#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define c(ans) cout << ans << endl
#define cs(ans) cout << ans << " "
#define fori(i,j,k) for(ll i = j; i < k; i++)
#define ifor(i,j,k) for(ll i = j; i >= k; i--)
#define inarr(j,n,a) for(ll i = j; i < n; i++) cin >> a[i];
#define sortall(v) sort(v.begin(), v.end())
#define sortarr(a,n) sort(a,a+n)
#define reverseall(v) reverse(v.begin(), v.end())
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define ff first
#define ss second

typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef queue<ll> qll;
typedef set<ll> sll;
typedef stack<ll> stll;
typedef priority_queue<ll> maxpqll;
typedef priority_queue<ll, vector<ll>, greater<ll>> minpqll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;

void cv(vector<ll> v){
    fori(i,0,v.size()){
        cs(v[i]);
    }
    cout << endl;
}
ll firstsetbit(ll x){
    return x & -x;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
ll sum(ll l, ll r)
{
	ll ans = r * (r + 1) >> 1;
	ans -= (l * (l - 1) >> 1);
	return ans;
}
struct my
{
    vector<ll> a;
    ll mx, mn;
    bool flag;
};
    
//------------------------------------code------------------------------------//
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ll T;
    // cin >> T;
    // while(T--){
        ll n; cin >> n;
        vector<my> v(n);
        vector<ll> maxi;
        ll have = 0;
        fori(i, 0, n){
            ll x; cin >> x;
            v[i].a.resize(x);
            v[i].flag = false;
            v[i].mx = INT_MIN;
            v[i].mn = INT_MAX;
            fori(j, 0, x){
                cin >> v[i].a[j];
                v[i].mx = max(v[i].mx, v[i].a[j]);
                v[i].mn = min(v[i].mn, v[i].a[j]);
                if(j == 0){
                    continue;
                }
                if(v[i].a[j] > v[i].a[j - 1]){
                    v[i].flag = true;
                }
            }
            if(v[i].flag){
                have++;
                continue;
            }
            maxi.pb(v[i].mx);
        }
        sortall(maxi);
        ll final = 0;
        ll size = sz(maxi);
        fori(i, 0, n){
            if(v[i].flag){
                final += n;
                continue;
            }
            ll just = upper_bound(all(maxi), v[i].mn) - maxi.begin();
            final += (have + size - just);
        }
        c(final);
    // }
    return 0;
}