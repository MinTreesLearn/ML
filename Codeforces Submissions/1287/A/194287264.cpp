#include<bits/stdc++.h>
#define Mohamed ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
#define ll long long
using namespace std;
int main()
{
    Mohamed
    int t,sum=0;cin>>t;
    while(t--)
    {
        int x,c1=0,c2=0;cin>>x;
        bool bl=false;
        for (size_t i = 0; i < x; i++)
        {
            char c;cin>>c;
            if(c=='A'){bl=true; c1=0;}
            else if(bl){c1++;}
            c2=max(c1,c2)  ; 
        }
        cout<<c2<<endl;
    }
    
}
				 	 		    	 	    	 	 	  	 	