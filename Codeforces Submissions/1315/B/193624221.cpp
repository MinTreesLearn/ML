#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int a, b, p;
        cin >> a >> b >> p;
        string s; cin >> s;
        int n = s.length();

        int cost = 0, ans = n;
        for(int i=n-2; i>=0; i--){
            if(i==0){
                if(s[i]=='A'){
                    cost+=a;
                }
                else{
                    cost+=b;
                }
                if(cost<=p){
                    ans = 1;
                }
                break;
            }
            if(s[i]!=s[i-1]){
                if(s[i]=='A'){
                    cost+=a;
                }
                else{
                    cost+=b;
                }
                if(cost>p){
                    break;
                }
                else{
                    ans = i+1;
                }
            }
        }

        cout << ans << endl;
    }
}