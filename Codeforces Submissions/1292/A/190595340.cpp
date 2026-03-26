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


void solve(){

    ll n,q;
    cin>>n>>q;

    ll a[2][n];

    memset(a,0,sizeof(a));

    ll block=0;
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        ll temp = x;
        temp--;
        
        if(temp<0)
            temp+=2;
        //cout<<temp<<endl;
        for(int i=-1;i<=1;i++){
            if(a[x][y]){

                if(y+i>=0 && y+i<n){
                    if(a[temp][y+i])block--;
                }
            }
            else{
                if(y+i>=0 && y+i<n){
                    if(a[temp][y+i])block++;
                }
            }
        }
        a[x][y]--;
        a[x][y]%=2;
        
        

        //cout<<block<<endl;
        if(block)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }

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