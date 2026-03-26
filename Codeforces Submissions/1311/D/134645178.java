import java.util.*;
import java.lang.*;
import java.io.*;
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	    PrintWriter out=new PrintWriter(System.out);
	     int t=1;
	    t=sc.nextInt();
	    while(--t>=0){
	        int a=sc.nextInt();
	        int b=sc.nextInt();
	        int c=sc.nextInt();
	        int min=a+b+c;
	        int X=-1,Y=-1,Z=-1;
	        for(int i=1;i<=Math.max(a,Math.max(b,c))*2;i++){
	            int x;
	            int X1,Y1,Z1;
	            if(c<=i){
	                x=Math.abs(i-c)+Math.abs(i-b);
	                Z1=i;
	            }
	            else{
	                int l=(c/i)*i;
	                int u=((c+i-1)/i)*i;
	                if(Math.abs(c-l)<Math.abs(c-u)){
	                    Z1=l;
	                }
	                else{
	                    Z1=u;
	                }
	                x=Math.min(Math.abs(c-l),Math.abs(c-u))+Math.abs(b-i);
	            }
	            for(int j=1;j*j<=i;j++){
	                if(i%j==0){
	                    if(min>(x+Math.abs(a-j))){
	                        min=x+Math.abs(a-j);
	                        X=j;Y=i;Z=Z1;
	                    }
	                    if(min>(x+Math.abs(a-i/j))){
	                        min=x+Math.abs(a-i/j);
	                        X=i/j;Y=i;Z=Z1;
	                    }
	                   // min=Math.min(min,x+Math.abs(a-j));
	                   // min=Math.min(min,x+Math.abs(a-i/j));
	                }
	            }
	            
	        }
	        out.println(min);
	        out.println(X+" "+Y+" "+Z);
	        
	    }
	    out.close();
	}
}
