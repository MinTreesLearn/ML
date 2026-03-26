 // don't place package name! 
 
import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	       Scanner op= new Scanner(System.in);
	      int t = op.nextInt();
	      while(t-->0){
	           int n = op.nextInt();
	        String s = op.next();
	        int count=0;
	        boolean A = false;
	        int max=0;
	         for(int i =0;i<n;i++){
	              if(s.charAt(i)=='A'){
	                   A = true;
	                   if(max<count){
	                        max=count;
	                   }
	                   count=0;
	              }
	              if(s.charAt(i)=='P'&& A!=false){
	                   count++;
	              }
	              }
	              if(count>max && A!=false){
	                   max=count;
	              }
	              System.out.println(max);
	         }
	        
	        
	     }
}