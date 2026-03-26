#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N = 2e5 + 10;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<int> r(N, -1), c(N, -1);
    for(int i = 0; i < n; i++ ){
        for(int j = 0; j < m; j++ ){
            cin >> a[i][j];
            a[i][j]--;
            r[i * m + j] = i;
            c[i * m + j] = j;
        }
    }

    ll ans = 0;
    for(int i = 0; i < m; i++ ){
        vector<int> cnt(n);
        for(int j = 0; j < n; j++ ){
            if(c[a[j][i]] == i){
                cnt[(j - r[a[j][i]] + n) % n]++;
            }
        }
        int res = n;
        for(int j = 0; j < n; j++ ){
            res = min(res, j + (n - cnt[j]));
        }
        ans += res;
    }
    cout << ans << "\n";
    return 0;
}