// LUOGU_RID: 102585203
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 22
ll n;
ll p[N],a[N]; 
ll f[1<<N];
ll cnn[1<<N];
bool vis[1<<N];
inline ll suan(ll x){
	if(f[x]!=-1)return f[x];
	ll an=(vis[x]);
	for(int i=(x-1)&x;i;i=(i-1)&x){
		if(!vis[x^i])continue;
		if(cnn[i]/2+1<=an)continue;
		an=max(an,suan(i)+1);
	}return f[x]=an;
}
map<ll,ll>dui;
ll cc=0;
vector<ll>hs[1<<(N-2)]; 
int main()
{
//	freopen("test1.in","r",stdin);
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll len;cin>>len;
	for(int i=1;i<=len;i++)cin>>p[i];
	for(int i=1;i<=len;i++)if(p[i]!=0)a[++n]=p[i];
	for(int i=1;i<(1<<n);i++){
		ll sum=0,cn=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1)))sum+=a[j],p[++cn]=a[j];
		}cnn[i]=cn;
		bool kz=0;
		if(cn>=2&&((sum+cn-1)&1)==0){
			for(ll k=(sum-cn+1)/2;k<=(sum+cn-1)/2;k++){
				if(dui.find(k)!=dui.end()){
					for(auto o:hs[dui[k]])if((o|i)==i){kz=1;break;}
				}if(kz)break;
			}
		}
		if(dui.find(sum)==dui.end())dui[sum]=++cc;
		hs[dui[sum]].push_back(i);
		if(!kz)continue;
		vis[i]=1;
	}memset(f,-1,sizeof(f));
	cout<<n-suan((1<<n)-1);
	return 0;
}
