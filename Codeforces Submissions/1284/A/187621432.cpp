#include "bits/stdc++.h"
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<=(b):i>=(b); i+=(s))
#define F_OR1(e) F_OR(i, 1, e, 1)
#define F_OR2(i, e) F_OR(i, 1, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define forn(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define dbg cout << "_____________________HERE_________________________"
 
using namespace std;
const int N=1e5+10,LOG=17,mod=998244353;
const int inf=1e9;
const double eps = 1e-9;
const int block = 340, timer = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define IOS ios_base::sync_with_stdio(false),cin.tie(0);cout.tie(0)
#define int ll
#define pii pair <int, int>

void solve(){
	int n , m ; cin >> n >> m ;
	string s[n + 1] , t[m + 1] ;
	forn(i , 1 , n){
		cin >> s[i] ;
	}
	forn(i , 1 , m){
		cin >> t[i] ;
	}
	int q ; cin >> q ;
	forn(i , 1 , q){
		int cur ; cin >> cur ;
		cur-- ;
		int x = cur % n ;
		int y = cur % m ;
		cout << s[x + 1] << t[y + 1] << "\n" ;
	}
}

signed main(){
	IOS ;
	int test = 1 ;
	// cin >> test ;
	forn(i , 1 , test){
		solve() ;
	}
}