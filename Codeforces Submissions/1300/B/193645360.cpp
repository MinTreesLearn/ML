#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define vi vector<int>
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[2*n];
        for(int i=0;i<2*n;i++){
            cin>>a[i];
        }
        sort(a,a+(2*n));
    //   
    // cout<<a[n]<<" "<<a[n+1]<<endl;
       cout<<abs(a[n-1]-a[n])<<endl;;
    }

 return 0;
}