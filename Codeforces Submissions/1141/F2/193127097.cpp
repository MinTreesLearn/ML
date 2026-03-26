#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(1e9+7)
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
#define foor(i,a,b) for (ll i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) /* return pair upper lower   auto r=num_ocur_insort(a,6);*/
typedef int ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=10000;


ll fun(vip &a) {
    ll sum = 1;
    ll mashgol = a[0].first;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i].second > mashgol) {
            mashgol = a[i].first;
            sum++;
        }
    }
    return sum;
}

void solve(ll hh ) {
    ll n;
    cin >> n;
    vi a(n);
    vi pr(n);
    ll ans = 0, res;
    map<ll, vector<pi>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pr[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pr[i] += pr[i - 1]+a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i ; j < n; ++j) {
            ll lst = 0;
            if (i)lst = pr[i - 1];
            ll val = pr[j] - lst;
            mp[val].push_back({j, i});
        }
    }
    for (auto it: mp) {
        auto vec = it.second;
        sort(all(vec));
        ll temp = fun(vec);
        if (temp > ans) {
            ans = temp;
            res = it.first;
        }
    }
    auto vec = mp[res];
    sort(all(vec));
    vip fin;
    ll mas = vec[0].first;
    fin.push_back({vec[0].second, vec[0].first});
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i].second > mas) {
            mas = vec[i].first;
            fin.push_back({vec[i].second, vec[i].first});
        }
    }
    cout << ans << endl;
    for (int i = 0; i < fin.size(); ++i) {
        cout << fin[i].first +1<< " " << fin[i].second+1 << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
   // cin >> t;
    ll hh=t;
    while (t--) {
        solve(hh-t);
    }
}