#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
      if(str[i]=='(') count1++;
      else count2++;
    }
    if(count1!=count2){
      cout<<-1<<"\n";
    }
    else{
      int len=0;
      int sum=0;
      for(int i=0;i<n;i++){
        if(str[i]=='('){
          if(sum==-1) len++;
           sum++;
        }
        else{
          sum--;
        }
        if(sum<0) len++;
      }
      cout<<len<<"\n";
    }
  }
//8929031003
//