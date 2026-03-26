#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        int p[m];
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        vector<vector<int>>prefix(n+1,vector<int>(26,0));

        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1];
            prefix[i][s[i-1]-'a']++;
        }

        vector<int>ans(26,0);
        for(int i=0;i<m;i++){

            for(int j=0;j<26;j++){
                ans[j]+=prefix[p[i]][j];
            }

        }
        for(int i=0;i<26;i++){
            cout<<1ll*ans[i]+prefix[n][i]<<" ";
            
        }
        cout<<'\n';
    

    }
    return 0;
}