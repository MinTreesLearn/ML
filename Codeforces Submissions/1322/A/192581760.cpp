#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n; cin >> n;
    string s; cin >> s;

    int cur = 0, ans=0, sum=0, k = 0;
    for(int i=0; i<n; i++){
        if(s[i]==')'){
            cur--;
        }
        else{
            cur++;
        }
        if(cur==0){
            if(k!=0)
                ans+= (k+1);
            cur = 0;
            // sum=0;
            k = 0;
        }
        else if(cur<0){
            k++;
        }
        // sum = min(cur, sum);
    }
    if(cur!=0){
        cout << -1 << endl; 
        return 0;
    }

    cout << ans << endl;
}