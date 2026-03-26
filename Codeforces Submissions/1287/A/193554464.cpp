#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t;
    cin >> t;


    while(t--){
        int n;
        string s;
        cin >> n >> s;
        
        int cnt = 0;
        int res = 0;
        
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == 'P'){
                cnt++;
            }
            else{
                res = max(res, cnt);
                cnt = 0;
            }
              
        }
        cout << res << "\n";
    }
	
	return 0;
}