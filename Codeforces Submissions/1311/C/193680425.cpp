#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> freq(n, 0);
        for(int i=0; i<m; i++){
            int x; cin >> x;
            freq[0]++;
            freq[x]--;
        }
        freq[0]++;

        for(int i=1; i<n; i++){
            freq[i] += freq[i-1];
        }
        vector<int> c(26, 0);
        for(int i=0; i<n; i++){
            c[(s[i]-'a')]+= freq[i];
        }

        for(int i=0; i<26; i++){
            cout << c[i] << " ";
        }
        cout << endl;
    }
}