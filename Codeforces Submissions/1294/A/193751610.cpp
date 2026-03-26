#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
            vector<int> v;
        for (int i = 0; i < 3; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        cin >> n;
        int a = v[0];
        int b = v[1];
        int c = v[2];

        sort(v.begin(),v.end());

        for (int i = 0; i < 2; i++)
        {
            n -= v[2]-v[i];
        }

        if(n%3 == 0 && n>=0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
        
    }
}