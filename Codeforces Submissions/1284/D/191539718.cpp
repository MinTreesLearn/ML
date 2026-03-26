#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 1e11;
const int mm = 1e5 + 10;
struct node{
	int x,f,s,p;
	node(){}
	node(int x,int f,int s,int p):x(x),f(f),s(s),p(p){}
	friend operator <(node a,node b){
		return a.x==b.x?a.p>b.p:a.x<b.x;
	}
};
int a[mm],b[mm],c[mm],d[mm],n;
bool check(){
	multiset<int>f,s;
	vector<node>v;
	for(int i=1;i<=n;i++){
		auto x=node(a[i],c[i],d[i],1);
		auto y=node(b[i],c[i],d[i],0);
		v.push_back(x);
		v.push_back(y);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<2*n;i++){
		if(v[i].p){
			if(f.size()){
				int x=*(--f.end()),y=(*s.begin());
				if(x>v[i].s||y<v[i].f)return 0;
			}
			f.insert(v[i].f),s.insert(v[i].s);
		}else f.erase(f.find(v[i].f)),s.erase(s.find(v[i].s));
	}return 1;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	int flog=check();
	swap(a,c),swap(b,d);
	int bj=check();
	if(flog&&bj)cout<<"YES";
	else cout<<"NO";
}
