/*
Here's to the crazy ones, the misfits, the rebels, the troublemakers,
the round pegs in the square holes ... the ones who see things differently .
They're not fond of rules, and they have no respect for the status quo. ...
You can quote them, disagree with them, glorify or vilify them,
but the only thing you can't do is ignore them because they change things. ...
They push the human race forward, and while some may see them as the crazy ones,
we see genius, because the people who are crazy enough to think that they can change the world, are the ones who do.
*/
/*
I watched a snail crawl along the edge of a straight razor.
That's my dream; that's my nightmare.
Crawling, slithering, along the edge of a straight razor.d.. and surviving..
*/
// Templates
// 1. tempgeo.cpp
// 2. tempunion.cpp
// 3. mysegtree.cpp
// 4. tempnt.cpp

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define int ll
#define pii pair <int, int>
#define pll pair <long long, long long>
#define endl '\n'
#include <random>
#define PI (2.0 * acos(0.0))
#define testcase int TT; cin >> TT; for (int tc = 1; tc <= TT; tc++)
// #define info pair<int, pair < int, string > >

#define mkp make_pair
#define info pair < int, pii >
typedef double T;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};
int fx[10] = {1, -1, 0, 0, 1, -1, 1, -1};
int fy[10] = {0, 0, 1, -1, 1 , -1, -1, 1};
const long long M = 2e5 + 10, M2 = 3e6 + 20, oo = 1e9 + 7, mod = 998244353;
const long long MC = (1 << 20) + 5;
inline int ceil(int a, int b) {
return (a + b - 1) / b;
}
inline int abs (int a, int b) {
int d1 = a - b;
if (d1 < 0) d1 *= -1;
return d1;
}

long long bigmod (int n, int p, int md) {
if (p == 0) return 1;
long long ans= bigmod(n, p / 2, md);
ans = (ans * ans) % md;
if (p % 2 == 1) ans = (ans * n) % md;
return ans;
}
long long pinverse (int num, int md) {
return bigmod(num, md - 2, md);
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


// ceil is a bad function
// think about reverse process
// read statement carefully
// think about corner cases before implementing
// don't forget to comment/uncomment define endl in interractive/non-interractive problems
// don't forget to return value in a return type function
// check if you are returning from solve before resetting array values
// try not to use continue / return statement, try to use if else
// try to write custom functions if stl one deals with floating point values
// don't use unordered map without custom hash
// multiset is bad try to use map if possible
// don't forget to return a value from a non-void function
int dp[M][2][2];
void precomp() {
}
void solve () {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < (1LL << n); i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -oo;
            }
        }
        dp[i][0][0] = 0;
    }
    int ofs = (1LL << (n - 1));
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        x--;
        x = x / 2 + ofs;
        if (dp[x][1][0] == 1) {
            dp[x][1][1] = 1;
        }
        dp[x][1][0] = dp[x][0][1] = 1;
        // cout << x << " xval now " << endl;
        // if (x - ofs == 5) cout << dp[x][1][1] << endl;
    }
    // cout << dp[5][1][0] << endl;
    for (int i = ofs - 1; i > 0; i--) {
        int c1 = i * 2, c2 = i * 2 + 1;
        for (int j1 = 0; j1 < 2; j1++) {
            for (int k1 = 0; k1 < 2; k1++) {
                for (int j2 = 0; j2 < 2; j2++) {
                    for (int k2 = 0; k2 < 2; k2++) {
                        // winner winner and loser loser
                        // cout << c1 << " " << c2 << endl;
                        // if (j2 == 1 && k2 == 0 && c2 == 5) cout << " this now " << dp[5][1][0] << endl;
                        // cout << i << " i here " << endl;
                        if (dp[c1][j1][k1] < 0 || dp[c2][j2][k2] < 0) continue;
                        // if (j1 + j2 + k1 + k2 > 0) cout << c1 << " ccc " << c2 << " "<< j1 << " " << k1 << " " << j2 << " " << k2 << " " << dp[c1][j1][k1] << " " << dp[c2][j2][k2] << endl;
                        int ex = 2 * (k1 | k2) + (j1 | j2);
                        // if (ex) cout << " ex " << ex << endl;
                        // cout << dp[c1][j1][k1] << " c1c2 " << dp[c2][j2][k2] << endl; 
                        dp[i][j1 | j2][k1 | k2] = max(dp[i][j1 | j2][k1 | k2], (dp[c1][j1][k1] + dp[c2][j2][k2] + ex));
                        // if (k1 + k2 == 0) {
                        //     dp[i][0][1] = max(dp[i][0][1], (dp[c1][j1][k1] + dp[c2][j2][k2] + (j1 | j2) + min(2LL, (k1 | k2)  + 1)));
                        // }
                        // if (i == 1) cout << dp[i][0][1] << " two " << ex << " " << j1 << " " << j2 << " " << k1 << " " << k2 << " " << min(2LL, (k1 | k2) + 1) << endl;
                        // cout << i << " " << c1 << " " << c2 << " " << 
                    }
                }
            }
        }
        dp[i][0][1] = max(dp[i][0][1], dp[i][1][0] + 1);
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = max(ans, dp[1][i][j] + (dp[1][i][j] > 0));
        }
    }
    cout << ans << endl;
}
int32_t main () {
    // freopen("E:/newts/in.txt", "r", stdin);
    //freopen("E:/newts/out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    // int T;
    // scanf("%d", &T);
    // while (T--) {
    // testcase {
        // cout << "Case #" << tc << ": ";
        // cout << "Case " << tc << ":"<< endl;
       solve ();    
    // }
return 0;
}
