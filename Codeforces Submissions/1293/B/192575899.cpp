#include<bits/stdc++.h>
using namespace std;
#define N 200001
#define ll long long
int main(){
    ll n;
    cin>>n;
    double x=0.0;
    while(n>0){
        x+=(double)1/n;
        n--;
    }
    cout<<setprecision(12)<<x<<endl;
    return 0;
    }