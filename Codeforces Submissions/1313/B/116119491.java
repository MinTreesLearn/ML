import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class _practise {

	public static void main(String args[])
	{

		FastReader in=new FastReader();
		PrintWriter so = new PrintWriter(new BufferedWriter(new  OutputStreamWriter(System.out)));
		  int t = in.nextInt();
		  //int t = 1;
		 while(t-->0)
			{
			 long n = in.nextLong();
			 long x = in.nextLong();
			 long y = in.nextLong();
			 //min
			 {
				 if(x+y<=n) so.print(1);
			     else so.print(((x+y)%n==0)?n:(x+y)%n+1);
			 }
			 //max
			 {
				 if(x+y>n) so.print(" "+n);
				 else so.print(" "+(x+y-1));
			 }
			 so.println();
			}
			     
			so.flush();
			
		/*String s = in.next();
		 * BigInteger f = new BigInteger("1"); 1 ke jagah koi bhi value ho skta jo aap 
		 *                                       initial value banan chahte
			int a[] = new int[n];
			ArrayList<Integer> al = new ArrayList<Integer>(); 
			StringBuilder sb = new StringBuilder();
			Set<Long> a = new HashSet<Long>();
			so.println("HELLO");*/
	}

	static class FastReader
	{ 
		BufferedReader br; 
		StringTokenizer st; 

		public FastReader() 
		{ 
			br = new BufferedReader(new InputStreamReader(System.in)); 
		} 

		String next() 
		{ 
			while (st == null || !st.hasMoreElements()) 
			{ 
				try
				{ 
					st = new StringTokenizer(br.readLine()); 
				} 
				catch (IOException  e) 
				{ 
					e.printStackTrace(); 
				} 
			} 
			return st.nextToken(); 
		} 

		int nextInt() 
		{ 
			return Integer.parseInt(next()); 
		} 

		long nextLong() 
		{ 
			return Long.parseLong(next()); 
		} 

		double nextDouble() 
		{ 
			return Double.parseDouble(next()); 
		} 

		int[] readIntArray(int n)
		{
			int a[]=new int[n];
			for(int i=0;i<n;i++)a[i]=nextInt();
			return a;
		}

		long[] readLongArray(int n)
		{
			long a[]=new long[n];
			for(int i=0;i<n;i++)a[i]=nextLong();
			return a;
		}

		String nextLine() 
		{ 
			String str = ""; 
			try
			{ 
				str = br.readLine(); 
			} 
			catch (IOException e) 
			{ 
				e.printStackTrace(); 
			} 
			return str; 
		} 
	} 
}