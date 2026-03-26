#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int move=0;
        if(n==k){
            cout<<0<<"\n";
        }
        else if(n<k){
            if((k-n)%2!=0) cout<<1<<"\n";
           else cout<<2<<"\n";
        }
        else{
            if((n-k)%2==0) cout<<1<<"\n";
            else cout<<(2)<<"\n";
        }
    }
    return 0;
    }