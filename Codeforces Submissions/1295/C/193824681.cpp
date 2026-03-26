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
    string s,t;
    cin >> s >> t;
    vector<vector<int>>freq(26);
    for (int i = 0; i < sz(s); ++i) {
        freq[s[i] - 'a'].push_back(i + 1);
    }
    int ans = 0, lst = 0;
    for (int i = 0; i < sz(t); ++i) {
        int c = t[i] - 'a';
        if(freq[c].empty())
        {
            cout << -1 << endl;
            return;
        }
        auto it = upper_bound(all(freq[c]), lst);
        if(it != freq[c].end())
        {
            lst = *it;
        }
        else
        {
            lst = freq[c][0];
            ans++;
        }
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