#include<iostream>
#include<cstring>
using namespace std;
using LL = long long;
const int maxn = 3e5 + 5;
int n, a, b, c;
int f[1005][3];
int sg[maxn], val[maxn];

int dp(int x, int y){
    if (~f[x][y]) return f[x][y];
    int s[4] = {0};
    s[dp(max(0, x - a), 0)] = 1;
    if (y != 1) s[dp(max(0, x - b), 1)] = 1;
    if (y != 2) s[dp(max(0, x - c), 2)] = 1;
    int ans = 0;
    while(s[ans]) ans++;
    return f[x][y] = ans;
}

int solve(){
    memset(f, -1, sizeof f);
    f[0][0] = f[0][1] = f[0][2] = 0;
    for(int len = 1; ; len++){
        bool success = 1;
        for(int i = 1000; i >= 500; i--){
            for(int j = 0; j < 3; j++)
                if (dp(i, j) != dp(i - len, j)){
                    success = 0;
                    break;
                }
            if (!success) break;
        }
        if (success) return len;
    }
    return -1;
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> a >> b >> c;
        int len = solve();
        int ans = 0;
        for(int i = 1; i <= n; i++){
            LL x;
            cin >> x;
            if (x > 1000) x = 500 / len * len + x % len;
            val[i] = x; 
            ans ^= (sg[i] = dp(x, 0));
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int t = dp(max(0, val[i] - a), 0);
            if ((t ^ ans ^ sg[i]) == 0) cnt++;
            t = dp(max(0, val[i] - b), 1);
            if ((t ^ ans ^ sg[i]) == 0) cnt++;
            t = dp(max(0, val[i] - c), 2);
            if ((t ^ ans ^ sg[i]) == 0) cnt++;
        }
        cout << cnt << '\n';
    }
}