#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ios_base::sync_with_stdio(false);   cout.tie(nullptr);  cin.tie(nullptr);
    int T=1; cin>>T;
    while(T--) {
        int n,lc=1,x,gd;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            lc=lcm(lc,x);
           if(i) gd=__gcd(gd,x);
           else gd=x;
        }
       if((lc-gd)%2==0)cout<<"YES\n";
       else cout<<"NO\n";


    }
    return 0;
}