#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 1e11;
const int mm = 2e5 + 10;
struct node{
	ll p,id,k;
	node(){}
	node(ll p,ll id,ll k):p(p),id(id),k(k){}
	friend bool operator < (node a,node b){
		return a.p==b.p?a.k<b.k:a.p<b.p;
	}
}a1[mm],a2[mm];
ull s[mm],val[mm];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	srand(time(NULL));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		val[i]=(ull)(rand()<<31|rand());
		ll x,y,z,w;
		cin>>x>>y>>z>>w;
		a1[i*2-1]=node(x,i,0);
		a1[i*2]=node(y,i,1);
		a2[i*2-1]=node(z,i,0);
		a2[i*2]=node(w,i,1);
	}int N=n*2;
	sort(a1+1,a1+1+N);
	sort(a2+1,a2+1+N);
	ll Xor=0;
	for(int i=1;i<=N;i++){
		if(a1[i].k)Xor^=val[a1[i].id];
		else s[a1[i].id]^=Xor;
	}Xor=0;
	for(int i=N;i>=1;i--){
		if(!a1[i].k)Xor^=val[a1[i].id];
		else s[a1[i].id]^=Xor;
	}Xor=0;
	for(int i=1;i<=N;i++){
		if(a2[i].k)Xor^=val[a2[i].id];
		else s[a2[i].id]^=Xor;
	}Xor=0;
	for(int i=N;i>=1;i--){
		if(!a2[i].k)Xor^=val[a2[i].id];
		else s[a2[i].id]^=Xor;
	}
	for(int i=1;i<=n;i++){
		if(s[i]>0){
			cout<<"NO";
			return 0;
		}
	}cout<<"YES";
}
