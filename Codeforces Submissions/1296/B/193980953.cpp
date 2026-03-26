#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        int sisa=0;
        int ans=0;
        while((a+sisa)>=10){
            sisa=a/10;
            ans+=(a/10)*10;
            a%=10;
            a+=sisa;
        }
        cout << ans+a << endl;
    }
}