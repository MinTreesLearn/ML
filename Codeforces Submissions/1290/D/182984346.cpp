#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 42, INF = 1e18 + 42;

bool eq[N];
int n, k, nb = 0;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    if(k == 1)
        k = 2;
    for(int i = 1; i < 2*n/k; i++) {
        for(int r = 0; r < i && r + i < 2*n/k; r++) {
            for(int j = r; j < 2*n/k; j += i) {
                int deb = j*(k/2);
                for(int id = 0; id < k/2; id++) {
                    cout << "? " << deb + id + 1 << '\n';
                    cout.flush();
                    char ans; cin >> ans;
                    if(ans == 'Y')
                        eq[deb + id] = true;
                }
            }
            cout << "R\n";
            cout.flush();
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(!eq[i])
            ans++;
    cout << "! " << ans;
}