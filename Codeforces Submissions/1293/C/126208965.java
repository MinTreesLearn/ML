import java.util.*;
import java.io.*;

public class NekoMazeGame {
	static InputReader in = new InputReader(System.in);
	static PrintWriter pw = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int T = 1;
//		T = in.nextInt();
		for (int i = 1; i <= T; i++)
			solve(i);
		pw.close();
	}

	static void solve(int testCase) {
		int n = in.nextInt(), q = in.nextInt();
//		MultiSet<Integer> firstRow = new MultiSet<>();
//		MultiSet<Integer> secondRow = new MultiSet<>();
		TreeSet<Integer> firstRow = new TreeSet<>();
		TreeSet<Integer> secondRow = new TreeSet<>();
		int can = 0;
		for (int i = 0; i < q; i++) {
			int r = in.nextInt(), c = in.nextInt();
			if (r == 1) {
				if (firstRow.contains(c)) { // ground
					firstRow.remove(c);
					Integer lower = secondRow.lower(c);
					Integer higher = secondRow.higher(c);
//					pw.println("turn first row to ground: " + lower + " " + higher + " " + c);
					if (lower != null && lower + 1 == c)
						can--;
					if (secondRow.contains(c))
						can--;
					if (higher != null && higher - 1 == c)
						can--;
				} else { // lava
					firstRow.add(c);
					Integer lower = secondRow.lower(c);
					Integer higher = secondRow.higher(c);
//					pw.println("turn first row to lava: " + lower + " " + higher + " " + c);
					if (lower != null && lower + 1 == c)
						can++;
					if (secondRow.contains(c))
						can++;
					if (higher != null && higher - 1 == c)
						can++;
				}
			} else {
				if (secondRow.contains(c)) { // ground
					secondRow.remove(c);
					Integer lower = firstRow.lower(c);
					Integer higher = firstRow.higher(c);
//					pw.println("turn second row to ground: " + lower + " " + higher + " " + c);
					if (lower != null && lower + 1 == c)
						can--;
					if (firstRow.contains(c))
						can--;
					if (higher != null && higher - 1 == c)
						can--;
				} else { // lava
					secondRow.add(c);
					Integer lower = firstRow.lower(c);
					Integer higher = firstRow.higher(c);
//					pw.println("turn second row to lava: " + lower + " " + higher + " " + c);
					if (lower != null && lower + 1 == c)
						can++;
					if (firstRow.contains(c))
						can++;
					if (higher != null && higher - 1 == c)
						can++;
				}
			}
			if (can == 0)
				pw.println("Yes");
			else
				pw.println("No");
//			pw.println(can);
		}
//		pw.println(firstRow);
//		pw.println(secondRow);
	}

	static class MultiSet<T> {
		TreeMap<Integer, Integer> multiset = new TreeMap<>();

		void add(int x) {
			if (multiset.containsKey(x))
				multiset.put(x, multiset.get(x) + 1);
			else
				multiset.put(x, 1);
		}

		void remove(int x) {
			multiset.put(x, multiset.get(x) - 1);
			if (multiset.get(x) == 0) {
				multiset.remove(x);
			}
		}

		Integer lower(int x) {
			return multiset.lowerKey(x);
		}

		Integer higher(int x) {
			return multiset.higherKey(x);
		}

		boolean contains(int x) {
			return multiset.containsKey(x);
		}

		public String toString() {
			return multiset.toString();
		}
	}

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = in.nextInt();
			return arr;
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}
