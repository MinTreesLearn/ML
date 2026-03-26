#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//priority_queue <int, vector<int>, greater<int>> q;
 
int fr[800005], ne[800005];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, x, nmax = 800000, sol = 0;
    cin >> q >> x;
    for(int i = 0; i < x; i++){
        ne[i] = i;
    }
    for(int i = 1; i <= q; i++){
        int y;
        cin >> y;
        y = y % x;
        if(ne[y] + x <= nmax){
            ne[y] = ne[y] + x;
        }
        y = ne[y] - x;
        fr[y] = 1;
        while(fr[sol] == 1){
            sol++;
        }
        cout << sol << "\n";
    }
    return 0;
}