import java.util.*;
import java.io.*;
import java.text.*;
 
public class C1321 {
 
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		char[] arr = sc.next().toCharArray();
		ArrayList<Character> a = new ArrayList<Character>();
		for (char c : arr)
			a.add(c);
		int og = a.size();
		while (a.size() > 0) {
			int remove = -1;
			char rem = 0;
			for (int i = 0; i < a.size(); i++) {
				if (remove == -1) {
					if (i != 0) {
						if (a.get(i - 1) == a.get(i) - 1) {
							remove = i;
							rem = a.get(i);
						}
					}
					if (i != a.size() - 1) {
						if (a.get(i + 1) == a.get(i) - 1) {
							remove = i;
							rem = a.get(i);
						}
					}
				} else if (a.get(i) > rem) {
					if (i != 0) {
						if (a.get(i - 1) == a.get(i) - 1) {
							remove = i;
							rem = a.get(i);
						}
					}
					if (i != a.size() - 1) {
						if (a.get(i + 1) == a.get(i) - 1) {
							remove = i;
							rem = a.get(i);
						}
					}
				}
			}
			if (remove == -1)
				break;
			else
				a.remove(remove);
		}
		pw.println(og - a.size());
		pw.close();
	}
 
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
 
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
 
		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
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
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArr(int n) throws IOException {
			int[] arr = new int[n];
			for (int i = 0; i < arr.length; i++)
				arr[i] = nextInt();
			return arr;
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
	}
}