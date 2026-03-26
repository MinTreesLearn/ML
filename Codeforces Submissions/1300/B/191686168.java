/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner sc=new Scanner(System.in);
	int t=sc.nextInt();
	for(int p=0;p<t;p++)
	{
	    int n=sc.nextInt();
	    int[] arr=new int[2*n];
	    for(int q=0;q<2*n;q++)
	    {
	        arr[q]=sc.nextInt();
	    }
	    Arrays.sort(arr);
	   System.out.println(arr[n]-arr[n-1]);
	}
	
	}
}
