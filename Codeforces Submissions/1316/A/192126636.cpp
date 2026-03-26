#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<int> BigInt;
#define ACPC ios_base::sync_with_stdio(false); cin.tie(NULL);
ll mod=1e9+7;

bool PowerOfTwo(ll x){
    return !(x&(x-1));
}

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
    return l%2>r%2;
}


void  Solution(){

    ll n,m;
    cin>>n>>m;
    ll s=0;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        s=s+x;
    }
    cout<<min(s,m)<<"\n";


}

int main(){
    ACPC
    int testcase=1;
    cin>>testcase;
    while(testcase--){
        Solution();
    }
}