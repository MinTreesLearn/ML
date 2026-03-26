#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int count=0;
        int arr[3];
        for(int j=0;j<3;j++){
            cin >> arr[j];
        }
        int max;
        int min;
        int mid;
        max=arr[0];
        min=arr[0];
        for(int p=0;p<3;p++){
            for(int k=0;k<2-p;k++){
                if (arr[k+1]<arr[k]){
                    int t =arr[k+1];
                    arr[k+1]=arr[k];
                    arr[k]=t;
                }
            }}
            min =arr[0];
            mid=arr[1];
            max=arr[2];
        if (min>0){
            count+=3;
            min=min-1;
            mid=mid-1;
            max=max-1;
            if (min>1){
                min=min-2;
                max=max-2;
                mid=mid-2;
                count+=3;
                if (min>0){
                    count=count+1;
                }}
             else if (min==1){
                    if (max!=min){
                    max=max-2;
                    min=min-1;
                    mid=mid-1;
                    count=count+2;
                    }
                    else {
                    count=count+1;
                    }

                }
            else if  (min==0){
                if (mid>0){
                    count=count+1;
                }
            }
            

        }
        else if (mid>0){
            count+=2;
            max=max-1;
            mid=mid-1;
            if (mid>0){
                count=count+1;
            }
        }
        else if(max>0){
        count=count+1;
        max=max-1;
        }

     cout<<count<<endl;
    }
return 0;
}