#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,even=0,odd=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        int lastindex=n-1;
        while(s.size()!=0 && s[lastindex]%2==0){
            s.pop_back();
            lastindex--;
        }
        if(odd%2==1){
            s.pop_back();
            lastindex--;
        }
         while(s.size()!=0 && s[lastindex]%2==0){
            s.pop_back();
            lastindex--;
        }
        if(s.size()!=0)
            cout<<s<<endl;
        else
            cout<<-1<<endl;    
    }
}