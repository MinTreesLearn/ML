#include<bits/stdc++.h>
#define fx for(int y=1;y<=m;++y)for(int z=1;z<=k;++z)
#define fy for(int x=1;x<=n;++x)for(int z=1;z<=k;++z)
#define fz for(int x=1;x<=n;++x)for(int y=1;y<=m;++y)
using namespace std;
const int N=2e5+7;
int n,m,k,a[N],f[6][N];
vector<pair<int,int> >tg[N];
const int dx[6]={1,-1,0,0,0,0};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};
bool chk(int x,int y,int z){
	if(x<1||x>n)
		return 0;
	if(y<1||y>m)
		return 0;
	if(z<1||z>k)
		return 0;
	return 1;
}
int id(int x,int y,int z){
	return m*k*(x-1)+k*(y-1)+z;
}
int idx(int y,int z){
	return k*(y-1)+z;
}
int idy(int x,int z){
	return k*(x-1)+z;
}
int idz(int x,int y){
	return m*(x-1)+y;
}
void clr(int x,int y,int z,int d){
	while(1){
		x+=dx[d];
		y+=dy[d];
		z+=dz[d];
		if(!chk(x,y,z))
			break;
		a[id(x,y,z)]=0;
	}
}
void upd(int x,int y,int z,int d,int c){
	while(1){
		x+=dx[d];
		y+=dy[d];
		z+=dz[d];
		if(!chk(x,y,z))
			break;
		if(!a[id(x,y,z)])
			continue;
		if(tg[id(x,y,z)].empty()||tg[id(x,y,z)][0].first==c){
			tg[id(x,y,z)].emplace_back(c,d);
			break;
		}
		a[id(x,y,z)]=0;
		for(auto u:tg[id(x,y,z)])
			upd(x,y,z,u.second,u.first);
		tg[id(x,y,z)].clear();
	}
}
void col(int x,int y,int z,int d,int c){
	while(1){
		x+=dx[d];
		y+=dy[d];
		z+=dz[d];
		if(!chk(x,y,z)){
			puts("-1");
			exit(0);
		}
		if(!a[id(x,y,z)])
			continue;
		a[id(x,y,z)]=tg[id(x,y,z)][0].first;
		if(a[id(x,y,z)]^c){
			puts("-1");
			exit(0);
		}
		break;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(a,-1,sizeof(a));
	fx scanf("%d",f[0]+idx(y,z));
	fx scanf("%d",f[1]+idx(y,z));
	fy scanf("%d",f[2]+idy(x,z));
	fy scanf("%d",f[3]+idy(x,z));
	fz scanf("%d",f[4]+idz(x,y));
	fz scanf("%d",f[5]+idz(x,y));
	fx if(!f[0][idx(y,z)]) clr(0,y,z,0);
	fx if(!f[1][idx(y,z)]) clr(n+1,y,z,1);
	fy if(!f[2][idy(x,z)]) clr(x,0,z,2);
	fy if(!f[3][idy(x,z)]) clr(x,m+1,z,3);
	fz if(!f[4][idz(x,y)]) clr(x,y,0,4);
	fz if(!f[5][idz(x,y)]) clr(x,y,k+1,5);
	fx if(f[0][idx(y,z)]) upd(0,y,z,0,f[0][idx(y,z)]);
	fx if(f[1][idx(y,z)]) upd(n+1,y,z,1,f[1][idx(y,z)]);
	fy if(f[2][idy(x,z)]) upd(x,0,z,2,f[2][idy(x,z)]);
	fy if(f[3][idy(x,z)]) upd(x,m+1,z,3,f[3][idy(x,z)]);
	fz if(f[4][idz(x,y)]) upd(x,y,0,4,f[4][idz(x,y)]);
	fz if(f[5][idz(x,y)]) upd(x,y,k+1,5,f[5][idz(x,y)]);
	fx if(f[0][idx(y,z)]) col(0,y,z,0,f[0][idx(y,z)]);
	fx if(f[1][idx(y,z)]) col(n+1,y,z,1,f[1][idx(y,z)]);
	fy if(f[2][idy(x,z)]) col(x,0,z,2,f[2][idy(x,z)]);
	fy if(f[3][idy(x,z)]) col(x,m+1,z,3,f[3][idy(x,z)]);
	fz if(f[4][idz(x,y)]) col(x,y,0,4,f[4][idz(x,y)]);
	fz if(f[5][idz(x,y)]) col(x,y,k+1,5,f[5][idz(x,y)]);
	for(int x=1;x<=n;++x,puts(""))
	for(int y=1;y<=m;++y)
	for(int z=1;z<=k;++z){
		if(!~a[id(x,y,z)])
			a[id(x,y,z)]=18260;
		printf("%d%c",a[id(x,y,z)]," \n"[z==k]);
	}
	return 0;
}