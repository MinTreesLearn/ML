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
#include <fstream>
#include <list>
#include <numeric>
#include <sstream>


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
#define prev sdjfsldfkjsdlkfjsldkfjlsdkjf
#define next oiasjdoiasjdasljdalsjdlaksjasd
#define time zsdfsijfsldfj83fsdfsdfsdfsdfsd
#define y1   ujqwoejqowiejqowiejqowiejqowij

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.141592653589793238462643383279502884L


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(int a, int b) { return 1ll * a * b / gcd(a, b); } //MAY BE DANGEROUS


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
const ll inf = 3e18 + 5;
//const int inf = 1e9 + 5;
//ll mod = 1e9 + 7;
#define endl "\n"
//////////////////////

vector<int> MIN(5001);
vector<int> MAX(5001);

vector<int> Prev;
void f(int i, int am, int sum) {
	if (am == 1 && sum == 0) {
		return;
	}
	
	{
		int SUM = sum - am + 1;
		int AM = am - 1;

		if (MIN[AM] <= SUM && SUM <= MAX[AM]) {
			Prev[i + 1] = i;
			f(i + 1, AM, SUM);
			return;
		}
	}
	

	for (int l = 1; l < am-1; ++l) {
		int r = am - 1 - l;
		if (l > r) break;


		int SUM = sum - am + 1;
		int AM = am - 1;

		for (int vl = MIN[l]; vl <= MAX[l]; ++vl) {
			int vr =SUM - vl;

			if (MIN[r] <= vr && vr <= MAX[r]) {
				Prev[i + 1] = i;
				Prev[i + l + 1] = i;
				f(i + 1, l, vl);
				f(i + l + 1, r, vr);
				return;
			}
		}
	}
}

void solve() {
	
	
	{
		int sum = 0;
		int am = 1;
		int s = 2;
		int z = 0;
		for (int i = 1; i <= 5000; ++i) {
			sum += z;
			MIN[i] = sum;
			--am;
			if (am == 0) {
				am = s;
				s *= 2;
				++z;
			}
		}
	}

	{
		for (int i = 1; i <= 5000; ++i) {

			int sum = 0;
			for (int g = 1; g <= i; ++g) {
				sum += (g - 1);

				int left = i - g;
				MAX[i] = max(MAX[i], sum + left * (g - 1));
			}
		}
	}
	int kek = 1;


	int q; cin >> q;
	while (q--) {
		int am, sum; cin >> am >> sum;
		if (sum < MIN[am] || sum > MAX[am]) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		Prev.assign(am + 1, 0);
		f(1, am, sum);
		for (int i = 2; i <= am; ++i) {
			cout << Prev[i] << " ";
		}
		cout << endl;
	}




}


int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	
	int TT = 1; //cin >> TT;
	while (TT--) {
		solve();
	}
	//Return;
}