#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define TIME cerr<<"Time Taken:"<<(float)clock()/CLOCKS_PER_SEC*1000<<"ms"<<endl

typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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

lli dp[200005];
vector<lli> dis(200002);
// pair<lli,lli> dp[200005];
void bfs(auto tg,lli r,lli n)
{
    bool vis[n];
    fill(vis,vis+n,false);
    // vis[r]=1;
    dis[r]=0;
    deque<pair<lli,lli>> d;
    d.pb({r,0});
    while(d.size())
    {
        auto x=d[0];
        d.pop_front();
        // cout<<x.ff<<endl;
        if(vis[x.ff])
            continue;
        vis[x.ff]=1;
        for(auto j:tg[x.ff])
        {
            if(vis[j]==false && dis[j]==1e18)
            {
                dis[j]=min(dis[j],x.ss+1);
                d.pb({j,x.ss+1});
            }
        }
    }
}
lli fmin(lli p[],lli k,auto g,lli i)
{
    if(i==k-1)
        return 0;
    lli r=p[i];
    
    lli &fans=dp[i];
    if(fans!=-1)
        return fans;
    // lli fans=1e18;
    fans=1e18;
    lli flag=0;
    for(auto j:g[p[i]])
    {
        if(dis[j]+1==dis[r])
        {
            lli ans=fmin(p,k,g,i+1);
            if(j!=p[i+1])
                ans++;
            fans=min(fans,ans);
        }
    }
    lli ans=fmin(p,k,g,i+1);
    ans++;
    fans=min(fans,ans);
    return fans;
}

lli fmax(lli p[],lli k,auto g,lli i)
{
    if(i==k-1)
        return 0;
    lli r=p[i];
    lli &fans=dp[i];
    if(fans!=-1)
        return fans;
    // lli fans=-1e18;
    fans=-1e18;
    lli flag=0;
    for(auto j:g[p[i]])
    {
        if(dis[j]+1==dis[r])
        {
            lli ans=fmax(p,k,g,i+1);
            if(j!=p[i+1])
                ans++;
            else
                flag=1;
            fans=max(fans,ans);
        }
    }
    lli ans=fmax(p,k,g,i+1);
    ans++;
    if(!flag)
        fans=max(fans,ans);
    return fans;
}

pair<lli,lli> solve(auto g,auto tg,lli n,lli k,lli p[])
{
    fill(all(dis),1e18);
    bfs(tg,p[k-1],n);
    memset(dp,-1,sizeof(dp));
    lli mini=fmin(p,k,g,0);//<<endl;;
    memset(dp,-1,sizeof(dp));
    lli maxi=fmax(p,k,g,0);//<<endl;;
    return {mini,maxi};
}
int main() {
fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    lli t=1,testcases=1;
    // cin>>t;
    while(t>=testcases)
    {
        lli n,m;
        cin>>n>>m;
        vector<lli> g[n];
        vector<lli> tg[n];
        for(lli i=0;i<m;i++)
        {
            lli a,b;
            cin>>a>>b;
            a--;
            b--;
            g[a].pb(b);
            tg[b].pb(a);
        }
        lli k;
        cin>>k;
        lli p[k];
        for(lli i=0;i<k;i++)
        {
            cin>>p[i];
            p[i]--;
        }
        // for(auto j:p)
        //     cout<<j<<" ";
        // cout<<endl;
        pair<lli,lli> ans=solve(g,tg,n,k,p);
        cout<<ans.ff<<" "<<ans.ss<<endl;
        cerr<<testcases<<" Done\n";
        //cout<<"Case #"<<testcases<<": "<<ans<<endl;
        testcases++;
    }
    TIME;
    return 0;
}
