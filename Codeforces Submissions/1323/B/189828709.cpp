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
        ll n, m, k; cin >> n >> m >> k;
        vll row(n), col(m);
        fori(i, 0, n){
            cin >> row[i];
        }
        // cv(row);
        fori(i, 0, m){
            cin >> col[i];
        }
        // cv(col);
        ll final = 0;
        fori(j, 1, n + 1){
            if(k % j == 0){
                ll upper = j, niche = k / j;
                ll cnt = 0;
                ll r = 0, c = 0;
                fori(i, 0, n){
                    if(row[i]){
                        cnt++;
                        if(cnt >= upper){
                            r++;
                        }
                    }else{
                        cnt = 0;
                    }
                }
                cnt = 0;
                fori(i, 0, m){
                    if(col[i]){
                        cnt++;
                        if(cnt >= niche){
                            c++;
                        }
                    }else{
                        cnt = 0;
                    }
                }
                final += r * c;
            }
        }
        c(final);
        sahil:;
    // }
    return 0;
}