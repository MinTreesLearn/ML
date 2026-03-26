#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9 + 7


void solve(){
    string s;
    cin >> s;
    
    vector<ll> cnt(26);
    vector<vector<ll>> dp(26ll, vector<ll>(26));
    for(int i=0; i<s.size(); ++i){
        int x = s[i] - 'a';
        for(int j=0; j<26; ++j){
            dp[j][x] += cnt[j];
        }
        cnt[x]++;
    }

    ll res = 0;
    for(int i=0; i<26; ++i){
        res = max(res, cnt[i]);
    }

    for(int i=0; i<26; ++i){
        for(int j=0; j<26; ++j){
            res = max(res, dp[i][j]);
        }
    }

    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
