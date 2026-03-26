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

const int N = 2e6 + 100;
ll a[N], stk[N], len[N];

db get(db sum, db len) {
	return sum / len;
}

int main()
{
	int T = 1;
	IOS;
	// cin >> T;
	while(T -- ) {
		int n;cin >> n;
		for(int i = 0;i < n;i ++ ) cin >> a[i];
		int now = 0;
		for(int i = 0;i < n;i ++ ) {
			len[++ now] = 1;
			stk[now] = a[i];
			while(now > 1 && get(stk[now-1], len[now-1]) > get(stk[now], len[now])) {
				len[now-1] += len[now];
				stk[now-1] += stk[now];
				now --;
			}
		} 
		for(int i = 1;i <= now;i ++ ) {
			for(int j = 0;j < len[i];j ++ ) {
				double t = stk[i] * 1.0 / len[i];
				printf("%.9lf\n", t);
			}
		}
	}
	return 0;
}
