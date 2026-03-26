#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define ll long long
#define code std::ios::sync_with_stdio(false);::cin.tie(nullptr);

bool isPrime(ll n){
    if(n < 2)
        return false;
    for (ll i = 2; i * i <= n; ++ i) {
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    ll z;
    cin >> z;
    while(z--){
        string s;
        cin >> s;
        ll o = 0;
        ll k = 0;
        for(int i = 0;i < s.size()+1;i++){
            if(s[i]=='L'){
                o++;
            }else{
                k = max(k,o);
                o = 0;
            }
        }
        cout << k+1 << endl;
    }
}