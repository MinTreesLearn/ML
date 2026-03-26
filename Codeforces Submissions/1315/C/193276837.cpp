#include <bits/stdc++.h>
using namespace std;
// Vamos Abhinav
// NO OBSTACLE IS BIGGER THAN HUMAN CAPABILITIES 
#define fo(i, n) for (i = 0; i < n; i++)
#define FO(i, n) for (i = 1; i <= n; i++)
#define ll long long
#define PI 3.1415926535897932384626
#define pb push_back
#define endl '\n'
const int mod = 596799;
const int N = 1e5, M = N;
void abhinav()
{
  ll n,i;
  cin>>n;
  vector<ll> v(n),ans;
  fo(i,n)    cin>>v[i];
  set<ll>s;
  fo(i,2*n)  s.insert(i+1);
  fo(i,n)    s.erase(v[i]);
  fo(i,n)
  {
    ans.pb(v[i]);
    auto it=s.upper_bound(v[i]);
    if(*it<=v[i])  
    {
        cout<<-1;
        return;
    }
    ans.pb(*it);
    s.erase(*it);
  }
  fo(i,ans.size())   cout<<ans[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    while(t--)
    {
        abhinav();
        cout << "\n";
    }
}