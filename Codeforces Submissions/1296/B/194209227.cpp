#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        long long a;
        cin >> a;
        long long cnt=a;
        if(a<10) cout << a <<endl;
        else{
            while(a>=10){
                long long z=a/10;
                a = (a%10) + z;
                cnt += z;
            }

            cout << cnt << endl;
        }

    }
    return 0;
}