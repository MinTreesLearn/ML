#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pb push_back
#define mp make_pair

constexpr int N = (int)1e5 + 111;
constexpr int INF = (int)1e9 + 11;
constexpr int md = (int)1e9+7;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,popcnt")

void solve(){
    string s1,s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    short cnt[256];
    memset(cnt,0,sizeof cnt);
    for(int i = 0; i < s1.size(); i++) cnt[s1[i]]++;
    for(int i = 0; i < s2.size(); i++) cnt[s2[i]]--;
    for(auto& y : cnt){
        if(y < 0){
            cout << "NO\n";
            return;
        }
    }

    bool dp[m+1][m+1];
    int pos = 0;
    int C = 0;
    int ptr = 0;
    for(int j = 0; j < s2.size(); j++){
        while(ptr < s1.size() && s1[ptr] != s2[j])
            ptr++;
        if(ptr == s1.size())
            break;
//        cerr << "ptr: " << ptr << "\n";
        C = j+1;
        ptr++;
    }

//    cerr << "C: " << C << "\n";

    #pragma GCC ivdep
    for(int s = max(0,C/2-1); s <= C; s++){
        memset(dp,0,sizeof dp);
        dp[0][0] = true;
        bool can = false;
        for(int i = 0; i < n; i++){
            for(int j = min(i,s); j >= 0; j--){
                for(int t = min(i,m-s); t >= 0; t--){
                    if(j + 1 <= s && s2[j] == s1[i])
                        dp[j+1][t] |= dp[j][t];
                    if(t + 1 <= m - s && s2[t+s] == s1[i])
                        dp[j][t+1] |= dp[j][t];
                }
            }
//            for(int j = 0; j <= min(i+1,s); j++){
//                for(int t = 0; t <= min(i+1,m - s); t++){
//                    dp[0][j][t] = dp[1][j][t];
////                    dp[1][j][t] = 0;
//                }
//            }
        }
        for(int j = 0; j <= m-s; j++)
            can |= dp[s][j];
        if(dp[s][m-s]){
//            cerr << "s: " << s << "\n";
            cout << "YES\n";
            return;
        }
//        if(!can)
//            break;
    }
    cout << "NO\n";

    return;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int tests = 1;
	cin >> tests;
	for(int test = 1; test <= tests; test++){
		solve();
	}
	return 0;
}
