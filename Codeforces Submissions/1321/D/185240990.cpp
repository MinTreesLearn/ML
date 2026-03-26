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
int ceile(int a, int b) {return (a / b) + ((a % b) != 0);}




/*###########################################################################*/


class Solution{
public:
int f(vi a, vi b){
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}


//SOLUTION STARTS HERE
void solve(){

    int n,m; cin>>n>>m;
    vvi adj1(n), adj2(n);
    FOR(_,0,m){
        int u,v; cin>>u>>v; u--, v--;
        adj1[u].PB(v), adj2[v].PB(u);
    }
    int k; cin>>k;
    vi path(k); FOR(i,0,k) {cin>>path[i]; path[i]--;}
    int s = path[0], d = path.back();

    vi dist(n,1e15);

    auto bfs = [&](void){
        queue<int> q;
        q.push(d);
        q.push(-1);
        int curr_dist = 0;
        vi vis(n,0);
        vis[d]=1;
        while(!q.empty()){

            int top = q.front();
            q.pop();
            // cerr<<top<<" ";
            if(top==-1){
                curr_dist++;
                if(q.empty()) break;
                q.push(-1);
                continue;
            }
            //update top
            dist[top] = curr_dist;
            //for top node 
            for(int c:adj2[top])
                if(!vis[c]){
                    vis[c]=1;
                    q.push(c);
                }
        }
    };

    bfs();
    // cerr<<"e";
    // return;
    int mini=0, maxi=0;
    //start going towards path
    FOR(i,1,k){
        //transition from path[i-1] to path[i]
        if(dist[path[i]] != dist[path[i-1]]-1){
            mini++;
            maxi++;
        }
        else{
            bool flag = false;

            for(int c: adj1[path[i-1]])
                if(c!=path[i] && dist[path[i]] == dist[c])
                    {flag = true; break;}

            maxi+=flag;            
        }
    }
    cout<<mini<<" "<<maxi;
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
