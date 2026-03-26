import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class code6 {

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
	public static void main(String[] args) throws CloneNotSupportedException {
		// TODO Auto-generated method stub
		FastReader scn = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		//int p = t;
		while(t-->0) {
			int n = scn.nextInt();
			int m = scn.nextInt();
			if(n == 1) {
				if(m>0)
					out.print(-1);
				else
					out.print(1);
				continue;
			}
			if(n == 2) {
				if(m>0)
					out.print(-1);
				else
					out.print("1 2");
				continue;
			}
			int a = (int) Math.sqrt(m);
			int p = 2*a+1;
			if(n<p) {
				System.out.println(-1);
				continue;
			}
			int[] dp = new int[n];
			for(int i=0; i<p; i++)
				dp[i] = i+1;
			int k = m-(int)Math.pow(a, 2);
			if(k>0 && n<p+1) {
				System.out.println(-1);
				continue;
			}
			if(k>dp[p-1]/2 && n<p+2) {
				System.out.println(-1);
				continue;
			}
			int j = p;
			if(k>=dp[p-1]/2) {
				dp[p] = p+1;
				j = p+1;
				k -= dp[p-1]/2;
			}
			if(k>0) {
				dp[j] = dp[j-1]+dp[j-1]-2*k;
				j++;
			}
			int v = dp[j-1]+1;
			while(j<n) {
				dp[j] = dp[j-1]+v;
				j++;
			}
			for(int i=0; i<n; i++)
				out.print(dp[i] + " ");
				
			
		}
		
		out.flush();
	}
	
  
	public static boolean check(int mid, int c, int[] arr, int k) {
		int ans = 0;
		for(int i=0; i<arr.length; i++) {
			if(c==0) {
				ans++;
				c = (c+1)%2;
			}else {
				if(arr[i]<=mid) {
					ans++;
					c = (c+1)%2;
				}
			}
		}
		return ans>=k;
	}
	public static int power(int x, int y, int p) 
    { 
        // Initialize result 
        int res = 1;      
         
        // Update x if it is more   
        // than or equal to p 
        x = x % p;  
  
       if (x == 0) return 0; // In case x is divisible by p;    
  
        while (y > 0) 
        { 
            // If y is odd, multiply x 
            // with result 
            if((y & 1)==1) 
                res = (res * x) % p; 
      
            // y must be even now 
            // y = y / 2 
            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res; 
    } 
	
	public static class Pair implements Comparable<Pair>{
		int i;
		int t;
		int a;
		int b;
		Pair(int i,int m, int s, int k){
			this.i = i;
			t = m;
			a = s;
			b = k;
		}
		public int compareTo(Pair p) {
			return this.t-p.t;
		}
	}
    
}

