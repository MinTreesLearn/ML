#include<iostream>
#include<algorithm>
using namespace std;
int tab[200006];
int main(){
int t;
cin>>t;
for(int k=0;k<t;k++){
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>tab[i];
    }
    sort(tab,tab+2*n);
    cout<<tab[n]-tab[n-1]<<"\n";
    for(int i=0;i<2*n;i++){
        tab[i]=0;
    }
}

}
