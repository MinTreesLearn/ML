
import java.util.*;
import java.lang.*;
import java.io.*;

public class feb20 {

	// __/\\\\\\\\\\\\\______/\\\\\\\\\_________/\\\\\\\\\___________/\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\________/\\\\\\\\\__/\\\\\\\\\\\\\\\_
	// _\/\\\/////////\\\__/\\\///////\\\_____/\\\\\\\\\\\\\______/\\\////////__\///////\\\/////__\/////\\\///______/\\\////////__\/\\\///////////__
	// _\/\\\_______\/\\\_\/\\\_____\/\\\____/\\\/////////\\\___/\\\/_________________\/\\\___________\/\\\_______/\\\/___________\/\\\_____________
	// _\/\\\\\\\\\\\\\/__\/\\\\\\\\\\\/____\/\\\_______\/\\\__/\\\___________________\/\\\___________\/\\\______/\\\_____________\/\\\\\\\\\\\_____
	// _\/\\\/////////____\/\\\//////\\\____\/\\\\\\\\\\\\\\\_\/\\\___________________\/\\\___________\/\\\_____\/\\\_____________\/\\\///////______
	// _\/\\\_____________\/\\\____\//\\\___\/\\\/////////\\\_\//\\\__________________\/\\\___________\/\\\_____\//\\\____________\/\\\_____________
	// _\/\\\_____________\/\\\_____\//\\\__\/\\\_______\/\\\__\///\\\________________\/\\\___________\/\\\______\///\\\__________\/\\\_____________
	// _\/\\\_____________\/\\\______\//\\\_\/\\\_______\/\\\____\////\\\\\\\\\_______\/\\\________/\\\\\\\\\\\____\////\\\\\\\\\_\/\\\\\\\\\\\\\\\_
	// _\///______________\///________\///__\///________\///________\/////////________\///________\///////////________\/////////__\///////////////__

	// created by : Nitesh Gupta

	public static void main(String[] srgs) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t = Integer.parseInt(br.readLine());
		int x = 1;
		while (t-- > 0) {
			String[] scn = (br.readLine()).trim().split(" ");
			int n = Integer.parseInt(scn[0]);
			int m = Integer.parseInt(scn[1]);
			int k = Integer.parseInt(scn[2]);
			long[] arr = new long[n];
			scn = (br.readLine()).trim().split(" ");
			for (int i = 0; i < n; i++) {
				arr[i] = Long.parseLong(scn[i]);
			}
			long ans = 0;
			int i = 0;
			if (k >= m) {
				k = m - 1;
			}
			int j = n - k - 1;
			while (j < n) {
				int en = i + m - k - 1;
				int st = j - (m - k - 1);
				long curr = Long.MAX_VALUE;
				int temp = i;
				while (temp <= en && st <= j) {
					curr = Math.min(curr, Math.max(arr[temp], arr[st]));
					st += 1;
					temp += 1;

				}
				ans = Math.max(ans, curr);
				i += 1;
				j += 1;

			}
			sb.append(ans);
			sb.append("\n");
		}
		System.out.println(sb);
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

	public static void print(int[] dp) {
		for (int ele : dp) {
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