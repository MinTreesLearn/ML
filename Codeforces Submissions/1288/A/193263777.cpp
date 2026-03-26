#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v;
ll n, d;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        
        cin >> n >> d;
        if (n >= d)
        {
            cout << "YES" << endl;
        }
        else
        {
            if(2*sqrt(d)-1<=n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
    }
    return 0;
}