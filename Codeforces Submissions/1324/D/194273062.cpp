#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
template<class T> using ordset = tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>;

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define ppb pop_back
#define vll vector<long long int>
#define vi vector<int>
#define PrintArray(arr) for(int i=0;i<(int)arr.size();i++)cout<<arr[i]<<" ";cout<<"\n";
#define lowerb lower_bound
#define upperb upper_bound
#define pqi priority_queue<int>
#define pqll priority_queue<long long>
#define nl '\n';
 

const long long MAX_SIZE = 1000001;
const int MAX_N = 1e5 + 5;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 9882999;
const ll INF = 1e18;
const ld EPS = 1e-9;

//----------------------------------------------Code---------------------------------------------------//

void solve()
{
    int n;
    cin >> n;
    vll a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    vll lhs, rhs;
    for (int i = 0; i < n; i++)
    {
        lhs.pb(a[i] - b[i]);
    }
    
    sort(all(lhs));
    
    ll ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        int temp = -1, l = i + 1, r = n - 1;
        
        while (l <= r)
        {
            int mid = (l + r) / 2;
            
            if (lhs[mid] + lhs[i] > 0)
            {
                temp = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        if (temp >= 0)
        {
            ans += (n - temp);
        }
    }
    cout << ans << nl;
}

//-----------------------------------------------------------------------------------------------------//

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}





