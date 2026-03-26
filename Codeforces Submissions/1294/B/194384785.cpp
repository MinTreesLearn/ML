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
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
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
        vector<pair<ll,ll>>v(n);
        pair<ll,ll>pos={0,0};
        for(int i=0;i<n;i++){
            cin>>v[i].first>>v[i].second;
        }
        sort(v.begin(),v.end(),cmp);
        bool f=1;
        string pth;
        for(int i=0;i<n;i++){
            if(pos.first>v[i].first||pos.second>v[i].second){
                f=0;
                break;
            }
            for(int j=0;j<v[i].first-pos.first;j++){
                pth.push_back('R');
            }
            for(int j=0;j<v[i].second-pos.second;j++){
                pth.push_back('U');
            }
            pos=v[i];
        }
        if(f)cout<<"YES\n"<<pth<<endl;
        else cout<<"NO\n";
    }
}