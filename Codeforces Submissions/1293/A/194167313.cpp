#include <bits/stdc++.h>
#define ll long long
#define lpi(x,n) for(int i=x;i<n;++i)
#define lpj(x,n) for(int j=x;j<n;++j)
#define S second
#define F first
#define all(x) x.begin(),x.end()
#define sorterase(v) {sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());}
#define pb push_back
#define pf push_front
#define R return
#define endl '\n'

using namespace std;

/*
        **          **         22222222
       ****         **         22222222
      **  **        **              222
     **    **       **  **          222
    **      **      ** **      22222222
   ************     ****       22
  **************    ****       22
 **            **   ** **      22222222
**              **  **  **     22222222

*/

//------------------------------------------------
void sieveprime(int n,bool prime[]){
    memset(prime,true,n);
    for (int p=2;p*p<=n;p++) {
        if(prime[p]==true) {
            for(int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
}
//------------------------------------------------
ll gcd(ll a,ll b){
    if(b==0) R a;
    R gcd(b,a%b);
}
//------------------------------------------------
ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    R a*b/g;
}
//------------------------------------------------
ll Pow(ll x,ll y){
    if(y==1) R x;
    if(y==0) R 1;
    ll ret=pow(x,y/2);
    ret*=ret;
    if(y%2) ret*=x;
    R ret;
}
//------------------------------------------------
bool isPrime(ll x){
    if (x<=1)
        R false;
    for(ll i=2;i<=sqrt(x);i++)
        if (x%i==0)
            R false;
    R true;
}
//------------------------------------------------
ll sqrt(ll x){
    ll l=1,r=1e9+9,res=1;
    while(l<=r){
        ll m=(l+r)>>1;
        if(m*m>x) r=m-1;
        else { l=m+1; res=m; }
    }
    R res;
}
//------------------------------------------------
ll mod(ll m,ll n){
    ll x=(m%n+n)%n;
    R x;
}
//------------------------------------------------
ll fact(ll n){
    if(n==0) R 1;
    ll res=1;
    for(int i=2;i<=n;i++) res=res*i;
    R res;
}
//------------------------------------------------
ll ncr(ll n,ll r){
    ll x=fact(n)/(fact(r)*fact(n-r));
    R x;
}

void AK2000YY(){
    ll n,s,k,ans=1e9,j=0;
    bool can=0;
    cin>>n>>s>>k;
    vector <ll> v(k);
    lpi(0,k){ cin>>v[i]; if(v[i]==s) can=1; }
    sort(all(v));
    if(!can){ cout<<0<<endl; R; }
    lpi(0,k) if(v[i]==s){ j=i; break; }
    for(int i=j-1;i>=0;--i){
        if(v[i+1]-v[i]>1) ans=min(ans,s-v[i+1]+1);
    }
    for(int i=j+1;i<v.size();++i){
        if(v[i]-v[i-1]>1) ans=min(ans,v[i-1]+1-s);
    }
    if(n>v[k-1]) ans=min(ans,v[k-1]+1-s);
    if(1<v[0]) ans=min(ans,s-v[0]+1);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--) AK2000YY();
}
//										POWERED BY ABDUL KARIM KOURINI
