#include <bits/stdc++.h>
using namespace std;
typedef double db;
#define int long long
#define fi first
#define se second
#define mk make_pair
#define pb emplace_back
#define poly vector<int>
#define Bt(a) bitset<a>
#define bc __builtin_popcount
#define pc putchar
#define ci const int&
const int mod = 1e9+7;
const db eps = 1e-10;
inline int Max(ci x, ci y) {return x > y ? x : y;}
inline int Min(ci x, ci y) {return x < y ? x : y;}
inline db Max(db x, db y) {return x - y > eps ? x : y;}
inline db Min(db x, db y) {return x - y < eps ? x : y;}
inline int Add(ci x, ci y, ci M = mod) {return (x + y) % M;}
inline int Mul(ci x, ci y, ci M = mod) {return 1ll * x * y % M;}
inline int Dec(ci x, ci y, ci M = mod) {return (x - y + M) % M;}
typedef pair<int, int> pii;
inline int Abs(int x) {return x < 0 ? -x : x;}
//char buf[1<<21],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char Obuf[105000],*O=Obuf;//Siz shoule be the size of Out File
int pst[30],ptop;
inline void Fprint(){fwrite(Obuf,1,O-Obuf,stdout);}
inline void Fwrite(int x){
  if(x==0){*O++='0';if(O-Obuf>100000)Fprint(),O=Obuf;return;}
  if(x<0)*O++='-',x=-x;ptop=0;
  while(x)pst[++ptop]=x%10,x/=10;
  while(ptop)*O++=pst[ptop--]+'0';
  if(O-Obuf>100000)Fprint(),O=Obuf;
}
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') w = -1;ch = getchar();}
    while (isdigit(ch)) {s = s * 10 + ch - '0';ch = getchar();}
    return s * w;
}
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
	pc(x % 10 + '0');
}
inline int qpow(int x, int y) {
    int res = 1;
    while (y) {if (y & 1)res = Mul(res, x);x = Mul(x, x);y >>= 1;}
    return res;
}
inline void cadd(int &x, int y) {x += y;}
inline void cmul(int &x, int y) {x *= y;}
inline void cmax(int &x, int y) {x = Max(x, y);}
inline void cmin(int &x, int y) {x = Min(x, y);}
const int N = 2e6 + 10;
namespace CG{

	struct P{
		db x, y;
		P(db x_ = 0, db y_ = 0){
			x = x_; y = y_;
		}
		db len() {
			return sqrt(x * x + y * y);
		}
		P mid() {
			return P(x / 2.0, y / 2.0);
		}
		db theta() {
			return atan2(y, x);
		}
	};
	P operator + (P x, P y) {return P(x.x + y.x, x.y + y.y);}
	P operator - (P x, P y) {return P(x.x - y.x, x.y - y.y);}
	P operator * (P x, db y) {return P(x.x * y, x.y * y);}
	P operator * (db y, P x) {return P(x.x * y, x.y * y);}
	db operator * (P x, P y) {return x.x * y.x + x.y * y.y;}
	db operator ^ (P a, P b) {return a.x * b.y - a.y * b.x;}
	struct Line {
		P x, y; db k;
		Line (P _x = P(0, 0), P _y = P(0, 0)) {
			x = _x; y = _y - _x; k = _y.theta();
		}
	};

	inline db sq(db x) {return x * x;}
	inline db dis(P x, P y) {return sqrt(sq(x.x - y.x) + sq(x.y - y.y));}
	inline db fdis(P x, P y) {return sq(x.x - y.x) + sq(x.y - y.y);}
	P crossover(Line x, Line y) {
		P C = x.x - y.x;
		db t = (y.y ^ C) / (x.y ^ y.y);
		return x.x + x.y * t;
	}
}
namespace Refined_heart{
	int n, k;
	int a[101][101];
	int f[101][101];
	int sd = 20060727 ^ time(0);
	int col[101];
	int ans = (1LL << 60);
	void solve(){
		n = read(); k = read();
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				a[i][j] = read();
			}
		}
		for(int T = 1; T <= 5000; ++T) {
			sd += (T & 1) ? 20060710 : 20060727; sd ^= 1234567; srand(sd);
			for(int i = 1; i <= n; ++i) col[i] = rand() & 1;
			for(int i = 1; i <= n; ++i) {
				for(int j = 0; j <= k; ++j) {
					f[i][j] = (1LL << 60);
				}
			}
			f[1][0] = 0;
			for(int j = 1; j <= k; ++j) {
				for(int i = 1; i <= n; ++i) {
					if(f[i][j - 1] > 10000000000ll) continue;
					for(int l = 1; l <= n; ++l) {
						if(col[l] == col[i]) continue;
						f[l][j] = Min(f[l][j], f[i][j - 1] + a[i][l]);
					}
				}
			}
			ans = Min(ans, f[1][k]);
		}
		cout << ans << '\n';
	}
}
signed main(){
	Refined_heart::solve();
	return 0;
}
