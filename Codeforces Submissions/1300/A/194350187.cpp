#include <bits/stdc++.h>
using namespace std;

#define int long long
#define For(i,a,n) for(int i = a; i < n; i++)
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int sum = 0,cnt = 0;
        For(i,0,n){
            int temp;
            cin >> temp;
            if (temp == 0) cnt++;
            sum += temp;
        }
        if (sum + cnt == 0) cnt++;
        cout <<cnt<<"\n";
    }
    return 0;
}