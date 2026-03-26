import java.util.*;
import java.io.*;
public class D614
{
	public static void main(String [] args)   
	{
		MyScanner sc = new MyScanner();
	    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	    long x_0 = sc.nextLong();
	    long y_0 = sc.nextLong();
	    long a_x = sc.nextLong();
	    long a_y = sc.nextLong();
	    long b_x = sc.nextLong();
	    long b_y = sc.nextLong();
	    long x_s = sc.nextLong();
	    long y_s = sc.nextLong();
	    long t = sc.nextLong();
	    
	    long LIMIT = ((long) 1 << 62) - 1;
	    ArrayList <Long> x = new ArrayList <Long> ();
	    ArrayList <Long> y = new ArrayList <Long> ();
	    x.add(x_0); y.add(y_0);
	    int index = 0;
	    while ((LIMIT - b_x) / (a_x) >= x.get(index) && (LIMIT - b_y) / (a_y) >= y.get(index))
	    {
	    	x.add(a_x * x.get(index) + b_x);
	    	y.add(a_y * y.get(index) + b_y);
	    	index++;
	    }
	    
	    
	    int ans = 0;
	    for (int lo = 0; lo <= index; lo++)
	    {
	    	for (int hi = lo; hi <= index; hi++)
	    	{
	    		long hi_dist = Math.abs(x_s - x.get(hi)) + Math.abs(y_s - y.get(hi));
	    		long lo_dist = Math.abs(x_s - x.get(lo)) + Math.abs(y_s - y.get(lo));
	    		long path = x.get(hi) - x.get(lo) + y.get(hi) - y.get(lo);
	    		
	    		if (path <= t - lo_dist  || path <= t - hi_dist) ans = Math.max(ans, hi - lo + 1);
	    	}
	    }
	    
	    out.println(ans);
	    out.close();
	}
	
		      
	   //-----------MyScanner class for faster input----------
	   public static class MyScanner
	   {
	      BufferedReader br;
	      StringTokenizer st;
	 
	      public MyScanner() {
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
	 
	      String nextLine(){
	          String str = "";
		  try {
		     str = br.readLine();
		  } catch (IOException e) {
		     e.printStackTrace();
		  }
		  return str;
	      }
	      
	      

	   }
	   

}
