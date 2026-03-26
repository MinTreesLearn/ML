#include <bits/stdc++.h>
using namespace std;

int t,n,a[105];

int main()
{
    cin >> t;
    while (t--){
        cin >> n;
        int indeven = 0;
        int numeven = 0;
        for(int i=1; i<=n; ++i){
            cin >> a[i];
            if(a[i] % 2 == 0){
                indeven = i;
                ++numeven;
            }
        }
        if (indeven > 0){
            cout << 1 << endl;
            cout << indeven << endl;
        } else if (numeven == 0 && n > 1){
            cout << 2 << endl;
            cout << 1 << ' ' << 2 << endl;
        } else {
            cout << -1 << endl;
        }

    }
}