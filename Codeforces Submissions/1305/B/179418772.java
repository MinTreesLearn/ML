
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.StringTokenizer;
public class cf {

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					String str = br.readLine();
 
					if(str == null)
						throw new InputMismatchException();
 
					st = new StringTokenizer(str);
				} catch(IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		String nextLine() {
			String str = "";
 
			try {
				str = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}
 
			if(str == null) 
				throw new InputMismatchException();
			return str;
		}
	}
    static boolean pal(String s)
    {
    	StringBuilder sb=new StringBuilder();
    	sb.append(s);
    	sb.reverse();
    	String s1=sb.toString();
    	if(s1.contentEquals(s))
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    
    static boolean isPrime(long arr)
{
    // Corner cases
    if (arr <= 1)
        return false;
    if (arr <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (arr % 2 == 0 || arr % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= arr; i = i + 6)
        if (arr % i == 0 || arr % (i + 2) == 0)
            return false;
 
    return true;
}
    public static int reverseBits(int n)
    {
        int rev = 0;
 
        // traversing bits of 'n'
        // from the right
        while (n > 0)
        {
            // bitwise left shift
            // 'rev' by 1
            rev <<= 1;
 
            // if current bit is '1'
            if ((int)(n & 1) == 1)
                rev ^= 1;
 
            // bitwise right shift
            //'n' by 1
            n >>= 1;
        }
        // required number
        return rev;
    }
    static int fact(int n)
    {
    	int fact=1;
    	while(n>=1)
    	{
    		fact=fact*n;
    		n--;
    	}
    	return fact;
    }
    static long __gcd(long a, long b)
    {
        if (a == 0 || b == 0)
            return 0;
         
        if (a == b)
            return a;
         
        if (a > b)
            return __gcd(a-b, b);
                 
        return __gcd(a, b-a);
    }
    
    static boolean coprime(long a, long b) {
        
        if ( __gcd(a, b) == 1)
            return true;
        else
            return false;    
    }
    static int xor(int n,int a,int b)
    {
		if(n>0)
		{
			xor(n-1,b,a^b);
			return a^b;
		}
		else
		{
			return a^b;
		}
    }
	public static void main(String[] args) 
	{
		FastReader sc = new FastReader();
	    PrintWriter out = new PrintWriter(System.out);
//        int t=sc.nextInt();
//        while(t-->0)
//        {
//        	
//        }
	    String s=sc.next();
	    int n=s.length();
	    int l=s.indexOf('(');
	    int r=s.lastIndexOf(')');
	    int c1=1,c2=1;
	    ArrayList<Integer> x1=new ArrayList<Integer>();
	    ArrayList<Integer> x2=new ArrayList<Integer>();
	    if(l<r)
	    {
		    x1.add(l);
		    x2.add(r);
	    }
	    l++;
	    r--;
	    while(l<=r)
	    {
	    	if(c1>c2)
	    	{
	    		while(s.charAt(r)!=')' && l<=r)
	    		{
	    			r--;
	    		}
	    		x2.add(r);
	    		r--;
	    		c2++;
	    	}
	    	else if(c2>c1)
	    	{
	    		while(s.charAt(l)!='(' && l<=r)
	    		{
	    			l++;
	    		}
	    		x1.add(l);
	    		l++;
	    		c1++;
	    	}
	    	else
	    	{
	    		while(l<=r && c1==c2)
	    		{
	    			if(s.charAt(l)=='(' && l<=r)
	    			{
	    				c1++;
	    				x1.add(l);
	    				l++;
	    			}
	    			else if(s.charAt(r)==')' && l<=r)
	    			{
	    				c2++;
	    				x2.add(r);
	    				r--;
	    			}
	    			else
	    			{
	    				l++;
	    				r--;
	    			}
	    		}
	    	}
	    }
	    if(!x1.isEmpty() && !x2.isEmpty())
	    {
		    Collections.sort(x1);
		   	Collections.sort(x2);
		    while((long)x1.get(x1.size()-1)>(long)x2.get(0))
		    {
		    	x1.remove(x1.size()-1);
		    	x2.remove(0);
		    }
		    while(x1.get(0)<0)
		    {
		    	x1.remove(0);
		    }
	    	while(x1.size()>=1 && x2.size()>=1 &&(long)x1.get(x1.size()-1)==(long)x2.get(0))
	    	{
	    		x1.remove(x1.size()-1);
	    		x2.remove(0);
	    	}
		   	int k1=x1.size(),k2=x2.size();
		   	while(x1.size()>Math.min(k1,k2))
		   	{
		   		x1.remove(x1.size()-1);
		   	}
	    	while(x2.size()>Math.min(k1,k2))
	    	{
	    		x2.remove(0);
		    }
	    }
	    if(x1.isEmpty() || x2.isEmpty())
	    {
	    	out.println(0);
	    }
	    else
	    {
		   	out.println(1);
		   	out.println(x1.size()+x2.size());
		   	for(int i=0;i<x1.size();i++)
		   	{
	    		out.print((x1.get(i)+1)+" ");
	    	}
		   	for(int i=0;i<x2.size();i++)
		    {
		   		out.print((x2.get(i)+1)+" ");
		   	}
	    }
	    out.close();
	}
}