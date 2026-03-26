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

const int N = 4e5 + 100;
int a[N], b[N];	

int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		int n;cin >> n;
		for(int i = 1;i <= n;i ++ ) {
			cin >> a[i];
		}
		ll ans = 0;
		for(int i = 24;i >= 0;i -- ) {
			int Mod = 1 << i;
			for(int j = 1;j <= n;j ++ ) b[j] = a[j] % (2 * Mod);
			sort(b + 1, b + n + 1);
			ll cnt = 0;
			for(int j = 1;j <= n;j ++ ) {
				cnt += upper_bound(b + 1, b + n + 1, 2 * Mod - b[j]-1) - lower_bound(b + 1, b + n + 1, Mod - b[j]); 
				cnt += upper_bound(b + 1, b + n + 1, 4 * Mod - b[j]-1) - lower_bound(b + 1, b + n + 1, 3 * Mod - b[j]);
				if((b[j] + b[j]) & (1 << i)) cnt --; // 删除自己和自己的
			}
			cnt /= 2;
			cnt &= 1;
			ans |= (cnt << i);
		}
		cout << ans << endl;
	}
	return 0;
}
