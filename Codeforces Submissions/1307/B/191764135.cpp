/*                  ________
                   /        \
                  / /      \ \
         ________/ /        \ \________
        /        \            /        \
       / /      \ \  ______  / /      \ \
      / /        \ \________/ /        \ \
      \            /        \            /
       \  ______  / /      \ \  ______  /
        \________/ /        \ \________/
        /        \            /        \
       / /      \ \  ______  / /      \ \
      / /        \ \________/ /        \ \
      \            /        \            /
       \  ______  / /      \ \  ______  /
        \________/ /        \ \________/
                 \            /
                  \  ______  /
                   \________/
*/
#include <bits/stdc++.h>

typedef long long ll ;
typedef long double ld ;

#define endl '\n'
#define T ll tt ; cin >> tt ; while (tt--)
#define pb push_back
#define F first
#define S second
using namespace std ;
const int N = 1e6 + 9 ;
const ll M = 1e9 + 7 ;
ll dx[] = {0 , 0 , -1 , 1} ;
ll dy[] = {1 , -1 , 0 , 0} ;
vector <ld> v , v1 ;
ll n , m , x , y , z , x1 , y1 , k , l , r , L , R , len , mid , cntt , cntt1 , g , h , q , id , ind , idx , sum , sum1 , cnt , ans , maxxx , maxx = -1e11 , minn = 1e11 , a[N] , b[N] , c , d ;
ll pi = 3.1415926535897932384626433832795 ;
string s , t ;
bool f , ff ;
ll fp(ll x , ll y)
{
    if(y == 0)
        return 1 ;
    if(y == 1)
        return x ;
    ll ret = fp(x , y / 2) ;
    ret = (ret * ret) % M ;
    if(y % 2)
        ret = (ret * x) % M ;
    return ret ;
}

int32_t main()
{
    ios :: sync_with_stdio(false) ; cin.tie(0) ;

    T {
        f = ff = 0 ;
        cin >> n >> k ;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i] ;
            if (a[i] == k)
                f = 1 ;
            else if (a[i] > k)
                ff = 1 ;
        }
        if (f) {
            cout << 1 << endl ;
            continue ;
        }
        if (ff) {
            cout << 2 << endl ;
            continue ;
        }
        sort (a , a + n) ;
        cout << (k - 1) / *max_element(a ,a + n) + 1 << endl ;
    }

    return 0 ;
}
