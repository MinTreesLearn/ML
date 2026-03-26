// LUOGU_RID: 102570643
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

LL a[26];
LL f[26][26];
int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            f[x][j] += a[j];
        }
        a[x]++;
    }
    LL ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, a[i]);
        for (int j = 0; j < 26; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
