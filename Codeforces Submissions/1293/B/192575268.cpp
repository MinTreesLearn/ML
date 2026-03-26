#include<bits/stdc++.h>
using namespace std;
#define N 200001
#define ll long long
int main(){
    ll n;
    cin>>n;
    //maximum possible value that i can get is 2
    double x=0.00000;
    while(n>0){
        x+=(double)1/n;
        n--;
    }
    cout<<x<<endl;
    return 0;
    }