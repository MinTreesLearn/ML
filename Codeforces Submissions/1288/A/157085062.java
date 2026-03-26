import java.io.*;
import java.util.*;
import java.lang.*;
public class Codeforces {
   public static void main(String[] args)
    {
		Scanner input= new Scanner(System.in);
		int test=input.nextInt();
		while(test-->0){
		double n=input.nextLong();
		double d=input.nextLong();
		boolean ok=false;
		for(double i=0;i<n;i++)
		{
		 if(i+Math.ceil(d/(i+1))<=n)
		 {
		ok=true;
		 break;
		 }
		}
		if(ok==true)
		{
		System.out.println("YES");
		}
		else
		{
		 System.out.println("NO");
		}
			
		}
    }
}


