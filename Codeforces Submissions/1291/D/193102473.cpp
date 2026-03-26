#include "bits/stdc++.h"
using namespace std; 
using ll =  long long;
const ll mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);



    string str; cin >> str;
    int n = str.size();
    vector<vector<int>> pre(26, vector<int>(n));

    for(int i = 0; i < 26; i++){

        for(int j = 0; j < n; j++){
            if(str[j] - 'a' == i) pre[i][j] = 1;
        }

        for(int j = 1; j < n; j++) pre[i][j] += pre[i][j - 1];
    }

    int q; cin >> q;

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        int characters = 0;
        for(int j = 0; j < 26; j++){

            int count = 0;
            if(l) count = pre[j][r] - pre[j][l - 1];
            else count = pre[j][r];
            if(count > 0) characters++;
        }

        if(characters >= 3 or r - l + 1 == 1) cout << "Yes" << endl;
        else if(characters > 1 and str[l] != str[r]) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
}
 


































