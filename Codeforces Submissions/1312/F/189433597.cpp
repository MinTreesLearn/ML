#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define uf(i,x,y) for(int i=x, i##end=y; i<i##end; ++i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back 
#define int long long
char ch;
int rd() {
	int f=1, x=0; ch=getchar();
	while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
int sg[300005][3], sgT; const int lim = 1005; ll a[300005], st;
int mex(int x, int y, int z) {
	if(x > y) swap(x, y);
	if(x > z) swap(x, z);
	if(y > z) swap(y, z);
	if(x == 0 && y == 1 && z == 2) return 3;
	else if(x == 0 && y == 0 && z == 1) return 2;
	else if(x == 0 && y == 1) return 2;
	else if(x == 0) return 1;
	else return 0;
	// if(x != 0) return 0;
	// else {
		// if(y != 1) return 1;
		// else if(z != 2) return 2;
		// else return 3;
	// }
}
int mex(int a, int b) {
	if(a > b) swap(a, b);
	if(a == 0 && b == 1) return 2;
	else if(a == 0) return 1;
	else return 0;
	// if(a != 0) return 0;
	// else {
		// if(b != 1) return 1;
		// else return 2;
	// }
}
int gainsg(ll v, int state) {
	if(v < st) return sg[v][state];
	return sg[( v - st ) % sgT + st][state];

	// return sg[v][state];
}
int lcm(int a, int b) {
	return a*b/__gcd(a, b);
}
int lcm(int x, int y, int z) {
	// f(i,1,100) if((i % x == 0) && (i % y == 0) && (i % z == 0)) return i;
	// assert(0); return -1;
	return lcm(x, lcm(y, z));
}
int chk(int pos) {
	f(i,0,sgT-1) if(sg[pos+i][0] != sg[pos+i+sgT][0]) return 0;
	return 1;
}
void solve() {
	int n=rd(), x=rd(), y=rd(), z=rd();
	sg[0][0] = sg[0][1] = sg[0][2] = 0;
	// cerr << "# " << x << ' ' << y << ' ' << z << endl;
	f(i,1,lim) {
		sg[i][0] = mex(sg[max(i-x, 0LL)][0], sg[max(i-y, 0LL)][1], sg[max(i-z, 0LL)][2]);
		sg[i][1] = mex(sg[max(i-x, 0LL)][0],                       sg[max(i-z, 0LL)][2]);
		sg[i][2] = mex(sg[max(i-x, 0LL)][0], sg[max(i-y, 0LL)][1]);
		// cerr << i << ' ' << sg[i][0] << ' ' << sg[i][1] << ' ' << sg[i][2] << endl;
	}
	// sgT = x * y * z;
	f(len,12,60) {
		sgT = len; st = -1;
		f(i,sgT,lim - sgT) if(chk(i)) { st = i; goto OPT; }
	}
	// OPT : cerr << "sgt = " << sgT << " st = " << st << endl;
	OPT : int ALLSG = 0; ll ans = 0;
	f(i,1,n) cin >> a[i];
	f(i,1,n) ALLSG ^= gainsg(a[i], 0);
	// f(i,1,n) ALLSG ^= sg[a[i]][0];
	// cerr << ALLSG << endl;
	f(i,1,n) {
		// int nowsg = ALLSG ^ gainsg(a[i], 0) ^ gainsg(max(a[i] - (t == 0 ? x : (t == 1 ? y : z)), 0LL), t);
		int nowsg0 = ALLSG ^ gainsg(a[i], 0) ^ gainsg(max(a[i] - x, 0LL), 0);
		int nowsg1 = ALLSG ^ gainsg(a[i], 0) ^ gainsg(max(a[i] - y, 0LL), 1);
		int nowsg2 = ALLSG ^ gainsg(a[i], 0) ^ gainsg(max(a[i] - z, 0LL), 2);
		
		// cerr << "ok " << i << ' ' << t << ' ' << nowsg << ' ' << (max(a[i] - (t == 0 ? x : (t == 1 ? y : z)), 0LL)) << endl;
		if(nowsg0 == 0) ++ans;
		if(nowsg1 == 0) ++ans;
		if(nowsg2 == 0) ++ans;
	}
	cout << ans << endl;
}
signed main() {
	int t=rd(); while(t--) solve();
	return 0;
}