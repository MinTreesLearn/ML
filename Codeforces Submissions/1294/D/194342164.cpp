#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int>pi;
typedef pair<ll, ll>pl;
typedef vector<pi>vpi;
typedef vector<pl>vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
const long double PI = acos(-1);
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 2e5 + 7;
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define read(v) for (auto& it : v) scanf("%d", &it);
#define readL(v) for (auto& it : v) scanf("%lld", &it);
#define print(v) for (auto it : v) printf("%d ", it); puts("");
#define printL(v) for (auto it : v) printf("%lld ", it); puts("");
void solve() {
	int q, x, mex = 0;
	scanf("%d %d", &q, &x);
	vi v(x);
	for (int i = 0; i < x; i++)
		v[i] = i;
	map<int, bool>vis;
	while (q--) {
		int n;
		scanf("%d", &n);
		int mo = n % x;
		vis[v[mo]] = true, v[mo] += x;
		while (vis[mex])
			mex++;
		printf("%d\n", mex);
	}
}
int t = 1;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	//scanf("%d", &t);
	while (t--) solve();
}