import static java.lang.Math.*;
import java.awt.Point;
import java.io.*;
import java.util.*;


public class Exercise {	
	
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	private static void solve() {
		readLine();
		int part = nextInt(); int ina = nextInt(); int time = 0; int inb = ina;
		
		
		int a, b; boolean allPC = true;
		for(int i = 0; i < part; i++) {
			readLine();
			int tm = nextInt(); int space = tm - time; time = tm;
			a = nextInt(); b = nextInt();
			
			if(min(a, b) > inb + space || max(a, b) < ina - space) {
				 allPC = false;
			}
			
			ina = min(a, b) <= ina - space ? ina - space : a;
			inb = max(a, b) >= inb + space ? inb + space : b;
		}
		
		System.out.println(allPC ? "YES" : "NO");
	}

	public static void main(String args[]) {
		readLine();
		
		int testcases = nextInt();
		
		while(testcases-- != 0) solve();
	}

	public static int nextInt() {
		return Integer.parseInt(st.nextToken());
	}
	
	public static String nextLine() {
		try {
			st = new StringTokenizer(br.readLine());
		} catch(Exception e) {}
		
		return st.nextToken();
	}
	
	public static void readLine() {
		try {
			st = new StringTokenizer(br.readLine());
		} catch(Exception e) {}
		
	}
	
}
