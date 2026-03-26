#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define mod 1000000007
#define len(x) x.size()
#define min3(a,b,c) min(a, min(b,c))
#define max3(a,b,c) max(a, max(b,c))
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1,i>=a;i--)
#define int  long long

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvii;
typedef vector<string> vs;


void solve(){
    int n,m;
    cin>>n>>m;
    vi edges[n+1];
    vi par[n+1];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        par[y].pb(x);
    }
    int k;cin>>k;
    vi v(k);
    rep(i,0,k)cin>>v[i];
    vi cnt(n+1,0);
    vi d(n+1,1e9);
    queue<int>q;
    map<int,bool>vis;
    q.push(v[k-1]);
    d[v[k-1]]=0;
    vis[v[k-1]]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y:par[x]){
            if(!vis[y]){
                q.push(y);
                d[y]=1+d[x];
                cnt[y]++;
                vis[y]=true;
            }
        }
    }
    int mn=0,mx=0;
    int prev=d[v[0]];
    rep(i,0,k){
        if(prev!=d[v[i]]){
            mx++;
            mn++;
            prev=d[v[i]];
            prev--;
        }
        else{
            if(i>0){
                int b=0;
                for(auto x:edges[v[i-1]]){
                    if(d[x]==d[v[i]] && x!=v[i])b=1;
                }
                mx+=b;
                
            }
            prev--;
        }
    }
    cout<<mn<<" "<<mx<<endl;

    

}


int32_t main() {
   /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}