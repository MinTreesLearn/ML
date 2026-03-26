import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C{
	static int n,m;
	static boolean w(int i, int j) {
		return min(i,j)>=0 && i < n && j < m;
	}
	static class Type{
		char mov;
		int i, j;
		public Type(char a, int b, int c) {
			mov=a;
			i=b;
			j=c;
		}
	}
	static StringBuilder res = new StringBuilder();
	static void add(char c, int times) {
		while(times-->0 && k--> 0)res.append(c);
 	}
	static int k;
	
	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		//new Thread(null, new (), "peepee", 1<<28).start();
		 n=readInt();
		 m =readInt();
		k =readInt();
		if (4*n*m-2*(m+n) < k) {
			System.out.println("NO");
			System.exit(0);
		}
		out.println("YES");
		
		for (int i = 0; i < m; i++) {
			if (i == m-1) {
				add('D', n-1);
				for (int j = 0; j < n-1; j++) {
					add('L', m-1);
					add('R', m-1);
					add('U', 1);
				}
				add('L', m-1);
				
			}
			else {
				add('D',n-1);
				add('U', n-1);
				add('R', 1);
			}
		}
		List<String> ans = new ArrayList<String>();
		char c = res.charAt(0);
		int len = 1;
		for (int i = 1; i < res.length(); i++) {
			if (res.charAt(i) == c) len++;
			else {
				ans.add("" + len + " " + c);
				len = 1;
			}
			c=res.charAt(i);
		}
		
		ans.add("" + len + " " + c);
		out.println(ans.size());
		for (String s: ans) out.println(s);
		//System.out.println(res + " " +res.length());
		out.close();
	}
	
	/* Stupid things to try if stuck:
	 * n=1, expand bsearch range
	 * brute force small patterns
	 * submit stupid intuition
	 */
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static StringTokenizer st = new StringTokenizer("");
	static String read() throws IOException{return st.hasMoreTokens() ? st.nextToken():(st = new StringTokenizer(br.readLine())).nextToken();}
	static int readInt() throws IOException{return Integer.parseInt(read());}
	static long readLong() throws IOException{return Long.parseLong(read());}
	static double readDouble() throws IOException{return Double.parseDouble(read());}
}