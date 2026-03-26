#include <bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << '\n';

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 5e5 + 10;

ll dp[N], dp2[N];

void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	stack<int> st;
	for (int i = 1; i <= n; ++i) {
		dp[i] = a[i];
		while (st.size() && a[st.top()] > a[i]) {
			st.pop();
		}
		int p = (st.size() == 0 ? 0 : st.top());
		dp[i] += dp[p] + 1LL * (i - p - 1) * a[i];
		st.push(i);
	}

	stack<int> st2;
	for (int i = n; i >= 1; --i) {
		dp2[i] = a[i];
		while (st2.size() && a[st2.top()] > a[i]) {
			st2.pop();
		}
		int p = (st2.size() == 0 ? n + 1 : st2.top());
		dp2[i] += dp2[p] + 1LL * (p - i - 1) * a[i];
		st2.push(i);
	}

	ll mx = 0, id;
	for (int i = 1; i <= n; ++i) {
		ll t = dp[i] + dp2[i] - a[i];
		if (t > mx) {
			mx = t;
			id = i;
		}
	}

	vector<int> ans(n + 1);
	ans[id] = a[id];
	for (int i = id - 1; i >= 1; --i) {
		ans[i] = min(ans[i + 1], a[i]);
	}
	for (int i = id + 1; i <= n; ++i) {
		ans[i] = min(ans[i - 1], a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " \n"[i == n];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}