#include <bits/stdc++.h>

#define Source ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define int long long
#define ld long double
#define Endl '\n'
//#define t int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(a) (int)(a).size()
using namespace std;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int nxt[N][26];

void testCase(int cs) {
    string s,t;
    cin >> s >> t;
    for(int i = 0; i < s.size() + 5; ++i)
        for(int j = 0; j < 26; ++j)
            nxt[i][j] = 1e18;

    for(int i = sz(s) - 1; i >= 0; --i){
        for(int j = 0; j < 26; ++j)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }
    int ans = 0, nxtIdx = 0;
    for (int i = 0; i < sz(t); ++i) {
        int c = t[i] - 'a';
        if(nxtIdx == sz(s)) {
            nxtIdx = 0;
            ans++;
        }
        if(nxt[nxtIdx][c] == 1e18)
        {
            nxtIdx = 0;
            ans++;
        }
        if(nxt[nxtIdx][c] == 1e18 && !nxtIdx)
        {
            cout << -1 << endl;
            return;
        }
        nxtIdx = nxt[nxtIdx][c] + 1;
    }
    cout << ans + 1 << endl;
}

signed main() {
    // files();
    Source
    ll t = 1;
    int cs = 0;
    cin >> t;
    while (t--) {
        testCase(++cs);
    }
    return 0;
}