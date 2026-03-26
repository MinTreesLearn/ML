#include <bits/stdc++.h>
using namespace std;

#define int long long
int tt;
void solve();

void IO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void testcase(int t)
{
	cin >> t;
	while (t--) solve();
}

typedef long long ll;
typedef long double lld;

#define ff first
#define ss second
#define pi pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define pv pair<vi, vi>
#define vpi vector<pi>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
#define vvvi vector<vvi>
#define pb push_back
#define mp make_pair
#define arr(k) array<int, k>
#define var(k) vector<arr(k)>
#define all(v) v.begin(), v.end()
#define len(v) (int)v.size()
#define rep(i, a, b) for(int i=a; i<b; i++)
#define each(nb, x) for (auto nb:x)


/*  ------------------------    BASIC INPUT -------------------------------  */

void read() {}
void read(int &a) {cin >> a;}
void read(string &s) {cin >> s;}
void read(double &a) {cin >> a;}
void read(lld &a) {cin >> a;}
template<typename x, typename y> void read(pair<x, y> &a) {read(a.first), read(a.second);}
template<typename x>void read(x &a) {for (auto  &i : a) read(i);}
template<typename x, typename... y> void read(x& a, y&... b) {read(a); read(b...);}
template<class T> void cmin(T&a, T b) {a = min(a, b);}
template<class T> void cmax(T&a, T b) {a = max(a, b);}

/*    ------------------------------------------------------------------   */


/* -------------------------------------  DEBUG STARTS ------------------------------- */

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

void print(int t) {cout << t;}
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(lld t) {cout << t;}
void print(double t) {cout << t;}
void print(bool t) {cout << t;}
void print(deque<int> t) {while (not t.empty()) {cout << t.front() << ' '; t.pop_front();}}
void print(queue<int> t) {while (not t.empty()) {cout << t.front() << ' '; t.pop();}}

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(deque<int> t) {while (not t.empty()) {cerr << t.front() << ' '; t.pop_front();}}
void _print(queue<int> t) {while (not t.empty()) {cerr << t.front() << ' '; t.pop();}}

template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T, class V> void print(pair <T, V> p) {print(p.ff); cout << " "; print(p.ss);}
template <class T> void print(vector <T> v) {for (T i : v) {print(i); cout << " ";}}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/* -------------------------------------  DEBUG ENDS --------------------------------- */

int n, m, l, r;
int dp[101][101][101][3];
vi a;

// we were getting WA due to -1 in parity

// rec(i) -> tot complexity in [i..n]
int rec(int i, int odd_left, int even_left, int prev_parity)
{
    if (i==n) return 0;

    if (dp[i][odd_left][even_left][prev_parity+1] != -1)
        return dp[i][odd_left][even_left][prev_parity+1];

    if (a[i] != 0)
    {
        return dp[i][odd_left][even_left][prev_parity+1] = (a[i]%2==prev_parity or i==0) ? 
                rec(i+1, odd_left, even_left, a[i]%2) :1 + rec(i+1, odd_left, even_left, a[i]%2);
    }

    int op1 = 1e9, op2 = 1e9;
    // assign odd parity
    if (odd_left > 0) 
    {
        op1 = (prev_parity==1 or i==0) ? rec(i+1, odd_left-1, even_left, 1) : 
                                1+rec(i+1, odd_left-1, even_left,1);
    }

    // assign even parity
    if (even_left > 0)  
    {
        op2 = (prev_parity==0 or i==0) ? rec(i+1, odd_left, even_left-1, 0) : 
                                1+rec(i+1, odd_left, even_left-1,0);
    }
    return dp[i][odd_left][even_left][prev_parity+1] = min(op1, op2);
}

void solve()
{
	cin >> n; a.resize(n);
    vi vis(n+1, 0);
    int odd=0, even=0;
    rep(i,0,n)
    {
        cin >> a[i];
        vis[a[i]] = 1;
    }

    rep(i,1,n+1)
    {
        if (vis[i] == 0)
        {
            if (i&1) odd++;
            else even++;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0,odd, even, -1);
}

signed main()
{
	IO();

	// testcase(tt);
	solve();
}