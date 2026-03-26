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
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    for (int i = 1; i <= n && m; i++) {
        if (m - (i - 1) / 2 >= 0) {
            ans.pb(i);
            m -= (i - 1) / 2;
        }
        else {
            ans.pb(ans.end()[-1] + ans.end()[- 2 * m]);
            m = 0;
        }
    }
    int nn = (ans.size() ? ans.back() : 1);
    if (m) {
        cout << "-1\n"; 
        return;
    }
    int lim = n - ans.size();
    for (int i = 0; i < lim; i++) {
        ans.pb(1e8 + i * (nn + 1));
    }
    for (auto &i : ans) cout << i << ' ';
    cout << '\n';
}

int main()
{
	IO("");
	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}
}
