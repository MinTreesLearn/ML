#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    std::cin >> t ;
    int x;
    int y;
    int a;
    int b;
    while (t--){
        cin >> x >> y>> a>> b;
        int i = y - x ;
        int j = a + b ;
        if ( i % j == 0){
            cout << i / j << "\n" ;
        }
        else {
            cout << "-1" << '\n' ;
        }
    }
    return 0;
}