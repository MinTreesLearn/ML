#include <bits/stdc++.h>
#define int long long int

void solve(){
    int n;
    std::cin >> n;
    int a[n], c[32] = {0};
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        int t = a[i], j = 0;
        while(t) {
            if(t & 1) {
                c[j] += 1;
            }
            j += 1;
            t >>= 1;
        }
    }
    std::vector <int> ans, vis(n);
    for(int i = 30; i >= 0; i--) {
        if(c[i] == 1) {
            for(int j = 0; j < n; j++) {
                if(vis[j]) {
                    continue;
                }
                if((a[j] >> i) & 1) {
                    ans.push_back(a[j]);
                    vis[j] = 1;
                    break;
                }
            }
        }
    }
    for(auto &i : ans) {
        std::cout << i << " ";
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            std::cout << a[i] << " ";
        }
    }
    std::cout << "\n";
}
     
signed main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int t = 1;
    //std::cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}