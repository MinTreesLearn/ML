#include<bits/stdc++.h>
#define fi first
#define se second
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

void IO(string name)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(name.size())
	{
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> par(n + 1, -1);
    vector<int> depth(n + 1, 0);
    vector<int> cnum(n + 1, 0);
    par[0] = 0;
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        int a = 2 * i;
        int b = 2 * i + 1;
        if (a <= n) {
            par[a] = i;
            depth[a] = depth[i] + 1;
            cnum[i]++;
            curr += depth[a];
        }
        if (b <= n) {
            par[b] = i;
            depth[b] = depth[i] + 1;
            cnum[i]++;
            curr += depth[b];
        }
    }
    if (d < curr || d > n * (n - 1) / 2) {
        cout << "NO\n";
        return;
    }
    vector<set<int>> available(n + 1);
    for (int i = 1; i <= n; i++) {
        if (cnum[i] < 2) {
            available[depth[i]].insert(i);
        }
    }
    while(curr < d) {
        for (int i = 2; i <= n; i++) {
            if (cnum[i] == 0 && available[depth[i]].size() > 1) {
                int dd = depth[i];
                available[dd].erase(i);
                int x = *available[dd].begin();
                cnum[par[i]]--;
                available[depth[par[i]]].insert(par[i]);
                par[i] = x;
                cnum[x]++;
                if (cnum[x] == 2) available[dd].erase(x);
                depth[i]++;
                available[dd + 1].insert(i);
                curr++;
                break;
            }
        }
    }
    cout << "YES\n";
    for (int i = 2; i <= n; i++) cout << par[i] << " \n"[i == n];
    
}

int main()
{
	IO("");
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
}



