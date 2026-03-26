#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
using LL = long long;
using LD = long double;
using ULL = unsigned long long;
using PII = pair<int, int>;
using TP = tuple<int, int, int>;
#define all(x) x.begin(),x.end()
#define mst(x,v) memset(x,v,sizeof(x))
#define mul(x,y) (1ll*(x)*(y)%mod)
#define mk make_pair
//#define int LL
//#define double LD
#define lc p*2
#define rc p*2+1
#define endl '\n'
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#pragma warning(disable : 4996)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const double eps = 1e-10;
const double pi = acos(-1);
const LL MOD = 1000000007;
const LL mod = 998244353;
const int maxn = 400010;

int N, A[maxn], B[maxn];

void solve()
{
	int ans = 0;
	for (int i = 0; i <= 25; i++)
	{
		for(int j=1;j<=N;j++)
		B[j] = A[j] % (1 << (i + 1));
		sort(B + 1, B + N + 1);
	/*	for (int j = 1; j <= N; j++)
			cout << B[j] << " ";
		cout << endl;*/
		int cnt = 0;
		for (int l = 1, r = N; l <= N; l++)
		{
			while (r > l && B[l] + B[r] >= (1 << i))
				r--;
			if (r <= l)
				r = l;
			cnt += N - r;
		}
		for (int l = 1, r = N; l <= N; l++)
		{
			while (r > l && B[l] + B[r] >= (1 << (i + 1)))
				r--;
			if (r <= l)
				r = l;
			cnt -= N - r;
		}
		//cout << cnt << "BBB" << endl;
		for (int l = 1, r = N; l <= N; l++)
		{
			while (r > l && B[l] + B[r] >= (1 << (i + 1)) + (1 << i))
				r--;
			if (r <= l)
				r = l;
			cnt += N - r;
		}
		//cout << i << "____" << cnt << endl;
		if (cnt & 1)
			ans |= 1 << i;
	}
	cout << ans << endl;
}

int main()
{
	IOS;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	solve();

	return 0;
}