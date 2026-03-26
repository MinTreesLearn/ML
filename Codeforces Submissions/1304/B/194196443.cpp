#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> // pbds
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//
using ll = long long;
using ld = long double;
typedef complex<ld> cd;
//
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
//
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
//
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
//
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define sumv(x)  accumulate(x.begin(), x.end(), 1LL*0)
#define yes cout << "YES" << endl
#define no cout<<"NO"<<endl
//
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define Unique(X) (X).erase(unique(all(X)),(X).end())
//
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
//
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
//
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << "}\n";}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
//
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const char nl = '\n';
const int MX = 1e5 + 1;
const ll c = 5*(1e5 + 1);
const ll INF = 1000000000000000000;
const ll inf = 1000000000;
const ll eps = 1e-9;



void solve(int test){	
	ll n, m ; cin >> n >> m;
	vector <string> v(n);
	map <string , ll> mm;
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
		mm[v[i]]++;
	}
	dbg(mm);
	vector<string> L , R;
	string middle;
	for(ll i = 0; i < n; ++i){
		string curr = v[i];
		reverse(all(curr));
		if(curr == v[i]){
			middle = curr;
		}
		else if(mm.find(curr) != mm.end()){
			L.pb(v[i]);
			R.pb(curr);
			mm.erase(v[i]);
			mm.erase(curr);	
		}
	}
	cout << sz(L) * 2 * m + sz(middle) << nl;
	for(auto i : L) cout << i;
	cout << middle;
	reverse(all(R));
	for(auto i : R) cout << i;
	cout << nl;
}



bool test_case = 0;


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
clock_t start = clock();
	cout << fixed << setprecision(15);
	ll t = 1;
	if(test_case){
		cin >> t;
	}
	for(ll i = 1; i <= t; ++i){
		solve(1);
	}
clock_t end = clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
cerr << "Time : " << fixed << time_taken << setprecision(5);
cerr << " sec" << nl;
}
