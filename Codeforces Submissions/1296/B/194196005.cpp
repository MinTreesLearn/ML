#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

long long t, n, a[100001];
int main(){
    cin >> t;
    for(int i = 1; i <= t; i ++){
        cin >> n;
        int sum = 0;
        while(n > 0){
            long long j = 1e9;
            while(n < j) j /= 10;
            sum += j;
            n -= j - j / 10;
        }
        cout << sum << '\n';
    }
}
