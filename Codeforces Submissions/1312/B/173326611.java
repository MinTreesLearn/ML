import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InterruptedIOException;
import java.security.PublicKey;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
public class Main {
	
	
	
	static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
	
	
	static void Parr(int[] arr) {
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}

	
	
	
	
	
	
	
	
    static void sort(int[] a) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }
 
    static void sort(long[] a) {
        ArrayList<Long> q = new ArrayList<>();
        for (long i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }
	
	
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}



	static long binpow(long a,long b) {
		long M=1000000007;
		long res=1;
		while(b>0) {
			if(b%2==1) {
				res=(res*a)%M;
			}
			a=(a*a)%M;
			b/=2;
		}

		return res;

	}
	
	
	static boolean ispalindrome(String s,int n) {
		
		for(int i=0;i<n;i++) {
			if(s.charAt(i)==s.charAt(s.length()-1-i)) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	
	
	static boolean isSquare(long x) 
	{
        long y = (long)Math.sqrt(x);
        return y*y==x;
    }
	
	
	
    static int computeXOR(int n)
    {
        // If n is a multiple of 4
        if (n % 4 == 0)
            return n;
      
        // If n%4 gives remainder 1
        if (n % 4 == 1)
            return 1;
      
        // If n%4 gives remainder 2
        if (n % 4 == 2)
            return n + 1;
      
        // If n%4 gives remainder 3
        return 0;
    }
    
    
    static boolean prime[] = new boolean[100000 + 1];
    
    public static void SoE(int n)
    {
        // Create a boolean array "prime[0..n]" and
        // initialize all entries it as true. A value in
        // prime[i] will finally be false if i is Not a
        // prime, else true.
        
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a
            // prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which
                // are multiple of p and are less than p^2
                // are already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
 
        // Print all prime numbers
//        for (int i = 2; i <= n; i++) {
//            if (prime[i] == true)
//                System.out.print(i + " ");
//        }
    }
    
    
    
   static class Pair{
    	int idx;
    	long val;
    	public Pair(int idx,int val) {
			// TODO Auto-generated constructor stub
    		this.idx=idx;
    		this.val=val;
		}
    }
	
	
	
  //REMINDERS:
    //- CHECK FOR INTEGER-OVERFLOW BEFORE SUBMITTING
 
    //- CAN U BRUTEFORCE OVER SOMETHING, TO MAKE IT EASIER TO CALCULATE THE SOLUTION

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastReader sc1=new FastReader();
		
		int t=sc1.nextInt();
		
		//SoE(100000);
		
		w:while(t-->0) {
			
			
			int n=sc1.nextInt();
			int arr[]=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=sc1.nextInt();
			}
			
			arr = Arrays.stream(arr).
				    boxed().
				    sorted((a, b) -> b.compareTo(a)). // sort descending
				    mapToInt(i -> i).
				    toArray();
			
			Parr(arr);
}
}
}
