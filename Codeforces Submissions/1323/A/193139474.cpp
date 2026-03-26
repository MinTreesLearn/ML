#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define fixed(name) fixed << setprecision(name)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define pi  3.14159265359
#define getline(s) getline(cin >> ws, s)
#define dl "\n"
#define cin(v) for(auto &i: v)  cin>>i
#define cout(v) for(auto &i: v) cout<<i<<" "
#define Mod  1'000'000'007
#define sz(x) int(x.size())
#define OO 2'000'000'000
using namespace std;

//using namespace __gnu_pbds;
void MAI(){
     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     #ifndef ONLINE_JUDGE
         freopen("input.txt","r" , stdin) ; 
         freopen("output.txt", "w" , stdout) ;  
     #endif
}
// template <typename K, typename V, typename Comp = std::less<K>>
// using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename K, typename Comp = std::less<K>>
// using ordered_set = ordered_map<K, null_type, Comp>;

// template <typename K, typename V, typename Comp = std::less_equal<K>>
// using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename K, typename Comp = std::less_equal<K>>
// using ordered_multiset = ordered_multimap<K, null_type, Comp>;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x : v) out << x << ' ';
    return out;
}
// summation n*(n+1)/2 -> (-1+ sqrt(1+8*x))/2
// 2D vector vector<vector<ll>>v(n,vector<ll>(m, -1)) ;
bool is_vowel (char c){
    if(c == 'a' || c=='u' || c=='i' || c=='e' || c=='o' ) return true;
    else return false;
}
void solve(){
    int n, sum=0, c=0, i=0; cin>>n;
    vector<int>v(n); cin>>v;
    for(i=0; i<n; i++){
        if(v[i]%2 == 0) {cout<<"1\n"<<i+1; return;}
        else if(sum > 0 && sum%2 == 0) break;
        else {sum+=v[i]; c++;}
    }
    if(sum > 0 && sum%2 == 0){
        cout<<i<<dl;
        for(int j=0; j<i; j++) cout<<j+1<<" ";
    }
    else cout<<"-1"; 
}
int main()
{   MAI(); 
    int t=1;
    cin>>t;
    while(t--){
        solve();
        if(t) cout << dl ; 
    }
}