#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,long long>, null_type,less<pair<long long,long long> >, rb_tree_tag,tree_order_statistics_node_update>*/
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
#define mod1   (long long)998244353
#define mod2   (long long)1000000007
#define first_bit(x) (x&(-x))
#define last_bit(x) (x&~(x))
#define ll   long long
#define ld   long double
#define int long long
#define ff    first
#define ss    second
#define pb    push_back
#define w(x)  long long x;cin>>x;while(x--)
#define vi    vector<long long> 
#define mii map<long long,long long>
#define pii pair<long long,long long>
#define set_bits(x) __builtin_popcountll(x)
#define fast()  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz(x) ((long long)x.size())
#define all(x) begin(x), end(x)
#define memo(x,y) memset((x),(y),sizeof(x));
map<int,vector<pii> > adj;
vector<int> path;
bool dfs(int root,int par,int tg){
    if(root==tg){
        return true;
    }
    for(auto i:adj[root])if(i.ff!=par){
        if(dfs(i.ff,root,tg)){
            path.push_back(i.ss);
            return true;
        }
    }
    return false;;
}
struct point{
    int st;
    int en;
    int mini;
};
signed main(){
fast();
int n;
cin>>n;
vector<int> res(n,1000000);
for(int i=1;i<=n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].pb({b,i});
    adj[b].pb({a,i});
}
int m;
cin>>m;
vector<point> v(m);
vector<vi> rut;
for(int i=0;i<m;i++){cin>>v[i].st>>v[i].en>>v[i].mini;}
sort(all(v),[&](point p1,point p2){
    return p1.mini<p2.mini;
});
for(auto i:v){
    vector<int> curr;
    dfs(i.st,0,i.en);
    curr=path;
    path.clear();
    rut.pb(curr);
    for(auto j:curr){res[j]=i.mini;}
}
bool can=true;
for(int i=0;i<m;i++){
    bool pass=false;
    for(auto j:rut[i])if(res[j]==v[i].mini)pass=true;
    can&=pass;
}
if(can)for(int i=1;i<=n-1;i++)cout<<res[i]<<" ";
else cout<<-1<<endl;
}

