#include<bits/stdc++.h>
#define task "C"
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MAXN = 80 + 5;
const ll INF = 1e18 + 5;

int n, k;
int a[MAXN][MAXN];

void Input()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}

vector<pair<int, int>> in[MAXN][MAXN];
int chon[MAXN], cnt[MAXN];
ll res = INF;

void DFS(int id)
{
    if (id == k / 2 + 1)
    {
        ll ans = 0;
        for (int i = 1; i <= k / 2; i++)
        {
            bool chk = 0;
            for (const auto& p : in[chon[i]][chon[i + 1]])
            {
                if (cnt[p.se])
                    continue;
                chk = 1;
                ans += p.fi;
                break;
            }
            if (!chk)
            {
                ans = INF;
                break;
            }
        }
        res = min(res, ans);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i]++;
        chon[id] = i;
        DFS(id + 1);
        cnt[i]--;
    }
}

void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int t = 1; t <= n; t++)
            {
                if (t == i || t == j)
                    continue;
                in[i][j].pb({a[i][t] + a[t][j], t});
            }
            sort(in[i][j].begin(), in[i][j].end());
        }
    }

    chon[1] = 1;
    chon[k / 2 + 1] = 1;
    DFS(2);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task".INP","r"))
    {
        freopen(task".INP","r",stdin);
        //freopen(task".OUT","w",stdout);
    }
    Input();
    Solve();
}
