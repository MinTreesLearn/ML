
import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;
import java.io.*;

public class Main{

	public static void mergeSort(int[] array) {
		if (array == null) {
			return;
		}

		if (array.length > 1) {
			int mid = array.length / 2;

			// Split left part
			int[] left = new int[mid];
			for (int i = 0; i < mid; i++) {
				left[i] = array[i];
			}

			// Split right part
			int[] right = new int[array.length - mid];
			for (int i = mid; i < array.length; i++) {
				right[i - mid] = array[i];
			}
			mergeSort(left);
			mergeSort(right);

			int i = 0;
			int j = 0;
			int k = 0;

			// Merge left and right arrays
			while (i < left.length && j < right.length) {
				if (left[i] < right[j]) {
					array[k] = left[i];
					i++;
				} else {
					array[k] = right[j];
					j++;
				}
				k++;
			}
			// Collect remaining elements
			while (i < left.length) {
				array[k] = left[i];
				i++;
				k++;
			}
			while (j < right.length) {
				array[k] = right[j];
				j++;
				k++;
			}
		}
	}

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();

		String s1 = sc.next();
		String s2 = sc.next();
		ArrayList<Integer>[] freq1 = new ArrayList[27];
		ArrayList<Integer>[] freq2 = new ArrayList[27];
		int[] arr1 = new int[150000];
		int[] arr2 = new int[150000];
		int o1 = 0;
		int o2 = 0;
		int f1 = 0;
		int f2 = 0;
		int[] ind = new int[300002];

		int j = 0;
		for (int i = 0; i < 27; i++) {
			freq1[i] = new ArrayList<>();
			freq2[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			if (s1.charAt(i) == '?') {
				freq1[26].add(i + 1);
				continue;
			}

			freq1[s1.charAt(i) - 'a'].add(i + 1);

		}
		for (int i = 0; i < n; i++) {
			if (s2.charAt(i) == '?') {
				freq2[26].add(i + 1);
				continue;
			}
			freq2[s2.charAt(i) - 'a'].add(i + 1);
		}

		for (int i = 0; i < 26; i++) {
			int len = Math.min(freq1[i].size(), freq2[i].size());

			for (int k = len; k < freq1[i].size(); k++) {
				arr1[o1++] = freq1[i].get(k);
			}
			for (int k = len; k < freq2[i].size(); k++) {
				arr2[o2++] = freq2[i].get(k);
			}
			for (int b = 0; b < len; b++) {
				ind[j++] = freq1[i].get(b);

				ind[j++] = freq2[i].get(b);

			}
		}

		int len = Math.min(o2, freq1[26].size());
		{
			for (int i = 0; i < len; i++) {
				ind[j++] = freq1[26].get(f1++);

				ind[j++] = arr2[--o2];
			}
		}
		len = Math.min(o1, freq2[26].size());
		{
			for (int i = 0; i < len; i++) {
				ind[j++] = arr1[--o1];
				ind[j++] = freq2[26].get(f2++);

			}
		}
		for (int i = 0; i <freq1[26].size()-f1; i++) {
			ind[j++] = freq1[26].get(i+f1);
			ind[j++] = freq2[26].get(i+f2);

		}
		/*
		 * 5
6 5
4 6
7 4
2 3
1 2

		 */

		int ans = j/2;
		pw.println(ans);
		while (j >= 1) {
			pw.println(ind[j - 2] + " " + ind[j - 1]);
			j -= 2;
		}

		pw.flush();

	}

	static class Scanner {

		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String file) throws IOException {
			br = new BufferedReader(new FileReader(file));
		}

		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}

		protected String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String readAllLines(BufferedReader reader) throws IOException {
			StringBuilder content = new StringBuilder();
			String line;
			while ((line = reader.readLine()) != null) {
				content.append(line);
				content.append(System.lineSeparator());
			}
			return content.toString();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}

		public long[] nextlongArray(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public Long[] nextLongArray(int n) throws IOException {
			Long[] a = new Long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public int[] nextIntArray(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public Integer[] nextIntegerArray(int n) throws IOException {
			Integer[] a = new Integer[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}
}

		 		    			    					  	 	 				