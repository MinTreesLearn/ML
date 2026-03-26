#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	vector<ll> presum(n + 1), sufsum(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	stack<ll> st;//栈里面存放的是下标
	vector<ll> l(n + 2), r(n + 2);
	for (int i = 1; i <= n; ++i) {
		while (!st.empty() && a[st.top()] >=
		        a[i]) {
			// 不同题目的符号不同，注意分辨
			st.pop();
		}
		l[i] = (st.size() == 0 ? 0 :
		        st.top());
		st.push(i);// 注意栈里面放进去的是下标
	}
	while (!st.empty())st.pop();
	for (int i = n; i >= 1; --i) {
		while (!st.empty() && a[st.top()] >=
		        a[i]) {
			// 不同题目的符号不同，注意分辨
			st.pop();
		}
		r[i] = (st.size() == 0 ? (n + 1) :
		        st.top());
		st.push(i);// 注意栈里面放进去的是下标
	}

	for (int i = 1; i <= n; i++) {
		presum[i] = presum[l[i]] + a[i] * (i - l[i]);
	}
	for (int i = n; i >= 1; --i) {
		sufsum[i] = sufsum[r[i]] + a[i] * (r[i] - i);
	}


	vector<ll> res(n + 1);
	int idx;
	ll ans = -1;
	for (int j = 1; j <= n; j++) {
		if (ans < presum[j] + sufsum[j] - a[j]) {
			ans = presum[j] + sufsum[j] - a[j];
			idx = j;
		}
	}
	ll pre = a[idx];
	for (int i = idx - 1; i >= 1; --i) {
		res[i] = min(pre, a[i]);
		pre = min(pre, a[i]);
	}
	res[idx] = a[idx];
	pre = a[idx];
	for (int i = idx + 1; i <= n; i++) {
		res[i] = min(pre, a[i]);
		pre = min(pre, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
}
	 			  	 	 			 	  	 	 		 	 			