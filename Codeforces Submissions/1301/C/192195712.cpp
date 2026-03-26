#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define int long long
int gauss(int x)
{
    return x*(x+1)/2;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int aux=n;
    n-=k;
    k++;
    //cout<<n<<' '<<k;
    cout<<gauss(aux)-gauss(n/k+1)*(n%k)-gauss(n/k)*(k-(n%k));
}
main()
{
    auto sol=[](bool x)->string
    {
        if(x)return "YES";
        return "NO";
    };
    int tt=1;
    cin>>tt;
    while(tt--)
    {
        solve();
        cout<<'\n';
    }
}
