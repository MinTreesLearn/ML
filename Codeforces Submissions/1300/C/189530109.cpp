#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    vector<int> bit_set(32,0);
    for(int i =0; i<n; i++){
        cin>>a[i];
        int temp = a[i];
        for(int j = 0; j<32; j++){
            if(temp & (1LL<<j)){
                bit_set[j]++;
            }
        }
    }
    int index = -1;
    for(int i =0; i<32; i++){
        if(bit_set[i] == 1){
            index = i;
        }
    }
    if(index == -1){
        for(int i =0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        int first = 0;
        for(int i =0; i<n; i++){
            if(a[i] & (1LL<<index)){
                first = a[i];
                a[i] = -1;
                break;
            }
        }
        cout<<first<<" ";
        for(int i =0; i<n; i++){
            if(a[i] != -1){
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
}
