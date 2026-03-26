#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int main(){
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		int a[N], b[N];
		cin >> n >> p;
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n; i++) b[i] = 0;
		for (int i = 0; i < p; i++) {
			int x;
			cin >> x;
			b[x-1] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (b[j] == 1 && a[j] > a[j + 1]) {
					swap(a[j], a[j + 1]);
				}
			}
		}

		bool x = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				x = false;
				break;
			}
		}
		if (x == true) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}
		   		 								 	 	  	  	 			