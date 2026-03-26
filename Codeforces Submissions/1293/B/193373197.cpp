#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define sz(s) (int)s.size()
#define F .first
#define S .second
#define all(v) ((v).begin()),((v).end())
#define allr(v) ((v).rbegin()),((v).rend())
const int mod = 1e9 + 7;
const int N = 2e5+5;
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("endure.in", "r", stdin);
    //freopen("", "w", stdout);
    int n;
    double ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        ans+=(1./i);
    }
    cout<<fixed<<setprecision(12)<<ans;

}
