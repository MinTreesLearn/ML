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

int ceile(int a, int b) {return (a / b) + ((a % b) != 0);}

class Solution{

public:
    int f(vi a, vi b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
//SOLUTION STARTS HERE
    void solve(){

       //find all n points first
        vi sc(2), a(2), b(2);
        cin>>sc[0]>>sc[1]>>a[0]>>a[1]>>b[0]>>b[1];
        vvi vec{sc};

        while(true){
            vi dc = sc;
            sc = {dc[0]*a[0] + b[0], dc[1]*a[1] + b[1]}; 
            if(sc[0]<dc[0] || sc[1]<dc[1] || sc[0]>(ll(1e17)) || sc[1]>(ll(1e17))){
                break;
            }       
            else{
                vec.PB(sc);
            }
        }
        vi ac(2); cin>>ac[0]>>ac[1];
        int time; cin>>time;
        int n = vec.size();
        int ans = 0;
        // for(auto c:vec) print(c);
            //first go to ith point
        FOR(j,0,n){
            FOR(k,0,n){
                //traverse array from ith to i+1
                // cover left first then right
                int timeReq = f(ac, vec[j]) + f(vec[j], vec[k]);

                if(timeReq>=0 && timeReq <=time){
                    ans=max(ans, abs(k-j)+1);
                }
            }
        }
        cout<<ans;
}};

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
