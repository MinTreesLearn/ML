#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

const int N = 1e6+5;
ll arr[N];
ll brr[N];
ll pre[N];

ll mod = 1000000007 ;

vector < ll > vec ;
set < ll > st ;

map < ll, ll > mp;
pair < ll, ll > p[N];

void cc()
{
    vec.clear();
    st.clear();
    mp.clear();
}

int main()
{
    int t = 1;
    cin >> t ;
    while(t--)
    {
       ll n , x , mx = 0 ;
       cin >> n >> x;

       bool ok = 0 ;
       
       for(int i=1 ; i <= n ; i++)
       {
           cin >> arr[i] ;
           mx = max(mx , arr[i]);
           if(arr[i] == x) ok = 1 ;
       }
       
       

       if(x == mx || ok)
       {
           cout << 1 << endl;
           continue;
       }

       if(mx > x)
       {
           cout << 2 << endl;
           continue;
       }

       cout << (x + mx-1) / mx << endl;
    }

}
