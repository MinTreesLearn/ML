// Problem: C2. Madhouse (Hard version)
// Contest: Codeforces - Codeforces Round #612 (Div. 1)
// URL: https://codeforces.com/contest/1286/problem/C2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back

string solve(int n) {
	multiset<string> st;
	printf("? %d %d\n", 1, n);
	fflush(stdout);
	rep(i, 1, n * (n + 1) / 2) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		st.insert(s);
	}
	
	if(n == 1) return (* st.begin());
	
	printf("? %d %d\n", 2, n);
	fflush(stdout);
	rep(i, 1, n * (n - 1) / 2) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		st.erase(st.find(s));
	}
	
	string pre[110]; int cnt = 0;
	for(string o : st) pre[++ cnt] = o;
	sort(pre + 1, pre + cnt + 1, [](string x, string y) {return x.length() < y.length();});
	
	int cnt1[30], cnt2[30];
	string ans = pre[1];
	rep(i, 1, n - 1) {
		rep(j, 0, 25) cnt1[j] = cnt2[j] = 0;
		for(auto o : pre[i]) cnt1[o - 'a'] ++;
		for(auto o : pre[i + 1]) cnt2[o - 'a'] ++;
		rep(j, 0, 25) if(cnt1[j] != cnt2[j]) {
			ans += j + 'a';
			break;
		}
	}
	return ans;
}

int cnt[110][30];

int main() {
	int n; scanf("%lld", &n); 
	
	vector<string> all;
	printf("? %d %d\n", 1, n);
	fflush(stdout);
	rep(i, 1, n * (n + 1) / 2) {
		string s; cin >> s;
		all.eb(s);
	}
	
	if(n == 1) {
		printf("! "); cout << * all.begin() << endl;
		fflush(stdout);
		return 0;
	}
	
	string ans = solve(n >> 1);

	for(string o : all) {
		int len = o.length();
		for(char c : o) cnt[len][c - 'a'] ++;
	}
	
	if(n & 1) {
		int len = (n + 1) >> 1;
		rep(c, 0, 25) {
			int s = cnt[len][c] - cnt[len - 1][c];
			if(s) {ans += c + 'a'; break;}
		}
	}
	per(i, n >> 1, 1) {
		rep(c, 0, 25) {
			int s = (cnt[i][c] - cnt[i - 1][c]);
			if(i < (n + 1) / 2) s -= (cnt[i + 1][c] - cnt[i][c]);
			if(s - (ans[i - 1] - 'a' == c)) {ans += c + 'a'; break;}
		}
	}
	
	printf("! "); cout << ans << endl;
	fflush(stdout);
	
	return 0;
}
