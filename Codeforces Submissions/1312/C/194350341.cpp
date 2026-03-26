#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
ll maxk(ll value, ll k)
{
    ll cnt = 0;
    while (value)
    {
        value = value / k;
        cnt++;
    }
    cnt--;
    return cnt;
}
ll power(ll value, ll k)
{
    ll ans = 1;
    while (k--)
    {
        /* code */
        ans = ans * value;
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    ll arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        while (arr[i] != 0)
        {
            /* code */
            ll maxik = maxk(arr[i], k);
            // cout<<arr[i]<<" "<<maxik<<" "<<m[maxik]<<nL;
            if (m[maxik] > 0)
            {

                cout << "NO" << nL;
                return;
            }

            m[maxik]++;
            arr[i] = arr[i] - power(k, maxik);
        }
    }
   // cout << m[0];
    cout << "YES" << nL;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ttt;
    cin >> ttt;
    for (int i = 1; i <= ttt; i++)
    {
        solve();
    }
    return 0;
}
