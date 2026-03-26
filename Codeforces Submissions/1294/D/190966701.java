import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * @submission : Nithin Bharathi 28-Jan-2023
 */

public class Problem {

	public static void main(String[] args) {
		Template t = new Template();
		int test = t.readInt();
		int x = t.readInt();
		HashMap<Integer,Integer>mp = new HashMap<>();
		StringBuilder sb = new StringBuilder();
		int mex = 0;
		boolean vis[] = new boolean[test];
		while(test-->0){
			int rem = t.readInt()%x;
			mp.put(rem,mp.getOrDefault(rem, 0)+1);
			while(mp.containsKey(mex%x)){
				rem = mex%x;
				mp.put(rem, mp.get(rem)-1);
				if(mp.get(rem) == 0)mp.remove(rem);
				mex++;
			}
			sb.append(mex+"\n");
		}
		System.out.println(sb);
	}

}
class Template {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	public static boolean isSorted(int a[]) {
		for (int i = 0; i < a.length; i++) {
			if (i + 1 < a.length && a[i] > a[i + 1])
				return false;
		}
		return true;
	}

	public static boolean isPrime(int n) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}

	public static long factorial(int n) {
		long fac = 1;
		for (int i = 1; i <= n; i++)
			fac *= i;
		return fac;
	}

	public static ArrayList<Integer> factors(int n) {
		ArrayList<Integer> l = new ArrayList<>();
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				l.add(i);
				if (n / i != i)
					l.add(n / i);
			}

		}
		return l;
	}

	public static void build(int seg[], int ind, int l, int r, int a[]) {
		if (l == r) {
			seg[ind] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(seg, (2 * ind) + 1, l, mid, a);
		build(seg, (2 * ind) + 2, mid + 1, r, a);
		seg[ind] = Math.min(seg[(2 * ind) + 1], seg[(2 * ind) + 2]);
	}

	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public static void swap(int a[], int i, int j) {
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	public static void swap(ArrayList<Integer> l, int i, int j) {
		int t = l.get(i);
		l.set(i, l.get(j));
		l.set(j, t);
	}

	public static void sort(int arr[]) {
		ArrayList<Integer> list = new ArrayList<>();
		for (int it : arr)
			list.add(it);
		Collections.sort(list);
		int z = 0;
		for (int i = 0; i < arr.length; i++)
			arr[z++] = list.get(i);
	}

	public String read() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	public int readInt() {
		return Integer.parseInt(read());
	}

	public long readLong() {
		return Long.parseLong(read());
	}

	public double readDouble() {
		return Double.parseDouble(read());
	}

	public String readLine() throws Exception {
		return br.readLine();
	}

}
