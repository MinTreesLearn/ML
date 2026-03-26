#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<vector<int>> p(n,vector<int>(2,0));
    for(int i =0; i<n; i++){
        cin>>p[i][0]>>p[i][1];
    }
    set<pair<int,int>> s;
    for(int i = 1; i<n; i++){
        pair<int,int> p1,p2,p_n1,p_n2;
        p1.first = p[i-1][0];
        p1.second = p[i-1][1];
        p2.first = p[i][0];
        p2.second = p[i][1];
        p_n1.first = p2.first-p1.first;
        p_n1.second = p2.second - p1.second;
        p_n2.first = p1.first-p2.first;
        p_n2.second = p1.second-p2.second;
        s.insert(p_n1);
        s.insert(p_n2);
    }
    s.insert(make_pair(p[0][0]-p[n-1][0],p[0][1]-p[n-1][1]));
    s.insert(make_pair(p[n-1][0]-p[0][0],p[n-1][1]-p[0][1]));
    if(s.size() == n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}