#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr);
#define int long long int

void GETAC(){
    
    int n, ans(0);
    string s;
    char c('z');
    cin>>n>>s;
    int i;
    while(c>'a')
    {
        if(s.size()==1) break;
        for(i=0; i<s.size(); ++i)
        {
            if(s[i]!=c) continue;
            if(i==0 and s[1]==c-1 or i==s.size()-1 and s[s.size()-2]==c-1 or s[i-1]==c-1 or s[i+1]==c-1)
            {
                s.erase(i,1),
                ++ans;
                break;
            }
        }
        if(i==s.size()) --c;
    }
    cout<<ans;
}

signed main() {
    fastio
    int t(1);//cin>>t;
    while(t--) GETAC(), cout<<'\n';
}
