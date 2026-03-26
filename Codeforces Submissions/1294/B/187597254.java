
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class CF {
	
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
//    	StringBuilder strBuilder = new StringBuilder(s);
//        return s.equals(strBuilder.reverse().toString());
boolean p=true;
    	int l=0,r=s.length()-1;
    	while(l<r)
    	{
    		if(s.charAt(r)!=s.charAt(l))
    		{
    			p=false;
    			break;
    		}
    		l++;
    		r--;
    	}
    	return p;
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
    static long gcd(long a, long element)
    {
        if (a == 0)
            return  element;
        return gcd((element % a), a);
    }
    static long findGCD(long arr[], int n)
    {
    	Arrays.sort(arr);
        long result = arr[0];
        for (long element: arr){
            result = gcd(result, element);
 
            if(result == 1)
            {
               return (long)1;
            }
        }
 
        return result;
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
		// TODO Auto-generated method stub
		FastReader sc = new FastReader();
	    PrintWriter out = new PrintWriter(System.out);
	    StringBuilder sb=new StringBuilder();
	    int t=sc.nextInt();
	    while(t-->0)
	    {
	    	int n=sc.nextInt();
	    	ArrayList<Long> key=new ArrayList<Long>();
	    	HashMap<Long,ArrayList<Long>> x=new HashMap<Long,ArrayList<Long>>();
	    	for(int i=0;i<n;i++)
	    	{
	    		long x1=sc.nextLong();
	    		long y1=sc.nextLong();
	    		if(x.containsKey(x1))
	    		{
	    			x.get(x1).add(y1);
	    		}
	    		else
	    		{
	    			ArrayList<Long> x2=new ArrayList<Long>();
	    			x2.add(y1);
	    			key.add(x1);
	    			x.put(x1, x2);
	    		}
	    	}
	    	Collections.sort(key);
	    	boolean p1=true;
	    	long p=0,q=0;
	    	String s="";
	    	for(int i=0;i<key.size();i++)
	    	{
	    	    long x3=key.get(i)-p;
	    	    while(x3-->0)
	    	    {
	    	    	s=s+"R";
	    	    }
	    	    Collections.sort(x.get(key.get(i)));
	    	    long x4=x.get(key.get(i)).get(x.get(key.get(i)).size()-1)-q;
	    	   if(x.get(key.get(i)).get(0)-q<0)
	    	   {
	    		   p1=false;
	    		   break;
	    	   }
	    	    while(x4-->0)
	    	    {
	    	    	s=s+"U";
	    	    }
	    	    p=key.get(i);
	    	    q=x.get(key.get(i)).get(x.get(key.get(i)).size()-1);
	    	}
	    	if(p1)
	    	{
	    		out.println("YES");
	    		out.println(s);
	    	}
	    	else
	    	{
	    		out.println("NO");
	    	}
	    	
	    }
	    out.close();
	}

}
