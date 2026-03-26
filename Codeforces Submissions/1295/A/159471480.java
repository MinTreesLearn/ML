/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0)
		{
		    long n=sc.nextLong();
		    while(n>1)
		    {
		    if(n%2==0)
		    {
		         System.out.print(1);
		         n=n-2;
		    }
		    else if(n==3)
		    {System.out.print("7");
		    break;}
		    else if (n%2==1)
		    {
		         n=n-3;
		         System.out.print("7");
		         n=n/2;
		         while(n-->0)
		         {
		              System.out.print("1");
		         }
		         break;
		    }
		    }
		    System.out.println();
		}
	}
}
