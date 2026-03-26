#include <bits/stdc++.h>


using namespace std;
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
#define repp(n) for(int i=0;i<n;i++)
//typedef __int128 lll;
const ll MOD=998244353;
const ll mod = 1e9+7;
#define ret(a) cout<<a<<"\n"; return
#define rep(i,a,b) for(long long i = a; i < b; i++)


double n;
void solve(){

    cin>>n;


    double ans = 0 ;


    while(n>0){

        ans += (1/n);
        n--;
    }

    cout<<ans<<endl;

    


    
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

   
    // int t;
    // cin>>t;
    // while(t--)
        solve();
   

    return 0;
}