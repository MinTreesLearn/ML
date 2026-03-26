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
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        //freopen("out.out", "w", stdout);
    #endif
    BATSY
    int t;
    cin>>t;
    while(t--){
        vector<ll>v(3);ll n;
        for(int i=0;i<3;i++)cin>>v[i];
        sort(v.begin(),v.end());
        cin>>n;
        bool f=1;
        for(int i=0;i<3;i++){
            ll dif=v[2]-v[i];
            if(n>=dif){
                v[i]+=dif;
                n-=dif;
            }
            else f=0;
        }
        if(!f)cout<<"NO\n";
        else if(n%3)cout<<"NO\n";
        else cout<<"YES\n";
    }        
}