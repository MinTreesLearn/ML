// LUOGU_RID: 100960512
#include <bits/stdc++.h>
#define sizen 200003
using namespace std;
const int MAXN = 1 << 18;
int a[sizen];
pair<int, int> large[sizen], best[MAXN + 3][2];
int fa[sizen];
int find(int x) {return (fa[x] == x ? x : fa[x] = find(fa[x]));}
void update(pair<int, int> A[2], pair<int, int> B[2]) {
	if (A[0].first < B[0].first || (A[0].first == B[0].first && A[0].second != B[0].second)) {
		if (B[0].second != A[0].second) A[1] = A[0];
		A[0] = B[0];
	} else if (A[1].first < B[0].first && B[0].second != A[0].second) A[1] = B[0];

	if (A[0].first < B[1].first || (A[0].first == B[1].first && A[0].second != B[1].second)) {
		if (B[1].second != A[0].second) A[1] = A[0];
		A[0] = B[1];
	} else if (A[1].first < B[1].first && B[1].second != A[0].second) A[1] = B[1];
}
int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	long long  ans = 0;
	for (int i = 1; i <= n + 1; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int cnt = n + 1;
	while (cnt > 1) {
		for (int i = 0; i < MAXN; ++i) best[i][0] = best[i][1] = make_pair(-1, -1);
		for (int i = 1; i <= n + 1; ++i) {
			int id = find(i);
			if (best[a[i]][0].second == -1)
				best[a[i]][0] = make_pair(a[i], id);
			else if (best[a[i]][1].second == -1 && id != best[a[i]][0].second)
				best[a[i]][1] = make_pair(a[i], id);
			// cout << id << " " << best[a[i]][0].first << " " << best[a[i]][1].first << endl;
		}
		for (int i = 0; i < 18; ++i)
			for (int j = 0; j < MAXN; ++j)
				if ((j >> i) & 1) {
					int k = j ^ (1 << i);
					update(best[j], best[k]);
					// cout << j << " " << best[j][0].first << endl;
				}
		for (int i = 1; i <= n + 1; ++i)
				large[i] = make_pair(-1, -1);
		for (int i = 1; i <= n + 1; ++i) {
			// cout << i << " ";
			int id = find(i);
			// cout << id << endl;
			// cout << "#" << ((MAXN - 1) ^ (a[i])) << endl;
			int x = (MAXN - 1) ^ (a[i]);
			// cout << "@" << x << endl;
			// int x = 0;
			// cout << best[x][0].first << endl;
			if (best[x][0].first == -1) continue;
			if ((best[x][0].first ^ a[i]) > large[id].first && best[x][0].second != id) large[id] = make_pair(best[x][0].first ^ a[i], best[x][0].second);
			if ((best[x][1].first ^ a[i]) > large[id].first && best[x][1].second != id) large[id] = make_pair(best[x][1].first ^ a[i], best[x][1].second);
			// cout << "-------------------" << endl;
		}
		// cout << "@@@@" << endl;
		// cout << cnt << endl;
		for (int i = 1; i <= n + 1; ++i) {
			if (find(i) != i) continue;
			if (large[i].first == -1) continue;
			int x = i, y = large[i].second;
			y = find(y);
			if (x == y) continue;
			fa[x] = y;
			--cnt;
			ans += large[i].first;
		}
	}
	for (int i = 1; i <= n; ++i) ans -= a[i];
	cout << ans << endl;
	return 0;
}