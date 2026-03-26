// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class CF1294C {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		int cases = Integer.parseInt(st.nextToken());
		for (int i = 0; i < cases; i++) {
			StringTokenizer st1 = new StringTokenizer(r.readLine());
			int num = Integer.parseInt(st1.nextToken());
			ArrayList<Integer> yippee = new ArrayList<Integer>();

			for (int n = 0; n < 2; n++) {
				//each time, get a factor and add it to YIPPEE!!!!!!!!!!!
				//if no factors then print NO!!
				//ok.
				for (int j = 2; j < Math.sqrt(num); j++) {
					if (num % j == 0 && yippee.contains(j) == false) {
						yippee.add(j);
						num /= j;
						break;
					}
				}
			}
			if (yippee.size() == 2) {
				pw.println("YES");
				pw.println(yippee.get(0) + " " + yippee.get(1) + " " + num);
			} else {
				pw.println("NO");
			}
		}
		/*
		 * Make sure to include the line below, as it
		 * flushes and closes the output stream.
		 */
		pw.close();
	}
}
