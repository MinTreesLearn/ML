/*
    handle:aryan15april(cf) <> aryan_sinha(cc)
    Va te faire foutre
    here we began :-
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include <string>
using namespace __gnu_pbds;
using namespace std;

#define ll long long int
#define all(vec) vec.begin(), vec.end()
#define endl "\n"
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define ff first
#define ss second
#define flush cout << flush;
// #define N 1e5 + 1
#define PI 3.141592653589793238
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef tree<char, null_type, less_equal<char>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
// find_by_order :- returns iterator to kth element starting from 0
// order_of_key:- elements less than current element

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x) { return out << x.ff << ' ' << x.ss; }
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &x) { return in >> x.ff >> x.ss; }

const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll NODE = 1e5 + 10;
const ll INF = 1e18;
const ll N =  10005 + 1;
#define debug(x)       \
    cout << #x << " "; \
    _print(x);
class node {
public:
    ll a;
    ll b;
};
long long sqrtf(long long x)
{
    long long ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) <= x)
        {
            ans += k;
        }
    }
    return ans;
}
long long binexp(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}
long long power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
ll f[200001];
void fac() {
    f[0] = 1;
    for (ll i = 1; i < 200001; i++)
        f[i] = (i % MOD * f[i - 1] % MOD) % MOD;
}
ll inverse(ll a, ll p) {
    return binexp(a, p - 2, p);
}
ll ncr(ll n, ll r, ll p) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (f[n] * inverse(f[r], p) % p * (inverse(f[n - r], p) % p)) % p;
}

vector<ll> prime()
{   // sieve
    vector<ll>ans;
    vector<ll> vec(N + 1, 1);
    vec[0] = 0;
    vec[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (vec[i] == 1)
        {
            vec[i] = 1;
            for (int j = 2 * i; j <= N; j += i)
            {
                if (vec[j] == 1)
                    vec[j] = 0;
            }
        }
    }
    for (ll i = 0; i <= N; i++)
    {
        if (vec[i] == 1)ans.push_back(i);
    }

    return ans;
}
ll Floor(ll a, ll b) {
    ll val = a / b;
    while (val * b > a)
        val--;
    return val;
}
// vector<ll> facto(ll n)
// {
//     vector<ll>ans;
//     while (n > 1)
//     {
//         ll val = vec[n];
//         while (n % val == 0)
//             n /= val;
//         ans.push_back(val);
//     }
//     return ans;
// }
int findNthOccur(string str,
                 char ch, int n)
{
    int occur = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
        {
            occur += 1;
        }
        if (occur == n)
            return i;
    }
    return -1;
}
bool subsequence(string main, string target)
{
    stack<char> s;
    for (ll i = 0; i < target.size(); i++)
        s.push(target[i]);

    for (ll i = main.size() - 1; i >= 0; i--)
    {
        if (s.top() == main[i])
            s.pop();
        if (s.empty())
            return true;
    }
    return s.empty();
}
ll binomialCoeff(ll n, ll k)
{
    ll C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = (ll)1; // nC0 is 1

    for (ll i = 1; i <= n; i++)
    {

        for (ll j = (ll)min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % MOD;
    }
    return C[k] % MOD;
}
ll kadane(vector<ll> &vec)
{
    ll curr = 0;
    ll mx = LLONG_MIN;
    for (ll i = 0; i < vec.size(); i++)
    {
        curr += vec[i];
        if (curr < 0)
        {
            curr = 0;
        }
        mx = max(mx, curr);
    }
    return mx;
}
vector<ll> adj[NODE];
ll vis[NODE] = {0};

multiset<ll> st;
vector<ll> par(NODE);
vector<ll> ranc(NODE);
vector<ll> sz(NODE);
void makeSet(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        par[i] = i;
        ranc[i] = 0;
        sz[i] = 1;
        st.insert(1);
    }
}
ll getPar(ll x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = getPar(par[x]);
}

void Union(ll u, ll v)
{
    u = getPar(u);
    v = getPar(v);
    if (ranc[v] < ranc[u])
    {
        par[v] = u;
    }
    else if (ranc[v] > ranc[u])
    {
        par[u] = v;
    }
    else
    {
        par[u] = v;
        ranc[v]++;
    }
}
void build(vector<pair<ll, ll>>&seg, vector<ll>&vec, ll ind , ll lo, ll hi)
{
    if (lo == hi)
    {
        seg[ind].first = vec[lo];
        seg[ind].second = 1;
        return;
    }
    ll mid = (lo + hi) / 2;
    build(seg, vec, 2 * ind + 1, lo, mid);
    build(seg, vec, 2 * ind + 2, mid + 1, hi);
    seg[ind].first = min(seg[2 * ind + 1].first , seg[2 * ind + 2].first);
    if (seg[2 * ind + 1].first == seg[2 * ind + 2].first)
        seg[ind].second = seg[2 * ind + 1].second + seg[2 * ind + 2].second;
    else if (seg[2 * ind + 1].first > seg[2 * ind + 2].first)
        seg[ind].second = seg[2 * ind + 2].second;
    else seg[ind].second = seg[2 * ind + 1].second;
}
pair<ll, ll> query(vector<pair<ll, ll>>&seg, vector<ll>&vec, ll ind, ll lo, ll hi, ll l, ll r)
{
    if (hi < l || lo > r) {
        return {LLONG_MAX, 0};
    }
    if (lo >= l && hi <= r) {
        return {seg[ind].first, seg[ind].second};
    }
    ll mid = (lo + hi) / 2;
    pair<ll, ll> left = query(seg, vec, 2 * ind + 1, lo, mid, l, r);
    pair<ll, ll> right = query(seg, vec, 2 * ind + 2, mid + 1, hi, l, r);
    if (left.first == right.first)
        return {left.first, (left.second + right.second)};
    else if (left.first > right.first)
        return {right.first, right.second};
    return {left.first, left.second};
}
void update(vector<pair<ll, ll>>&seg, vector<ll>&vec, ll ind, ll lo, ll hi, ll pos, ll val)
{
    if (lo == hi)
    {
        seg[ind].first = val;
        seg[ind].second = 1;
        return;
    }
    ll mid = (lo + hi) / 2;
    if (pos <= mid && pos >= lo) update(seg, vec, 2 * ind + 1, lo, mid, pos, val);
    else update(seg, vec, 2 * ind + 2, mid + 1, hi, pos, val);

    seg[ind].first = min(seg[2 * ind + 1].first , seg[2 * ind + 2].first);
    if (seg[2 * ind + 1].first == seg[2 * ind + 2].first)
        seg[ind].second = seg[2 * ind + 1].second + seg[2 * ind + 2].second;
    else if (seg[2 * ind + 1].first > seg[2 * ind + 2].first)
        seg[ind].second = seg[2 * ind + 2].second;
    else seg[ind].second = seg[2 * ind + 1].second;

}
void rangeupdate(vector<ll>&seg, vector<ll>&lazy, vector<ll>&vec, ll ind, ll lo, ll hi, ll l, ll r, ll val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (hi - lo + 1) * lazy[ind];
        if (lo != hi) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < lo || hi < l || lo > hi) return;

    if (lo >= l && hi <= r) {
        seg[ind] += (hi - lo + 1) * val;
        if (lo != hi)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }
    ll mid = (lo + hi) >> 1;
    rangeupdate(seg, lazy, vec, 2 * ind + 1, lo, mid, l, r, val);
    rangeupdate(seg, lazy, vec, 2 * ind + 2, mid + 1, hi, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll querylazy(vector<ll>&seg, vector<ll>&lazy, vector<ll>&vec, ll ind, ll lo, ll hi, ll l, ll r, ll val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (hi - lo + 1) * lazy[ind];
        if (lo != hi) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < lo || hi < l || lo > hi) return 0;
    if (lo >= l && hi <= r) {
        return seg[ind];
    }
    ll mid = (lo + hi) >> 1;
    ll left = querylazy(seg, lazy, vec, 2 * ind + 1, lo, mid, l, r, val);
    ll right = querylazy(seg, lazy, vec, 2 * ind + 2, mid + 1, hi, l, r, val);
    return left + right;

}
// priority_queue<ll, vector<ll>, greater<ll>> pq;
map<ll, ll>pp;
vector<ll>to_prime;
map<ll, ll>p;
void _segfault_()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == ')')
            cnt--;
        else
            cnt++;
    }
    if (cnt != 0)
    {
        cout << -1 << endl;
        return;
    }
    cnt = 0;
    ll ans = 0;
    ll cap = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
        {
            ans++;
        }
        if (cnt == 0 && ans > 0)
        {
            cap += ans + 1;
            ans = 0;
        }
    }
    cout << cap << endl;
}
int32_t main(int argc, char const *argv[])
{
    // int32_t for returning val 32 bit integer always
    IOS
    clock_t z = clock();
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout << setprecision(20);
    int t = 1;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> t;
    fac();
    // to_prime = prime();
    while (t--)
    {
        // cout << "Case #" << a << ": ";
        _segfault_();
        // a++;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}