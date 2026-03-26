#include<bits/stdc++.h>
using namespace std;
const int maxn=205; 
map<string,int>h1[maxn],h2[maxn]; 
vector<char>ans; 
char geta(string a,string b){
     int c[30];
     memset(c,0,sizeof(c));
     for(int i=0;i<a.size();i++)c[a[i]-'a']++;
     for(int i=0;i<b.size();i++)c[b[i]-'a']--; 
     for(int i=0;i<26;i++){
         if(c[i]>0)return i+'a'; 
     }
}
int main(){
    int n;
    cin>>n;
    if(n==1){
         cout<<"? 1 1"<<endl; 
         string sss;
        cin>>sss;
        cout<<"! "<<sss<<endl; 
    }
    else{
         cout<<"? 1 "<<n<<endl; 
         for(int i=0;i<n*(n+1)/2;i++){ 
             string s;
             cin>>s;
             sort(s.begin(),s.end()); 
             h1[s.size()][s]++; 
         }
         cout<<"? 2 "<<n<<endl; 
         for(int i=0;i<n*(n-1)/2;i++){ 
             string s;
             cin>>s; 
             sort(s.begin(),s.end()); 
             h2[s.size()][s]++; 
         }
         for(int i=1;i<=n;i++){
              for(auto p:h2[i]){
                   h1[i][p.first]-=h2[i][p.first]; 
              }
              for(auto p:h1[i]){ 
                  if(p.second>0){
                      string nw=""; 
                      for(int j=0;j<ans.size();j++)nw+=ans[j]; 
                      ans.push_back(geta(p.first,nw));
                  }   
              }
         }
         string nw2=""; 
         for(int j=0;j<ans.size();j++)nw2+=ans[j];
         cout<<"! "<<nw2<<endl; 
    }
    return 0; 
}