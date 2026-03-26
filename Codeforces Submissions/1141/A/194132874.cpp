#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();
    long long n,a,b,c,d=0,e,f,g,h,i,j,k;
    cin>>a>>b;
    /*e=a;
    c=log2(b/a);
    d=log2(b/a)/log2(3);
    //cout<<c<<" "<<d<<endl;
    if(a==b){
    	cout<<0<<endl;
    }
    else if(((int)(b)%2!=0 && (int)(b)%3!=0) || a>(b/3)){
    	cout<<-1<<endl;
    }
    else if(floor(c)==ceil(c)){
    	cout<<log2(c)<<endl;
    }
    else if(floor(d)==ceil(d)){
    	cout<<log2(d)/log2(3)<<endl;
    }
    else{
    	g=0;
    	h=0;
    	for( i=2;;i+=2){
    		e=e*6;
    		if(e==b){
    			cout<<i<<endl;
    			return 0;
    		}
    		else if(e>b){
    			e/=6;
    			f=e;
    			i-=2;
    			for( j=1;;j++){
    				e*=2;
    				if(e==b){
    					cout<<i+j<<endl;
    					return 0;
    				}
    				else if(e>b){
    					e/=2;
    					j--;
    					g=1;
    					break;
    				}
    			}
    			for( k=1;;k++){
    				f*=3;
    				if(e==b){
    					cout<<i+j+k<<endl;
    					return 0;
    				}
    				else if(f>b){
    					h=1;
    					break;
    				}
    			}
    			if(g==1 && h==1){
    				cout<<-1<<endl;
    			}
    		}

    	}
    }*/
    if(a==b){
    	cout<<0<<endl;
    	return 0;
    }
    else if(b%a!=0 || a>b/2){
    	cout<<-1<<endl;
    	return 0;
    }
    c=b/a;
    while(c!=1){
    	if(c%2==0){
    		c/=2;
    		d++;
    	}
    	else if(c%3==0){
    		c/=3;
    		d++;
    	}
    	else{
    		break;
    	}

    }
    if(c==1){
    	cout<<d<<endl;
    }
    else{
    	cout<<-1<<endl;
    }
    
    
    return 0;
}
