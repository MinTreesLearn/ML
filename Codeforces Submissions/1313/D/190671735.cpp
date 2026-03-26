/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define eb emplace_back
#define PI 3.14159265359
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define BIT(x,i) (1&((x)>>(i)))
#define MASK(x) (1LL<<(x))
#define task "tnc"  
typedef long long ll;
const ll INF=1e18;
const int maxn=1e6+5;
const int mod=1e9+7;
const int mo=998244353;
using pi=pair<ll,ll>;
using vi=vector<ll>;
using pii=pair<pair<ll,ll>,ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,m,s1;
pair<int,int>ed[maxn];
vector<int>qu;
vector<int>l[maxn]; 
vector<int>r[maxn];
int dp[2][1<<8];
int used=0;
int id[maxn];
int doi[9];
int trc=0;
signed main()
{
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    //freopen(task".inp" , "r" , stdin);
    //freopen(task".out" , "w" , stdout);
    cin>>n>>m>>s1;
    for(int i=1;i<=n;i++){
		int l,r;
    	cin>>l>>r;
    	ed[i]={l,r+1};
    	qu.pb(l);
    	qu.pb(r+1);
    }
    sort(qu.begin(),qu.end());
    qu.resize(distance(qu.begin(),unique(qu.begin(),qu.end())));
    for(int i=1;i<=n;i++){
    	ed[i].fi=lower_bound(qu.begin(),qu.end(),ed[i].fi)-qu.begin();
    	ed[i].se=lower_bound(qu.begin(),qu.end(),ed[i].se)-qu.begin();
    	l[ed[i].fi].pb(i);
    	r[ed[i].se].pb(i);
    }
    int ans=0;
    for(int i=0;i<qu.size()-1;i++){
    	int aft=(i&1);
    	int bef=(aft^1);
    	memset(doi,0,sizeof(doi));
    	trc=used;
    	for(auto v:r[i]){
    		used^=(1<<id[v]);
    		doi[id[v]]=1;
    	}
    	for(auto v:l[i]){
    		for(int j=0;j<8;j++){
    			if(((used>>j)&1)==0){
    				id[v]=j;
    				used^=(1<<j);
    				doi[j]=1;
    				break;
    			}
    		}
    	}
    	for(int j=used;;j=(j-1)&used){
    		int sus=0;
    		int bat=0;
    		for(int check=0;check<8;check++){
    			if(doi[check]==0 ){
    				sus+=(1<<check);
    				if(BIT(j,check)==1){
    					bat+=(1<<check);
    				}
    			}
    		}
    		int trc1=sus^trc;
    		for(int k=trc1;;k=(k-1)&trc1){
    			int ok=0;
    			int f=__builtin_popcount(j);
    			dp[aft][j]=max(dp[aft][j],dp[bef][k^bat]+((f%2)==1?(qu[i+1]-qu[i]):0));
    			ans=max(ans,dp[aft][j]);
    			if(k==0)break;
    		}
    		if(j==0)break;
    	}
    }
    cout<<ans;
    return 0;
}
