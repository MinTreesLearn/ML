import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution{
	
	static long mod = 998244353L;
	
	public static void main(String[] args) throws Exception{

		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int n = fs.nextInt();
		int[] b = fs.readArray(n);
		
		HashMap<Integer, Long> map = new HashMap<Integer, Long>();
		
		long ans = 0L;
		
		for(int i=0;i<n;i++) {
			int cnst = b[i] - i;
			map.put(cnst, map.getOrDefault(cnst, 0L) + b[i]);
			ans = Math.max(ans, map.get(cnst));
		}
		
		out.println(ans);
		
		
		
		out.close();
	}
	
	

	
	static class FastScanner{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		public String next(){
			while(!st.hasMoreElements()){
				try{
					st = new StringTokenizer(br.readLine());
				} catch(IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		public String nextLine() throws IOException {
			return br.readLine();
		}
		
		public int nextInt(){
			return Integer.parseInt(next());
		}

		public int[] readArray(int n){
			int[] a = new int[n];
			for(int i=0;i<n;i++)
				a[i] = nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	
}
