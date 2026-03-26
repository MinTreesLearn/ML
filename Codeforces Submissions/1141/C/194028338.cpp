/*Dev Karan Singh Sisodia*/
#include <bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define pyes cout << "Yes" << "\n";
#define pno cout << "No" << "\n";
#define br cout << "\n";
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define sz(x) ((long long)(x).size())
#define modd 1000000007
#define mod 998244353
#define inf 9223372036854775807
#define all(x) (x).begin(),(x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll gcd(ll a, ll b){ if (a == 0ll) { return b;} return gcd(b % a, a);}

void solve(){
    int n;
    cin >> n;
    vector<int> q(n);
    for(int i = 0; i < n-1; i++){
        cin >> q[i];
    }
    vector<int> arr(n, 0);
    int sum = 0;
    int maxi = INT_MIN;
    int index;
    for(int i = 0; i < n-1; i++){
        sum += q[i];
        if(sum > maxi){
            maxi = sum;
            index = i+1;
        }
    }
    if(maxi < 0){
        index = 0;
    }
    arr[index] = n;
    for(int i = index; i < n-1; i++){
        arr[i+1] = arr[i] + q[i];
    }
    for(int i = index - 1; i >= 0; i--){
        arr[i] = arr[i+1] - q[i];
    }
    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    if(*st.begin() == 1 && st.size() == n){
        for(auto it : arr){
            cout << it << " ";
        }
    }else{
        cout << -1;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}