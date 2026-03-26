#include<iostream>
#include<cstdio>
#include<bitset>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<unordered_set>
#include <cstring>
#include <iomanip>
//#include <bits/stdc++.h>
#define BATSY ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define endl '\n'
#define DEC(n) cout<<fixed;cout<<setprecision(n);
#define LENGTH(n) (floor(log10(max(abs(n),1LL)))+1)
#define log_n(number,n) log2(number)/log2(n)
#define OO (ll)1e18
#define F first
#define S second
using namespace std;
//_____________________                              _____________________
//`-._                 \           |\__/|           /                 _.-'
//    \                 \          |    |          /                 /
//     \                 `-_______/      \_______-'                 /
//      |       '||''|.       |   |''||''| .|'''.|  '||' '| '      |
//      |        ||   ||     |||     ||    ||..  '    || |         |
//      |        ||'''|.    |  ||    ||     ''|||.     ||          |
//      /        ||    ||  .''''|.   ||   .     '||    ||          \
//     /________.||...|'  .|.  .||. .||.  |'....|'    .||.__________\
//                   `----._                    _.----'
//                          `--.            .--'
//                              `-.      .-'
//                                 \    /
//                                  \  /
//                                   \/
bool isPrime(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return n>1;
}
ll get(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return i;
    }
    return 1;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        //freopen("out.out", "w", stdout);
    #endif
    BATSY
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll>st;
        bool f=0;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                ll tm[]={i,n/i};
                for(ll j=0;j<2;j++){
                    st.clear();
                    st.insert(tm[j]);
                    ll tmp=get(tm[1-j]);
                    if(tmp!=1){
                        st.insert(tmp);
                        st.insert(tm[1-j]/tmp);
                    }
                    if(st.size()==3){
                        f=1;
                        break;
                    }
                }
                if(f)break;
            }
        }
        if(f){
            cout<<"YES\n";
            for(auto it:st)cout<<it<<' ';
            cout<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
}