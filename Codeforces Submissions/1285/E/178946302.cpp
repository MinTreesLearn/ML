// LUOGU_RID: 92581424
#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 6;

int T, n, m, ans, cnt[N], mx;
pair<int, int> q[N];
set<int> st;

inline void solve()
{
	scanf("%d", &n);
	ans = m = 0;
	st.clear();
	mx = -1;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		q[++m] = make_pair(l, -i);
		q[++m] = make_pair(r, i);
	}
	sort(q + 1, q + m + 1);
	for (int i = 1; i <= m; i++)
	{
		int j = q[i].second;
		if (j > 0)
		{
			if (st.size() == 1)
				cnt[j]--;
			st.erase(j);
		}
		else
		{
			if (st.empty())
				cnt[-j]--;
			st.insert(-j);
		}
		if (st.empty())
			ans++;
		else if (st.size() == 1)
			cnt[*st.begin()]++;
	}
	for (int i = 1; i <= n; i++)
		mx = max(mx, cnt[i]), cnt[i] = 0;
	printf("%d\n", mx + ans);
}

int main()
{
	scanf("%d", &T);
	while (T--)
		solve();
}