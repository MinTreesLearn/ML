//Dhiraj's Template
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define testcase int t;cin>>t;while(t--)
#define forloop(start,size) for(int i=start;i<size;i++)
#define all(v) v.begin(),v.end()
#define foreachx(v) for(auto&x:v)
#define maxofvec(v) *max_element(v.begin(),v.end())
#define minofvec(v) *min_element(v.begin(),v.end())
#define M 1000000007

void D(){
    // int a,b,c;
    // cin>>a>>b>>c;
    // int count=0;
    // if(a>0){
    //     a = a-1;
    //     count++;
    // }
    // if(b>0){
    //     b = b-1;
    //     count++;
    // }
    // if(c>0){
    //     c = c-1;
    //     count++;
    // }
    // if(a>0 && b>0){
    //     a = a-1;
    //     b = b-1;
    //     count++;
    // }
    // if(a>0 && c>0){
    //     a = a-1;
    //     c = c-1;
    //     count++;
    // }
    // if(c>0 && b>0){
    //     c = c-1;
    //     b = b-1;
    //     count++;
    // }
    // if(a>0 && b>0 && c>0){
    //     count++;

    // }
    // cout<<count<<endl;
    int count=0;
    int arr[3];
    forloop(0,3){

        cin>>arr[i];
    }
    sort(arr,arr+3);
    if(arr[0]>0){
        count++;
        arr[0]--;
    }
    if(arr[1]>0){
        count++;
        arr[1]--;
    }
    if(arr[2]>0){
        count++;
        arr[2]--;
    }
    sort(arr,arr+3);
    if(arr[2]>0 && arr[1]>0){
        count++;
        arr[2]--;
        arr[1]--;
    }
    if(arr[2]>0 && arr[0]>0){
        count++;
        arr[2]--;
        arr[0]--;
    }
    if(arr[0]>0 && arr[1]>0){
        count++;
        arr[0]--;
        arr[1]--;
    }
    if(arr[0]>0 && arr[1]>0 && arr[2]>0){
        count++;
    }
    cout<<count<<endl;
    
}

signed main(){
   
    testcase{
        D();
    }
    
    return 0;
}
