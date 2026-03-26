
import java.util.*;
import java.lang.*;
import java.io.*;

public class feb20 {

	public static void main(String[] srgs) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] scn = (br.readLine()).trim().split(" ");
		int n = Integer.parseInt(scn[0]);
		long mod = Integer.parseInt(scn[1]);
		long[] fact = new long[n + 1];
		fact[1] = 1;
		for (int i = 2; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
			fact[i] %= mod;
		}
		long ans = 0;
		for (int len = 1; len <= n; len++) {
			long curr = (((fact[len] * fact[n - len + 1]) % mod) * (n - len + 1)) % mod;
			ans = (ans + curr) % mod;
		}
		System.out.println(ans);
		return;

	}

	public static void sec() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while (t-- > 0) {
			String[] scn = (br.readLine()).trim().split(" ");
			int n = Integer.parseInt(scn[0]);
			long[] arr = new long[n];
			scn = (br.readLine()).trim().split(" ");
			for (int i = 0; i < n; i++) {
				arr[i] = Long.parseLong(scn[i]);
			}
			sb.append("\n");
		}
		System.out.println(sb);
		return;

	}

	public static void third() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String[] scn = (br.readLine()).trim().split(" ");
		int n = Integer.parseInt(scn[0]);
		long[] arr = new long[n];
		scn = (br.readLine()).trim().split(" ");
		for (int i = 0; i < n; i++) {
			arr[i] = Long.parseLong(scn[i]);
		}
		System.out.println(sb);
		return;

	}

	public static void debug() {
		System.out.println("working..");
	}

	public static void debug(int i) {
		System.out.println("working on " + i);
	}

	public static void sort(long[] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			int idx = (int) Math.random() * n;
			long temp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = temp;
		}

		Arrays.sort(arr);
	}

	public static void sort(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			int idx = (int) Math.random() * n;
			int temp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = temp;
		}
		Arrays.sort(arr);
	}

	public static void print(long[][] dp) {
		for (long[] a : dp) {
			for (long ele : a) {
				System.out.print(ele + " ");
			}
			System.out.println();
		}
	}

	public static void print(int[][] dp) {
		for (int[] a : dp) {
			for (int ele : a) {
				System.out.print(ele + " ");
			}
			System.out.println();
		}
	}

	public static void print(boolean[] dp) {
		for (boolean ele : dp) {
			System.out.print(ele + " ");
		}
		System.out.println();
	}

	public static void print(long[] dp) {
		for (long ele : dp) {
			System.out.print(ele + " ");
		}
		System.out.println();
	}

}