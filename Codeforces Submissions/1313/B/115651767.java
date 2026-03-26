import java.io.*;
import java.util.*;

public class B {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	public static void main(String[] args) throws IOException {
		readInput();
		out.close();
	}
	
	static int n,x,y;
	
	static int best() {
		if (x + y < n+1) return 1;
		// How many numbers can we make strictly bigger than x+y?
		int opp = x+y-n;
		return Integer.min(n, opp+1);
		
	}
	
	static int worst() {// I trust this.
		if (x + y >= n+1) return n;
		return (x+y-1);
	}

	public static void readInput() throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		int t = Integer.parseInt(br.readLine());
		while (t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			
			out.println(best() +" " + worst());
		}
	}
}
