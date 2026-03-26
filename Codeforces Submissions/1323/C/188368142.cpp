#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10;
int ne[N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(2);
	int n;
	cin >> n;
	string a;
	cin >> a;
	int cnt = 0;
	int ok = -1;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ')')cnt--;
		else cnt++;
		if (cnt < 0 && ok == -1) {
			ok = i;
		}
		if (ok != -1 && cnt == 0) {
			ans += i - ok + 1;
			ok = -1;
		}
	}
	if (cnt) {
		cout << -1;
	} else
		cout << ans;
	return 0;
}
