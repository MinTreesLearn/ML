#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace std;
#define int long long int
#define ll long long
#define mod 1000000007
// #define mod 998244353
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define vi vector<int>

#define min_heap_pii priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define min_haep_i priority_queue<int, vector<int>, greater<int>>
#define umii unordered_map<int, int>
#define vpi vector<pair<int, int>>
#define preci(x) cout << fixed << setprecision(9) << x << endl
#define msi map<string, int>
#define mii map<int, int>
#define spi set<pair<int, int>>
#define vst vector<string>
#define vbl vector<bool>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pbr(val) cout << val << endl;
#define pn cout << "No" << endl
#define py cout << "Yes" << endl
#define pim cout << "Impossible" << endl
#define PI acos(-1.0)
// tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
//      tree_order_statistics_node_update>
//     T;
const int limit = 1e18;
// const int sz = 1000005;
// const int LOG = 20;
// vector<vector<int>> dxy = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int str_int(string s)
{
    stringstream ob(s);
    int num = 0;
    ob >> num;
    return num;
}
vector<int> primef(int n)
{
    vector<int> ans;
    if (n % 2 == 0)
    {
        ans.pb(2);
        while (n % 2 == 0)
        {

            n /= 2;
        }
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            ans.pb(i);

            while (n % i == 0)
            {
                // ans.pb(i);
                n /= i;
            }
        }
    }
    if (n > 2)
        ans.pb(n);
    return ans;
}
vi fact(int n)
{
    vi ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                ans.pb(i);
            }
            else
            {
                ans.pb(i);
                ans.pb(n / i);
            }
        }
    }
    return ans;
}

int binExp(int base, int exp)
{
    base %= mod;
    int res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (int)((long long)res * base % mod);
        }
        base = (int)((long long)base * base % mod);
        exp >>= 1;
    }
    return res;
}
void sort_i(vi &v)
{
    return sort(v.begin(), v.end());
}
void sort_d(vi &v)
{
    return sort(v.begin(), v.end(), greater<int>());
}

int log_a_to_base_b(int a, int b)
{
    return log(a) / log(b);
}
int msb(int n) // most significant bit of a number
{
    int ans = -1;
    while (n > 0)
    {
        n >>= 1;
        ans++;
    }
    return ans;
}
int modInv(int a, int m)
{
    return binExp(a, m - 2);
}
int sum_v(vector<int> &a)
{
    int val = accumulate(a.begin(), a.end(), 0ll);
    return val;
}
bool is_nondecreasing(vector<int> &a, int s, int e)
{
    bool flag = 1;
    for (int i = s + 1; i <= e; i++)
    {
        if (a[i] < a[i - 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int lcm(int a, int b)
{
    int ans = a * b / __gcd(a, b);
    return ans;
}
bool is_same_parity(int a, int b)
{
    if (a % 2 == b % 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ispalin(string s, int l, int r)
{
    bool flag = 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            flag = 0;
            break;
        }
        l++;
        r--;
    }
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int modFact(int n, int p)
{
    if (n >= p)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}

void printyn(bool val)
{
    if (val)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

bool isSubSequence(string str1, string str2, int m, int n)
{
    int j = 0;

    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;

    return (j == m);
}
void nextGreater(vector<int> &nums, vector<int> &ng)
{
    stack<int> st;

    int len = nums.size();
    ng[len - 1] = -1;
    // ng[len - 1] = len;
    st.push(len - 1);

    for (int i = len - 2; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        if (st.empty())
            // ng[i] = len;
            ng[i] = -1;
        else
            ng[i] = st.top();
        st.push(i);
    }
}
void preGreater(vi &nums, vi &pg)
{
    stack<int> st;
    int n = nums.size();
    pg[0] = -1;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pg[i] = -1;
        }
        else
            pg[i] = st.top();
        st.push(i);
    }
}

void nextSmaller(vector<int> &nums, vector<int> &ns)
{
    stack<int> st;

    int len = nums.size();
    // ns[len - 1] = -1;
    ns[len - 1] = len;
    st.push(len - 1);

    for (int i = len - 2; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        if (st.size() > 0)
            ns[i] = st.top();

        st.push(i);
    }
}
void preSmaller(vi &nums, vi &ps)
{
    stack<int> st;
    int len = nums.size();

    for (int i = 0; i < len; i++)
    {
        while (st.size() > 0 && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        if (st.size() > 0)
        {
            ps[i] = st.top();
        }
        st.push(i);
    }
}
int dig_len(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

bool is_vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i')
        return 1;
    return 0;
}
bool is_digit(char ch)
{
    int val = ch - '0';
    if (val >= 0 && val <= 9)
        return 1;
    return 0;
}
int binomialCoeff(int n, int r)
{

    if (r > n || n < 0 || r < 0)
        return 0;
    int m = 998244353;
    int inv[r + 1] = {0};
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;

    // Getting the modular inversion
    // for all the numbers
    // from 2 to r with respect to m
    // here m = 1000000007
    for (int i = 2; i <= r; i++)
    {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }

    int ans = 1;

    // for 1/(r!) part
    for (int i = 2; i <= r; i++)
    {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }

    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (int i = n; i >= (n - r + 1); i--)
    {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}

vi fac, ifac;
void precompute(int n)
{
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fac[i] = (int)((long long)i * fac[i - 1] % mod);
    }

    ifac.resize(n + 1);
    for (int i = 0; i < fac.size(); i++)
    {
        ifac[i] = binExp(fac[i], mod - 2);
    }
    return;
}

int nCr(int n, int r)
{
    if ((n < 0) || (r < 0) || (r > n))
    {
        return 0;
    }
    return (int)((long long)fac[n] * ifac[r] % mod * ifac[n - r] % mod);
}

bool isprime(int x)
{
    for (int i = 2; i * 1ll * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// mod stuff
int add(int x, int y)
{
    x += y;
    while (x >= mod)
        x -= mod;
    while (x < 0)
        x += mod;
    return x;
}
int sub(int x, int y)
{
    return add(x, -y);
}
int mul(int x, int y)
{
    return (x * 1ll * y) % mod;
}
// prime factors of a numbers in log(n) time using sieve()
#define MAXN 20000001
int spf[MAXN];
void sieve_log()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int getFactorization(int x)
{
    // vector<int> ret;
    // unordered_set<int> ret;
    mii ret;

    while (x != 1)
    {
        ret[spf[x]]++;
        // to[(spf[x])]++;
        x = x / spf[x];
    }
    return ret.size();

    // cnt of to divisor
    //   int ans = 1;
    //   for (auto it : ret)
    //   {
    //       ans *= (it.second + 1);
    //   }
    //  return ans;
}

int mex(vi a)
{
    int n = a.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (s.count(i) == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
/*******************************************************************/
const int maxn = 200001;
vi adj[200001];
int par[maxn];
int sz[maxn];
int dia[maxn];
int maxi, maxiv;
bool vis[maxn];
int fir, sec;

void dfs(int node, int d, int p)
{
    par[node] = p;
    if (d > maxi)
    {
        maxiv = node;
        maxi = d;
    }
    for (auto x : adj[node])
    {
        if (x != p)
        {
            dfs(x, d + 1, node);
        }
    }
}
int calc_d(int node)
{
    maxi = -1;
    dfs(node, 0, -1);
    fir = maxiv;
    maxi = -1;
    dfs(maxiv, 0, -1);
    sec = maxiv;
    return maxi;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // dfs(1, 0, -1);
    int dval = calc_d(1);
    vector<int> dnodes;
    while (sec != fir)
    {
        dnodes.pb(sec);
        sec = par[sec];
    }
    dnodes.pb(sec);
    // cout << dval << endl;
    // for (auto it : dnodes)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    if (dnodes.size() == n)
    {
        cout << n - 1 << endl;
        cout << dnodes[0] << " " << dnodes[1] << " " << dnodes[n - 1] << endl;
    }
    else
    {
        queue<int> q;
        vi dis(n + 1, -1);
        for (auto it : dnodes)
        {
            dis[it] = 0;
            q.push(it);
        }
        while (q.size())
        {
            int node = q.front();
            q.pop();
            for (auto x : adj[node])
            {
                if (dis[x] == -1)
                {
                    dis[x] = dis[node] + 1;
                    q.push(x);
                }
            }
        }
        pair<int, int> mx = make_pair(dis[0], 0);
        for (int v = 1; v <= n; ++v)
        {
            mx = max(mx, make_pair(dis[v], v));
        }
        cout << dval + mx.first << endl;
        cout << dnodes[0] << " " << mx.second << " " << dnodes[dnodes.size() - 1] << endl;
    }
}
signed main()
{

    fastIO;
    int t = 1;
    // sieve_log();

    // cin >> t;
    while (t--)
    {
        solve();
    }
}
