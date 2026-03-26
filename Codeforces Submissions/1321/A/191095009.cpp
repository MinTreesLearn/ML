#include <bits/stdc++.h>
using namespace std;

int main () {
	int n; cin >> n;
	vector<int> a (n);
	vector<int> b (n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;
	int aWin = 0, bWin = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] && !b[i])
			++aWin;
		if (!a[i] && b[i])
			++bWin;
	}
	if (!aWin) {
		cout << -1 << endl;
		return 0;
	}
	++bWin;
	cout << (bWin+(aWin-1))/aWin << endl;
}
