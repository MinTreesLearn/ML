#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//priority_queue <int, vector<int>, greater<int>> q;
 

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while(test--){
        int n, x, nr = 0, sol = 0;
        string s;
        cin >> n >> x >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') nr++;
            else nr--;
            if(nr == x) sol++;
        }
        if(nr == 0){
            if(sol > 0) cout << "-1\n";
            else cout << "0\n";
            continue;
        }
        if(x == 0) sol++;
        int num = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') num++;
            else num--;
            int dif = x - num;
            if((dif > 0 && nr > 0) || (dif < 0 &&  nr < 0)){
                if(dif % nr == 0) sol++;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
