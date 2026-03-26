


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.*;

public class Solution {
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }		
	
	static class Pair {
	    int x;
	    int y;
	    int z;
	    // Constructor
	public Pair(int x, int y, int z)
	    {
	        this.x = x;
	        this.y = y;
	        this.z = z;
	    }
//	 @Override
//	    public int hashCode() {
//	        return this.x ^ this.y;
//	    }
//
//	    @Override
//	    public boolean equals(Object obj) {
//	        if (this == obj)
//	            return true;
//	        if (obj == null)
//	            return false;
//	        if (getClass() != obj.getClass())
//	            return false;
//	        Pair other = (Pair) obj;
//	        if (x != other.x)
//	            return false;
//	        if (y != other.y)
//	            return false;
//	        return true;
//	    }
	}
	
	static class Quad {
		String a;
		String b;
		String c;
		String d;
	  
	    // Constructor
	public Quad(String a, String b, String c, String d)
	    {
	        this.a = a;
	        this.b = b;
	        this.c = c;
	        this.d = d;
	    }
	 
	}
	public static void swap(int i, int[] arr) {
		int temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	
}

	
	static boolean isPrime(long n)
    {
        // Corner cases
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
  
        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n % 2 == 0 || n % 3 == 0)
            return false;
  
        for (long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
  
        return true;
    }
	
	static long gcd(long a, long b)
	{
	    if (a == 0)
	        return b;
	    else if (b == 0)
	        return a;
	    if (a < b)
	        return gcd(a, b % a);
	    else
	        return gcd(b, a % b);
	}
	 
	static int factorial(int n)
	  {
	  
	    // single line to find factorial
	    return (n == 1 || n == 0) ? 1 : (n * factorial(n - 1))/1000000007;
	  
	  }
	  
	// Function to convert decimal to fraction
	public static void SubString(String str, int n, HashSet<String> hs)
    {
       for (int i = 0; i < n; i++)
           for (int j = i+1; j <= n; j++)
            
                // Please refer below article for details
                // of substr in Java
                // https://www.geeksforgeeks.org/java-lang-string-substring-java/
                hs.add(str.substring(i, j));
    }
	
	static class TrieNode{
        TrieNode children[];
        boolean isEnd;
         
        TrieNode(){
            this.children = new TrieNode[26];          
            this.isEnd = false;
        }
    }
     
	static void subStrings(String s,HashSet<String> hs)
	{
	 
	    // To store distinct output subStrings
	    HashSet<String> us = new HashSet<String>();
	 
	    // Traverse through the given String and
	    // one by one generate subStrings beginning
	    // from s[i].
	    for (int i = 0; i < s.length(); ++i)
	    {
	 
	        // One by one generate subStrings ending
	        // with s[j]
	        String ss = "";
	        for (int j = i; j < s.length(); ++j)
	        {
	            ss = ss + s.charAt(j);
	            us.add(ss);
	        }
	    }
	 
	    // Print all subStrings one by one
	    for (String str : us) {
	    	hs.add(str);
	    }
	        
	}
	static boolean isSubSequence(String str1, String str2,
            int m, int n)
	{
	int j = 0;
	
	// Traverse str2 and str1, and compare
	// current character of str2 with first
	// unmatched char of str1, if matched
	// then move ahead in str1
	for (int i = 0; i < n && j < m; i++)
	if (str1.charAt(j) == str2.charAt(i))
	j++;
	
	// If all characters of str1 were found
	// in str2
	return (j == m);
	}
	static int onesComplement(int n)
    {
          
        // Find number of bits in the 
        // given integer
        int number_of_bits = 
               (int)(Math.floor(Math.log(n) /
                             Math.log(2))) + 1;
  
        // XOR the given integer with poe(2,
        // number_of_bits-1 and print the result
        return ((1 << number_of_bits) - 1) ^ n;
    }
	public static void main(String[] args) throws IOException{
		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		FastReader sc = new FastReader();	
//		int t = sc.nextInt();
//		while(t-- > 0) {

			long H = sc.nextLong();
			int n = sc.nextInt();
			long[] arr = new long[n];
			long diff=0;
			long min=Integer.MAX_VALUE;
			for(int i=0;i<n;i++) {
				arr[i]=sc.nextLong();
				diff+=arr[i];
				min=Math.min(min, diff);
				if(diff+H<=0) {
					System.out.println(i+1);
					return;
				}	
			}
			if(diff>=0) {
				System.out.println(-1);
				return;
			}
			long HH=H;
			H=H+min;
			
			//System.out.println(min);
			//System.out.println(H);
			long ans=H/Math.abs(diff);
			//System.out.println(ans);
			H=H%Math.abs(diff);
			if(H!=0) { ans++;H=HH-(Math.abs(diff)*(ans));}
			else H=HH-(Math.abs(diff)*ans);
			//System.out.println(H);
			diff=0;
			for(int i=0;i<n;i++) {
				diff+=arr[i];
				if(diff+H<=0) {
					System.out.println(i+1+(ans*n));
					return;
				}	
			}
		}
//	
//		}	
		//output.flush();
		
}
		
	
	
