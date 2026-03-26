#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n;
cin>>t;
int k[t];
for(int i=0;i<t;i++){
cin>>k[i];
string s;
cin>>s;
int maxi=0;
int sum=0;
int flag=0;
for (int j = 0; j <k[i]; j++)
{
    
        if(s[j]=='A'){
            flag=1;

            if(sum>maxi){
                maxi=sum;
            }
                sum=0;
        }
       else  if(s[j]=='P' and flag==1){
            sum++;
         
        }
        
    }
    if(sum>maxi){
        maxi=sum;
        sum=0;
    }
    cout<<maxi<<endl;
}

return 0;
}
// }