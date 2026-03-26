#include<bits/stdc++.h>
const int N=1e5+10;
#define ll long long
using namespace std;

int main(){
    int n,cnt=0,ans=0,cnt1=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            cnt--;
        }else{
            cnt++;
        }
        if(cnt<0){
            cnt1=1;
        }
            ans+=cnt1;
        if(cnt==0){
            cnt1=0;
        }
    }
    if(cnt==0){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}