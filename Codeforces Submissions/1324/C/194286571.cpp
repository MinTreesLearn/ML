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

void testCase(int cs) {
    string s; cin >> s;
    s.push_back('R');
    int ans = 0, lst = 0;
    for (int i = 0; i < sz(s); ++i) {
        if(s[i] == 'R')
        {
            ans = max( (i+1) - lst, ans);
            lst = i + 1;
        }
    }
    cout << ans << endl;
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