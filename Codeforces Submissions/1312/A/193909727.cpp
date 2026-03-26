#include <bits/stdc++.h>

#define tvoy ios::sync_with_stdio(false);
#define sex cin.tie(0); cout.tie(0)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

int main(){
    tvoy sex;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if (a%b==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
