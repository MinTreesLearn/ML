//#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")

#include "bits/stdc++.h" 
#define F first
#define S second
#define me "| Temirlan |"
#define ALL(a) a.begin() , a.end()

#define OK  cerr << "---------------------------OK-----------------------" << endl;
#define deb(x) cerr << #x  << " = " << x << endl;

#define endl '\n'
#define ll long long 
#define int long long
using namespace std ;

const int N =  1e2 + 7;
const int INF = 1e18  + 7 ;
const int mod = 1e9 + 7 ;
const double eps = 1e-9 ;
const int dx[4]  = { 0 , 0 , 1 , -1} , dy[4] = {1 , -1 , 0 , 0} ;
int n , m , x , y  , a[N] , dnt[N] , dp[N][N][N][2] ;
void test(){
	cin >> n ;
	for(int i =  1; i <=n ; i++){
		cin >> a[i] ;
		dnt[a[i]] = 1;
	}
	int cnt[2] = {} ;
	for(int i = 1;  i <= n; i++){
		if(!dnt[i]){
			cnt[i % 2]++;
		}
	}

	for(int i = 1; i <=n ;i++){
		for(int j = 0; j <= cnt[0] ; j++){
			for(int k = 0 ; k <= cnt[1] ;k++){
				dp[i][j][k][0] = dp[i][j][k][1] = INF ;
				if(a[i]){
					if(a[i] % 2)
						dp[i][j][k][1] = min(dp[i - 1][j][k][1] , dp[i - 1][j][k][0] + 1 ) ;
					else
						dp[i][j][k][0] = min(dp[i - 1][j][k][1] + 1 , dp[i - 1][j][k][0]  )  ;
				}
				else{
					if(k > 0){
						dp[i][j][k][1] = min(dp[i - 1][j][k - 1][1] , dp[i- 1][j][k - 1][0] + 1 ) ;
					}
					if(j > 0){
						dp[i][j][k][0] = min(dp[i - 1][j - 1][k][1] + 1 , dp[i - 1][j - 1][k][0]) ;
					}
				}
			}
		}
	}

	cout << min(dp[n][cnt[0]][cnt[1]][0] , dp[n][cnt[0]][cnt[1]][1] ) << endl;
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
   