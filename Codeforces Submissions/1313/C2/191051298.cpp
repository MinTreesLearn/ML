#include <iostream>
#include <stack>
using namespace std;
#define int long long
int ans[500005];
int n, a[500005];
int suml[500005];
int sumr[500005];
stack<int> st;
signed main(){
	scanf("%lld", &n);
	st.push(0);
	a[0] = -999999999;
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++){
		while(a[st.top()] > a[i]) st.pop();
		suml[i] = suml[st.top()] + a[i] * (i - st.top());
		st.push(i);
	}
	while(!st.empty()) st.pop();
	st.push(n + 1);
	a[n + 1] = -999999999;
	for(int i = n; i >= 1; i--){
		while(a[st.top()] > a[i]) st.pop();
		sumr[i] = sumr[st.top()] + a[i] * (st.top() - i);
		st.push(i);
	}
	int maxn = -999999999, id;
	for(int i = 1; i <= n; i++){
		if(suml[i] + sumr[i] - a[i] > maxn){
			maxn = suml[i] + sumr[i] - a[i];
			id = i;
		}
	}
	int minn = a[id];
	for(int i = id - 1; i >= 1; i--){
		minn = min(minn, a[i]);
		ans[i] = minn;
	}
	minn = a[id];
	for(int i = id + 1; i <= n; i++){
		minn = min(minn, a[i]);
		ans[i] = minn;
	}
	ans[id] = a[id];
	for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}