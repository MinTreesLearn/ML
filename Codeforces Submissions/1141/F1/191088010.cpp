                                        //  ॐ
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long int



int main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        

   int test = 1;
   // cin>>test;


   
   while(test--){
               
                int n;
                cin>>n;

                int a[n+1];
                map<int,vector<pair<int,int>>> mp;


                for(int i=1;i<=n;i++){
                     cin>>a[i];
                }

                for(int i=1;i<=n;i++){
                     int curr=0;
                     for(int j=i;j<=n;j++){
                         curr+=a[j];
                         mp[curr].push_back({j,i});
                     }
                }

                int opt;
                int blocks=0;

                for(auto [sum,vec] : mp){

                       sort(vec.begin(),vec.end());
                       int st=0;
                       int mx=0;

                       for(auto [j,i] : vec){
                          if(i>st){
                              mx++;
                              st=j;
                          }
                       }

                       if(mx>blocks){
                           blocks=mx;
                           opt=sum;
                       }
                }

                cout<<blocks<<'\n';
                auto vec=mp[opt];
                sort(vec.begin(),vec.end());

                int st=0;
                for(auto [j,i] : vec){
                       if(i>st){
                          cout<<i<<' '<<j<<'\n';
                          st=j;
                       }
                }


                // cout<<"\n";
                
                        
   }
    return 0;
}