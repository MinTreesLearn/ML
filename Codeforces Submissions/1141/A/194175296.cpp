#include "iostream"
using namespace std;
int n,m;
int cnt=0;
int main(){
    cin>>n>>m;
    int temp=m/n;
    if(m%n!=0){
        cout<<"-1";
        return 0;
    }
    while(temp%2==0)
    {
        cnt++;
        temp/=2;
    }
    while(temp%3==0)
    {
        cnt++;
        temp/=3;
    }
    if(temp!=1){
        cout<<"-1";
        return 0;
    }
    cout<<cnt;
    return 0;
}

 	  			 								       	   		