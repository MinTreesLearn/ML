#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>
#include <vector>
#include <array>
#include <string>
#include <istream>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <climits>
#include <chrono>
#include <iterator>
#include <bitset>
#include <complex>

using namespace std;

#define sz(x) (int)(x).size()
const int INF = 1e9 + 1;
const int mod = 998244353;
const int mxN = 1e5 + 1;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<int> cnt(32, 0);
	for (int x : a)
		for (int i = 0; i < 32; ++i)
			cnt[i] += ((x >> i) & 1);

	pair<int, int> last = { -1, -1 };
	for (int j = 0; j < n; ++j)
	{
		int curr = 0;
		for (int i = 0; i < 32; ++i)
			if (cnt[i] == 1 && ((a[j] >> i) & 1))
				curr += (1 << i);
		if (curr > last.second)
			last = { j, curr };
	}
	swap(a[0], a[last.first]);
	for (auto x : a)
		cout << x << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("_.in", "r", stdin);
	//freopen("_.out", "w", stdout); 

	int test = 1;
	//cin >> test;
	while (test--)
		solve();
	return 0;
}