#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    if(m%n!=0){
        cout<<-1<<endl;
        return 0;
    }
    if(n==m){
        cout<<0<<endl;
        return 0;
    }

    int ans = m/n;
    int count = 0;
    while(ans % 3 == 0){
        ans /= 3;
        count++;
    }
    while(ans % 2 == 0){
        ans /= 2;
        count++;
    }
    if(ans != 1){
        cout<<-1<<endl;
    }
    else cout<<count<<endl;
    
}
