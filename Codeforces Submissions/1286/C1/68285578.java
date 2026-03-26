import java.io.*;
import java.util.*;

public class D {

	static void query(int l, int r) {
		System.out.printf("? %d %d\n", l, r);
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		query(1, n);
		char[] ans = new char[n];
		if (n == 1) {
			ans = sc.next().toCharArray();
		} else {
			HashMap<String, Integer> map = new HashMap();
			for (int i = n * (n + 1) / 2; i > 0; i--) {
				String s = sc.get();
				map.put(s, map.getOrDefault(s, 0) + 1);

			}

			query(2, n);
			for (int i = n * (n - 1) / 2; i > 0; i--) {
				String s = sc.get();
				map.put(s, map.get(s) - 1);
			}
			ArrayList<String> a = new ArrayList();
			for (String x : map.keySet()) {
				if (map.get(x) > 0)
					a.add(x);
			}
			Collections.sort(a, (x, y) -> x.length() - y.length());

			for (int i = 0; i < n; i++) {
				String curr = a.get(i);
				int[] f = new int[26];
				for (char c : curr.toCharArray())
					f[c - 'a']++;
				for (int j = 0; j < i; j++)
					f[ans[j] - 'a']--;
				for (int c = 0; c < 26; c++)
					if (f[c] > 0)
						ans[i] = (char) (c + 'a');
			}
		}

		System.out.printf("! %s\n", new String(ans));
	}

	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String get() throws IOException {
			String ans = next();
			char[] s = ans.toCharArray();
			Arrays.sort(s);
			return new String(s);
		}

		Scanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		String nextLine() throws IOException {
			return br.readLine();
		}

		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		boolean ready() throws IOException {
			return br.ready();
		}

	}

	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}

}