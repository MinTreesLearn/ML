#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);

    int t= 1;
    cin >>t ;
    while (t--)
    {
        int a , b , p ;

        cin >> a >> b >> p ;

        string s ;
        cin >> s;

        int n = s.size() ;

        vector<ll> cost(n+1 , 0 );

        cost[n] =0 ;
        cost[n-1] = (s[n-2] == 'A' ? a : b) ;

        int ans = n ;

        if(cost[n-1] <= p) ans = n-1 ;


        for(int i = n-2 ; i >= 1; i--)
        {
            cost[i] = cost[i+1] ;

            if(s[i-1] != s[i]) cost[i] += (s[i-1] == 'A' ? a : b) ;

            if(cost[i] <= p) ans = i ;
        }

        cout << ans << "\n" ;
    }

    return 0;
}