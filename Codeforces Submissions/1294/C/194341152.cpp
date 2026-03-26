 //#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define ll long long 
#define ff first
#define ss second
#define pb push_back 
#define pf push_front
#define UseOFF ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0);
#define sz size
using namespace std ;
const ll N = 1e6 + 111 ;
const ll mod = 1e9 + 7 ;
ll a[ N ] ;
ll num ;
int main()
{
    UseOFF
    //freopen( "A.in","r",stdin ) ;
    //freopen("A.out","w",stdout) ;
    //underidoderidoderooderiododoogovehment ( Winston Cherchil ) ;
    ll t ;
    cin >> t ;
    while( t-- )
    {
        ll n ;
        cin >> n ; 
        ll a = 0, b = 0, c = 0 ;
        for( int i = 2 ; i <= sqrt( n ) ; i++ )
        {
            if( n % i == 0 )
            {
                a = i ;
                n /= i ;
                break ;
            }
        }
        for( int i = 2 ; i <= sqrt( n ) ; i++ )
        {
            if( n % i == 0 && i != a )
            {
                b = i ; 
                if( n / b != b )
                {
                    c = n / b ;
                }
                break ;
            }
        }
        if( a > 0 && b > 0 && c > 0 ) cout << "YES" << '\n' << a << " " << b << " " << c << '\n' ;
        else cout << "NO" << '\n' ;
    }
}