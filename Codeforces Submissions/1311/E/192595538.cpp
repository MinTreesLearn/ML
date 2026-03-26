// just for fun

#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = (x); i <= (y); i+=1)
#define epr(i, x) for (int i = head[x]; i; i = nxt[i])
#define per(i, x, y) for (int i = (x); i >= (y); i-=1)
#define DC int T = gi <int> (); while (T--)
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef pair <LL, int> PLI;
typedef pair <int, LL> PIL;
typedef pair <LL, LL> PLL;

template <typename T>
inline T gi()
{
	T x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

template <typename T> inline void chkmax(T &x, const T &y) {x = x > y ? x : y;}
template <typename T> inline void chkmin(T &x, const T &y) {x = x < y ? x : y;}

const int N = 5003, M = N << 1, INF = 0x3f3f3f3f;

int n, d;
int cnt[N];
vector <int> vec[N];

inline void solve()
{
	n = gi <int> (), d = gi <int> ();
	int cc = 0, mn = 0, mx = 1ll * n * (n - 1) / 2, mxd = 0;
	rep(i, 0, n) cnt[i] = 0, vec[i].clear();
	rep(i, 0, 20)
	{
		cnt[i] = min(n - cc, 1 << i);
		mn += min(n - cc, 1 << i) * i;
		cc += min(n - cc, 1 << i);
		if (cc == n) {mxd = i; break;}
	}
	if (d < mn || d > mx) return (void)puts("NO");
	puts("YES");
	int dlt = d - mn, pp = mxd;
	per(i, mxd, 1)
	{
		int o = cnt[i];
		rep(j, 1, o - 1)
		{
			--cnt[i];
			int now = i;
			while (dlt && cnt[now]) ++now, --dlt;
			++cnt[now], chkmax(pp, now);
			if (!dlt) break;
		}
		if (!dlt) break;
	}
	int oid = 0;
	rep(i, 0, pp) rep(j, 1, cnt[i])
		vec[i].eb(++oid);
//		cout << i << ' ' << j << ' ' << cnt[i] << ' ' << oid << endl;
	rep(i, 1, pp)
	{
		int zz = 0, oc = 0;
		rep(j, 1, cnt[i])
		{
			printf("%d ", vec[i - 1][zz]);
//			cout << "{ " << oc << ' ' << zz << "}\n";
			if (oc == 0) ++oc;
			else oc = 0, ++zz;
		}
	}
	puts("");
}

int main()
{
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	DC solve();
	return !!0;
}
