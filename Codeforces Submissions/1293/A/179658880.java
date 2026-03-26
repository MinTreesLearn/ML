
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
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
        int t=sc.nextInt();
        while(t-->0)
        {
        	long n=sc.nextLong();
			long s=sc.nextLong();
			long k=sc.nextLong();
			long arr[]=new long[(int) k];
			HashMap<Long,Boolean> x=new HashMap<Long,Boolean>();
			for(int i=0;i<k;i++)
			{
				x.put(sc.nextLong(),false);
			}
			long s1=s,s2=s;
			while(true)
			{
				if(!x.containsKey(s) && s<=n)
				{
					out.println(Math.abs(s2-s));
					break;
				}
				if(!x.containsKey(s1) && s1>=1)
				{
					out.println(Math.abs(s1-s2));
					break;
				}
				s++;
				s1--;
			}
        }
	    out.close();
	}
}