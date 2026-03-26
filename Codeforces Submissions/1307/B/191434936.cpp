//Created by yrm_1406
#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
for (int i = 0; i < t; i++)
{
int n,x;
cin>>n>>x;
vector<int>a(n);
bool ans = true;
for (int i = 0; i < n; i++)
{
    cin>>a[i];
    if(x == a[i])
    {
        ans = false;
    }
}

if(!ans)
{
    cout<<"1"<<endl;
}

else
{
    int temp = *max_element(a.begin(),a.end());
    cout<<max(2,((x + temp - 1)/temp))<<endl;
}




}
return 0;
}