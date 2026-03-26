// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.StringTokenizer;

public class CF1370B2 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		int cases = Integer.parseInt(st.nextToken());
		for (int i = 0; i < cases; i++) {
			StringTokenizer st1 = new StringTokenizer(r.readLine());
			int len = Integer.parseInt(st1.nextToken());
			int dist = Integer.parseInt(st1.nextToken());
			StringTokenizer st2 = new StringTokenizer(r.readLine());
			int hoppage = -1;
			for (int j = 0; j < len; j++) {
				int next = Integer.parseInt(st2.nextToken());
				if (next == dist) {
					hoppage = next;
					break;
				}
				hoppage = Math.max(hoppage, next);
			}
			if (hoppage == dist) {
				pw.println(1);
			} else {
				//pw.println(dist/(double)hoppage);
				pw.println( (int) Math.max(Math.ceil(dist/(double) hoppage), 2));
			}
		}
		/*
		 * Make sure to include the line below, as it
		 * flushes and closes the output stream.
		 */
		pw.close();
	}
}
