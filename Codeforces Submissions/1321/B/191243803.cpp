#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vl vector<ll>
#define pl pair<ll, ll>
#define vi vector<int>
#define pi pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fl(i, a, b) for (ll i = a; i <= b; i++)
#define bfl(i, k, n) for (ll i = k; i > n; i--)
#define prDouble(d) cout << fixed << setprecision(10) << d
#define endl "\n"
#define int long long
#define inf 1e18

const int mod = 1000000007;
double epsilon = 1e-6;
/*-----------------------------------------------------------------------------------------*/
void init_code()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE;
}


void solve()
{  
   int n; cin>>n;
   int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];  
   
   map<int, int> mp;
   for(int i=0;i<n;i++){
      if(mp.find(arr[i]-i)==mp.end()) mp[arr[i]-i] = arr[i];
      else mp[arr[i]-i]+=arr[i];
   }

   int ans = 0;
   for(auto x : mp) ans = max(ans, x.ss);

   cout<<ans<<endl;   

   




   


   return;   


}


signed main()
{

   init_code();
   auto start_time = std::chrono::high_resolution_clock::now();

    int t;
    //cin>>t;

    t = 1;

    while (t--)
    {
        solve();
    }

   auto stop_time = std::chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);

#ifndef ONLINE_JUDGE
   cerr << "Time: " << duration.count() / 1000. << " ms" << endl;
#endif

    return 0;
}
