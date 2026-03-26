// ඞ
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "debug.h"
#define dbg(...) debug_out(splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define ALL(v) (v).begin(), (v).end()
#define mem(a, x) memset(a , x , sizeof(a))
#define F first
#define S second
#define pb push_back
#define popCnt __builtin_popcountll

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair <int, int> pii;
typedef vector<pair <int, int>> vpii;
typedef vector<vector<char>> vvc;

const int mod = 1e9 + 7;
const int oo = 0x5f5f5f5f;
const long double PI = acos(-1.0L);


int Log2 (int x) {return 31 - __builtin_clz(x);}
int ceiledLog2 (int x){return Log2(x) + (__builtin_popcount(x) != 1);}
ll toLL (int first, int second, int mx){return (1LL*first*mx) + second;}
vi Unique(vi x){sort(ALL(x));x.resize(distance(x.begin(),unique(ALL(x))));return x;}
template <class T, class U> T GCD (T a, U b) {return (!b ? a : GCD(b, a%b));}
template <class T, class U> T LCM (T a, U b) {return ((a/GCD(a, b)) * b);}
template <class T> bool isSquare (T n) {T sq = sqrt(n);  return (sq*sq)==n;}
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//bool sortBySecond (pii &a, pii &b) {return a.second < b.second;} //asc

int ys[] = {-1, -1, 0, 1, 1, 1, 0, -1};     //edges [0, 2, 4, 6]
int xs[] = {0, 1, 1, 1, 0, -1, -1, -1};

//-----------------------------------------------------------------------------//

int n,m=0, z=0,o=0;
vector<int> a;
int dp[101][2][55][55];
int solve (int idx, int last, int usedZ, int usedO)
{
    if (idx == n){
        return 0;
    }

    if (~dp[idx][last][usedZ][usedO]){
        return dp[idx][last][usedZ][usedO];
    }
    if (a[idx] == -1){
        int ans1,ans2;
        ans1=ans2=1e9;
        if (usedO<o){
            ans1=solve(idx+1, 1, usedZ, usedO+1)+(1 != last);
        }
        if (usedZ<z){
            ans2 = solve(idx+1, 0, usedZ+1, usedO)+(0 != last);
        }
        return dp[idx][last][usedZ][usedO]=min(ans1,ans2);
    }
    else{
        return dp[idx][last][usedZ][usedO] = solve(idx+1, a[idx], usedZ, usedO)+(a[idx] != last);
    }
}
void run_test ()
{
    mem(dp,-1);
    cin >> n;
    vi f(n+1,0);

    a=vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]] =1;
        if (a[i]==0){
            a[i] = -1;
            m++;
        }
        else{
            a[i] %=2;
        }
    }

    vi miss;

    for (int i = 1; i <= n; ++i) {
        if (f[i] == 0){
            miss.pb(i);
            if (i&1){
                o++;
            }
            else{
                z++;
            }
        }
    }
    dbg(miss,z,o);
    if (a[0] == -1){
        int ans1,ans2;
        ans1=ans2=1e9;
        if (o){
            ans1=solve(1, 1, 0, 1);
        }
        if (z){
            ans2 = solve(1, 0, 1, 0);
        }
        dbg(ans1,ans2);
        cout << min(ans1,ans2);
    }
    else
        cout << solve(1,a[0], 0, 0);
}

void initialize(char _mode = 's');
int32_t main()
{
    initialize();
    //cout << fixed << setprecision (9);

    int tc = 1;
    //cin >> tc;
    for (int t=1; t <= tc; t++) {
        //cout << "Case #" << t << ": ";
        run_test();
    }
    cerr << "$time taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
void initialize(char _mode){  //s,d,c,x
    if (_mode == 's' || _mode == 'c'){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
#ifdef LOCAL
    if (_mode == 's' || _mode == 'd'){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif
}
