#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const int M = 1e9+7, M2 = 998244353;
const double EPS = 1e-9;

void burn(int tc)
{
    int n, m, k; cin >> n >> m >> k;
    if (4*n*m-2*n-2*m < k)
        return void (cout << "NO");
    cout << "YES\n";
    vector <int> cnt;
    vector <string> path;
    int cur = 0;
    while(cur < n && k) {
        if (m > 1) {
            if (cur + 1 < n) {
                if (k < 3) {
                    if (k == 2) cnt.push_back(1), path.emplace_back("RD");
                    else cnt.push_back(1), path.emplace_back("R");
                    k = 0;
                }
                else {
                    if (k <= 3*m-3) {
                        cnt.push_back(k/3), path.emplace_back("RDU");
                        k%=3;
                        if (k == 2) cnt.push_back(1), path.emplace_back("RD");
                        else if (k == 1) cnt.push_back(1), path.emplace_back("R");
                        k = 0;
                    }
                    else cnt.push_back(m-1), path.emplace_back("RDU"), k-=3*m-3;
                }
            }
            else {
                if (k <= m-1) cnt.push_back(k), path.emplace_back("R"), k = 0;
                else cnt.push_back(m-1), path.emplace_back("R"), k-=m-1;
            }
            if (!k) continue;
            if (k <= m-1) cnt.push_back(k), path.emplace_back("L"), k = 0;
            else cnt.push_back(m-1), path.emplace_back("L"), k-=m-1;
        }
        if (!k) continue;
        if (cur+1 < n) cnt.push_back(1), path.emplace_back("D"), k--;
        else if (cur+1 == n) {
            if (k <= n-1) cnt.push_back(k), path.emplace_back("U"), k = 0;
            else cnt.push_back(n-1), path.emplace_back("U"), k-=n-1;
        }
        cur++;
    }
    assert(!k);
    cout << cnt.size() << '\n';
    for (int i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << ' ' << path[i] << '\n';
    }
}

int main()
{
    AboTaha_on_da_code

//    freopen("Ain.txt", "r", stdin);
//    freopen("Aout.txt", "w", stdout);

    int T = 1; // cin >> T;

    for (int i = 1; i <= T; i++) {
//        cout << "Case #" << i << ": ";
        burn(i);
        cout << '\n';
    }
    return 0;
}