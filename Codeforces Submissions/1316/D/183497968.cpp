// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const  int    N = 1000;
const  int di[] = { -1, 1, 0, 0 };
const  int dj[] = { 0, 0, -1, 1 };
const char dd[] = { 'D', 'U', 'R', 'L' };

int ii[N][N], jj[N][N];
char cc[N][N + 1];
int n;

void dfs(int i, int j) {
	for (int h = 0; h < 4; h++) {
		int i_ = i + di[h];
		int j_ = j + dj[h];
		if (0 <= i_ && i_ < n
				&& 0 <= j_ && j_ < n
				&& !cc[i_][j_]
				&& ii[i][j] == ii[i_][j_]
				&& jj[i][j] == jj[i_][j_]) {
			cc[i_][j_] = dd[h];
			dfs(i_, j_);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int i_, j_; cin >> i_ >> j_, i_--, j_--;
			ii[i][j] = i_;
			jj[i][j] = j_;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (cc[i][j])
				continue;
			int i_ = ii[i][j];
			int j_ = jj[i][j];
			if (i_ == i && j_ == j) {
				cc[i][j] = 'X';
				dfs(i, j);
			} else if (i_ == -2) {
				int h = 0;
				while (h < 4) {
					i_ = i + di[h];
					j_ = j + dj[h];
					if (0 <= i_ && i_ < n && 0 <= j_ && j_ < n && ii[i_][j_] == -2)
						break;
					h++;
				}
				if (h == 4) {
					cout << "INVALID\n";
					return 0;
				}
				cc[i][j] = dd[h ^ 1];
				cc[i_][j_] = dd[h];
				dfs(i, j);
				dfs(i_, j_);
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!cc[i][j]) {
				cout << "INVALID\n";
				return 0;
			}
	cout << "VALID\n";
	for (int i = 0; i < n; i++) {
		cc[i][n] = '\0';
		cout << cc[i] << '\n';
	}
	return 0;
}
