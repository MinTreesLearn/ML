// package codeforces;
import java.io.*;
import java.util.*;
	
public class practice {
	
	static FastScanner fs = new FastScanner();
		
	public static void main(String[] args) {
		int t = 1;
		t = fs.nextInt();   
		for(int i=1;i<=t;i++) {
			solve(t);
		}
	}
	
	public static void solve(int tt) {
		int a = fs.nextInt();
		int b = fs.nextInt();
		int x = fs.nextInt();
		int y = fs.nextInt();
		int f[] = new int[4];
		f[0] = x * b;
		f[1] = (a - x - 1) * b;
		f[2] = y * a;
		f[3] = (b - y -1) * a;
		int c = 0;
		for(int i=0;i<4;i++)c=Math.max(c,f[i]);
		System.out.println(c);
		return;
	}
		
	public static int [] sortarray(int a[]) {
		ArrayList<Integer> L = new ArrayList<Integer>();
		for(int i:a) {
			L.add(i);
		}
		Collections.sort(L);
		for(int i=0;i<L.size();i++)a[i]=L.get(i);
		return a;
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
		ArrayList<Integer> readList(int n) {
			ArrayList<Integer> a = new ArrayList<Integer>();
			int x;
			for(int i=0;i<n;i++) {
				x=fs.nextInt();
				a.add(x);
			}
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}
