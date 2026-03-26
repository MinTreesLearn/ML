#include<bits/stdc++.h>
#include <ext/random>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define GET(n, i) (((n) >> (i)) bitand 1)
#define LAST(n) ((n) bitand (-(n)))
#define RANGE(x, y, i, j) (i > -1 and i < x and j > -1 and j < y)
#define SET(x, k) (x | (1LL << k))
#define CLEAR(x, k) (x bitand ~ (1LL << k))
#define CHECK(x, k) (x bitand (1LL << k))
#define TOGGLE(x, k) (x ^ (1LL << k))
using LL = int64_t;
LL dx [] = {0, 1, 0, -1};
LL dy [] = {1, 0, -1, 0};
LL dxx [] = {0, 1, 0, -1, 1, 1, -1, -1};
LL dyy [] = {1, 0, -1, 0, 1, -1, 1, -1};
const LL mod = 1000000007;
#define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
__gnu_cxx::sfmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const LL MAX = 1000;
vector<LL> fre(MAX, 0);
int main(void) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        srand(chrono :: high_resolution_clock :: now().time_since_epoch().count());
        LL T = 1; 
        for (LL qq = 0; qq < T; qq++) {
                LL n, m;
                cin >> n >> m;
                vector<LL> a(n, 0), b;
                unordered_set<LL> ss, bb;
                for (LL k = 0; k < n; k++) {
                        cin >> a[k];
                        ss.insert(a[k]);
                }
                if (ss.size() < n or n > m) {
                        cout << 0;
                        cout << '\n';
                        exit(0);
                }
                LL res = 1LL;
                for (LL k = 0; k < n; k++) {
                        for (LL j = k + 1; j < n; j++) {
                                res = res * (abs(a[k] - a[j]));
                                res = res % m;
                        }
                }
                cout << res << '\n';
                exit(0);
        }
        return 0;
}
