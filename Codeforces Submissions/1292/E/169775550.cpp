//llllljy
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int t,n,vis[maxn],czc;
void solve1(){
	int x,y;
	memset(vis,0,sizeof(vis));
	printf("? CH\n");fflush(stdout);scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=1,vis[y+1]=3;
	printf("? CC\n");fflush(stdout);scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=1,vis[y+1]=1;
	printf("? CO\n");fflush(stdout);scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=1,vis[y+1]=2;
	printf("? OO\n");fflush(stdout);scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=2,vis[y+1]=2;
	printf("? HO\n");fflush(stdout);scanf("%d",&x);
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=3,vis[y+1]=2;
	for(int i=2;i<n;i++)if(vis[i]==0)vis[i]=3;
	
	int flag1=1,flagn=1;
	if(vis[1]==0)flag1=0;
	if(vis[n]==0)flagn=0;

	if(!flag1)vis[1]=3;
	if(!flagn)vis[n]=1;//H C
	printf("? ");
	fflush(stdout);
	for(int i=1;i<=n;i++){
		if(vis[i]==1)printf("C");
		if(vis[i]==2)printf("O");
		if(vis[i]==3)printf("H");
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);scanf("%d",&y);
	for(int i=1;i<=y;i++)scanf("%d",&x);
	if(y!=0)return ;
	
	if(!flag1)vis[1]=3;
	if(!flagn)vis[n]=3;//H H
	printf("? ");
	fflush(stdout);
	for(int i=1;i<=n;i++){
		if(vis[i]==1)printf("C");
		if(vis[i]==2)printf("O");
		if(vis[i]==3)printf("H");
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);scanf("%d",&y);
	for(int i=1;i<=y;i++)scanf("%d",&x);
	if(y!=0)return ;
	
	if(!flag1)vis[1]=2;
	if(!flagn)vis[n]=1;//O C
	printf("? ");
	fflush(stdout);
	for(int i=1;i<=n;i++){
		if(vis[i]==1)printf("C");
		if(vis[i]==2)printf("O");
		if(vis[i]==3)printf("H");
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);scanf("%d",&y);
	for(int i=1;i<=y;i++)scanf("%d",&x);
	if(y!=0)return ;

	if(!flag1)vis[1]=2;
	if(!flagn)vis[n]=3;//O H
}
int check(){
	int y,x;
	printf("? ");
	fflush(stdout);
	for(int i=1;i<=n;i++){
		if(vis[i]==1)printf("C");
		if(vis[i]==2)printf("O");
		if(vis[i]==3)printf("H");
	}
	printf("\n");
	fflush(stdout);scanf("%d",&y);
	for(int i=1;i<=y;i++)scanf("%d",&x);
	if(y!=0)return 1;
	return 0;
}
void solve2(){//牛马啊 
	int x,y;
	memset(vis,0,sizeof(vis));
	int num=0;
	printf("? CO\n");fflush(stdout);scanf("%d",&x),num+=x;
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=1,vis[y+1]=2;
	printf("? CC\n");fflush(stdout);scanf("%d",&x),num+=x;
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=1,vis[y+1]=1;
	printf("? CH\n");fflush(stdout);scanf("%d",&x),num+=x;
	for(int i=1;i<=x;i++)scanf("%d",&y),vis[y]=1,vis[y+1]=3;
	if(num!=0){//出现了！牛马czc 
		int flag1=0,flagn=0;
		if(vis[1]==1){//3,4不确定 (3不可能为C) 
			if(vis[3]==0)flag1=1;
			if(vis[4]==0)flagn=1;
			for(int i=2;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(flag1)vis[3]=i;
					if(flagn)vis[4]=j;
					if(check())return ;
				}
			}
		}
		else if(vis[2]==1){//二次出现牛马 
			if(vis[1]==0)flag1=1;
			if(vis[4]==0)flagn=1;
			for(int i=2;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(flag1)vis[1]=i;
					if(flagn)vis[4]=j;
					if(check())return;
				}
			}
		}else{//第三只（也是最后一只牛马） 
			if(vis[1]==0)flag1=1;
			if(vis[2]==0)flagn=1;
			for(int i=2;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(flag1)vis[1]=i;
					if(flagn)vis[2]=j;
					if(check())return ;
				}
			}
		}
		return ;
	}
//	牛马预处理 
	
	printf("? HO\n");fflush(stdout);scanf("%d",&x);
	if(x!=0){
		if(x==2){
			scanf("%d%d",&y,&y);
			vis[1]=3,vis[2]=2,vis[3]=3,vis[4]=2;
			return ;
		}
		scanf("%d",&y);
		vis[y]=3,vis[y+1]=2;
		int lid,rid;
		if(y==1)lid=3,rid=4;
		if(y==2)lid=1,rid=4;
		if(y==3)lid=1,rid=2;
		int flag1=0,flagn=0;
		if(vis[lid]==0)flag1=1;
		if(vis[rid]==0)flagn=1;
		for(int i=2;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(flag1)vis[lid]=i;
				if(flagn)vis[rid]=j;
				if(check())return ;
			}
		}
	}
	
	//最后一步！ OO
	
	printf("? OO\n");fflush(stdout);scanf("%d",&x);
	if(x==0){
		vis[2]=vis[3]=3;
		printf("? HHH\n");fflush(stdout);scanf("%d",&x);
		if(x==0){
			vis[1]=2,vis[4]=1;
			return ;
		}
		if(x==2){
			scanf("%d%d",&y,&y);
			vis[1]=vis[4]=3;
			return ;
		}
		scanf("%d",&y);
		if(y==1)vis[1]=3,vis[4]=1;
		else vis[4]=3,vis[1]=2;
	}
	else{
		if(x==1){
			scanf("%d",&y);
			vis[1]=vis[2]=2,vis[3]=3;
			int flag1=0;
			if(vis[4]==0)flag1=1;
			for(int i=1;i<=3;i+=2){
				if(flag1)vis[4]=i;
				if(check())return ;
			}
		}
		else if(x==2){
			scanf("%d%d",&y,&y);
			vis[1]=vis[2]=vis[3]=2;
			int flag1=0;
			if(vis[4]==0)flag1=1;
			for(int i=1;i<=3;i+=2){
				if(flag1)vis[4]=i;
				if(check())return ;
			}
		}else{
			scanf("%d%d%d",&y,&y,&y);
			vis[1]=vis[2]=vis[3]=vis[4]=2;
			return ;
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		if(n!=4)solve1();
		else solve2();
		printf("! ");
		fflush(stdout);
		for(int i=1;i<=n;i++){
			if(vis[i]==1)printf("C");
			if(vis[i]==2)printf("O");
			if(vis[i]==3)printf("H");
		}
		printf("\n");
		fflush(stdout);
		scanf("%d",&czc);
		if(czc==0)break;
	}
	return 0;
}
//2
//5
//CHHHH
//8
//HHHCCOOH