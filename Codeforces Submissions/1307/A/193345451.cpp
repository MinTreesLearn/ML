#include <bits/stdc++.h>
using namespace std;

int t,n,a[105],d;

int main()
{
    cin >> t;
    while (t--){
        cin >> n >> d;
        for (int i=1; i<=n; ++i){
            cin >> a[i];
        }
        while (d--){
            for (int i=2; i<=n; ++i){
	            if (a[i] > 0){
	                ++a[i-1];
                    --a[i];
	                break;
	            }
            }
        }
        cout << a[1] << endl;
    }
}