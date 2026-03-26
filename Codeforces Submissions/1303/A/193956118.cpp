#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t ;
    cin>>t;
    while(t--){
        string a;
        int  k=0 ;
        cin>>a;
        for(int i=a.find('1') ;i<a.find_last_of('1');i++){
            if(a[i]=='0'){
                k++;
            }
        }
        cout <<k<<endl;
    }
    return 0;
}
