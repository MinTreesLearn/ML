/*
        author :- sairaj
*/
#pragma GCC optimize("O1")
#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define sortv(a) sort(all(a))
#define sortvg(a) sort(all(a),greater<>());
#define int long long
#define endl "\n"
#define SPEED {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template<class T>
void display(T a)
{
    for(auto& it:a)
    {
        cout<<it<<" ";
        cout<<endl;
    }
}
void jawab()
{
    string a;
    cin>>a;
    int flag = 0;
    vector<int> b;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='1')
        {
            b.push_back(i);
        }
    }
    int count = 0;
    if(b.size()){for(int i=0;i<b.size()-1;i++)
    {
        count+=b[i+1]-b[i]-1;
    }}
    cout<<count<<endl;
}
int32_t main()
{
    SPEED;
    int t=1;
    cin>>t;
    while(t--)
    {
        jawab();
    }
    return 0;
}