#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        string map = "R", str; cin >> str;
        map += str + "R";
        vector<int>arr;
        for(int i=0; i<map.size(); i++)if(map[i] == 'R')arr.push_back(i);
        int res = 0;
        for(int i=1; i<arr.size(); i++)res = max(res, arr[i] - arr[i-1]);
        cout << res << "\n";
    }
    return 0;
}