#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ll
#define fr first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Rep(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
typedef pair<int,int> pii;
#ifdef OVAL
const ll N = 2e3+10;
#else
const ll N = 2e5+10;
#endif
string s;
int n, q;
int sum[N][30];
vector<int> query[N];
void solve()
{
	cin >> s;
	n = s.size();
	s = " " + s;
	For(i,1,n){
		For(j,0,26)sum[i][j] = sum[i-1][j];
		sum[i][s[i]-'a']++;
	}
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		// cout << s.substr(l, r-l+1) << ' ';
		if(s[l] != s[r] || r==l){
			cout << "Yes\n";
			continue;
		}
		if(r-l+1 <= 3){
			cout << "No\n";
			continue;
		}
		int cnt[30], num = 0;
		For(i,0,26){
			cnt[i] = sum[r][i]-sum[l-1][i];
			if(cnt[i])num++;
		}
		if(num <= 2)cout << "No\n";
		else cout << "Yes\n";
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int tt = 1;
	// cin >> tt;
	For(tc,1,tt){
		solve();
	}
	return 0;
}
/*
acacaabcaacbca
7
1 5
6 9
10 14
1 8
2 6
3 7
1 14


acbca
baacc
*/
	 	 		   	 		   	  	 	   		 	