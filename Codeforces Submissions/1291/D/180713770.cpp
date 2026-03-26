#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=2e5+5;
string s1;
int q,n,sum[INF][29];
signed main()
{
	ios::sync_with_stdio(false);
	cin>>s1;n=s1.size();s1=" "+s1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<26;j++)
			sum[i][j]=sum[i-1][j];
		sum[i][s1[i]-'a']++;
	}
	cin>>q;
	while (q--) {
		int l=0,r=0;
		cin>>l>>r;
		if (l==r) {cout<<"Yes\n";continue;}
		if (s1[l]!=s1[r]) {cout<<"Yes\n";continue;}
		int cnt=0;
		for (int i=0;i<26;i++)
			cnt+=!!(sum[r][i]-sum[l-1][i]);
//		cout<<cnt<<" fad?\n";
		if (cnt>=3) {cout<<"Yes\n";continue;}
		cout<<"No\n";
	}
	return 0;
}