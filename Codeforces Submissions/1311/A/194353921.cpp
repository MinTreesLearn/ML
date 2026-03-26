#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,k=0;
        cin >> a >> b;
        if(a==b)
            cout << k << endl;
        else if(b>a){
            k=b-a;
            if(k%2==0)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }else{
            k=a-b;
            if(k%2==0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }

        }
    }
