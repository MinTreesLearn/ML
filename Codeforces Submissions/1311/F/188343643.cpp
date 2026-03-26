#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define  vll vector<ll>
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define vp vector<pair<ll,ll>>
#define tc ll t; cin >> t; for(ll i = 0; i < t; i++){solve(i, t);}
#define tc1 solve(1, 1);
#define mpvll map<ll, vll>
#define vfast vll a(n); for (ll i = 0; i < n; i++) { cin >> a[i]; }
#define mpll map<ll,ll>
#define vll2 vector<vector<ll>> dp(m, vector<ll>(n));
#define FIXED(A) cout << fixed; cout.precision(20); cout << A << "\n";
#define mp(A, B) make_pair(A, B)
#define all(x) (x).begin(), (x).end()
#define pll pair<ll,ll>
struct tri{ll x = 0, y = 0, z = 0;};
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
void setIO(string name) {freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}
ll rd(ll a, ll b){return (a+b-1) / b;}
ll isqrt(ll x){ll ans = 0; for(ll k = 1LL << 30; k != 0; k /= 2){if ((ans + k) * (ans + k) <= x) {ans += k;} } return ans;   }
vll prime(ll x){ll n = x; vll ans; while (n % 2 == 0) {ans.pb(2);n = n/2;} for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){ans.pb(i);n = n/i;}}if (n > 2){ans.pb(n);} return ans;}
ll binpow(ll a, ll b, ll m) { a %= m; ll res = 1; while (b > 0) { if (b & 1){res = res * a % m;}a = a * a % m; b >>= 1;} return res;}
ll lg2(ll n){ll cnt=0;while(n){cnt++;n/=2;}return cnt;}




template<class T>
class seg {
private:
    T comb(T a, T b) { return a + b; }
    const T DEFAULT = 0;
    vector<T> segtree;
    int len;
public:
    seg(int len) : len(len), segtree(len * 2, DEFAULT) { }
    void set(int ind, T val) {
        assert(0 <= ind && ind < len);
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
        }
    }
    T sum(int start, int end) {
        assert(0 <= start && start < len && 0 < end && end <= len);
        T sum = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if ((start & 1) != 0) {
                sum = comb(sum, segtree[start++]);
            }
            if ((end & 1) != 0) {
                sum = comb(sum, segtree[--end]);
            }
        }
        return sum;
    }
};

void solve(ll TC, ll TC2) {
    vll nums; mpll cnt;
    ll n; cin >> n; ll ans = 0;
    seg<ll> b(n+5), c(n+5);
    vp a(n); for(ll i = 0; i < n; i++){cin >> a[i].first;} for(ll i = 0; i  < n; i++){cin >> a[i].second;}
    sort(all(a));
    for(ll i = 0; i < n; i++){cnt[a[i].second]++;if(cnt[a[i].second] == 1){nums.pb(a[i].second);}}
    sort(all(nums)); mpll val;
    vector<vp> d(n+5);
    for(ll i = 0; i < nums.size(); i++){val[nums[i]] = i;}for(ll i = 0; i < n; i++){a[i].second = val[a[i].second];}
    for(ll i =0 ; i < a.size(); i++){d[a[i].second].pb(mp(i,a[i].first)); }
    vll pre(n+5); for(ll i = n-1; i >= 0; i--){pre[i] = pre[i+1] + a[i].first;}
    for(ll i =0; i < nums.size(); i++){
         for(pll x: d[i]){
              ans += pre[x.first+1] - (x.second * (n-x.first-1));
              ans -= b.sum(x.first,n+4) - (c.sum(x.first,n+4) * x.second);
              //cout << x.first << " " << ans << "\n";
         }
         for(pll x: d[i]){
             b.set(x.first, x.second); c.set(x.first,1);
         }
    }
    cout << ans;

 }

int main() {
    FAST;
    tc1;
}