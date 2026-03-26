// Problem: D. Three Integers
// Contest: Codeforces - Codeforces Round #624 (Div. 3)
// URL: https://codeforces.com/contest/1311/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define endl '\n'
#define Carol MyWife^=^
#define pb push_back
#define pp pop_back
#define debug1(x) cout << #x << " = " << (x) << '\n'
#define debug2(x) cout << #x << " = " << (x) << ' '
//#define x first
//#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e4+5, M = 1e6+5;
const int MOD = 998244353, INF = 0x3f3f3f3f;
vector<int> v[N];
int a, b, c;
int A, B, C;
void solve() {
	int mn = INF;
	cin >> a >> b >> c;
	for(int i = 1; i <= 20000; i ++) {
		LL temp = abs(c - i);
		for(auto x : v[i]) {
			LL cost = abs(b - x) + temp;
			for(auto y : v[x]) {
				if(mn > cost + abs(a - y)) {
					mn = cost + abs(a - y);
					A = y, B = x, C = i;
				}
			}
		}
	}
	cout << mn << endl;
	cout << A << ' ' << B << ' ' << C << endl;
}

int main() {
	for(int j = 1; j <= 20000; j ++) {
		int x = j;
		for(int i = 1; i <= x / i; i ++) {
			if(x % i == 0) {
				v[j].pb(i);
				if(x / i != i) v[j].pb(x / i);
			}
		}
		sort(v[j].begin(), v[j].end());
	}
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while(t --) solve();
	
	return 0;
}