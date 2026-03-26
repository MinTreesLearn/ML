///
///   ♪ Hashire sori yo ♪
///   ♪ Kaze no you ni  ♪
///   ♪ Tsukimihara wo  ♪
///   ♪ PADORU PADORU   ♪
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;

bool qry(int x)
{
	cout << "? " << x+1 << '\n';
	char c;
	cin >> c;
	return toupper(c) == 'Y';
}

void clear()
{
	cout << "R\n";
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<bool> ok(n, 1);
	if (k > 1)
		k /= 2;
	int m = n/k;
	for (int dis = 1; dis < m; ++dis) {
		Loop (i,0,dis) {
			if (i + dis >= m)
				continue;
			clear();
			for (int j = i; j < m; j += dis) {
				Loop (x,j*k,j*k+k) {
					if (qry(x))
						ok[x] = 0;
				}
			}
		}
	}
	int ans = 0;
	Loop (i,0,n)
		ans += ok[i];
	cout << "! " << ans << '\n';
}
