#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//---------------------------------------------------------------------------------
#define ll long long
#define fixed(n) cout << fixed << setprecision(n)
#define sz(x) int(x.size())
#define TC int t; cin >> t;   while(t--)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define dl "\n"
#define Ceil(a, b) ((a / b) + (a % b ? 1 : 0))
#define pi 3.141592
#define OO 2'000'000'000
#define MOD 1'000'000'007
#define EPS 1e-10 
using namespace std;
using namespace __gnu_pbds;
//---------------------------------------------------------------------------------
template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::greater<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = std::less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;
// order_of_key(val)  count elements smaller than val
// *s.find_by_order(idx)  element with index idx

template<typename T = int > istream& operator >> (istream &in , vector < T > &v){
    for(auto &i : v) in >> i ; 
    return in ; 
}

template<typename T = int > ostream& operator << (ostream &out ,vector < T > &v){
    for(auto &i : v) out <<  i  << ' ' ; 
    return out ; 
}

//-----------------------------------------------------------------------------------------
void ZEDAN() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin) ;
          freopen("output.txt", "w", stdout) ;
    #endif
}
//-----------------------------------------(notes)-----------------------------------------
/*
*/
//-----------------------------------------(function)--------------------------------------
//-----------------------------------------(code here)-------------------------------------
void solve(){
    string s ; cin >> s ; 
    s.push_back('R') ; 
    ll ans=-OO , cnt = 0 ; 
    for(auto &i : s){
        cnt++ ; 
        if(i=='R'){
            ans = max(ans,cnt) ; 
            cnt = 0 ;
        }
    }
    cout << ans ; 
}
//-----------------------------------------------------------------------------------------
int main()
{
    ZEDAN() ;
    ll t = 1 ; 
    cin >> t ;
    while(t--){
        solve() ; 
        if(t) cout << dl ; 
    }
    return 0;   
} 