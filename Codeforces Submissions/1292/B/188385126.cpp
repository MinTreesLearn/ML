#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
}p[100];
int dist(int a,int b,int c,int d){
	if(a<c) swap(a,c);
	if(b<d) swap(b,d);
	return a-c+b-d;
}
signed main(){
	int x,y,a,b,c,d,sx,sy,t,m=1,cnt=0,ans=-1;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x,&y,&a,&c,&b,&d,&sx,&sy,&t);
	p[1].x=x,p[1].y=y;
	while(dist(sx,sy,p[m].x*a+b,p[m].y*c+d)<=t||(dist(sx,sy,p[m].x*a+b,p[m].y*c+d)>t&&p[m].x*a+b<sx&&p[m].y*c+d<sy)){
		m++,p[m].x=p[m-1].x*a+b,p[m].y=p[m-1].y*c+d;
	}
	for(int i=1;i<=m;i++){
		int lasx=sx,lasy=sy,tot=0,j;cnt=0;
		for(j=i;j>0&&cnt+dist(lasx,lasy,p[j].x,p[j].y)<=t;j--){
			cnt+=dist(lasx,lasy,p[j].x,p[j].y);
			lasx=p[j].x,lasy=p[j].y,tot++;
		}
		if(j!=0){ans=max(ans,tot);continue;}
		lasx=p[1].x,lasy=p[1].y;
		for(j=i+1;j<=m&&cnt+dist(lasx,lasy,p[j].x,p[j].y)<=t;j++){
			cnt+=dist(lasx,lasy,p[j].x,p[j].y);
			lasx=p[j].x,lasy=p[j].y,tot++;
		}
		ans=max(ans,tot);
	}
	printf("%lld\n",ans);
	return 0;
}