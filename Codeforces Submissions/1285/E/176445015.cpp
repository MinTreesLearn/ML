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
PII a[N];
int ans[N];

int main()
{
	int T = 1;
	cin >> T;
	while(T -- ) {
		int n;cin >> n;
		memset(ans, 0, sizeof ans);
		for(int i = 1;i <= n;i ++ ) {
			int l, r;cin >> l >> r;
			a[i * 2 - 1] = {l, -i};
			a[2 * i] = {r, i};
		}
		multiset<int> s;
		sort(a+1, a + n*2+1);
		int c = 0;
		for(int i = 1;i <= 2 * n;i ++ ) {
			if(a[i].se < 0) {
				s.insert(-a[i].se);
			}
			else {
				s.erase(s.find(a[i].se));
			}
			if(SZ(s) == 0) c ++;
			if(SZ(s) == 1 && a[i].se > 0 && a[i+1].se < 0 && a[i+1].fi > a[i].fi) {
				ans[*s.begin()] ++;
			}
			if(SZ(s) == 1 && a[i].se < 0 && a[i+1].se > 0) {
				ans[*s.begin()] --;
			}
		}
		int Ans = -n;
		for(int i = 1;i <= n;i ++ ) {
			Ans = max(Ans, ans[i]);
		}
		cout << c + Ans << endl;
	}
	return 0;
}
