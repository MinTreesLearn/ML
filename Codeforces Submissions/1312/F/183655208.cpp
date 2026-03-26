#include<bits/stdc++.h>
using namespace std;
long long n , x , y , z , dp [10004][4] , arr [300005];
vector < int > bt [4];
int grundy ( long long x , int y )
{
    if ( x < 15e2 ) return dp [x][y];
    else
    {
        int xx = ( x - 1000 ) % bt [y] . size ();
        return bt [y][xx];
    }
}
int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        scanf ( "%lld%lld%lld%lld" , &n , &x , &y , &z );
        int xr = 0;
        for ( int i = 1 ; i <= 15e2 ; i ++ )
        {
            for ( int j = 0 ; j < 3 ; j ++ )
            {
                int a = max ( i - x , 0ll );
                int b = max ( i - y , 0ll );
                int c = max ( i - z , 0ll );
                vector < int > v;
                if ( j == 0 )
                {
                    v . push_back ( dp [a][0] );
                    v . push_back ( dp [b][1] );
                    v . push_back ( dp [c][2] );
                }
                if ( j == 1 )
                {
                    v . push_back ( dp [a][0] );
                    v . push_back ( dp [c][2] );
                }
                if ( j == 2 )
                {
                    v . push_back ( dp [a][0] );
                    v . push_back ( dp [b][1] );
                }
                sort ( v . begin () , v . end () );
                v . resize ( unique ( v . begin () , v . end () ) - v . begin () );
                dp [i][j] = -1;
                for ( int z = 0 ; z < v . size () ; z ++ )
                {
                    if ( v [z] != z )
                    {
                        dp [i][j] = z;
                        break;
                    }
                }
                if ( dp [i][j] == -1 ) dp [i][j] = v . size ();
            }
        }
        bt [0] . clear ();
        bt [1] . clear ();
        bt [2] . clear ();
        for ( int i = 30 ; i <= 70 ; i ++ )
        {
            for ( int j = 0 ; j < 3 ; j ++ )
            {
                vector < int > a , b;
                int x = 1000 , y = i;
                while ( y -- ) a . push_back ( dp [ x ++ ][j] );
                y = i;
                while ( y -- ) b . push_back ( dp [ x ++ ][j] );
                if ( a == b ) bt [j] = a;
            }
        }
        if ( bt [0] . size () == 0 ) cout << 0 / 0 << endl;
        if ( bt [1] . size () == 0 ) cout << 0 / 0 << endl;
        if ( bt [2] . size () == 0 ) cout << 0 / 0 << endl;
        for ( int i = 0 ; i < n ; i ++ )
        {
            scanf ( "%lld" , &arr [i] );
            xr ^= grundy ( arr [i] , 0 );
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; i ++ )
        {
            if ( grundy ( max ( arr [i] - x , 0ll ) , 0 ) == ( xr ^ grundy ( arr [i] , 0 ) ) ) ans ++;
            if ( grundy ( max ( arr [i] - y , 0ll ) , 1 ) == ( xr ^ grundy ( arr [i] , 0 ) ) ) ans ++;
            if ( grundy ( max ( arr [i] - z , 0ll ) , 2 ) == ( xr ^ grundy ( arr [i] , 0 ) ) ) ans ++;
        }
        printf ( "%d\n" , ans );
    }
}















