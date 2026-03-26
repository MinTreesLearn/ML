#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>   // everything related to pbds
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef int node; // change type here
// typedef tree<node, null_type, less<node>,
//              rb_tree_tag, tree_order_statistics_node_update> // this is push_backds
//     ordered_set;
using ll = long long;
using vi = vector<long long>;
using vpi = vector<pair<ll, ll>>;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ps(x, y) fixed << setprecision(y) << x
#define int long long

ll INF = 1e18;
ll MOD = 998244353;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0}; // useful when dealing with points
ll maxx(vi &a)
{
    return (*max_element(a.begin(), a.end()));
}

ll minn(vi &a)
{
    return (*min_element(a.begin(), a.end()));
}

long long gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
long long mod(long long x)
{
    return ((x % MOD + MOD) % MOD);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}
void input(vi &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void print(vi &a)
{
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

int stringToInt(string s)
{
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
string binaryTransformation(long long x)
{
    if (x == 0)
        return "";
    else
    {
        string s = binaryTransformation(x / 2);
        s.push_back(char('0' + x % 2));
        return s;
    }
}
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
    {
        return 1;
    }
    ll ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2)
    {
        ans *= a;
    }
    return ans % mod;
}
double power(double a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    double t = power(a, b / 2);
    if (b & 1)
    {
        return t * t * a;
    }
    else
    {
        return t * t;
    }
}
int modularInverse(int number, int mod)
{
    return power(number, mod - 2, mod);
}
// it should be 1LL and not 1
// write more tests
// google if stuck
// take a walk if stuck
// precompute first

const int N = 200005;

int fact[N], invfact[N];

int pow(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

int modinv(int k)
{
    return pow(k, MOD - 2, MOD);
}

void precompute()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= MOD;
    }
}

int nCr(int x, int y)
{
    if (y > x)
        return 0;
    int num = fact[x];
    num *= invfact[y];
    num %= MOD;
    num *= invfact[x - y];
    num %= MOD;
    return num;
}
void solve()
{
    // learned a lot from this problem ,lol
    // relearned stars and bars
    // basically we have 2*m positions and n candidates for each position
    // this can be rewritten as x1 + x2+x3+...xn= 2*m, here xi>=0
    // so when we place a bar it means that many positions for that number
    int n, m;
    cin >> n >> m;
    if (n == 2)
    {
        cout << 0 << endl;
        return;
    }
    int ans = mul(nCr(m, n - 1), n - 2);
    ans = mul(ans, power(2, n - 3, MOD));
    cout << ans << endl;
}
// you should look down sometimes

// https://github.com/Manjunath0408/CPSnippets
int32_t main()
{
    // freopen("pump.in", "r", stdin);
    // freopen("pump.out", "w", stdout);
    /* stuff you should look for
     * int overflow, array bounds
     * special cases (n==1?)
     * do smth instead of nothing and stay organized
     * WRITE STUFF DOWN
     * DON'T GET STUCK ON ONE APPROACH
     * IF STUCK ON A QUESTION, MOVE TO THE NEXT ONE
     */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    precompute();
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}