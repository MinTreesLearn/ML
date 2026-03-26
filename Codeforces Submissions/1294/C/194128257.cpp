#include <iostream>
using namespace std;
void solve(){
    int n,a=2,b=3,c=4;
    cin>>n;
    if (n<24){
        cout<<"NO\n";
        return ;
    }
    while(a*b*c<=n){
        while(a*b*c<=n) {
            c=n/(a*b);
            if (a*b*c==n && c!=a && c!=b){
                cout<<"YES\n"<<a<<' '<<b<<' '<<c<<endl;
                return ;
            }
            b++;
            c=b+1;
        }
        a++;
        b=a+1;
        c=b+1;
    }
    cout<<"NO\n";
}
int main (){
    int n;
    cin>>n;
    while(n--)
        solve();
}