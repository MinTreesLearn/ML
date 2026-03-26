// LUOGU_RID: 101198123
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 5e3 + 10;
const int NN = N << 2;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
#define endl '\n'
#define int long long
typedef pair<int, int> PII;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    string ans_s = s;
    int ans_k = 1;
    for (int k = n; k >= 1; --k) {
        string s1 = s.substr(0, k - 1);
        if ((n - k + 1) % 2 == 1)
            reverse(s1.begin(), s1.end());
        string s2 = s.substr(0 + k - 1);
        string ss = s2 + s1;
        if (ss <= ans_s)
            ans_s = ss, ans_k = k;
    }
    cout << ans_s << endl;
    cout << ans_k << endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}