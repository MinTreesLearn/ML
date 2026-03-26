#include<iostream>
#include<stdio.h>
#include<list>
#include<set>
#include<map>
#include<string>
#include<functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,k,n) for(int i=k;i<n;i++)
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;int a[n];forn(i,0,n){cin>>a[i];}
        int k=0;
        int k1=0;
        // if(n==1){cout<<"YES"<<endl;continue;}
        forn(i,0,n){
            if(a[i]%2==0){k++;}
            if(a[i]%2!=0){k1++;}
        }
        if(k==n){cout<<"YES"<<endl;continue;}
        if(k1==n){cout<<"YES"<<endl;continue;}
        else{cout<<"NO"<<endl;}
    }
    return 0;
}