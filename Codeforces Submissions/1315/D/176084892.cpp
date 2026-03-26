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

int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		int n;cin >> n;
		vector<int> a(n), t(n);
		map<int, vector<int>> mp;
		for(int i = 0;i < n;i ++ ) cin >> a[i];
		for(int i = 0;i < n;i ++ ) cin >> t[i];
		for(int i = 0;i < n;i ++ ) {
			mp[a[i]].pb(t[i]);
		}
		int mx = 2e9;
		mp[mx].pb(mx);
		multiset<int, greater<int>> s;
		ll sum = 0, ans = 0;
		int lst = 0;
		for(auto [x, v] : mp) {
			if(SZ(s) > 0) {
				int i = lst;
				while(SZ(s) && i < x) {
					int y = *s.begin();
					s.erase(s.begin());
					sum -= y;
					ans += sum;
					i ++;
				}
			}
			for(int y : v) {
				sum += y;
				s.insert(y);
			}
			lst = x;
			// for(int x: s) cout << x << " ";
			// cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
