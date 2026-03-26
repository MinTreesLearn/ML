// LUOGU_RID: 99403697
#include<bits/stdc++.h>
using namespace std;
#define N 1050
int n,k,a[N],ans;
bool flag[N];
int read(){
	char ch[2];
	scanf("%s",ch);
	return ch[0]=='Y';
}
int main(){
	scanf("%d%d",&n,&k);
	int x,b;
	if(k==1){
		ans=1;
		for(int i=2;i<=n;i++){
			bool f=1;
			for(int j=1;j<i;j++){
				cout<<"? "<<j<<endl;
				x=read();
				cout<<"? "<<i<<endl;
				x=read();
				if(x){
					f=0;
					break;
				}
			}
			ans+=f;
		}
		printf("! %d",ans);
		return 0;
	}
	k>>=1,b=n/k,ans=0;
	for(int i=1;i<=k;i++){
		cout<<"? "<<i<<endl;
		x=read();
		if(!x)ans++;
	}
	cout<<"R"<<endl;
	for(int i=2;i<=b;i++){
		memset(flag,0,sizeof(flag));
		for(int j=1;j<i;j++){
			for(int l=(j-1)*k+1;l<=j*k;l++){
				cout<<"? "<<l<<endl;
				x=read();
			}
			for(int l=(i-1)*k+1;l<=i*k;l++){
				cout<<"? "<<l<<endl;
				x=read();
				if(x)flag[l-(i-1)*k]=1;
			}
			cout<<"R"<<endl;
		}
		for(int j=1;j<=k;j++)
			if(!flag[j])ans++;
	}
	cout<<"! "<<ans<<endl;
	return 0;
}