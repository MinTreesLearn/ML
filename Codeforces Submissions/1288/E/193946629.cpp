 //#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")

#include "bits/stdc++.h" 
#define F first
#define S second
#define me "| Temirlan |"
#define ALL(a) a.begin() , a.end()

#define OK  cout << "---------------------------OK-----------------------" << endl;
#define deb(x) cout << #x  << " = " << x << endl;

//#define endl '\n'
#define int long long
using namespace std ;


const int N =  6e5  + 7;
const int INF = 1e9 + 7 ;
const int mod = 1e9 + 7 ;
const double eps = 1e-9 ;
const int dx[4]  = { 0 , 0 , 1 , -1} , dy[4] = {1 , -1 , 0 , 0} ;
int n , m , k , x , a[N] , mx[N] , mn[N]  , p[N] , t[N];

void upd(int v ,int x){
	while(v < N){
		t[v] += x;
		v += v & -v ;
	}
}

int get(int v ){
	int s = 0 ;
	while(v ){
		s += t[v] ;
		v -= v & -v ;
	}
	return s;
}
void test(){
	cin >> n >> m ;
	for(int i =1 ; i<=n ; i++){
		mx[i] = i  ;
		mn[i] = i ;
		p[i] = i + m ;
		upd(p[i] , 1) ;
	}
	for(int i = m  ; i >= 1; i--){
		int x ;
		cin >> x ;
		mn[x] = 1 ;
		mx[x] = max(mx[x] , get(p[x]));
		upd(p[x] , -1 ) ;
		p[x] = i ;
		upd(p[x] , 1) ;
	//	deb(mx[x]) ;
	}

	for(int i =1 ; i <= n; i++){
		mx[i] = max(mx[i] , get(p[i]) ) ;
	}

	for(int i =1 ; i<= n; i++){
		cout << mn[i] << " " << mx[i] << endl;
	}
}
signed main(){
    ios_base::sync_with_stdio(false) ;	
    cin.tie(0) ;
    cout.tie(0);
//  freopen("floor.in" , "r" , stdin) ;
//  freopen("floor.out" , "w" , stdout) ;
    int t = 1;
	//cin >> t ;
    for(int i = 1 ; i <= t ;i++ ){
    	test() ;
    } 
    return 0; 
} 
 