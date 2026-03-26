#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int q;
    cin >> s;
    cin >> q;

    unsigned int n = s.length();
    vector<vector<int>> d(26, vector<int>(n + 1, 0));
    
    for (int i = 0; i < n; i++){
        int idx = s[i] - 'a';
        for (int j = 0; j < 26; j++){
            d[j][i + 1] = d[j][i];
            if (j == idx){
                d[j][i + 1]++;
            }
        }
    }
    
   
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r ;
        l--;
        
        int temp = 0;
        for (int j = 0; j < 26; j++){
            if  (d[j][r] - d[j][l] >= 1){
                temp++;
            }
        }
        
        if (r - l == 1 or s[r-1] != s[l] or temp > 2){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
      }
    return 0;
}