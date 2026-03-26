#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define B break
#define R return
#define C continue
#define F first
#define S second
using namespace std;
ll t,n,m,i,a[1000000],ans,sum,q,x,b;
string w;
map<int,int>mm;
char cc;
stack <char>s;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<int>());
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
}


