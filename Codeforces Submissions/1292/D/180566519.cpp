#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>

using namespace std;
typedef long long ll;
ll cnt[5010] = {},pr[5010][5010],p[5010],mx = 5000;
bool f[5010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n; cin >> n;
    for(i=0;i<n;i++){
        int k; cin >> k; cnt[k]++; f[k] = true;
    }
    for(i=2;i<=mx;i++){
        if(p[i]) continue;
        for(j=i;j<=mx;j+=i) p[j] = i;
    }
    for(i=2;i<=mx;i++){
        for(j=1;j<=mx;j++) pr[i][j] = pr[i - 1][j];
        int x = i;
        while(x>1){
            pr[i][p[x]]++; x /= p[x];
        }
    }
    ll ans = 0;
    for(i=1;i<=mx;i++){
        ll sum = 0;
        for(j=1;j<=mx;j++) sum += pr[i][j];
        ans += sum*cnt[i]; 
    }
    for(j=mx;j>=1;){
        int num = 0;
        for(i=1;i<=mx;i++){
            if(!f[i]) continue;
            if(pr[i][j]) num += cnt[i];
        }
        if(2*num<=n){
            for(i=1;i<=mx;i++){
                if(pr[i][j]) f[i] = false;
            }
            j--;
        }else{
            ans += (n - 2*num);
            for(i=1;i<=mx;i++){
                if(pr[i][j]==0) f[i] = false;
                else pr[i][j]--;
            }
        }
    }
    cout << ans << endl;
}