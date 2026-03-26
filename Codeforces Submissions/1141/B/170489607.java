	import java.io.*;
	import java.util.*;
	
	 
	public class ProblemA {
	 
		public static void main(String[] args) throws Exception {
			Scanner in = new Scanner();
			StringBuilder sb = new StringBuilder();
			int n  = in.readInt();
			int a[] = new int[n];
			for(int i = 0;i<n;i++){
				a[i] = in.readInt();
			}
			int ans = 0;
			for(int i = 0;i<n;i++){
				if(a[i] == 1){
					int count = 0;
					while(i<n && a[i] == 1){
						i++;
						count++;
					}
					ans = Math.max(count, ans);
				}
			}
			if(a[0] == 1 && a[n-1] == 1){
				int count = 0;
				for(int i = n-1;i>=0;i--){
					if(a[i] == 1)count++;
					else break;
				}
				for(int i = 0;i<n;i++){
					if(a[i] == 1)count++;
					else break;
				}
				ans = Math.max(ans, count);
			}
			System.out.println(ans);
			
			
			
			
			
			
	}
		public static int parity(int a){
			return a%2;
		}
		public static void swap(int a[],int i, int j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		
		public static boolean subsequence(String cur,String t){
			int pos = 0;
			for(int i = 0;i<cur.length();i++){
				if(pos<t.length() && cur.charAt(i) == t.charAt(pos)){
					pos++;
				}
			}
			return pos == t.length();
		}
		public static long gcd(long a, long b){
			return b ==0 ?a:gcd(b,a%b);
		}
		
		static class Pair{
			int x,y;
			public Pair(int x,int y){
				this.x = x;
				this.y = y;
			}
		}
		
		static class Scanner{
			BufferedReader br;
			StringTokenizer st;
			
			public Scanner(){
				br = new BufferedReader(new InputStreamReader(System.in));
			}
			
		    public String read()
		    {
		         while (st == null || !st.hasMoreElements()) {            
		            try {	st = new StringTokenizer(br.readLine()); }
		            catch (Exception e) {	e.printStackTrace(); }
		         }
		         return st.nextToken();
		     }
	
		     public int  readInt() { return Integer.parseInt(read()); }
	
		     public long readLong() { return Long.parseLong(read()); }
	
		     public double readDouble(){return Double.parseDouble(read());}
	
		     public  String readLine() throws Exception { return br.readLine(); }  
		 
		}
	
	}
	
	
