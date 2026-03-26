/* ______ Defines _____ */
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#include <bits/stdc++.h>
#define Num_of_Digits(n) ((int)log10(n)+1)
using namespace std;
#define Lion_Heart ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
double pi=3.141592653590;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef long double ld;
#define yes cout<<"YES\n";return;
#define no cout<<"NO\n";return;
#define F first
#define S second
#define el '\n'
#define INF 1e18
#define PI 3.1415926535
#define L00 0x3f3f3f3f3f3f3f3f
#define I00 0x3f3f3f3f
#define NL00 -0x3f3f3f3f3f3f3f3f
#define popcount __builtin_popcount
ll MOD = 1e18+5;
int TEST_CASE = 1;
void file(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int
di[] = {1, 0, -1, 0,  1, -1, -1, 1},
dj[] = {0, 1, 0, -1, 1,  1, -1, -1},
dx[] = {0, 1, 0 , -1},
dy[] = {1, 0, -1,  0};
//right, down, left, up
int const N = 1e5 + 5, M = 2*N + 9 ,SQRT=1e6+10 ,mod = 1e9 + 7, oo = 1e9 + 10;
//------------start solve-------------------
void solve() {
    int n, m; cin>>n>>m;
    map<string, int> mp;
    string s, res = "";
    for (int i = 0; i < n; ++i) {
        cin>>s;
        //check if there plaindrome
        string rev = s;
        reverse(rev.begin(), rev.end());
        if(mp.find(rev) != mp.end()) {
            res += s;
            mp.erase(rev);
        }else mp[s]++;
    }
    string mid = "";
    for(auto mm:mp) {
        string tmp = mm.F;
        string rev = tmp;
        std::reverse(rev.begin(), rev.end());
        if(tmp == rev) mid = tmp;
    }
    cout<<res.size() * 2 + mid.size()<<el;
    cout<<res<<mid;
    reverse(res.begin(), res.end());
    cout<<res;
}
int main() {
    file();
    Lion_Heart
    /** ______ IF YOU HAVE ANY BUG IN YOUR CODE,JUST ERASE IT _____ goooddd **/
    cout<<fixed<<setprecision(10);
    int tt=1;
//    cin>>tt;
    for (int i = 0; i < tt; ++i) {
        solve();
//      TEST_CASE++;
    }
    return 0;
}
