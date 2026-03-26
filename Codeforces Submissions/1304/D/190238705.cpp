#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define M_PI       3.14159265358979323846
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     pb                push_back 
#define     ff                first 
#define     ss                second
#define     pii                pair<int,int> 
#define sz(x)                 (int)x.size()
#define all(x)                 (x).begin(), (x).end()
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x <<"\n";
#else
#define debug(x)
#endif
#ifndef ONLINE_JUDGE
#define debugg(x) cerr << #x << " " << x <<"\n";
#else
#define debugg(x)
#endif


using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, 
rb_tree_tag,tree_order_statistics_node_update> ;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define precise std::setprecision(20)
typedef long long ll;
typedef long double ld;
inline void setIO(string );

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// use setprecision before not after
// don't modify map while iterating
// beware of precendence bitwise with arithmetic, use sz(arr) instead of arr.size()
// can't think of anything then think of xor
// pigeonhole and bruteforce mostly go together
// powl() instead of pow() for 64 bit
// vector.assign(size, value) it resizes if necessary.
// use fill() works with vectors as well as arrays

int solve(){
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> adj[n], indeg(n, 0);
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '<') {
            adj[i].pb(i + 1);
            indeg[i + 1]++;
        } else {
            adj[i + 1].pb(i);
            indeg[i]++;
        }
    }

   

    vector<ll> a1(n, 0), a2(n, 0);

    {
        vector<ll> dindeg = indeg;
        priority_queue<ll> q;
        for(int i = 0; i < n; i++) {
            if(dindeg[i] == 0) q.push(i);
        }
        ll c = 1;

        while(!q.empty()) {
            ll u = q.top();
            a1[u] = c;
            c++;
            q.pop();

            for(auto v: adj[u]) {
                dindeg[v]--;
                if(dindeg[v] == 0) q.push(v);
            }
        }  
    }

    {
        vector<ll> dindeg = indeg;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for(int i = 0; i < n; i++) {
            if(dindeg[i] == 0) q.push(i);
        }
        ll c = 1;

        while(!q.empty()) {
            ll u = q.top();
            a2[u] = c;
            c++;
            q.pop();

            for(auto v: adj[u]) {
                dindeg[v]--;
                if(dindeg[v] == 0) q.push(v);
            }
        }  
    }


    for(auto u: a1) cout << u << " ";

    cout << "\n";

    for(auto u: a2) cout << u << " ";
    cout << "\n";
  
    return 0;
  }
 

int main(){
    Speed_UP
    
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        //freopen("output.txt", "w", stdout);
    #endif


    ll t = 1;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        // cout << "Case #"<<i<<": "; 
        solve();
    }
}


inline void setIO(string name="") {
    #ifndef ONLINE_JUDGE 
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
    #endif
    }
