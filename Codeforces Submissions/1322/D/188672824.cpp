//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,fma,sse4.2")
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef long long ll;
typedef long double ld;
typedef pair<int, pair<int, int>> ft;

const ld PI = acos(-1);
const int maxn = 2e3+20;
const ll inf = 1e18;
const int mod = 998244353;

int n, m;

ll dp[maxn][maxn], dp2[maxn*2][maxn], dp3[maxn];

ll C[2*maxn], cost[maxn], A[maxn];

ll eval(int mask, int pos){
    ll re = 0;
    for(int i = 0; i < 11; i++){
        if(mask&(1<<i))re+=C[pos+i];
    }
    return re;
}

signed main(){
    ll ans = 0;
    cin >> n >> m;
    //assert(n <= 200 && m <= 200);
    for(int i = 1; i <= n; i++)cin >> A[i];
    for(int i = 1; i <= n; i++)cin >> cost[i];
    for(int i = 1; i <= n+m; i++){
        for(int k = 1; k <= n; k++){
            dp2[i][k] = -inf;
        }
        cin >> C[i];
    }
    for(int i = n; i > 0; i--){
        for(int k = 1; k <= n; k++)dp[i][k] = -inf;
        dp[i][1] = C[A[i]] - cost[i];
        for(int j = i+1; j <= n; j++){
            if(A[i] - A[j] >= 11)dp[i][1] = max(dp[i][1], dp3[j] + C[A[i]] - cost[i]); 
        }
        for(int j = A[i]; j > max(0LL, A[i]-11); j--){
            for(int k = 1; k <= n; k++){
                int nmask = k>>(A[i] - j);
                dp[i][nmask+1] = max(dp[i][nmask+1], dp2[j][k] + eval(nmask^(nmask+1), A[i]) - cost[i]);
            }
        }
        dp3[i] = -inf;
        for(int k = 1; k <= n; k++){
            dp2[A[i]][k] = max(dp2[A[i]][k], dp[i][k]);
            dp3[i] = max(dp3[i], dp[i][k]);
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
}
 