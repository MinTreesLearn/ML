#include<bits/stdc++.h>
using namespace std;

int main(){
int t,n,d,num;
cin >> t;
while(t--){
cin >> n >> d;
int ans=0;
for(int i=0;i<n;i++){

cin >> num;
if(i==0){
ans=num;
}else if(d>=i*num){
ans+=num;
d-=i*num;
}else{
ans+=d/i;
d=0;
}
}
cout << ans << endl;
}

}