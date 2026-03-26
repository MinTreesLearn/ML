#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int sumDigit(long long int n){
    long long m=n;
    long long sum=0;
    while (m>0){
       sum+=m%10;
        m=m/10;
    }
   long long  int gcd=__gcd(n,sum);
    return gcd;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t-- != 0) {
        long long n;
        cin >> n;
        vector<int> a(n);

        int dcount = 0;
        int sum= accumulate(a.begin(),a.end(),0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 0) {
                dcount++;
                sum++;

            }

}
        cout<<dcount+(sum==0)<<endl;

    }
}