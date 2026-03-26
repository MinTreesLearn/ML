# include<iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int k;
        if (n%2==0){
             k=n/2;
        }
        else{
             k=(n-3)/2;
        }
        if (n%2==0){
        for(int g=0;g<k;g++){
            cout<<"1";
        }
        }
        else
        {
            cout<<"7";
            for(int y=0;y<k;y++){
                cout<<"1";
            }
        }
        cout<<endl;
    }
}