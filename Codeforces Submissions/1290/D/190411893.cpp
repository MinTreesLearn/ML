/*

   Wei Wai Wei Wai
   Zumigat nan damu dimi kwayt rayt

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
/*typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod FM(2);*/
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}

#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define MP(x, y) make_pair(x, y)
#define F first
#define S second

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e3 + 10;

int n, k;
bool vis[maxn];

bool ask(int x){
	cout << "? " << x << endl;
	char res; cin >> res;
	return (res == 'Y'? true: false);
}

int md(int x){
	return (x <= 0? x + n / k: (x > n / k? x - n / k: x));
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	if (n == 1){
		return cout << "! 1" << endl, 0;
	}
	if (k > 1){
		k >>= 1;
	}
	for (int i = 1; i <= n/k/2; i++){
		cout << "R" << endl;
		for (int j = 1; j <= n/k; j++){
			int tmp = j / 2 * (j & 1? -1: 1);
			int blc = md(i + tmp);
			for (int idx = (blc-1) * k + 1; idx <= blc * k; idx++){
				if (!vis[idx]){
					vis[idx] = ask(idx);
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++){
		ans += (!vis[i]);
	}

	cout << "! " << ans << '\n';

	return 0;
}

