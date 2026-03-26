#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<ll>a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        pre[i] += pre[i - 1] + a[i];
    }
    ll j = 0, x = -1, mx = INT_MIN;
    bool ok = false, okk = false;
    for (int i = 1; i <= n - 1; i++){
        if (pre[i] < pre[i + 1] && pre[i] <= 0){
                ok = true;
                j = i;
        }
        if (pre[i] > pre[i + 1] && pre[i + 1] <= 0){
            ok = true;
            j = i + 1;
        }
        else if ((pre[i] < pre[i + 1])||(pre[i] > pre[i + 1] && pre[i + 1] > 0)){
            if (ok) x = i + 1;
            else x = i;
        }
        if (x != -1){
            okk = true;
            mx = max(mx, pre[x] - pre[j]);
            x = -1;
        }
    }
    if (!okk)mx = pre[1];
    if (pre[n] > mx)cout << "YES" << el;
    else cout << "NO" << el;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
