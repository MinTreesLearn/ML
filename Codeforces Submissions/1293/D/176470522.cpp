//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
/*测量运行时间
#include <windows.h>
DWORD star_time = GetTickCount();
DWORD end_time = GetTickCount();
cout << (end_time - star_time) << "ms." << endl;
*/
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
#define pb push_back
#define fi first
#define SZ(x) ((int)(x).size())
#define se second
#define int128 __int128
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
template <class T>
inline bool in(T &ret) 
{
	char c;T sgn;
	if(c=getchar(),c==EOF) return 0; 
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}
template <class T>
inline void out(T x)
{
    if(x<0)
	{	
        putchar('-');
        x=-x;
    }
    if(x>9)
    out(x/10);
    putchar(x%10+'0');
}

const int N = 110;
ll x[N], y[N];
ll xs, ys, t, ax, ay, bx, by;
int tot = 0;
int solve(ll xb) {
	ll cst = t;
	ll xx = xs, yy = ys;
	int cnt = 0;
	for(int i = xb;i >= 0;i -- ) {
		ll val = abs(xx - x[i]) + abs(yy - y[i]);
		if(cst < val) break;
		cst -= val;
		cnt ++;
		xx = x[i];
		yy = y[i];
	}
	for(int i = xb+1;i <= tot;i ++ ) {
		ll val = abs(xx - x[i]) + abs(yy - y[i]);
		if(cst < val) break;
		cst -= val;
		cnt ++;
		xx = x[i];
		yy = y[i];
	}
	return cnt;
}

int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
		cin >> xs >> ys >> t;
		for(int i = 1;;i ++ ) {
			x[i] = x[i-1] * ax + bx;
			y[i] = y[i-1] * ay + by;
			// cout << x[i] << " " << y[i] << endl;
			if(x[i] >= xs && y[i] >= ys && abs(x[i] - xs) + abs(y[i] - ys) > t) break;
			tot = i;
		}
		int ans = 0;
		for(int i = 0;i <= tot;i ++ ) {
			ans = max(ans, solve(i));
		}
		cout << ans << endl;
	}
	return 0;
}
