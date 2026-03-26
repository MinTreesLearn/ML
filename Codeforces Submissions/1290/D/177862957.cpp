// LUOGU_RID: 91499649
#include<bits/stdc++.h>
using namespace std;
int const M=1233;char ch;bool a[M];
int i,j,n,k,bound,Ans,l[M],r[M];
void clr(){cout<<"R"<<endl;}
bool ask(int x){
	cout<<"? "<<x<<endl;
	cin>>ch;return ch=='Y';
}
void solve(int x){
	for (int i=l[x];i<=r[x];i++)
		if (a[i]&&ask(i)) a[i]=0;
}
int main(){
	cin>>n>>k;bound=n/k;for (i=1;i<=n;i++) a[i]=1;
	for (i=1;i<=bound;i++) l[i]=r[i-1]+1,r[i]=i*k;
	for (i=1;i<=bound;clr(),i++)
		for (j=1;j<=bound;j++)
			if (j&1) solve((i-j/2+bound-1)%bound+1);
			else solve((i+j/2-1)%bound+1);
	for (i=1;i<=n;i++) Ans+=a[i];
	return cout<<"! "<<Ans<<endl,0;
}