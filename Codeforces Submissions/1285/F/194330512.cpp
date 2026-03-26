// LUOGU_RID: 102598786
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100000 + 10;

int n, lim, a[N], vis[N];
vector<int> vec, d[N];
int cnt[N], sta[N], top;
int p[N], v[N], mu[N], pcnt = 0;

void init(int n)
{
    mu[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!v[i])
            p[++pcnt] = i, mu[i] = -1;
        for (int j = 1; j <= pcnt && i * p[j] <= n; ++j)
        {
            v[i * p[j]] = 1;
            if (i % p[j])
                mu[i * p[j]] = -mu[i];
            else
                break;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            d[j].push_back(i);
}

int main()
{
    init(1e5);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], lim = max(lim, a[i]), ++vis[a[i]];
    ll ans = 0;
    for (int g = 1; g <= lim; ++g)
    {
        vec.clear();
        for (int i = g; i <= lim; i += g)
            for (int j = 1; j <= vis[i]; ++j)
                vec.push_back(i / g);
        sort(vec.begin(), vec.end(), greater<int>());
        for (int i : vec)
        {
            int s = 0;
            for (int j : d[i])
                s += mu[j] * cnt[j];
            while (s)
            {
                int x = sta[top--];
                if (__gcd(i, x) == 1)
                    ans = max(ans, 1ll * g * i * x), --s;
                for (int j : d[x])
                    --cnt[j];
            }
            sta[++top] = i;
            for (int j : d[i])
                ++cnt[j];
        }
        while (top)
        {
            int x = sta[top--];
            for (int i : d[x])
                --cnt[i];
        }
    }
    cout << ans;
}