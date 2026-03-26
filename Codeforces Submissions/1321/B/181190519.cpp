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
ll a[Max];
/*queue<ll> q;
stack<ll> s;
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;*/
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    map<ll,ll>mp;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]-i]+=a[i];
        ans=max(ans,mp[a[i]-i]);
    }
    cout<<ans<<endl;
    return 0;
}
  	 	 			 		  				  		  		 			