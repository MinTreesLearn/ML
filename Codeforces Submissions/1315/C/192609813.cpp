#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
fast_cin();
int test;
    cin >> test;
    while(test--){
        int n; cin >> n;
        int a[n];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        vector<int> res;
        bool ck = false;
        for(int i=0;i<n;i++){
            int k = a[i];
            if(k>2*n){
                cout << -1 << endl;
                ck = true;
                break;
            }
            else res.push_back(k);
            while(mp[k]){
                k++;
            }
            if(k>2*n){
                cout << -1 << endl;
                ck= true;
                break;
            }
            else{
                res.push_back(k);
                mp[k]++;
            }
        }
        if(ck) continue;
        for(int i:res) cout << i << " ";
        cout << endl;
    }

    return 0;
}