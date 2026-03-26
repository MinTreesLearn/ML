#include <bits/stdc++.h>

using namespace std;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define endl '\n'
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define incr_loop(a, n) for (int i = a; i < n; i++)
#define decr_loop(a, b) for (int i = a; i > b; i--)
#define nested_incr_loop(a, b) for (int j = a; j < b; j++)
#define nested_decr_loop(a, b) for (int j = b; j > a; --j)
typedef long long ll;
typedef double long dl;
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define sort_all(v) sort(all(v));
#define PI 3.141592653589793238462
#define space cout << ' ';
typedef unordered_map<int, int, custom_hash> mp;
ll MOD = 998244353;

vector<ll> primes;
ll ans = 0;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n), brr(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    vector<ll> mmp1(n + 1), mmp2(m + 1);
    for (int i = 0; i < n;)
    {
        if (arr[i] == 0)
        {
            i++;
            continue;
        }
        int cnt = 0;
        while (i < n && arr[i] == 1)
        {
            i++;
            cnt++;
        }
        for (int j = 1; j <= cnt; j++)
        {
            mmp1[j] += cnt + 1 - j;
        }
    }
    for (int i = 0; i < m;)
    {
        if (brr[i] == 0)
        {
            i++;
            continue;
        }
        int cnt = 0;
        while (i < m && brr[i] == 1)
        {
            i++;
            cnt++;
        }
        for (int j = 1; j <= cnt; j++)
        {
            mmp2[j] += cnt + 1 - j;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i > n)
        {
            break;
        }
        if (k % i)
        {
            continue;
        }
        if ((k / i) > m)
        {
            continue;
        }
        ans += mmp1[i] * mmp2[k / i];
    }
    cout << ans << endl;
}

int main()
{
    fio int tc = 1;
    // cin >> tc;
    // int p = 10000000;
    // vector<bool> is_prime(p, true);
    // for (int i = 2; i < p; ++i)
    // {
    //     if (!is_prime[i])
    //         continue;
    //     primes.push_back(i);
    //     for (int j = i + i; j < p; j += i)
    //     {
    //     is_prime[j] = false;
    // }
    // }

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}