#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string str , ans;
    int t,n,x,i;
    cin>>t;
    
    while( t-- ){
        cin>>n>>str;
        x = 2;
        ans = "";
        for( i=0 ; i<n && x>0 ; i++ ){
            if( (str[i]-'0') % 2 ){
                x--;
                ans += str[i];
            }
        }
        if( x>0 )
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    
    return 0;
}