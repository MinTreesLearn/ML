
import java.util.*;
import java.lang.*;
import java.io.*;


public class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		  Scanner sc = new Scanner(System.in);
        
          int n = sc.nextInt();
          String s = sc.next();
          int l=0,r=0;
          
          for(char c:s.toCharArray()){
              if(c=='L')l++;
              if(c=='R')r++;
          }
          System.out.println(l+r+1);
	}
}
