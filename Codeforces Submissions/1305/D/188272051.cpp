#include<bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
#define LL long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=200010,MOD=1e9+7;
typedef pair<int,int> PII;
int e[N],ne[N],h[N],w[N],idx=0;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
LL n,z,x,y,a,b,d[N];
queue<int> q;
int main(){
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<n;i++){
		cin>>a>>b;
		add(a,b);
		add(b,a);
		d[a]++;
		d[b]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1) q.push(i);
	}
	while(q.size()>1){
		int x=q.front();
		q.pop();
		int y=q.front();
		q.pop();
		for(int i=h[x];i!=-1;i=ne[i]){
			int j=e[i];
			d[j]--;
			if(d[j]==1) q.push(j);
		}
		for(int i=h[y];i!=-1;i=ne[i]){
			int j=e[i];
			d[j]--;
			if(d[j]==1) q.push(j);
		}
		cout<<"? "<<x<<" "<<y<<endl;
		cin>>z;
		if(x==z){
			cout<<"! "<<x<<endl;
			break;
		}else if(y==z){
			cout<<"! "<<y<<endl;
			break;
		}
	}
	if(q.size()==1) cout<<"! "<<q.front()<<endl;
}
 	 	 		 	 	  	  	  		 			  	 	