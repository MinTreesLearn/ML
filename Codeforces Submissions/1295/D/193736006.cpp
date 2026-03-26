#include<iostream>
using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define sst string
#define pb push_back
#define maxco 100000+5
#define lld long double
#define cha ios_base::sync_with_stdio(false);
#define ffl cout.flush();
#define phi acos(-1)
#define mod 1000000007
ll mem[1000069];
ll fak (ll h){
    if(h<=1){
    return 1;
    }
    else if(mem[h]!=0){
    return mem[h];
    }
    else{
    return mem[h]=h%mod*fak(h-1)%mod;
    }
}
ll powmod(ll x,ll y){
    if(y==0){
        return 1;
    }
    else{
        ll tmp=powmod(x,y/2);
        tmp=(tmp*tmp)%mod;
        if(y%2==1){
            return (tmp*x)%mod;
        }
        else{
            return tmp;
        }
    }
}
ll com(ll n,ll m){
    if(n < 0 || m < 0 || n < m) return 0;
    ll ans=fak(n)%mod;
    ll ans2=fak(m)%mod;
    ll ans3=(fak(n-m))%mod;
    ans2=powmod(ans2,mod-2);
    ans3=powmod(ans3,mod-2);
    ans2*=ans3%mod;
    ans*=ans2%mod;
    ans%=mod;
    return ans;
}
int main(){
    cha
    ll tc;
    cin>>tc;
    while(tc--){
        ll a,b;
        cin>>a>>b;
        ll val=b/gcd(a,b);
        ll nih=val;
        for(ll i=2;i*i<=val;i++){
            if(val%i==0){
//                cout<<i<<" "<<val<<endl;
                nih*=(i-1);
                nih/=i;
                while(val%i==0)val/=i;
            }
        }
        if(val>1 && val<b/gcd(a,b)){
            nih*=(val-1);
            nih/=val;
        }
        if(nih==val)cout<<nih-1<<endl;
        else cout<<nih<<endl;
    }
}
