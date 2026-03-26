#include<bits/stdc++.h>
using namespace std;
const int N=6,V=5,L=31,mod=998244353;
int f[L][N*V][N*V][N*V][N*V][2][2];
int x[N],y[N];
int n,m;

int calc(int p,int px,int nx,int py,int ny,int gx,int gy){
if(p==L-1)return (!px&&!nx&&!py&&!ny&&!gx&&!gy);
int &f=::f[p][px][nx][py][ny][gx][gy];
if(f!=-1)return f;
f=0;
int w=(m>>p)&1;
for(int i=0;i<1<<n;i++){
int pxx=px,nxx=nx,pyy=py,nyy=ny;
for(int j=0;j<n;j++)if((i>>j)&1){
(x[j]<0?nxx:pxx)+=abs(x[j]);
(y[j]<0?nyy:pyy)+=abs(y[j]);
}
int pxxx=pxx&1,nxxx=nxx&1,pyyy=pyy&1,nyyy=nyy&1;
if(pxxx!=nxxx||pyyy!=nyyy)continue;
f=(f+calc(p+1,pxx>>1,nxx>>1,pyy>>1,nyy>>1,w==pxxx?gx:pxxx>w,w==pyyy?gy:pyyy>w))%mod;
}
return f;
}
int main(){
cin>>n>>m;
for(int i=0;i<n;i++)cin>>x[i]>>y[i];
memset(f,-1,sizeof(f));
cout<<(calc(0,0,0,0,0,0,0)+mod-1)%mod<<endl;
}
