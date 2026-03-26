#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int s,ans=0;
        cin>>s;
        while(s){
            ans+=((s/10)*10);
            s=(s%10)+(s/10);
            if(s<10)break;
        }
        ans+=s;
        cout<<ans<<endl;
    }
    return 0;
}