#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    set<pair<int,int>> invalid;
    vector<int> r1(n+1,0);
    vector<int> r2(n+1,0);
    for(int i = 0; i<q; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        if(temp1 == 1){
            if(r1[temp2-1] == 1){
                r1[temp2-1] = 0;
                if(r2[temp2-1] == 1){
                    invalid.erase(make_pair(temp2,temp2));
                }
                if(r2[temp2-2] == 1){
                    invalid.erase(make_pair(temp2, temp2-1));
                }
                if(r2[temp2] == 1){
                    invalid.erase(make_pair(temp2, temp2+1));
                }
                if(invalid.size() == 0){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            else{
                r1[temp2-1] = 1;
                if(r2[temp2-1] == 1){
                    invalid.insert(make_pair(temp2,temp2));
                }
                if(r2[temp2-2] == 1){
                    invalid.insert(make_pair(temp2, temp2-1));
                }
                if(r2[temp2] == 1){
                    invalid.insert(make_pair(temp2, temp2+1));
                }
                if(invalid.size() == 0){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
        }
        else{
            if(r2[temp2-1] == 1){
                r2[temp2-1] = 0;
                if(r1[temp2-1] == 1){
                    invalid.erase(make_pair(temp2,temp2));
                }
                if(temp2 >=2 && r1[temp2-2] == 1){
                    //Maybe this can go out of bound 
                    invalid.erase(make_pair(temp2-1, temp2));
                }
                if(temp2<n && r1[temp2] == 1){
                    invalid.erase(make_pair(temp2+1, temp2));
                }
                if(invalid.size() == 0){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            else{
                r2[temp2-1] = 1;
                if(r1[temp2-1] == 1){
                    invalid.insert(make_pair(temp2,temp2));
                }
                if(temp2 >=2 && r1[temp2-2] == 1){
                    //Maybe this can go out of bound 
                    invalid.insert(make_pair(temp2-1, temp2));
                }
                if(temp2<n && r1[temp2] == 1){
                    invalid.insert(make_pair(temp2+1, temp2));
                }
                if(invalid.size() == 0){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
             }
        }
    }
}