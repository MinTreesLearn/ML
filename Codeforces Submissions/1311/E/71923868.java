import java.util.*;

import java.io.*;

public class dsu {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(br.readLine());
		TreeSet<Integer> div[] = new TreeSet[3 * 10000];
		for (int i = 0; i < div.length; i++) {
			div[i] = new TreeSet<>();
		}
		for (int i = 1; i < div.length; i++) {
			for (int j = 1; j <= Math.ceil(Math.sqrt(i)); j++) {
				if (i % j == 0) {
					div[i].add(j);
					div[i].add(i / j);
				}
			}
		}
		while (t-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			ArrayList<Integer> a = new ArrayList<>();
			int i = 1;
			int sum = 0;
			int idx = 0;
			int x = 1;
			int q = n - 1;
			while (n > 0) {
				a.add(Math.min(i, n));
				n -= Math.min(i, n);
				i *= 2;
			}
			for (int j = 0; j < a.size(); j++) {
				sum += a.get(j) * (j);

			}
			boolean f = true;
			long max = (q * 1l * (q + 1)) / 2;
			if (m < sum || m > max) {
				f = false;
			}
			m -= sum;
			// System.out.println(a+" "+sum);
			x = -1;
			if (f)
				while (m != 0 && sum != max && sum != x) {
					x = sum;
					for (int j = 0; j < a.size() - 1; j++) {
						if ((a.get(j) - 1) * 2 >= (a.get(j + 1) + 1)) {
							a.set(j, a.get(j) - 1);
							a.set(j + 1, a.get(j + 1) + 1);
							sum++;
							m--;
							break;

						}
					}
					if (sum == x && a.get(a.size() - 1) != 1) {
						a.add(1);
						a.set(a.size() - 2, a.get(a.size() - 2) - 1);
						sum++;
						m--;
					}
				}
			if (f) {
				System.out.println("YES");
				x = 1;
				int r=1;
				for (int j = 1; j < a.size(); j++) {
					x=r;
					int w = a.get(j);
					while (w != 0) {
						int e = Math.min(w, 2);
						w -= e;
						while (e-- > 0) {
							System.out.print(x + " ");
						}
						x++;
					}
					r+=a.get(j-1);
				}
				System.out.println();
			} else
				System.out.println("NO");
		}
	}

	static class pair {
		long x;
		int y;

		pair(long r, int t) {
			x = r;
			y = t;
		}

	}
}