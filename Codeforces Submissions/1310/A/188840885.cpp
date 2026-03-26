#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

map <int, int> m; 
priority_queue <pair <int, int>> q;
pair <int, int> v[200005], aux;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i].first;
        m[v[i].first]++;
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i].second;
    }
    sort(v + 1, v + n + 1);
    long long sol = 0;
    for(int i = 1; i <= n; i++){
        if(m[v[i].first] > 1){
            int nr = m[v[i].first], x = v[i].first;
            while(x - v[i].first + 1 < nr){
                x++;
                nr += m[x];    
            }
            int y = v[i].first;
            for(y; y <= x; y++){
                while(v[i].first <= y && i <= n){
                    q.push({v[i].second, v[i].first});
                    i++;
                }
                aux = q.top();
                q.pop();
                sol = sol + 1LL * aux.first * (y - aux.second);
            } 
            i--;
        }
    }
    cout << sol;
    return 0;
}