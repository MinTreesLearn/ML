#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define Py     cout<<"YES"<<endl;
#define Pn         cout<<"NO"<<endl;
#define oo 1e18+5
#define MOD ll(1e9+7)
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
#define foor(i,a,b) for (ll i = a; i < b; i++)
typedef long long ll;
typedef map<ll,ll> mapi;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b) {return (a * b) / gcd(a, b);}



void solve( ll h) {

    ll n, m, k;
    cin >> n >> m >> k;
    vi freq(n + 10, 0);
    vi freq2(m + 10, 0);
    vi a, b;
    ll con = 0;
    vi div;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x == 0) {
            if (con != 0) {
                freq[con]++;
                if (freq[con] == 1)
                    a.push_back(con);
            }
            con = 0;
        } else {
            con++;
        }
    }
    if (con != 0) {
        freq[con]++;
        if (freq[con] == 1)
            a.push_back(con);
    }
    con = 0;
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        if (x == 0) {
            if (con != 0) {
                freq2[con]++;
                if (freq2[con] == 1)
                    b.push_back(con);
            }
            con = 0;
        } else {
            con++;
        }
    }
    if (con != 0) {
        freq2[con]++;
        if (freq2[con] == 1)
            b.push_back(con);
    }
    for (int i = 1; i * i <= k; ++i) {
        if (k % i == 0)div.push_back(i);
    }


    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            ll mul = freq[a[i]] * freq2[b[j]];
            ll has = 0;
            for (int l = 0; l < div.size(); ++l) {
                ll fir = div[l];
                ll sec = (k / div[l]);
                if (fir <= a[i] && sec <= b[j]) {
                    has += (a[i] - fir + 1) * (b[j] - sec + 1);
                }
                if (fir <= b[j] && sec <= a[i] && (fir != sec)) {
                    has += (b[j] - fir + 1) * (a[i] - sec + 1);
                }
            }
            ans += has * mul;
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
   //cin >> t;
    cout << fixed << setprecision(9);
    ll h = 1;
    while (t--) {
        solve(h++);
    }
}