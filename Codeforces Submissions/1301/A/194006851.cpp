#include <bits/stdc++.h>
using namespace std;

string a,b,c;
int t;

int main()
{
    cin >> t;
    while(t--){
        cin >> a;
        cin >> b;
        cin >> c;

        bool f = true;

        for(int i=0; i<a.size(); ++i){
            if(c[i] != a[i] && c[i] != b[i]){
                f = false;
                break;
            }
        }
        if(f){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
