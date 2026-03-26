// LUOGU_RID: 98656651
//A tree without skin will surely die.
//A man without face will be alive
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define Tim ((double)clock()/CLOCKS_PER_SEC)
#define lowbit(x) (x&-x)
int const N=3e5+10;
int a[N],pre,len,vis[6];
map< vector< vector<int> >,int >mp;vector< vector<int> >sg;
inline int mex(int a,int b,int c){
	memset(vis,0,sizeof(vis));vis[a]=vis[b]=vis[c]=1;
	for (int i=0;i<5;++i) if (!vis[i]) return i;
	return 0;
}
inline void add(int x,int y,int z){
	vector<int>tmp(3,0);int l=sg.size();
	tmp[0]=mex(sg[max(l-x,0ll)][0],sg[max(l-y,0ll)][1],sg[max(l-z,0ll)][2]);
	tmp[1]=mex(sg[max(l-x,0ll)][0],sg[max(l-z,0ll)][2],4);
	tmp[2]=mex(sg[max(l-x,0ll)][0],sg[max(l-y,0ll)][1],4);
	sg.push_back(tmp);
}
inline void go(int x,int y,int z){
	sg.clear(),mp.clear();
	sg.push_back({0,0,0});int cnt=0;
	for (int i=1;i<5;++i) add(x,y,z);
	while ("CCF is very good~"){
		vector< vector<int> > tmp(sg.end()-5,sg.end());
		if (mp[tmp]){pre=mp[tmp],len=sg.size()-5-pre;break;}
		mp[tmp]=sg.size()-5;add(x,y,z);
	}
}
inline int getsg(int x){return (x<=pre)?x:(x-pre)%len+pre;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while (t--){
		int n,x,y,z;cin>>n>>x>>y>>z;
		for (int i=1;i<=n;++i) cin>>a[i];
		go(x,y,z);int sum=0,num[4]={0,0,0,0};
		for (int i=1;i<=n;++i){
			int la=sg[getsg(a[i])][0];
			int X=sg[getsg(max(0ll,a[i]-x))][0];
			int Y=sg[getsg(max(0ll,a[i]-y))][1];
			int Z=sg[getsg(max(0ll,a[i]-z))][2];
			sum^=la;++num[X^la],++num[Y^la],++num[Z^la];
		}
		cout<<num[sum]<<'\n';
	}
	return 0;
}