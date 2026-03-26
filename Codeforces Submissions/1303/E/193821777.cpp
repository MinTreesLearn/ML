#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) static_cast<int>((x).size())
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;


void solve(){

        string s, t;
        cin >> s >> t;

        array<int, 26> def;
        for (int i = 0; i < 26; ++i) def[i] = (int)s.size() + 1;
        vector<array<int, 26>> next((int)s.size() + 1, def);

        for (int i = (int)s.size() - 1; i >= 0; --i){
                for (int j = 0; j < 26; ++j){
                        next[i][j] = next[i + 1][j];
                }
                int chr = s[i] - 'a';
                next[i][chr] = i + 1;
        }

        auto solve = [&] (string &a, string &b) -> bool{
                int n = a.size(), m = b.size();
                int dp[n + 1][m + 1];
                for (int i = 0; i <= n; ++i) 
                        for (int j = 0; j <= m; ++j) 
                                dp[i][j] = (int)s.size() + 1;
                
                dp[0][0] = 0;
                for (int i = 0; i <= n; ++i){
                        for (int j = 0; j <= m; ++j){
                                if (dp[i][j] == (int)s.size() + 1) continue;
                                if (i + 1 <= n) {
                                        int chr = a[i] - 'a';
                                        dp[i + 1][j] = min (dp[i + 1][j], next[dp[i][j]][chr]);
                                }
                                if (j + 1 <= m){
                                        int chr = b[j]  - 'a';
                                        dp[i][j + 1] = min (dp[i][j + 1], next[dp[i][j]][chr]);
                                }
                        }
                }

                return (dp[n][m] <= (int)s.size());

        };

        for (int i = 0; i < t.size(); ++i){
                string a = t.substr (0, i);
                string b = t.substr(i, (int)t.size() - i);
                if (solve (a, b)){
                        cout << "YES \n";
                        return;
                }
        }

        cout << "NO \n";

}


signed main(){
 
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0); 
        int t ;
        cin >> t;
        while(t--){
                solve();
        }
}