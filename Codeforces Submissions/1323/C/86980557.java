import java.util.*;
import java.io.*;
public class Solution { 
	public static void main(String[] args)throws IOException { 
		Scanner in = new Scanner(System.in); 
		int t = 1,i,j; 
		StringBuilder sb = new StringBuilder(); 
		while(t-->0) {
			int n=in.nextInt(),ans=0;
			String s=in.next();
			int c=0,o=0,x=0;
			for(i=0;i<n;i++)
			{
				if(s.charAt(i)=='(')
					o++;
				else
					c++;
				if(c>o) {
					ans++;
					x=1;
				}
				if(c==o && x==1) {
					ans++;
					x=0;
				}
			}
			if(c!=o)
				ans=-1;
			System.out.println(ans);
		}
	} 
}
