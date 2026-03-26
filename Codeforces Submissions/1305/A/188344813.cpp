#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> x(n);
        vector<ll> y(n);
        for(int i=0;i<n;i++){cin >> x[i];}
        for(int i=0;i<n;i++){cin >> y[i];}
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for(int i=0;i<n;i++){
            cout << x[i] << " ";
        }
        cout << '\n';
        for(int i=0;i<n;i++){
            cout << y[i] << " ";
        }
        cout << '\n';
    }
}
