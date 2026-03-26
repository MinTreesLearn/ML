#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N = 1000000007;
// int dp[200001];
string func(int i,vector<vector<int>> &adj,int pr){
  string str="";
  str.push_back('a'+i);
  for(auto ch:adj[i]){
    if(ch==pr)continue;
      str=str+func(ch,adj,i);
  }
  return str;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(10);

    int t;
    cin>>t;
    while(t--){
      vector<vector<int>> adj(27);
      string str;
      cin>>str;
      vector<bool> present(26,false);
      vector<vector<int>> vist(26,vector<int>(26,false));
      
      for(int i=0;i<str.size()-1;i++){
        int a=str[i]-'a';
        int b=str[i+1]-'a';
        present[a]=true;
        present[b]=true;
        if(vist[a][b])continue;
        else{
          vist[a][b]=true;
          vist[b][a]=true;
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
      }

      int d1=0;
      int d2=0;
      int idx=-1;
      bool flag=true;
      for(int i=0;i<26;i++){
        if(adj[i].size()==0)continue;
        if(adj[i].size()==2)d2++;
        else if(adj[i].size()==1){
          d1++;
          idx=i;
        }
        else {
          flag=false;
          break;
        }
      }
      if(str.size()==1){
        d1=2;
        idx=str[0]-'a';
        present[idx]=true;
      }
      if(flag && d1==2){
        cout<<"YES"<<endl;
        string str=func(idx,adj,-1);
        for(int i=0;i<26;i++){
          if(!present[i])str.push_back('a'+i);
        }
        cout<<str<<endl;
      }else cout<<"NO"<<endl;
      

    }
      
      
    
 
    return 0;
}
 
 