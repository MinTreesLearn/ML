#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 101
#define bas (133)
#define yu (998244353)
ll n;
inline void ask(ll x,ll y){
	cout<<"? "<<x<<' '<<y<<'\n';
	cout.flush();
	return ;
}
string s1[N*N/2],s2[N*N/2];
char ans[N];
ll hs1[N*N/2],hs2[N*N/2];
bool vis[N*N/2];
ll p[N],len[N*N/2],cn=0;
inline bool cmp(ll x,ll y){return len[x]<len[y];}
inline void solve(ll x){
	if(x==1){
		ask(1,1);
		cin>>s1[0];ans[1]=s1[0][0];
		return ;
	}
	ask(1,x);
	ll cnt[N];
	for(int i=1;i<=x*(x+1)/2;i++){
		cin>>s1[i];memset(cnt,0,sizeof(cnt));
		for(int j=0;j<s1[i].size();j++)cnt[s1[i][j]-'a']++;
		for(int j=0;j<26;j++)hs1[i]=(hs1[i]*bas+cnt[j])%yu;
	}ask(1,x-1);
	for(int i=1;i<=(x-1)*x/2;i++){
		cin>>s2[i];memset(cnt,0,sizeof(cnt));
		for(int j=0;j<s2[i].size();j++)cnt[s2[i][j]-'a']++;
		for(int j=0;j<26;j++)hs2[i]=(hs2[i]*bas+cnt[j])%yu;
	}
	for(int i=1;i<=(x-1)*x/2;i++){
		for(int j=1;j<=x*(x+1)/2;j++){
			if(vis[j])continue;
			if(hs2[i]==hs1[j]){
				vis[j]=1;break;
			}
		}
	}for(int i=1;i<=x*(x+1)/2;i++){
		if(vis[i])continue;p[++cn]=i;len[i]=s1[i].length();
	}sort(p+1,p+cn+1,cmp);
	for(int j=1;j<=cn;j++){
		memset(cnt,0,sizeof(cnt));
		ll o=p[j];for(int g=0;g<s1[o].length();g++)cnt[s1[p[j]][g]-'a']++;
		if(j>1)for(int g=0;g<s1[p[j-1]].length();g++)cnt[s1[p[j-1]][g]-'a']--;
		for(int g=0;g<26;g++)if(cnt[g])ans[cn-j+1]=g+'a';
	}
	return ;
}
ll cnt[N*N][26];
bool vv[N*N];
ll tmp[26];
inline void del(){
	for(int i=1;i<=(n+1)*n/2;i++){
		bool kz=1;if(vv[i])continue;
		for(int j=0;j<26;j++)if(cnt[i][j]!=tmp[j])kz=0;
		if(kz){
			vv[i]=1;break;	
		}
	}
	return ;
}
int main()
{
//	freopen("test1.in","r",stdin);
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;ll o=(n+1)/2,p=n-o;solve(o);
	ask(1,n);
	for(int i=1;i<=n*(n+1)/2;i++){
		string s;cin>>s;
		for(int j=0;j<s.length();j++)cnt[i][s[j]-'a']++;
	}
	for(int i=1;i<=n;i++){
		if(i>o){
			ll p=n-i,an[26];memset(an,0,sizeof(an));
			for(int j=1;j<=n*(n+1)/2;j++){
				if(vv[j])continue;
				ll tot=0;
				for(int k=0;k<26;k++)tot+=cnt[j][k];
				if(tot==p+1)for(int k=0;k<26;k++)an[k]+=cnt[j][k];
				if(tot==p)for(int k=0;k<26;k++)an[k]-=cnt[j][k];
			}for(int j=i-1;j>=i-p;j--)an[ans[j]-'a']--;
			for(int j=0;j<26;j++)if(an[j])ans[i]=j+'a';
		}
		memset(tmp,0,sizeof(tmp));
		for(int j=i;j>=1;j--){
			tmp[ans[j]-'a']++;
			del();
		}
	}
	cout<<"! ";for(int i=1;i<=n;i++)cout<<ans[i];
	return 0;
}
