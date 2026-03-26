

import java.util.*;
import java.io.*;

public class Array {

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
		int[] a = sc.nextIntArray(n-1);
		int last= 200000;
		int [] arr= new int[n];
		arr[n-1]=last;
		int min=last;
		for (int i=n-2;i>=0;i--) {
		arr[i]=arr[i+1]-a[i];
		min=Math.min(min, arr[i]);
		}
		for (int i=0;i<n;i++) {
			arr[i]-=(min-1);
			//pw.println(arr[i]);
		}
		int[] newArr=arr.clone(); 
		mergeSort(newArr);
		boolean flag= true;
for (int i=0;i<n;i++) {
	if(newArr[i]-1!=i) {
		pw.println(-1);
		flag= false;
		break;
	}
	
}
if(flag) {
	for (int i=0;i<n;i++)
		pw.print(arr[i]+" ");
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
