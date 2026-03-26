#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

#define endl '\n'
typedef long long ll;
#define mod1 (ll)1000000007
#define mod2 (ll)998244353
#define pll pair<ll,ll>
typedef long double lb;
typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll, ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
#define eps (lb)(1e-9)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll p){ // gives random number in [0,p]

 return uniform_int_distribution<ll>(0, p)(rng);
}
ll inf=1<<20;
ll n,k;
vector<ll>v;
vector<ll>con[1<<19]; // con[i]-> nodes that contain i
vector<ll>okg[1<<19];// okg[i]-> values that node i contain
set<pll>adj[1<<19]; // {node,set} 
ll complement(ll x,ll n=k){
    if(x<n){return x+n;}
    else{return x-n;}
}
class DisjSet {
    vector<int>sz,parent; int n;

public:
       int connected;
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n)
    {
        sz = vector<int>(n,1);
        parent = sz;
        this->n = n;
        this->connected=n; 
        makeSet();
    }

    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Finds set of given item x
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {

            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);

            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }

        return parent[x];
    }

    int size(int x)
    {
        return sz[find(x)];
    }
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);

        // If they are already in same set
        if (xset == yset){
            return;
        }

         connected--;
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (sz[xset] <= sz[yset]) {
            parent[xset] = yset;
            sz[yset] += sz[xset];
        }
        else  {
            parent[yset] = xset;
            sz[xset] += sz[yset];
        }

    }
};
class Bipartite_DisjSet {
    // could be slow (i.e logn per query at most) because i am assuring if x is 
    // a parent so is x+n, path 
public:
    vector<ll>sz,parent; ll n;

    // i and (i+n) are different colors
    //    int connected;
    // Constructor to create and
    // initialize sets of n items
    Bipartite_DisjSet(ll n)
    {
        sz = vector<ll>(2*n,1);
        for(ll i(n);i<2*n;++i){sz[i]=0;}
        parent = sz;
        this->n = n;
        // this->connected=n; 
        makeSet();
    }

    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < 2*n; i++) {
            parent[i] = i;
        }
    }

    // Finds set of given item x
    ll find(ll x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {

            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);

            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }

        return parent[x];
    }

    ll size(ll x)
    {
        return sz[find(x)];
    }
    // Do union of two sets represented
    // by x and y.
    void Union(ll x, ll y,ll edge=0) // parity of edge
    {
        
        if(x>y){
            return Union(y,x,edge);
        }
        // x<y
        if(y>=n){cout<<"Fuck"<<endl; exit(0);}
        // x and y are both <n
        // Find current sets of x and y
        ll xset = find(x);
        ll yset = find(y);

        // If they are already in same set
        if (xset == yset){
            assert(edge==0);
            return;
        }
        else if(xset%n==yset%n){
            assert(edge==1);
            return;
        }
        //  connected--;
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if(edge==0){
            // merge xset, yset
            // merge xset^c,yset^c
            parent[yset]=xset;
            parent[complement(yset,n)]=complement(xset,n);
            sz[xset]+=sz[yset];
            sz[complement(xset,n)]+=sz[complement(yset,n)];
        }
        else{
            // merge xset,yset^c
            // merge xset^c,yset
            parent[yset]=complement(xset,n);
            parent[complement(yset,n)]=xset;
            sz[xset]+=sz[complement(yset,n)];
            sz[complement(xset,n)]+=sz[yset];
        }

    }
};

void solve();
int main() {
io;
ll t=1,n=1;
// cin>>t;
while (t--){
     solve();
    }
     return 0;
}
void solve(){
     cin>>n>>k;
     for(ll i(0);i<n;++i){
        char pp; cin>>pp; 
        auto p=pp-'0';
        p^=1;
        v.push_back(p);
     }
     for(ll i(0);i<k;++i){
        ll sz; cin>>sz;
        for(ll j(0);j<sz;++j){
            ll tt; cin>>tt;
            tt--;
            con[tt].push_back(i);
            okg[i].push_back(tt);
        }
        sort(begin(okg[i]),end(okg[i]));
     }
    //  for(ll i(0);i<n;++i){
    //     if(con[i].size()==2){
            // adj[con[i][0]].insert({con[i][1],v[i]});
            // adj[con[i][1]].insert({con[i][0],v[i]});
    //     }
    //  }
    Bipartite_DisjSet dsu(k);
     vector<ll>ans(n,0);
     ll prev=0;
     for(ll i(0);i<n;++i){
        if(con[i].empty()){
            ans[i]=prev;
        }
        else if(con[i].size()==2){
            // add an edge
            ll kk=prev; // just storing previous answer
            {
                // adj[con[i][0]].insert({con[i][1],v[i]});
                // adj[con[i][1]].insert({con[i][0],v[i]});
                // dsu.Union(con[i][0],con[i][1],v[i]);
                if(dsu.find(con[i][0])%k==dsu.find(con[i][1])%k){
                    // nothing new happens
                    ans[i]=prev;
                }
                else if(min(okg[con[i][0]][0],okg[con[i][1]][0])==i){
                    // adding 2 nodes
                    dsu.Union(con[i][0],con[i][1],v[i]);
                    ll pr=dsu.find(con[i][0]);
                    ll q=complement(pr);
                    ans[i]=prev+min(dsu.size(q),dsu.size(pr));
                }
                else if(okg[con[i][0]][0]==i){
                    // adding 1 new node
                    ll val=min(dsu.size(con[i][1]),dsu.size(complement(con[i][1])));
                    ans[i]=prev-val;
                    dsu.Union(con[i][0],con[i][1],v[i]);
                    ans[i]+=min(dsu.size(con[i][1]),dsu.size(complement(con[i][1])));
                }
                else if(okg[con[i][1]][0]==i){
                    swap(con[i][1],con[i][0]);
                    // same as before now
                    ll val=min(dsu.size(con[i][1]),dsu.size(complement(con[i][1])));
                    ans[i]=prev-val;
                    dsu.Union(con[i][0],con[i][1],v[i]);
                    ans[i]+=min(dsu.size(con[i][1]),dsu.size(complement(con[i][1])));

                }
                else{
                    // new connection
                    ll val1=min(dsu.size(con[i][1]),dsu.size(complement(con[i][1])));
                    ll val2=min(dsu.size(con[i][0]),dsu.size(complement(con[i][0])));
                    ans[i]=prev-val1-val2;
                    dsu.Union(con[i][0],con[i][1],v[i]);
                    ans[i]+=min(dsu.size(con[i][1]),dsu.size(complement(con[i][1])));
                }
            }
        }
        else{
            // fix a size
            ll t=con[i][0];
            {
                ans[i]=prev-min(dsu.size(t),dsu.size(complement(t)));
                // if(i==6){cout<<ans[i]<<"&&&";}
                if(v[i]==0){ // always choose an even number of times
                    // choose complement
                    dsu.sz[dsu.find(t)]=inf;
                }
                else{
                    // choose t
                    dsu.sz[dsu.find(complement(t))]=inf;
                }
                ans[i]+=min(dsu.size(t),dsu.size(complement(t)));
            }
        }
        prev=ans[i];
     }
     for(auto i:ans){
        cout<<i<<endl;
     }





}
// Do not get stuck on a single approach for long, think of multiple ways