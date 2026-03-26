#include <bits/stdc++.h>
#define ll long long
#define sz(x) (x).size() 
#define all(x) (x).begin(), (x).end()
#define tv ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n,m,t;
void x(){
    int a,b;
    cin>>a>>b;
    if(a<b)swap(a,b);
    if(a%b==0)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){tv cin>>t;
while(t--){
    x();
}
    return 0;
}























