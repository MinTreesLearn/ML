# include<iostream>
#include<cmath>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n]; // robo_coder robot
    int b[n]; // bionic_solver robot
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int k=0;k<n;k++){
        cin>>b[k];
    }
    float sa=0;
    float sb=0;
    float p=0; 
    for(int j=0;j<n;j++){
   sa=sa+a[j];
   sb=sb+b[j];
   if(a[j]>b[j]){
    p++;
   }}


    if (p!=0){
        cout<<1+ceil(((sb-sa+1)/p))<<endl;
    }
    else{
        cout<<-1<<endl;
    }

}