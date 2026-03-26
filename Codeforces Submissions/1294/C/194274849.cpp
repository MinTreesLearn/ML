// Online C++ compiler to run C++ program online
#include <iostream>
#define k long long unsigned 
using namespace std;
int main() {
    int t;cin>>t;
    while(t--){
        k n,a=1,b=1,c=1;cin>>n;
        for(k i=2;i*i<=n;i++){
            if(n%i==0){
                a=i;
                n/=a;
                break;
            }   
        }
        for(k i=2;i*i<=n;i++){
            if(n%i==0 && i!=a && n/i!=i && n/i!=a){
                b=i; c=n/i;
                n/=b;n/=c;
                break;
            }   
        }
        if(n==1 && a!=b && a!=c && b!=c){
            cout<<"YES \n"<<a<<" "<<b<<" "<<c;
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
        
    }
    return 0;
}