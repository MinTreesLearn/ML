#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <random>
#include <complex>
#include <bitset>
#include<fstream>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;;
typedef pair<int, int> pii;

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << ii << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
#define rand kjsdflsdfsdlsjdlkfsdjflsjdfl 

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.1415926535897932384626L

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool BREAKTIME(ld v) {
	return 1.0 * clock() >= v * CLOCKS_PER_SEC;
}

#define OR(a, b)  ((a) | (b))
#define AND(a, b) ((a) & (b))
#define XOR(a, b) ((a) ^ (b))
#define BIT(a) (1ll << (a))

ll COUNT(ll n) {
	ll count = 0;
	while (n) {
		count += n & 1ll;
		n >>= 1ll;
	}
	return count;
}


///////////////////////
#define int long long
const ll inf = 3e18;
ll mod = 1e9 + 7;
#define endl '\n'
/////////////////////


struct Tree {
	int n = 1;
	vector<int> t;
	vector<int> p;


	Tree(vector<int>& A) {
		while (n < A.size()) n *= 2;
		t.assign(2 * n, -inf);
		p.assign(2 * n, 0);


		for (int i = n; i < n + A.size(); ++i) {
			t[i] = A[i - n];
		}

		for (int i = n - 1; i >= 1; --i) {
			t[i] = max(t[i * 2], t[i * 2 + 1]);
		}



	}


	void Push(int x, int tl, int tr) {
		t[x] += p[x];
		if (x * 2 < t.size()) {
			p[x * 2] += p[x];
			p[x * 2+1] += p[x];
		}
		p[x] = 0;
	}

	int Get(int x, int tl, int tr, int ql, int qr) {
		Push(x, tl, tr);
		if (ql <= tl && tr <= qr) {
			return t[x];
		}
		if (tl > qr || tr < ql) {
			return -inf;
		}

		int tm = (tl + tr) / 2;

		int ans = max(Get(x * 2, tl, tm, ql, qr), Get(x * 2 + 1, tm + 1, tr, ql, qr));

		t[x] = max(t[x * 2], t[x * 2 + 1]);
		return ans;
	}
	int Get(int l, int r) {
		return Get(1, 0, n - 1, l, r);
	}

	void Add(int x, int tl, int tr, int ql, int qr, int v) {
		Push(x, tl, tr);
		if (ql <= tl && tr <= qr) {
			p[x] += v;
			Push(x, tl, tr);
			return;
		}
		if (tl > qr || tr < ql) {
			return;
		}

		int tm = (tl + tr) / 2;

		Add(x * 2, tl, tm, ql, qr, v); Add(x * 2 + 1, tm + 1, tr, ql, qr, v);

		t[x] = max(t[x * 2], t[x * 2 + 1]);
		return;
	}
	void Add(int l, int r, int v) {
		return Add(1, 0, n - 1, l, r, v);
	}
};
void solve() {
	int n, m, p; cin >> n >> m >> p;
	const int N = 1e6 + 10;
	vector<int> A(N, inf);
	fori(n) {
		int a, b; cin >> a >> b;
		A[a] = min(A[a], b);
	}
	vector<int> B(N, inf);
	fori(m) {
		int a, b; cin >> a >> b;
		B[a] = min(B[a], b);
	}

	vector<vector<int>> C(p, vector<int>(3));
	fori(p) {
		forj(3) {
			cin >> C[i][j];
		}
	}

	for (int i = N - 2; i >= 0; --i) {
		A[i] = min(A[i], A[i + 1]);
		B[i] = min(B[i], B[i + 1]);
	}

	sort(all(C));


	fori(N) {
		B[i] = -B[i];
	}

	Tree T(B);



	int ans = -A[0] + B[0];
	for (int i = 0; i < p; ++i) {
		int a, b, c; a = C[i][0]; b = C[i][1]; c = C[i][2];
		T.Add(b+1, N-1, c);


		int v  = T.Get(0, N-1);
		ans = max(ans, v - A[a+1]);
	}
	cout << ans << endl;

}

int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T = 1; //cin >> T;
	while (T--) {
		solve();
	}
}