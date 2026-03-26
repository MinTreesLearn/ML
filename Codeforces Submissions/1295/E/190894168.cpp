#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
typedef vector <ll> Row;
typedef vector <Row> Matrix;
#define T while(t--)
#define TASHLEEF ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin() , x.end()
#define debv(v) for(auto p : v) cout << p << " ";
#define deb(x) cout << #x << " = " << x << " ";
#define f(i,n) for(i;i<n;i++)
#define endl '\n'
#define LFT 2*p, L, (L+R)/2
#define RGT 2*p+1, (L+R)/2+1, R
#define PI 3.14159265
#define pb push_back
ll seg[800400], lzy[800800];
ll n, idx[200200], b[200200];
pair <ll, ll> a[200200];
void push(int p)
{
	if (lzy[p] != 0)
	{
		seg[2 * p] += lzy[p], seg[2 * p + 1] += lzy[p];
		lzy[2 * p] += lzy[p], lzy[2 * p + 1] += lzy[p];
		lzy[p] = 0;
	}
}
ll mrg(ll a, ll b)
{
	return min(a, b);
}
ll build(int p, int L, int R)
{
	if (L == R) return seg[p] = b[L]; return seg[p] = mrg(build(LFT), build(RGT));
}
ll qry(int i, int j, int p, int L, int R)
{
	if (j < L || R < i) return  1e18;
	if (i <= L && R <= j) {
		return seg[p];
	}
	push(p);
	return mrg(qry(i, j, LFT), qry(i, j, RGT));
}
ll upd(int i, int j, int inc, int p, int L, int R) {
	if (j < L || R < i) return seg[p];
	if (i <= L && R <= j) {
		lzy[p] += inc;
		return seg[p] += inc;
	}
	push(p);
	return seg[p] = mrg(upd(i, j, inc, LFT), upd(i, j, inc, RGT));
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first, idx[a[i].first] = i;
	for (int i = 0; i < n; i++) cin >> a[i].second, b[i] = a[i].second;
	for (int i = 1; i < n; i++) b[i] += b[i - 1];

	ll ans = min(b[0], a[n - 1].second);
	build(1, 0, n - 1);
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, qry(0, n - 1, 1, 0, n - 1));
		upd(0, idx[i] - 1, a[idx[i]].second, 1, 0, n - 1);
		upd(idx[i], n - 2, -a[idx[i]].second, 1, 0, n - 1);
	}
	cout << ans;
}
int main()
{
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
		cout << endl;
	}
}
