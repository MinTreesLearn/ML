#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())

using u16=uint16_t;
using u64=uint64_t;

const int small=1<<16;
const u16 g=-1;
u16 Log[small],pw[small];

template<bool flag=1>
u64 nim_mul(u64 a, u64 b, int mid=32){
	if(a<=1||b<=1) return a*b;
	if(flag&&a<small&&b<small){
		int x=Log[a]+Log[b];
		if(x>=small-1) x-=small-1;
		return pw[x];
	}
	u64 s=(1ULL<<mid)-1;
	u64 a0=a&s,a1=a>>mid,b0=b&s,b1=b>>mid;
	u64 val1=nim_mul<flag>(a0,b0,mid/2),val2=nim_mul<flag>(a0^a1,b0^b1,mid/2),val3=nim_mul<flag>(a1,b1,mid/2);
	return val1^((val1^val2)<<mid)^nim_mul<flag>(val3,1ULL<<(mid-1),mid/2);
}

void init(){
	pw[0]=1;
	for(int i=1; i<small-1; ++i) pw[i]=nim_mul<0>(pw[i-1],g,8);
	for(int i=0; i<small-1; ++i) Log[pw[i]]=i;
}

u64 Pow(u64 x, u64 y){u64 res=1; for(; y; x=nim_mul(x,x),y>>=1) if(y&1) res=nim_mul(res,x); return res;}
const u64 p[7]={3,5,17,257,641,65537,6700417};
u64 s[7];
u64 inv(u64 x){return Pow(x,-2);}

u64 ord(u64 x){
	u64 res=-1;
	for(int i=0; i<7; ++i) if(Pow(x,res/p[i])==1) res/=p[i];
	return res;
}

u64 solve(u64 x, u64 y, int id){
	//ord(x)=ord(y)=p[id]
	//x^?=y
	u64 x_1=inv(x);
	vector<pair<u64,int>> vec(s[id]+5);
	vec[0]={y,0};
	for(int i=1; i<vec.size(); ++i) vec[i]={nim_mul(vec[i-1].first,x_1),i};
	sort(all(vec));
	x=Pow(x,s[id]);
	u64 cur=1;
	for(int i=0; i<vec.size(); ++i){
		auto it=lower_bound(all(vec),pair<u64,int>(cur,-1));
		if(it!=vec.end()&&(*it).first==cur) return s[id]*i+(*it).second;
		cur=nim_mul(cur,x);
	}
	assert(0);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    init();
    for(int i=0; i<7; ++i) s[i]=sqrt(p[i]);
    int t;
	cin >> t;
	while(t--){
		u64 a,b,bb,n,m,res;
		cin >> a >> b;
		n=ord(a),m=ord(b);
		bb=b;
		if(n%m){
			cout << "-1\n";
			continue;
		}
		res=0;
		while(m>1){
			int id=-1;
			for(int i=0; i<7; ++i) if(m%p[i]==0) id=i;
			u64 t=solve(Pow(a,n/p[id]),Pow(b,m/p[id]),id),g=Pow(a,n/m);
			res+=t*(n/m);
			b=nim_mul(b,Pow(g,-1-t));
			m=ord(b);
		}
		assert(Pow(a,res)==bb);
		cout << res << "\n";
	}
}