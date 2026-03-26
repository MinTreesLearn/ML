#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool flag = false;
        int cnt = 0;
        int mx = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                flag = true;
                mx = max(mx, cnt);
                cnt = 0;
            }else if(flag){
                cnt++;
            }
        }
        mx = max(mx, cnt);

        cout << mx << '\n';

    }


    
    return 0;
}