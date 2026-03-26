#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=4e5+3;
int a[N];
void solve() {
	int q,x;
	cin>>q>>x;
	map<int ,int >mp;
	int ans=0;
	while(q--) {
		int k;
		cin>>k;
	    mp[k%x]++;        //转化为1~x-1 
	    while(mp[ans%x]){        // 可以转为为ans 
	    	mp[ans%x]--;
	    	ans++;
		}
		cout<<ans<<endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	int t;	cin>>t;	while(t--)
	solve();
	return 0;
}


