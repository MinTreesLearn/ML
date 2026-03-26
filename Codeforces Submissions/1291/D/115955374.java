import java.io.*;
import java.util.*;

public class D {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	public static void main(String[] args) throws IOException {
		readInput();
		out.close();
	}

	public static void readInput() throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		String s = br.readLine();
		int[][] p = new int[s.length()+1][26];
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 26; j++) {
				p[i+1][j] = s.charAt(i)-'a'==j?1:0;
				p[i+1][j] += p[i][j];
			}
		}
		int q = Integer.parseInt(br.readLine());
		while (q-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			int r=  Integer.parseInt(st.nextToken());
			if (l==r)out.println("Yes");
			else {
				int[] pre = new int[26];
				for (int j = 0; j < 26; j++) pre[j] = p[r][j]-p[l-1][j];
				int zeroes = 0;
				for (int x: pre) if (x == 0) zeroes++;
				zeroes = 26-zeroes;
				if (zeroes == 1) {
					out.println("No");
				}
				else if (zeroes >= 3) out.println("Yes");
				else {
					if (s.charAt(l-1) == s.charAt(r-1)) {
						out.println("No");
					}
					else out.println("Yes");
				}
			}
		}
	}
}
