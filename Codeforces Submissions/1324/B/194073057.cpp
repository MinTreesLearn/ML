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
		bool ok = false;
		for (int i = 0; i < n; i ++) {
			for (int j = i; j < n; j ++) {
				if (i != j && abs(i-j) > 1) {
					if (a[i] == a[j]) {
						ok = true;
					}
				} 
			}
		}
		if (ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}	
}