/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++){
        long a=sc.nextLong();
         long b=sc.nextLong();
          long c=sc.nextLong(); 
          long n=sc.nextLong();
          long sum=a+b+c+n;
          if(sum%3==0&&a<=sum/3&&b<=sum/3&&c<=sum/3){
              System.out.println("YES");
          }
            else{
                System.out.println("NO");
            }
        }
	}
}
