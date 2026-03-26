#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int,int> PII;
typedef long long LL;
const int INF=0x3f3f3f3f;
const long long LNF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
const int N=200010,M=N<<1;
inline int read(){ 
    int f=1,x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}

int n,m;
struct Node{
    int a,t;
    bool operator<(const Node &W)const{
        return a<W.a;
    }
}a[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i].a;
    for(int i=1;i<=n;++i)cin>>a[i].t;
    sort(a+1,a+1+n);

    priority_queue<int>q;
    LL res=0,cost=0;
    for(int i=1,now=1;i<=n;++now){
        if(q.empty())now=a[i].a;
        while(now==a[i].a&&i<=n)q.push(a[i].t),cost+=a[i].t,++i;
        cost-=q.top();q.pop();
        res+=cost;
    }
    while(!q.empty()){
        cost-=q.top();q.pop();
        res+=cost;
    }
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int Tt=1;
    //cin>>Tt;
    while(Tt--){
        solve();
    }
    return 0;
}