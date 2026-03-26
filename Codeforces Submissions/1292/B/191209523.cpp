#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
priority_queue <int, vector<int>, greater<int>> q;
 
pair <long long, long long> v[105];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ax, ay, bx, by, x, y, t, sol = 0;
    cin >> v[1].first >> v[1].second >> ax >> ay >> bx >> by;
    cin >> x >> y >> t;
    int n = 1;
    while(v[n].first < x + t && v[n].second < y + t){
        n++;
        v[n].first = v[n - 1].first * ax + bx;
        v[n].second = v[n - 1].second * ay + by;
    }
    for(int i = 1; i <= n; i++){
        long long xx = x, yy = y, nr = 0, num = 0;
        for(int j = i; j <= n; j++){
            long long dist = abs(xx - v[j].first) + abs(yy - v[j].second);
            nr += dist;
          //  cout << nr << " ";
            if(nr <= t) num++;
            else break;
            xx = v[j].first;
            yy = v[j].second;
        }
        sol = max(sol, num);
        xx = x, yy = y, nr = 0, num = 0;
        for(int j = i; j >= 1; j--){
            long long dist = abs(xx - v[j].first) + abs(yy - v[j].second);
            nr += dist;
          //  cout << nr << " ";
            if(nr <= t) num++;
            else break;
            xx = v[j].first;
            yy = v[j].second;
        }
        sol = max(sol, num);
    }
    cout << sol;
    return 0;
}