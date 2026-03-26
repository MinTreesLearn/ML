#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a,m;
        cin>>a>>m;
        ll GCD = __gcd(a,m);
        a = a/GCD;
        m = m/GCD;
        ll ans = m,m1 = m;
        for(ll j = 2;j*j<=m1;j++){
            if(m%j==0){
                ans = ans/j;
                ans = ans*(j-1);
                while(m%j==0){
                    m = m/j;
                }
            }
        }
        if(m > 1){
            ans = ans/m;
            ans = ans*(m-1);
        }
        cout<<ans<<endl;

    }
}







