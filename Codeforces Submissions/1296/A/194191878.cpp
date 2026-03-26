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
        int sum = 0, cnt = 0;
        for(int j = 1; j <= n; j ++){
            cin >> a[j];
            if(a[j] % 2 == 0) sum ++;
            else cnt ++;
        }
        if((sum * 2 + cnt) % 2 != 0) cout << "YES\n";
        else{
            if(sum > 0 && cnt > 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
