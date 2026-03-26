//package differentrules;

import java.util.*;
import java.io.*;

public class differentrules {
	public static void main(String[] args) throws IOException {
		BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(fin.readLine());
		StringBuilder fout = new StringBuilder();
		while(t-- > 0) {
			StringTokenizer st = new StringTokenizer(fin.readLine());
			int n = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int max = Math.min(a + b - 1, n);
			int min = Math.min(Math.max((a + b + 1) - n, 1), n);
			fout.append(min).append(" ").append(max).append("\n");
		}
		System.out.print(fout);
	}
}
