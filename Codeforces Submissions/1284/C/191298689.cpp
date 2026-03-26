#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define int             long long
#define all(a)          a.begin(),a.end()
#define endl            "\n"
#define fill(a,b) memset(a, b, sizeof(a))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
int MOD;
int power(int a, int b, int p){
    if(a==0)
    return 0;
    int res=1;
    a%=p;
    while(b>0)
    {
        if(b&1)
        res=(1ll*res*a)%p;
        b>>=1;
        a=(1ll*a*a)%p;
    }
    return res;
}
int modInverse(int n,int p)
{
	return power(n, p - 2, p);
} 
vector<int>fac;
int choose(int a,int b) { //get nCr
        if(a<b) {
            return 0;
        }
        return ((fac[a]*modInverse(fac[b],MOD))%MOD*modInverse(fac[a-b],MOD))%MOD;
    }            
signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
while(t--){
    fac.clear();
    int i,j,x=0,y=0,p=0,n,q=-1,u=0,v=0,k,c=0,m,z;
    cin>>n>>m;
    MOD=m;
    fac.push_back(1);
    p=1;
    for(i=1;i<=n;i++){
        p=(p*i)%m;
        fac.push_back(p);
    }
    //r-l=1=i...i+1...n-(i+1)...n-i
    int ansx=0;
    for(i=0;i<=n-1;i++){
        x=fac[i+1];
        y=fac[n-(i+1)];
        z=n-i;
        int ans=1;
        ans=((x*y)%m)%m;
        ans=(ans*z)%m;
        q=z;
        ans=(ans*q)%m;
        ansx+=ans;
        ansx%=m;
    }
    cout<<ansx<<endl;


    }
}