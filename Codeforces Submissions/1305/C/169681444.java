import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static int n, m;
	public static int[] a;

	public static void Input() {
		n = sc.nextInt(); m = sc.nextInt();
		a = new int[n];
		for (int i=0; i<n; i++) a[i] = sc.nextInt();
	}

	public static void Solve() {
		if (n > m) {System.out.println(0); return;}

		int ans = 1;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				ans = (int)(((long)ans * Math.abs(a[i] - a[j])) % m);
			}
		}
		System.out.println(ans);
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}