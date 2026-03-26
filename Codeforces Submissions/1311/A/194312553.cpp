#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#define int long long int

const int M = 86028121 ;

using namespace std ;

int32_t main()
{
        int t ;
        cin >> t ;
        while(t--)
        {
            int a , b ;
            cin >> a >> b ;
            if(a==b)
            {
                cout << 0 << endl ;
            }
            else if(a<b)
            {
                int d = b-a ;
                if(d%2==1)
                {
                    cout << 1 << endl ;
                }
                else
                {
                    cout << 2 << endl ;
                }
            }
            else
            {
                int d = a-b ;
                 if(d%2==0)
                {
                    cout << 1 << endl ;
                }
                else
                {
                    cout << 2 << endl ;
                }
            }
        }
    return 0 ;
}