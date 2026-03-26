import java.io.*;
import java.util.*;
 
public class Main {
	static PrintWriter out = new PrintWriter(System.out);
    static FastScanner fs = new FastScanner();
	
	public static void solve() throws IOException {
		String password = fs.next();
		LinkedList<Character> q = new LinkedList<>();
		boolean[] used = new boolean[26];
		ArrayList<HashSet<Integer>> nextTo = new ArrayList<>();
		for (int i = 0; i < 26; i++) nextTo.add(new HashSet<Integer>());
		for (int i = 1; i < password.length(); i++) {
			nextTo.get((int)password.charAt(i)-97).add((int)password.charAt(i-1) - 97);
			nextTo.get((int)password.charAt(i-1)-97).add((int)password.charAt(i)-97);
		}
		for (char c : password.toCharArray()) {
			if(used[(int)c - 97]) continue;
			if(q.isEmpty()) q.add(c);
			else {
				if(nextTo.get((int)c - 97).contains((int)q.getFirst() - 97)) {
					q.addFirst(c);
				}
				else {
					q.addLast(c);
				}
			}
			used[(int)c-97]=true;
		}
		for (int i = 0; i < 26; i++) {
			if(!used[i]) q.add((char)(i+97));
		}
		boolean[][] adj = new boolean[26][26];
		char[] perm = new char[26];
		for (int i = 0; i < 26; i++) perm[i] = q.removeFirst();
		for (int i = 1; i < 26; i++) {
			adj[(int)perm[i] - 97][(int)perm[i-1] - 97] = true;
			adj[(int)perm[i-1]-97][(int)perm[i]-97] = true;
		}
		for (int i = 1; i < password.length(); i++) {
			if(!adj[(int)password.charAt(i)-97][(int)password.charAt(i-1)-97]) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		out.println(new String(perm));
	}
	public static void main(String[] args) throws IOException {
		int t = fs.nextInt();
		for (int i = 0; i < t; i++) solve();
		out.close();
	}
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}