/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
    static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
	    int t = sc.nextInt();
	    for(int i = 0 ; i < t;i++)
	    {
	        String a = sc.next();
	        String b =sc.next();
	        String c = sc.next();
	        check(a,b,c);
	    }
	}
	static void check(String a, String b , String c)
	{
	    int[]freq =new int[26];
	    String ans = "YES";
	    for(int i = 0 ; i < a.length();i++)
	    {
	        if(a.charAt(i)==b.charAt(i)&&c.charAt(i)!=a.charAt(i)){
	            ans="NO";
	            break;
	        }
	        if(a.charAt(i)!=b.charAt(i))
	        {
	            if(c.charAt(i)!=b.charAt(i)&&c.charAt(i)!=a.charAt(i)){
	                ans = "NO";
	                break;
	            }
	        }
	    }
	    System.out.println(ans);
	}
}
