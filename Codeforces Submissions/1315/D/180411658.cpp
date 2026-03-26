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
PII p[Max];
/*queue<ll> q;
stack<ll> s;
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;*/
bool cmp(PII a,PII b)
{
    if(a.ft==b.ft)return a.sd<b.sd;
    return a.ft<b.ft;
}
int main()
{
    ios::sync_with_stdio(false);
    map<ll,ll>mp,mp1;
    cin>>n;
    for(ll i=1;i<=n;i++){cin>>p[i].ft;mp[p[i].ft]++;}
    for(ll i=1;i<=n;i++)cin>>p[i].sd;
    sort(p+1,p+1+n,cmp);
    priority_queue<ll,vector<ll>,less<ll>>q;
    bool flog=true;
    ans=0;
    
    ll w=0;
    ll sum=0;
    ll i=0;
    while(!q.empty()||i<=n)   
    {
        if(q.empty())w=p[i].ft;
        while(i<=n&&w==p[i].ft)
        {
            sum+=p[i].sd;
            q.push(p[i].sd);
            i++;
        }
        sum-=q.top();
        q.pop();
        ans+=sum;w++;
    }
    cout<<ans<<endl;
    return 0;
}
			    	   	 		   		 		  				 	