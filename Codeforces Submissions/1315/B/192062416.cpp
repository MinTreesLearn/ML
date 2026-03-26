#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int binarySearch(vector<ll> main, int money) {
	int L = 0;
	int R = main.size() - 1;

	while (R >= L) {
		int mid = L + (R-L)/2;
		if (main[mid] <= money && main[mid-1] > money) return mid+1;

		if (main[mid] > money) L = mid + 1;
		else if (main[mid] <= money && main[mid-1] <= money) R = mid - 1; 
	}
	return 1;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, p; string s; 
		cin >> a >> b >> p >> s;

		vector<ll> needed(s.length());
		needed[s.length() - 1] = 0;
		needed[s.length() - 2] = (s[s.length()-2] == 'A' ? a : b);
		for (int i = s.length()-3; i >= 0; i--) {
			if (s[i] == s[i+1]) needed[i] = needed[i+1];
			else if (s[i] == 'A') needed[i] = needed[i+1] + a;
			else if (s[i] == 'B') needed[i] = needed[i+1] + b;
		}

		cout << binarySearch(needed, p) << endl;
	}
}