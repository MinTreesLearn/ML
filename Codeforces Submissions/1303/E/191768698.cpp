#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
constexpr int N = int(4e2) + 5;
constexpr int inf = 0x7f7f7f7f;
constexpr int MOD = int(1e9) + 7;

short dp[N][N][N];
string s, t;

void solve(){
    cin >> s >> t;

    for(short i = 0; i <= s.size(); i++){
        for(short j = 0; j <= t.size(); j++){
            for(short k = 0; k < t.size(); k++){
                dp[i][j][k] = 0;
            }
            dp[s.size()][j][t.size()] = j;
        }
    }
    for(short i = s.size() - 1; ~i; i--){
        for(short j = t.size(); ~j; j--){
            for(short k = t.size(); ~k; k--){
                auto& r = dp[i][j][k] = dp[i + 1][j][k];
                if(s[i] == t[j]) r = max(r, dp[i + 1][j + 1][k]);
                if(s[i] == t[k]) r = max(r, dp[i + 1][j][k + 1]);
            }
        }
    }
    for(int i = 0; i < t.size(); i++){
        if(dp[0][0][i + 1] > i){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}