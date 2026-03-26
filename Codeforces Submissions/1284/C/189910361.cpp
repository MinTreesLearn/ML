#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//priority_queue <int, vector<int>, greater<int>> q;
 
long long factorial[250005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m, sol = 0;
    cin >> n >> m;
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= n; i++){
        factorial[i] = (factorial[i - 1] * i) % m;
    }
    for(int i = 1; i <= n; i++){
        long long nr = ((n - i + 1) * (n - i + 1)) % m; 
        nr = (nr * factorial[i]) % m;
        nr = (nr * factorial[n - i] % m);
        sol = (sol + nr) % m;
    }
    cout << sol;
    return 0;
}
