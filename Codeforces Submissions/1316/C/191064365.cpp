#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,p;
    cin>>n>>m>>p;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    int f1 = 0;
    for(int i = 0; i<min(n,m); i++){
        if(a[i]%p !=0){
            f1 = i;
            break;
        }
        if(b[i]%p != 0){
            f1 = i;
            break;
        }
    }
    if(b[f1]%p != 0 && a[f1]%p != 0){
        cout<<2*f1<<endl;
    }
    else{
        if(a[f1]%p != 0){
            for(int i = f1+1; i<m; i++){
                if(b[i]%p != 0){
                    cout<<f1+i<<endl;
                    break;
                }
            }
        }
        else{
            for(int i = f1+1; i<n; i++){
                if(a[i]%p != 0){
                    cout<<f1+i<<endl;
                    break;
                }
            }
        }
    }

}