#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=6;
const int inf=0x3f3f3f3f;
const int mod=998244353;

struct mint {
	int val;
	mint():val(0) {}
	mint(ll tval) {
		if(-mod<=tval&&tval<2*mod) {
			if(tval>=mod) {
				tval-=mod;
			} 
			if(tval<0) {
				tval+=mod;
			}
		} else {
			tval%=mod;
			if(tval<0) {
				tval+=mod;
			}			
		}
		val=tval;
	}
	mint& operator += (const mint &b) {
		val=val+b.val>=mod?val+b.val-mod:val+b.val;
		return *this;
	}
	mint& operator -= (const mint &b) {
		val=val-b.val<0?val-b.val+mod:val-b.val;
		return *this;
	}
	mint& operator *= (const mint &b) {
		val=1ll*val*b.val>=mod?1ll*val*b.val%mod:val*b.val;
		return *this;
	}
	mint& operator /= (const mint &b) {
		*this*=b.inv();
		return *this;
	}
	friend mint operator + (const mint &a,const mint &b) {
		mint ans=a;
		ans+=b;
		return ans;
	}
	friend mint operator - (const mint &a,const mint &b) {
		mint ans=a;
		ans-=b;
		return ans;
	}
	friend mint operator * (const mint &a,const mint &b) {
		mint ans=a;
		ans*=b;
		return ans;
	}
	friend mint operator / (const mint &a,const mint &b) {
		mint ans=a;
		ans/=b;
		return ans;
	}
	friend bool operator < (const mint &a,const mint &b) {
		return a.val<b.val;
	}
	friend bool operator == (const mint &a,const mint &b) {
		return a.val==b.val;
	}
	friend bool operator != (const mint &a,const mint &b) {
		return a.val!=b.val;
	}
	friend istream& operator >> (istream &is,mint &x) {
		ll val;
		cin>>val;
		x.val=val%mod; 
		return is;
	}
	friend ostream& operator << (ostream &os,const mint &x) {
		os<<x.val;
		return os;
	}
	mint qpow(ll y) const {
		mint x=*this,ans=1;
		while(y) {
			if(y&1) {
				ans*=x;
			} 
			x*=x;
			y>>=1;
		}
		return ans;
	}
	mint inv() const {
		// mod must be a prime
		return qpow(mod-2);
	}
	mint sqrt() {
		mint a=*this; 
		auto check=[&](mint x) {
			return x.qpow((mod-1)/2)==1;
		};
		static mt19937 rnd(73385);
		mint b=rnd()%mod;
		while(check(b*b-a)) {
			b=rnd()%mod;
		}
		static mint val=b*b-a;
		struct Complex {
			mint real,imag;
			Complex(mint treal=0,mint timag=0):real(treal),imag(timag) {}
			Complex operator * (const Complex &rhs) {
				return {real*rhs.real+imag*rhs.imag*val,real*rhs.imag+imag*rhs.real};
			}
			Complex& operator *= (const Complex &rhs) {
				return *this=*this*rhs;
			}
		};
		auto qpow=[&](Complex x,int y) {
			Complex ans={1};
			while(y) {
				if(y&1) {
					ans*=x;
				}
				x*=x;
				y>>=1;
			}
			return ans;
		};
		mint ans=qpow({b,1},(mod+1)/2).real;
		return min(ans,mod-ans);
	}
};

int n,m;
int dx[maxn];
int dy[maxn];
bool vis[35][25][25][25][25][2][2];
mint f[35][25][25][25][25][2][2];

#define state p][x][nx][y][ny][fx][fy
mint dfs(int p,int x,int nx,int y,int ny,bool fx,bool fy) {
	if(vis[state]) {
		return f[state];
	}
	if(p==30) {
		return !x&&!nx&&!y&&!ny&&fx&&fy;
	}
	auto ck=[&](bool f,int x,int m) {
		return x!=m?x<m:f;
	};
	mint ans=0;
	for(int s=0;s<=(1<<n)-1;s++) {
		auto trans=[&](int v) {
			for(int i=1;i<=n;i++) {
				if((s>>(i-1))&1) {
					if(dx[i]>=0) {
						x+=dx[i]*v;
					} else {
						nx-=dx[i]*v;
					}
					if(dy[i]>=0) {
						y+=dy[i]*v;
					} else {
						ny-=dy[i]*v;
					}
				}
			}//
		};
		trans(1);
		if((x&1)==(nx&1)&&(y&1)==(ny&1)) {
			ans+=dfs(p+1,x>>1,nx>>1,y>>1,ny>>1,ck(fx,(x&1),(m>>p)&1),ck(fy,(y&1),(m>>p)&1));
		}
		trans(-1);
	}
//	cerr<<p<<" "<<x<<" "<<nx<<" "<<y<<" "<<ny<<" "<<fx<<" "<<fy<<": "<<ans<<"\n";
	vis[state]=true;
	return f[state]=ans;
}

signed main() {//asd
//	freopen("d.in","r",stdin);
//	freopen("m.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	m++;
	for(int i=1;i<=n;i++) {
		cin>>dx[i]>>dy[i];
	}
	cout<<dfs(0,0,0,0,0,0,0)-1<<"\n";
}