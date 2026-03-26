#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)b; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define ms(x, y) memset(x, y, sizeof(x))
#define SZ(x) int(x.size())
#define fk cerr<<"fk"<<endl
#define db(x) cerr<<(#x)<<'='<<(x)<<endl
#define db2(x,y) cerr<<(#x)<<'='<<(x)<<' '<<(#y)<<'='<<(y)<<endl
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define ll long long
ll dis[100][15];
ll d[100][100];
int c[110];
int n,k;
ll solve(){
	for(int i=1;i<=n;i++){
		c[i]=rand()%2;
		for(int j=0;j<=k;j++)dis[i][j]=1e15;
	}
	dis[1][0]=0ll;
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(c[i]^c[j])dis[j][l]=min(dis[j][l],dis[i][l-1]+d[i][j]);
			}
		}
	}
	return dis[1][k];
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    srand(time(NULL));
    cout<<fixed;
	#ifdef LOCAL_DEFINE
    	freopen("tmp.in", "r", stdin);
    	freopen("tmp.out", "w", stdout);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	int t=clock();
	ll ans=1e15;
	while(clock()-t<2850){
		ans=min(ans,solve());
	}
	cout<<ans<<endl;
}
