#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

typedef vector<long long> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define sai(a, n) sort(a, a + n);
#define sad(a, n) sort(a, a + n, greater<int>());
#define svi(x) sort(x.begin(), x.end());
#define svd(a) sort(a.begin(), a.end(), greater<int>());
#define fi(i, x, n) for (int i = x; i < n; i++)
#define PB push_back
#define MP make_pair
#define FF firstṇ
#define SS second
#define ull unsigned long long
#define int long long
// #define MOD 1000000007
#define MOD 998244353
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Function to find a^b % MOD. Time Complexity : O(log b).
int highPowerMod(int a, int b)
{
    // a %= MOD;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

// Function to find the lcm of a and b. Time Complexity : O(log(min(a, b))).
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}

void bfs(int start, vector<vector<int>> &g2, vector<pair<int, bool>> &dp, int m)
{
    queue<int> q;
    q.push(start);
    int cnt = 0;
    bool flag = false;
    while (!q.empty())
    {
        cnt = q.front();
        if (cnt < m)
            flag = true;
        q.pop();

        dp[cnt].second = flag;
        for (const auto &nbr : g2[cnt])
        {
            if (dp[nbr].first == -1)
            {
                dp[nbr].first = dp[cnt].first + 1;
                q.push(nbr);
            }
        }
    }
}

int compliment(int x, int n)
{
    return (x ^ (n - 1));
}

void dfs(int start, vector<vi> &graph, vector<bool> &vis)
{
    vis[start] = true;

    for (const auto &nbr : graph[start])
    {
        if (!vis[nbr])
        {
            dfs(nbr, graph, vis);
        }
    }
}

pair<int, int> intersection(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.second || b.first > a.second)
        return {-1, -1};
    return {max(a.first, b.first), min(a.second, b.second)};
}

int cntDigits(int n)
{
    string t = to_string(n);
    return (int)t.size();
}

int bs_sqrt(int x)
{
    int left = 0, right = 2000000123;
    while (right > left)
    {
        int mid = left + (right - left) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}

void primeFactors(int n, vi &arr)
{
    int t = 1e5 + 7;
    fi(i, 1, t)
    {
        if (i * i > n)
            break;
        if (n % i == 0)
        {
            arr.push_back(i);
            arr.push_back(n / i);
        }
    }
}

void SieveOfEratosthenes(int n, vi &primess)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primess.push_back(p);
}

// And of a Range of numbers from a to b.
int andOperator(int a, int b)
{
    int shiftcount = 0;
    while (a != b and a > 0)
    {
        shiftcount++;
        a = a >> 1;
        b = b >> 1;
    }
    return int64_t(a << shiftcount);
}

void solve(int cake)
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    // vi arr(n);
    // fi(i, 0, n) cin >> arr[i];
    string s;
    vector<string> v1, v2;
    fi(i, 0, n)
    {
        cin >> s;
        v1.push_back(s);
    }
    fi(i, 0, k)
    {
        cin >> s;
        v2.push_back(s);
    }

    int q;
    cin >> q;
    fi(i, 0, q)
    {
        int y;
        cin >> y;
        y--;
        int x1 = y % n, x2 = y % k;

        string res = v1[x1] + v2[x2];
        cout << res << endl;
    }
}

int32_t main()
{
    // OJ;
    FIO;
    int t = 1;
    int cake = 1;
    // cin >> t;

    // vi primes;
    // int N = 31622;
    // SieveOfEratosthenes(N, primes);
    while (t--)
    {
        solve(cake);
        cake++;
    }

    return 0;
}