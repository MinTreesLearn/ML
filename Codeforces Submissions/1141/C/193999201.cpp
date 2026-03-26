#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
	int n; cin >> n;
	vector<int> q(n - 1);
	for (int &x : q)
		cin >> x;
	vector<int> answer(n, 0);
	for (int i = 0; i < n - 1; i++)
		answer[i + 1] = answer[i] + q[i];
	int mx = *max_element(begin(answer), end(answer));
	for (int &x : answer)
		x += n - mx;
	set<int> st;
	for (int x : answer)
		st.insert(x);
	if (*st.begin() < 1 || st.size() != n)
		cout << -1;
	else
		for (int x : answer)
			cout << x << ' ';
}