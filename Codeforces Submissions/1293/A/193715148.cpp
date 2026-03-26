#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <array>
#include <deque>
#include <map>
#include <set>
using namespace std ;
void testCase(){
    int n , s , k ;
    cin >> n >> s >> k ;
    map <int,int> mp ;
    for ( int i=0; i<k; i++ ){
        int a ;
        cin >> a ;
        mp[a] ++ ;
    }
    for ( int i=0; i<n; i++ ){
        int x = s - i , y = s + i ;
        if ( x <= 0 )
            x = 1 ;
        if ( y > n )
            y = n ;
        if ( mp[x] == 0 or mp[y] == 0 ){
            cout << i << endl ;
            return ;
        }
    }
}
int main(){
    int t = 1 ;
    cin >> t ;
    while ( t -- )
        testCase () ;
}
