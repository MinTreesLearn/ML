#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC; while (TC--) {
		string S; cin >> S; int N = S.size();
		string T; cin >> T; int M = T.size();
		int pos[N+10][30];
		for (int i = 0; i < N; ++i) for (int j = 0; j < 26; ++j) pos[i][j] = -1;
		for (int i = N-1; i >= 0; --i) {
			pos[i][S[i]-'a'] = i;
			for (int j = 0; j < 26; ++j) {
				if (i+1 < N && pos[i][j] == -1) pos[i][j] = pos[i+1][j];
			}
		}
		int res = 1, idx = 0;
		for (int i = 0; i < M; ++i) {
			if (idx == N) {
				++res; idx = 0;
			}
			int next = pos[idx][T[i]-'a'];
			if (next == -1) {
				next = pos[0][T[i]-'a'];
				if (next == -1) {
					res = -1; break;
				} else {
					++res; idx = ++next;
				}
			} else {
				idx = ++next;
			}
		}
		cout << res << endl;
	}
	return 0;
}