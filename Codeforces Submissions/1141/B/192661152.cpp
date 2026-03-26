#include <bits/stdc++.h>


#define ll long long
using namespace std;



int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int mx = 0;
        int current_length = 0;
        for(int i = 0; i < 2 * n; i++){
            if(a[i % n] == 0){
                mx = max(mx, current_length);
                current_length = 0;
            }else{
                current_length++;
            }
        }

        
        cout << mx << '\n';
        
    }
    

    return 0;
}