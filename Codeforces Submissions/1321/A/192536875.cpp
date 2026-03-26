//This is coded by VIDYARTH GS
//#include <bits/stdc++.h>
#include <iostream> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "<<x<<"\n";
#else
#define debug(x)
#endif

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> mii;
typedef map<int,v32> miv;
ll MOD = 998244353;
double eps = 1e-12;
#define rep(i,e) for(ll i = 0; i < e; i++)
#define repFR(i,s,e) for(ll i = s; i < e; i++)
#define repR(i,s) for(ll i = s; i >= 0; i--)
#define repRR(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    v32 arr1(n),arr2(n);
    rep(i,n){
        cin>>arr1[i];
    }
    rep(i,n){
        cin>>arr2[i];
    }
    int cnt1 = 0;
    int cnt2 = 0;
    rep(i,n){
        if(arr1[i] == 1 && arr2[i] == 0){
            cnt1++;
        }  
        if(arr1[i] == 0 && arr2[i] == 1){
            cnt2++;
        }
    }
    if(cnt1 == 0){
        cout<<-1<<"\n";
        return;
    }
    int ans = ceil((cnt2+1)/(float)cnt1);
    cout<<ans;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    fast_cin();
    solve();
    return 0;
}