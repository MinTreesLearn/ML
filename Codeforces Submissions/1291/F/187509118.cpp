#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, k;
vector<int> B[MAXN];
set<pll> st;

inline bool ask(int x) {
	cout << "? " << x << endl;
	string ans;
	cin >> ans;

	return ans == "Y";
}

inline void R() {
	cout << "R" << endl;
}

inline vector<int> hamiltonian_path(int n, int i) {
	vector<int> path;
	for (int j = 0; j < n; j++)
		path.push_back((i + (j & 1 ? -1 : 1) * ((j + 1) / 2) + n) % n);

	return path;
}

int main() {
	cin >> n >> k;
	if (n == 1 && k == 1) return cout << "! 1" << endl, 0;

	if (k > 1) k /= 2;
	for (int i = 0; i < n / k; i++) {
		for (int j = 1; j <= k; j++) {
			int x = i * k + j;
			if (!ask(x))
				B[i].push_back(x);
		}
	}

	R();
	for (int i = 0; i < n / k / 2; i++) {
		vector<int> path = hamiltonian_path(n / k, i);

		for (int e : path)
			for (int j = B[e].size() - 1; j >= 0; j--)
				if (ask(B[e][j]))
					B[e].erase(B[e].begin() + j);

		for (int i = 1; i < path.size(); i++)
			st.insert({min(path[i], path[i - 1]), max(path[i], path[i - 1])});
		R();
	}

	int ans = 0;
	for (int i = 0; i < n / k; i++)
		ans += B[i].size();

	cout << "! " << ans << endl;
	return 0;
}
