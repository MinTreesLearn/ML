#include<bits/stdc++.h>
#define deq deque<int
#define vec vector<int
#define pb push_back
#define pf push_front
#define sonic ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	sonic;
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		int ch = 0, nch = 0;
		for (int i = 0; i < n; i ++) {
			if (a[i] % 2 == 0) {
				ch += 1;
			}
			else {
				nch += 1;
			}
		}
		if (ch == n || nch == n) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}