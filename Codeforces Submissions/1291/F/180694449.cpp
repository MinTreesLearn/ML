// LUOGU_RID: 93829825
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=1e4+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,k,flag[maxn],x,ans=0,z=0;
int g[1055][1055];
char a[5];
void query(int x){
	cout<<"? "<<x<<endl;
	fflush(stdout);
	scanf("%s",a);
	if(a[0]=='Y')flag[x]=1;
}
void solve(int x,int y){
	cout<<"R \n";
	fflush(stdout);
	for(int i=0;i<k/2;i++)
		query(g[x][i]);
	for(int i=0;i<k/2;i++)
		query(g[y][i]);
}
void add(int x,int y){
	cout<<"R \n";
	fflush(stdout);
	for(int i=x;i<=z;i+=y){
		for(int j=0;j<k/2;j++)
			query(g[i][j]);
	}
}
signed main(){
	n=read(),k=read();
	if(n<=k){
		for(int i=1;i<=n;i++){
			query(i);ans+=!flag[i];
		}
		cout<<"! "<<ans<<endl;
		fflush(stdout);
		exit(0);
	}
	if(k==1){
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++){
				cout<<"R \n";
				fflush(stdout);
				query(j),query(i);
				if(flag[i])break;
			}
		for(int i=1;i<=n;i++)
		if(!flag[i])ans++;
		cout<<"! "<<ans<<endl;
		fflush(stdout);exit(0);
	}z=0;
	for(int i=1;i<=n;i+=k/2){++z;
		for(int j=0;j<k/2;j++)
			g[z][j]=i+j;
	}
	for(int i=1;i<=z;i++){
		for(int j=1;j<=i;j++){
			if(j+i<=z){
				add(j,i);
			}
		}
	}	
	for(int i=1;i<=n;i++)
		if(!flag[i])ans++;
	cout<<"! "<<ans<<endl;
	fflush(stdout);
 	return 0;
}