#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, ll> ii;
#define eps 1e-9
#define MOD 1000000007
#define pi 3.141592653589793
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yo cout << "I reached here" << endl;
const int INF = 1e9 + 5;


int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
    for(int len = 1; len <= n; len++){
        for(int i = 0; i < n; i++){
            int j = i + len - 1;
            if(j >= n) continue;
            if(i == j){
                dp[i][j] = A[i];
//                cout << "i = " << i << "  j = " << j <<  "  value = " << dp[i][j] << " " << endl;
                continue;
            }
            int cnt = 0;
            bool possible = false;
            int answer = -1;
            for(int k = i; k < j; k++){
                if(dp[i][k] == dp[k+1][j] && dp[i][k] != -1){
                    possible = true;
                    answer = dp[i][k];
                }
            }
            if(possible) dp[i][j] = answer + 1;
        }
    }
//    for(int len = 1; len <= n; len++){
//        for(int i = 0; i < n; i++){
//            cout << "len = " << len << endl;
//            int j = i + len - 1;
//            if(j >= n) continue;
//            cout << "i = " << i << "  j = " << j <<  "  value = " << dp[i][j] << " " << endl;
//        }
//    }
//    for(int i = 0; i < n; i++){
//        for(int j = i; j < n; j++){
//            cout << "i = " << i << "  j = " << j <<  "  value = " << dp[i][j] << " " << endl;
//        }
//        cout << endl;
//    }
    vector<ll> sp(n + 1, INF);
    sp[0] = 0;
    for(int i = -1; i < n; i++){
        for(int j = i + 1; j < n; j++){
//            cout << "i = " << i << "   j = " << j << endl;
            if(dp[i+1][j] > 0){
//                cout << "----------------i = " << i << "   j = " << j << endl;
                sp[j + 1] = min(sp[j + 1], sp[i + 1] + 1);
            }
        }
    }
//    for(int i = 0; i <= n; i++){
//        cout << sp[i] << " ";
//    }
//    cout << endl;
    cout << sp[n] << endl;
    return 0;
}
