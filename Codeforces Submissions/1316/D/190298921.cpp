#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define debug(x) void(37)
#endif

#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define setprec(n) cout << fixed << showpoint;cout << setprecision(n);
typedef long long ll;
typedef long double ld;
const ld eps = 1e-10;
const ll MOD1 = 1e9+7;//1000000007
const ll MOD2 = 998244353ll;
const ll LINF = (ll)1e18;
const int IINF = (int)1e9;
#define int ll

int v[] = {1, 0, 0, -1};
int h[] = {0, 1, -1, 0};
// {i + v[k], j + h[k]}
char chr[] = {'D', 'R', 'L', 'U'};
char rev[] = {'U', 'L', 'R', 'D'};

void solve(){
    int n;
    cin >> n;

    vector<vector<pair<int,int>>> arr(n+2, vector<pair<int,int>>(n+2, {-2, -2}));
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
        cin >> arr[i][j].first >> arr[i][j].second;

    set<pair<int,int>> xses;
    vector<vector<char>> ans(n+2, vector<char>(n+2, '.'));
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(arr[i][j].first != -1){
        ans[arr[i][j].first][arr[i][j].second] = 'X';
        xses.insert(arr[i][j]);
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(ans[i][j] == 'X' && (arr[i][j].first != i || arr[i][j].second != j)){
        cout << "INVALID" << "\n";
        return;
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(arr[i][j].first == -1){
        for(int k = 0;k < 4;k++){
            int ti = i + v[k];
            int tj = j + h[k];
            if(arr[ti][tj].first == -1){
                ans[i][j] = chr[k];
            }
        }
    }

    queue<pair<int,int>> q;
    for(auto it:xses) q.push(it);

    while(q.size()){
        pair<int,int> cur = q.front();
        q.pop();

        for(int k = 0;k < 4;k++){
            int ti = cur.first + v[k];
            int tj = cur.second + h[k];
            if(ans[ti][tj] == '.' && (arr[ti][tj].first == arr[cur.first][cur.second].first && arr[ti][tj].second == arr[cur.first][cur.second].second)){
                ans[ti][tj] = rev[k];
                q.push({ti, tj});
            }
        }
    }

    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(ans[i][j] == '.'){
        cout << "INVALID" << "\n";
        return;
    }

    cout << "VALID" << "\n";
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << ans[i][j];
        }cout << "\n";
    }
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    mt19937 mt(time(NULL));
    //setprec(10);

    //freopen("sleepy.in", "r", stdin);
    //freopen("in.txt", "w", stdout);

    int t = 1;
    //cin >> t;
    for(int i = 1;i <= t;i++)
        solve();

    return 0;
}