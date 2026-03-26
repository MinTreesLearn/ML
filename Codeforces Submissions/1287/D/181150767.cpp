#include<bits/stdc++.h>
using namespace std;

using ll = long long;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define DFOR(i,a,b)  for (int i=(a);i>=(b);--i)

#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define PB push_back
#define pi (double(2) * acos(0.0))
// #define mod (1000000007)
#define eps 1e-3
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

void print(vi a, int s=0){FOR(i,s,a.size())cout<<a[i]<<" ";cout<<'\n';}

const int K = 26;
class Vertex {
public:
    int next[K];
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);
void add_string(string const& s){
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}



class Solution{

    vvi adj;
    vi C;
public:
    vvi dfs(ll v){
        vvi res;
        int shift = 0;
        for(int c:adj[v]){
            vvi temp = dfs(c);
            if(temp.empty()){
                return temp;
            }
            //temp has all the below nodes
            //temp[0]->node id, temp[1]->value assigned to it
            for(vi cc:temp) 
                res.PB({cc[0], cc[1]+shift});
            shift = res.back()[1];
        }
        //res has all the subroot nodes
        //insert curr at c[v] index position
        if(res.size()<C[v])
            return vvi(0);
        res.insert(res.begin() + C[v],vi{v,C[v]+1});
        FOR(i,C[v]+1,res.size())
            res[i][1]++;

        return res;
    }

    void solve(){
        int n; cin>>n;
        adj.assign(n,vi(0));
        C.assign(n,0);
        int root=0;
        FOR(i,0,n){
            int p,c; cin>>p>>c; p--;
            if(p!=-1){
                adj[p].PB(i);
            }
            else
                root = i;
            C[i] = c;
        }
        //output values of nodes such that C is followed
        vvi ans = dfs(root);
        if(ans.empty()){
            cout<<"NO";
        }
        else{
            cout<<"YES\n";
            sort(all(ans));
            FOR(i,0,n)
                cout<<ans[i][1]<<" ";
        }
    }

};

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FIO;  
    int t=1;
    // cin>>t;
    int T=1;
    Solution ss;
    while (t--) {
        // cout<<"Case #"<<T<<": ";
        ss.solve(); 
        cout<<endl;       
        T++;
    }
    return 0;
}


