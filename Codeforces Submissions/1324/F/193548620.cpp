// LUOGU_RID: 102122836
#include <bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 5;
int n;
int col[_] , dp1[_] , dp2[_];
vector< int > G[_];

void DFS1( int x , int fa ) {
	dp1[ x ] = col[ x ];
	for( int i = 0 ; i < G[ x ].size() ; i++ ) {
		if( G[ x ][ i ] != fa ) {
			DFS1( G[ x ][ i ] , x );
			dp1[ x ] += max( 0 , dp1[ G[ x ][ i ] ] );
		}
	}
}

void DFS2( int x , int fa ) {
	if( x != 1 ) dp2[ x ] = max( dp2[ fa ] - max( 0 , dp1[ x ] ) , 0 ) + dp1[ x ];
	for( int i = 0 ; i < G[ x ].size() ; i++ ) {
		if( G[ x ][ i ] != fa )
			DFS2( G[ x ][ i ] , x );
	}
}

int main() {
	cin >> n;
	for( int i = 1 , x ; i <= n ; i++ ) {
		cin >> x;
		col[ i ] = x * 2 - 1;
	}
	for( int i = 1 , u , v ; i < n ; i++ ) {
		cin >> u >> v;
		G[ u ].push_back( v );
		G[ v ].push_back( u );
	}
	DFS1( 1 , 0 );
	dp2[ 1 ] = dp1[ 1 ];
	DFS2( 1 , 0 );
	for( int i = 1 ; i <= n ; i++ ) cout << dp2[ i ] << " \n"[ i == n ];
	return 0;
}