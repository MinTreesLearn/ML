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

const int N = 3e5 + 100;
int l[N][2], s[N*2], cnt[N*2];
int find(int x) {
	if(s[x] != x) return s[x] = find(s[x]);
	return s[x];
}
int n, k;
int calc(int x) {
	int y = (x <= k ? x + k : x - k);
	int xx = find(x), yy = find(y);
	if(xx == 0 || yy == 0) return cnt[xx + yy];
	return min(cnt[xx], cnt[yy]); 
}

void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	if(yy == 0) swap(xx, yy);
	s[yy] = xx;
	if(xx != 0) cnt[xx] += cnt[yy];
}

int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		cin >> n >> k;
		string t;cin >> t;
		for(int i = 1;i <= k;i ++ ) {
			s[i] = i;
			s[i+k] = i+k;
			cnt[i + k] = 1;
			int c;cin >> c;
			for(int j = 0;j < c;j ++ ) {
				int x;cin >> x;
				if(l[x][0] == 0) l[x][0] = i;
				else l[x][1] = i;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++ ) {
			if(l[i][1] == 0) {
				int x = l[i][0];
				if(x) { // 如果两个都不存在就不要处理
					ans -= calc(x);
					if(t[i-1] == '1') s[find(x+k)] = 0;
					else s[find(x)] = 0;
					ans += calc(x);
				}
			}
			else {
				int x = l[i][0], y = l[i][1];
				if(t[i-1] == '1') {
					if(find(x) != find(y)) {
						ans -= calc(x);
						ans -= calc(y);
						// cout << x << " " << y << endl;
						merge(x, y);
						merge(x+k, y+k);
						ans += calc(x);
					}
				}
				else {
					if(find(x+k) != find(y)) { // 你说x 和 y + k也是一样的
 						ans -= calc(x);
 						ans -= calc(y);
 						merge(x+k, y);
 						merge(x, y+k);
 						ans += calc(x);
 					}
				}
			}
			cout << ans << endl;
		}
		
	}
	return 0;
}
