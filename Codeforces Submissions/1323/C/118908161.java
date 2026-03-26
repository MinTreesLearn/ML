import java.io.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		//new Thread(null, new (), "peepee", 1<<28).start();
		
		int n =readInt();
		char[] c = read().toCharArray();
		
		int l = 0, r = 0;
		for (char ch: c) if (ch == '(')l++; else r++;
		boolean works = l==r;
		int min = 0;
		boolean bal = true;
		l = r=0;
		int b = 0;
		for (int i= 0 ; i < n;i+=1) {
			if (c[i] == '(') {
				l++;
				b++;
			}
			else {
				r++;
				b--;
			}
			if (b < 0) bal = false;
			if (b == 0) {
				if (!bal) min += (l+r);
				l = r=0;
				bal = true;
			}
		}
		
		
		out.println(!works?"-1":min);
		out.close();
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static StringTokenizer st = new StringTokenizer("");
	static String read() throws IOException{return st.hasMoreTokens() ? st.nextToken():(st = new StringTokenizer(br.readLine())).nextToken();}
	static int readInt() throws IOException{return Integer.parseInt(read());}
	static long readLong() throws IOException{return Long.parseLong(read());}
	static double readDouble() throws IOException{return Double.parseDouble(read());}
	
}