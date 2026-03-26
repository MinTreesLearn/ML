# include<iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
    int n;
    cin >> n;
    int arr[n];
    for(int j=0;j<n;j++){
        cin >> arr[j];
    }
    int min=arr[0];
    for(int k=0;k<n;k++){
        if(min>arr[k]){
        min=arr[k];
        } 
    }
    for(int j=0;j<n;j++){
        arr[j]=arr[j]-min;
    }
    int p=0;
    for(int j=0;j<n;j++){
        if ((arr[j] % 2)==1){
            p=-1;
            break;
        }
    }
    if (p==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}
}