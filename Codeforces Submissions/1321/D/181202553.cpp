#include<bits/stdc++.h>
#define ll long long
#define PI 3.141592653589793
#define E 2.718281828459045
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define FO( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define lowbit(a) ((a)&-(a))
#define PII pair<ll ,ll >
#define ft first
#define sd second
#define endl "\n"
typedef unsigned long long ull;
const ll mod=10007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll Max=2e5+10;
using namespace std;
ll mov[][2]={0,1,0,-1,1,0,-1,0};
ll t,n,m,l,r,k;
ll ans;
ll p[Max];
ll e[Max],ne[Max],h[Max],idx;
ll dist[Max];
ll st[Max];
/*queue<ll> q;
stack<ll> s;
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;*/
void add(ll a,ll b)
{
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
void dijkstra(ll x)
{
    mset(dist,INF);
    mset(st,0);
    queue<ll>q;
    q.push(x);
    dist[x]=0;
    while(q.size())
    {
        ll p=q.front();
        q.pop();
        for(ll i=h[p];~i;i=ne[i])
        {
            ll j=e[i];
            if(dist[j]>dist[p]+1)
            {
                if(dist[j]==INF)dist[j]=dist[p]+1,q.push(j),st[j]=1;
            }
            else 
            if(dist[j]==dist[p]+1)st[j]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    mset(h,-1);
    for(ll i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        add(b,a);
    }
    cin>>k;
    for(ll i=1;i<=k;i++)
    {
        cin>>p[i];
    }
    dijkstra(p[k]);
    //cout<<dist[p[k]]<<endl;
    //for(ll i=1;i<=k;i++)
        //cout<<p[i]<<' '<<dist[p[i]]<<endl;
    ll sum1=0,sum2=0;
    for(ll i=1;i<k;i++)
    {
        if(dist[p[i]]==dist[p[i+1]]+1)
            {
                if(st[p[i]]>1)
                sum2++;
            }
        else sum1++,sum2++;
    }
    cout<<sum1<<' '<<sum2<<endl;
    return 0;
}
    			   			 	  	 		  	  	 		