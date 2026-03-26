#include <bits/stdc++.h>
using namespace std;

int n,t,a[105];

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        int num0 = 0;
        int sum = 0;

        for(int i=1; i<=n; ++i){
            cin >> a[i];
            sum += a[i];
            if(a[i] == 0){
                ++num0;
            }
        }

        int ans = 0;

        if(num0 == 0 && sum != 0){
            ans = 0;
        } else if (num0 == 0 && sum == 0){
            ans = 1;
        } else if (num0 != 0){
            sum += num0;
            ans = num0;
            num0 = 0;
            if(sum == 0){
                ++sum;
                ++ans;
            }
        }
        cout << ans << endl;

    }
}
