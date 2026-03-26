/*
وَاتَّقُوا فِتْنَةً لَّا تُصِيبَنَّ الَّذِينَ ظَلَمُوا مِنكُمْ خَاصَّةً ۖ وَاعْلَمُوا أَنَّ اللَّهَ شَدِيدُ الْعِقَابِ
 0xTesla
*/
#include <bits/stdc++.h>
using namespace std ;
#define Tesla ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define sp " "
#define el '\n'
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define PI 3.14159265
using namespace std;
const long long N = 2e5 + 7, Mod = 1e9, INF = 2e18;
# define test int t ; cin >> t ; while(t--)
void solve()
{
    int n ;
    cin >> n ;
    vector<int>v(n) ;
    for(int i = 0 ; i < n ; i ++)
    {

        cin >> v[i] ;
    }
    list<int>v1(2*n) ;
    iota(v1.begin(),v1.end(),1) ;
    for(auto i : v)
    {
        remove(v1.begin(),v1.end(),i) ;
    }
    v1.resize(n) ;
    vector<int>v2;bool flag = 0 ;
//    for(auto i : v) cout << i << sp ;
//    cout << el ;
//    for(auto i : v1) cout << i << sp ;
//    cout << el ;
    for(auto i : v)
    {
        auto it = upper_bound(v1.begin(),v1.end(),i) ;
        if( it != v1.end())
        {
            v2.push_back(i) ;
            v2.push_back(*it) ;
            v1.erase(it) ;
        }
        else flag = 1 ;
    }
    if(flag) cout << "-1" ;
    else for(auto i : v2) cout << i << sp ;
    cout << el ;
}
int main()
{
    Tesla
    test
        solve();
    return 0;
}
