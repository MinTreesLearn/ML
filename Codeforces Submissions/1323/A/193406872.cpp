#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        bool ans = false;
        cin >> n;
        int dp[n+1];
        dp[0] = 0;
        vector<int> indexes;

        for(int i = 1 ; i <= n ; i++)
            cin >> dp[i];
    
        for(int i = 1 ; i <= n && !ans; i++)
            if(!(dp[i]%2)){
                ans = true;
                indexes.push_back(i);
                indexes.push_back(i);
            }
        
        if(!ans){
            for(int i = 1 ; i < n && !ans; i++){
                int sum = dp[i];
                for(int j = i + 1 ; j <= n && !ans ; j++){
                    sum += dp[j];
                    if(!(sum%2)){
                        ans = true;
                        indexes.push_back(i);
                        indexes.push_back(j);
                    }
                }
            }
        }

        if(ans){
            cout << indexes[1] - indexes[0] + 1 << '\n';
            for(int i = indexes[0] ; i <= indexes[1]; i++){
                if(i == indexes[1])
                    cout << i << '\n';
                else
                    cout << i << ' ';
            }
        }else
            cout << "-1\n";
    }
}