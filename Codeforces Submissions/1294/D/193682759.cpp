// Akash Singh
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //Make less_equal for multiset
// find_by_order(k)  returns iterator to kth element || order_of_key(k) returns count of elements smaller than k
#define deb(x) cout << x << "\n";
#define deb2(x,y) cout << x << " " << y << "\n";
#define debv(v) for(auto e: v) cout << e << " "; cout << '\n';
#define int long long
#define ll long long
#define mod 1000000007
const int N = 0;

void solver();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int KitniBar = 1;
    // cin >> KitniBar;

    for(int tc = 1; tc <= KitniBar; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solver();
    }
    return 0;
}
void solver()
{
    int q, x, y, ans, mex = 0; cin >> q >> x;
    vector<bool> arr(400001, false);
    vector<int> pre(x+1, 0);
    while(q--) {
        cin >> y; y -= (y/x)*x;
        int mul = max(0LL, mex-y)/x;
        for(int i = max(mul, pre[y]); y+i*x <= 400000; i++) {
            if(arr[y+i*x]) continue;

            arr[y+i*x] = true;
            pre[y] = i;
            break;
        }
        while(arr[mex] && mex <= 400000) {
            mex++;
        }
        cout << mex << endl;
    } 
}