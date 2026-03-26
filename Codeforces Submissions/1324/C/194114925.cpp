#include<bits/stdc++.h>
using namespace std;


#define     ll             long long
#define     fr(m)          for(int i=0; i<m; i++)
#define     frr(n)         for(int i=n; i>=0; i--)
#define     yes            cout<<"YES"<<"\n"
#define     no             cout<<"NO"<<"\n"
#define     vr             vector<ll>
#define     all(x)         x.begin(),x.end()
#define     pb             push_back
#define     maxof(x)       *max_element(x.begin(),x.end());
#define     minof(x)       *min_element(x.begin(),x.end());
#define     srt(x)         sort(x.begin(), x.end())
#define     dsrt(x)        sort(x.begin(), x.end(),greater<ll>())
#define     _a-z_          "abcdefghijklmnopqrstuvwxyz"
#define     SuperFast      ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     sp             " "
#define     ln             "\n"
#define     fi             first
#define     se             second

using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mxn=1e5+9;
const int N=1e5+5;
const int mod=1e9+7;
//Check Prime or not???!!!
bool prime(int n){
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2){
       if(n%i==0) return false;
    }
	return true;
}

//Greatest Common Divisor--> GCD
ll gcd (int p, int q) { if (q == 0) return p; return gcd(q, p % q); }
//Least Common Multiple--> LCM
ll lcm(int p, int q){ return (p / gcd(p, q))*q; }


void testCase(){
    string s;cin>>s;
    int l=0, mx=0;
    fr(s.size()){
        if(s[i]=='L'){
            l++;
            mx=max(mx,l);
        }
        else l=0;

    }
    cout<<mx+1<<ln;
}
int main(){
SuperFast;
    //int t=1;
    int t;cin>>t;
    while(t--){
        testCase();
    }
}


