#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool flag=false;
        int first_index=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                first_index=i;
                break;
            }
        }
        int second_index=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                second_index=i;
                break;
            }
        }
        int c=0;
        for(int i=first_index;i<second_index;i++){
            if(s[i]=='0')
                c++;
        }
        cout<<c<<endl;
    }
    return 0;
}
