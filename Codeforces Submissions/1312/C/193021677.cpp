#include<bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define fix(n,f) std::fixed<<std::setprecision(f)<<n
#define ll long long 
#define all(v) v.begin(),v.end()
#define nl "\n"
#define M 1000000007 
#define sum(a,b) ((a%M)+(b%M))%M
#define pro(a,b) ((a%M)*(b%M))%M
#define diff(a,b) ((a%M)-(b%M)+M)%M

/*============================                  ░██████╗░██████╗░              ========================*/
/*============================                 ██╔════╝░██╔══██╗               =======================*/
/*============================                 ██║░░██╗░██║░░██║               =======================*/
/*============================                 ██║░░╚██╗██║░░██║               =======================*/
/*============================                 ╚██████╔╝██████╔╝               =======================*/
/*============================                 ░╚═════╝░╚═════╝░               =======================*/

/*                                  Before Solving the Problem:
1. Dry run testcases , with pen -paper
2. Don't forget the simplest tests
3. Stay calm & keep code on
*/
 
/*=========================================  I BOW TO LORD SHIVA  =============================================*/
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    for(auto &p:v){
        cin>>p;
    }
    map<ll,ll> m;
    for(auto &p:v){
        ll z=p;
        ll ct=0;
        while(z!=0){
            if(m.count(ct)){
                m[ct]+=(z%k);
            }
            else{
                m[ct]=(z%k);
            }
            z/=k;
            ct++;
        }
    }
    for(auto &p:m){
        if(p.second>1){
            cout<<"NO"<<nl;
            return;
        }
    }
    cout<<"YES"<<nl;
}

int main(){
    fastio();
   // freopen("input.txt", "r" ,stdin);
   // freopen("output.txt", "w" ,stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();    
    }
}