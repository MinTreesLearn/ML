#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, sum;

int main()
{
    cin >> t;
    while (t--){
        cin >> n >> m;
        int sum = 0;
        for(int i=1; i<=n; ++i){
            cin >> a;
            sum += a;
        }
        cout << min(m,sum) << endl;
    }
}