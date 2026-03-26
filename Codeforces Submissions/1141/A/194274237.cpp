#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c = 0;cin>>a>>b;
    double ans = b/a;
    if(static_cast<long long>(pow(2, 0)*pow(3, 0)==ans)) c = 0;
    else{
        for(int i = 0; i < 31;i++){
            for(int j = 0; j < 31;j++){
                if(pow(2, i) * pow(3, j)==ans){
                    c = i+j;
                    cout<<c<<endl;
                    return 0;
                }
                if(pow(2, i) * pow(3, j) > b){
                    c = -1;
                    break;
                }
            }
        }
    }
    cout<<c<<endl;
}