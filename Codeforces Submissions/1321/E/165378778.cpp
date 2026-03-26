#include <bits/stdc++.h>
using namespace std;
struct weapon{
	long long atk;
	long long cost;
};
struct armor{
	long long def;
	long long cost;
};
struct monster{
	long long atk;
	long long def;
	long long money;
};
bool wpncmp(weapon a,weapon b){
	return a.atk<b.atk;
}
bool amrcmp(armor a,armor b){
	return a.def<b.def;
}
bool monscmp(monster a,monster b){
	return a.def<b.def;
}
long long line[200001],value[400010],lazy[400010]={},l[400010],r[400010],p=0;
int rangel[400010],ranger[400010];
weapon wpn[200000];
armor amr[200000];
monster mons[200000];
long long maxi(long long a,long long b){
	if(a<b)a=b;
	return a;
}
long long gen(int st,int en,int t){
	long long a,b;
	int mem=p;
	rangel[t]=st;
	ranger[t]=en;
	if(en-st==1)
	{
		value[t]=line[st];
		return value[t];
	}
	p+=2;
	a=gen(st,(st+en+1)/2,mem+1);
	b=gen((st+en+1)/2,en,mem+2);
	value[t]=maxi(a,b);
	l[t]=mem+1;
	r[t]=mem+2;
	return value[t];
}
long long pls(int x,int y,int k,int t){
	if(x==rangel[t]&&y==ranger[t])
	{
		lazy[t]+=k;
		return lazy[t]+value[t];
	}
	if(x>=(rangel[t]+ranger[t]+1)/2)
	{
		value[t]=maxi(pls(x,y,k,r[t]),value[l[t]]+lazy[l[t]]);
	}
	else if(y<=(rangel[t]+ranger[t]+1)/2)
	{
		value[t]=maxi(pls(x,y,k,l[t]),value[r[t]]+lazy[r[t]]);
	}
	else
	{
		value[t]=maxi(pls(x,(rangel[t]+ranger[t]+1)/2,k,l[t]),pls((rangel[t]+ranger[t]+1)/2,y,k,r[t]));
	}
	return value[t]+lazy[t];
}
long long ans(int x,int y,int t){
	if(x==rangel[t]&&y==ranger[t])
	{
		return lazy[t]+value[t];
	}
	if(x>=(rangel[t]+ranger[t]+1)/2)return ans(x,y,r[t])+lazy[t];
	if(y<=(rangel[t]+ranger[t]+1)/2)return ans(x,y,l[t])+lazy[t];
	return maxi(ans(x,(rangel[t]+ranger[t]+1)/2,l[t]),ans((rangel[t]+ranger[t]+1)/2,y,r[t]))+lazy[t];
}
int main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m,px,i,j,st,en,tmp;
	long long maxprof=-10000000000000000,an;
	cin>>n>>m>>px;
	for(i=0;i<n;i++)
	{
		cin>>wpn[i].atk>>wpn[i].cost;
	}
	sort(wpn,wpn+n,wpncmp);
	for(i=0;i<m;i++)
	{
		cin>>amr[i].def>>amr[i].cost;
	}
	sort(amr,amr+m,amrcmp);
	for(i=0;i<px;i++)
	{
		cin>>mons[i].def>>mons[i].atk>>mons[i].money;
	}
	sort(mons,mons+px,monscmp);
	for(i=0;i<m;i++)
	{
		line[i]=-amr[i].cost;
	}
	gen(0,m,0);
	j=0;
	for(i=0;i<n;i++)
	{
		for(;j<px&&mons[j].def<wpn[i].atk;j++)
		{
			st=-1;
			en=m-1;
			while(en-st>1)
			{
				tmp=(st+en+1)/2;
				if(amr[tmp].def>mons[j].atk)en=tmp;
				else st=tmp;
			}
			if(amr[en].def>mons[j].atk)pls(en,m,mons[j].money,0);
		}
		an=ans(0,m,0);
		if(an-wpn[i].cost>maxprof)maxprof=an-wpn[i].cost;
	}
	cout<<maxprof<<'\n';
	return 0;
}