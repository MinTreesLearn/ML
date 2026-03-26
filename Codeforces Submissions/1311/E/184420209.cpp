#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) (x&(-x))
#define lb long double
#define db double
#define pll pair<ll,ll>
#define debug(a) cout<<"debug: "<<(#a)<<" = "<<a<<'\n'
#define cer(a) cerr<<#a<<'='<<(a)<<"@ line"<<__LINE__<<endl
#define cer2(a,b) cerr<<#a<<'='<<(a)<<','<<#b<<'='<<(b)<<"@ line"<<__LINE__<<endl
#define cer3(a,b,c) cerr<<#a<<'='<<(a)<<','<<#b<<'='<<(b)<<','<<#c<<'='<<(c)<<','<<"@ line"<<__LINE__<<endl
#define pdd pair<db,db>
using namespace std;
const int maxn=2e5+100;
const int mode=1e9+7;
const ll inf=9223372036854775807;
const db eps=1e-6;
ll n,m,a[maxn];
ll sum,ans[maxn],d;
string str;
vector<int>vt;
int vis[maxn];
int par[maxn],ch[maxn];
int now,c,mx;
int get()
{
	int res=now;
	c++;
	if(c==mx)
	{
		now++;
		mx*=2;
		c=1;
	}
	return res;
}
void solve()
{
    cin>>n>>d;
    ll cnt=0;
    for(int i=1;i<=n-1;i++)
    {
    	ans[i]=i;
    	ch[i]=0;
    	cnt+=i;
	}
	ch[0]=0;
	if(cnt<d)
	{
		cout<<"NO"<<'\n';
		return;
	}
	now=1;
	mx=2;
	c=1;
	ll pos=n-1;
	while(cnt>d)
	{
		int deg=get();
		ll res=cnt-d;
		if(deg>=pos)
		break;
		if(res>=(pos-deg))
		{
			ans[pos]=deg;
			cnt-=(pos-deg);
		}else{
			ans[pos]-=res;
			cnt=d;
			break;
		}
		pos--;
	}
	if(cnt>d)
	{
		cout<<"NO"<<'\n';
		return;
	}
	cout<<"YES"<<'\n';
	ans[0]=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			if(ans[j]==ans[i]-1&&ch[j]<2)
			{
				par[i]=j;
				ch[j]++;
				break;
			}
		}
	}
    for(int i=1;i<=n-1;i++)
    {
    	cout<<par[i]+1<<" ";
	}
	cout<<'\n';
 
 
 
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\JIAJIEASHI\\Desktop\\in.cpp","r",stdin);
	//	freopen("out.cpp","w",stdout);
	#endif
   ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	t=1;
    cin>>t;
	while(t--) 
    solve();
	return 0;
}



