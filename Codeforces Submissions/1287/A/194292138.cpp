#include <bits/stdc++.h>
using namespace std;
int main() {
int n;cin>>n;
while(n--){
    int indx=0,sum=0, s=0,t = 0;
    cin>>t;
    string srt ;
    cin>>srt;
    for(int i =0;i<10000;i++){
      s=srt.find_last_of( "A")  ;
        if(s<srt.size()){
        sum=srt.size()-s-1;
        srt.erase(s,srt.size()-s );
        }
        if(sum>indx)
        indx=sum;
    }
    cout<<indx<<endl;
}

}
 	   	 						   	 	 	 		    			