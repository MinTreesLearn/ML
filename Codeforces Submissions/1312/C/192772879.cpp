#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007ll

bool inPowerOfK(ll num, int k, bool vis[]){
    int bit = 0;
    while(num){
        if(num % k > 1) return false;
        if(num % k == 1) {
            if(!vis[bit]) vis[bit] = true;
            else return false;
        }
        num /= k;
        bit++;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        bool vis[60] = {false};
        int n, k; cin >> n >> k;
        ll arr[n];
        bool ans = true;
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n; i++){
            if(!inPowerOfK(arr[i], k, vis))
                {ans = false; break;}
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}