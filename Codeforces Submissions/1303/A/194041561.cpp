/* In The Name Of God */
#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define sortt(v) sort(v.begin(), v.end())

typedef long long ll;
const ll maxx = 1e10 + 10;

void solve()
{
    string s; cin >> s;
    vector <int> v;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '1') v.pb(i);
    }
    if (v.size() == 0) {cout << "0\n"; return;}
    int ans = 0;
    for (int i=0; i<v.size() - 1; i++){
        ans += v[i+1] - v[i] - 1;
    }
    cout << ans << '\n';
}
int main()
{
    int t; cin >> t;
    while (t--) solve();
}
 /*
    Life can only be understood backwards;
        but it must be lived forwards;
*/