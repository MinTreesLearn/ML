#include <bits/stdc++.h>
// #include "Algorithms.h"

#define long long long
const int Mod = 1e9 + 7, N = 1e3 + 1;

void Solution() {
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int l = 0, r = n;
    while (l < n && a[l] >= l) l++;
    while (r > 0 && a[r - 1] >= n - r) r--;

    if (l > r) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t = 1; std::cin >> t;
    while (t--) {
        Solution();
    }
    return 0;
}
							 		     	     	   	  	 	