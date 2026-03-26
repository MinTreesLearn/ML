#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, g, b;
        cin >> n >> g >> b;
        auto h = (n >> 1LL) + (n & 1LL);
        auto t = g + b;
        cout << max(n, ((h / g) * t) + (h % g == 0LL ? -b : h % g)) << '\n';
    }
}

			 	 				 	 		    	  		 				 	