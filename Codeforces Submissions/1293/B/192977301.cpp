#include <iostream>
#include <iomanip>
#define ll long long
#include <set>
using namespace std;
int main() {
    int t=1;
    while(t--){
        int n; cin>>n;
        float a=0;
        for(float i=n;i>0;i--){
            a=a+(1/i);
        }
        cout<<a<<setprecision(13)<<endl;
    }return 0;}