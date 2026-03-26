#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
constexpr int N = int(4e2) + 5;
constexpr int inf = 0x7f7f7f7f;
constexpr int MOD = int(1e9) + 7;

short dp[N][N][N];
string s, t;

short check(short x, short y, short z){
    if(x == s.size()){
        return z == t.size() ? y : -500;
    }
    auto& r = dp[x][y][z];
    if(r != -1) return r;

    r = check(x + 1, y, z);
    if(y < t.size() && s[x] == t[y]) r = max(r, check(x + 1, y + 1, z));
    if(z < t.size() && s[x] == t[z]) r = max(r, check(x + 1, y, z + 1));
    return r;
}
void solve(){
    cin >> s >> t;

    for(int i = 0; i <= s.size(); i++){
        for(int j = 0; j <= t.size(); j++){
            for(int k = 0; k <= t.size(); k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(short i = 0; i < t.size(); i++){
        if(check(0, 0, i + 1) > i){
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
		  	  			  	  		 						  		  	