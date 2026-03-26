#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	long long int n, ans = 0;
	cin >> n;
	vector<int>a(n + 1);
	map<long long int, long long int>mp;
	for(int i = 1; i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n;i++) {
		mp[a[i] - i]+=a[i];
		ans = max(ans, mp[a[i] - i]);
	}
	cout << ans << '\n';
}