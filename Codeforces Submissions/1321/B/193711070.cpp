#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ECPC ios_base::sync_with_stdio(false); cin.tie(NULL);
ll mod=1e9+7;
ll FastPower(ll base,ll power) {
    if (power == 0)
        return 1;
    ll ans = FastPower(base, power / 2);
    ans *= ans;
    if (power % 2)
        ans *= base;
    return ans;

}

bool isPrime(ll v){
    if(v<=1) return false;
    if(v==2) return true;
    if(v%2==0) return false;
    for(int i=3;i*i<=v;i+=2){
        if(v%i==0) return false;
    }
    return true;
}

ll LCM(ll a,ll b){
    return (a/ gcd(a,b))*b;
}

ll getGcd(ll a,ll b){
    if(b==0)
        return a;
    return getGcd(b,a%b);
}

bool isPowerOftwo(ll x){
    return !((x-1)&x);
}

bool sorting(int l,int r){
    return l%2<r%2;
}

bool output(vector<int>arry,int n,int v){
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(arry[i]>arry[i+1]) ans++;
    }
    return ans==v;
}

ll SumofDigites(ll value){
    ll sum=0;
    while(value>0){
        sum+=(value % 10);
        value/=10;
    }
    return sum;
}

void  Solution(){
    ll n,x;
    cin>>n;
    vector<pair<ll,ll>>myarry;
    map<ll,ll>myMap;
    for(ll i=1;i<=n;i++){
        cin>>x;
        myMap[x-i]=myMap[x-i]+x;
    }
    ll ans=0;
    for(auto it:myMap)
        ans=max(ans,it.second);
    cout<<ans<<"\n";




}
int main(){
    ECPC
    int testcase=1;
   //cin>>testcase;
    while(testcase--){
        Solution();
    }
}