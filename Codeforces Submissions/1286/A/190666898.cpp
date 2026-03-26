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

int n, m, l, r, odd, even;

// we can observe that if we at ith level and then even_to_fill + odd_to_fill = blank_pos till i

// so we'll use this fact to cut one dimension in iterative dp,
// define dp(i,j,k,par) -> min complexity till ith index and we have filled j odds and
// k evens till now and the current element we fill is of parity = par

// so we currently at index i, we know that we have filled j odds, so the rest blank pos
// = (0_till_i - j) have to be filled with evens

void solve()
{
	cin >> n;
    vi vis(n+1, 0), a(n+1), zero(n+1, 0);
    rep(i,1,n+1)
    {
        cin >> a[i];
        vis[a[i]] = 1;
        if (a[i] == 0) zero[i] = zero[i-1] + 1;
        else zero[i] = zero[i-1];
    }
    
    rep(i,1,n+1)
    {
        if (vis[i] == 0)
        {
            if (i&1) odd++;
            else even++;
        }
    }

    vvvi dp(n+5, vvi(n+5, vi(4, 1e18)));
    // base case
    dp[0][0][0] = dp[0][0][1] = 0;

    for (int i=1; i<=n; i++)
    {
        for (int of=0; of<=odd; of++)
        {
            // we have filled "of" odds(those which were not present in a[]) till ith index
            // so the remaining blank pos till i must be filled with evens
            // evens_to_fill = zeros[i] - of
            int etf = zero[i] - of;
            
            if (a[i] == 0)
            {
                if (of > 0) dp[i][of][1] = min(dp[i-1][of-1][1], dp[i-1][of-1][0]+1);
                if (etf > 0 and etf <= even) 
                    dp[i][of][0] = min(dp[i-1][of][0], dp[i-1][of][1]+1);
            }
            else
            {
                if (a[i]%2 == 1)
                    dp[i][of][1] = min(dp[i-1][of][1], dp[i-1][of][0]+1);
                else
                    dp[i][of][0] = min(dp[i-1][of][1]+1, dp[i-1][of][0]);
            }
        }
    }
    cout << min(dp[n][odd][0], dp[n][odd][1]);
}

signed main()
{
	IO();

	// testcase(tt);
	solve();
}