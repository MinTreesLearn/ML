import java.util.*;
import java.io.*;

public class A {
	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		StringBuilder str = new StringBuilder();
		int t = sc.nextInt();
		for (int xx = 1; xx <= t; xx++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = sc.nextInt();
			boolean ok = false;
			HashMap<Integer, Integer> map = new HashMap<>();
			for (int i = 0; i < n; i++) {
				if (map.containsKey(arr[i])) {
					if (i - map.get(arr[i]) > 1)
						ok = true;
				} else
					map.put(arr[i], i);
			}
			if (ok)
				str.append("YES" + "\n");
			else
				str.append("NO" + "\n");
		}
		System.out.println(str);
		sc.close();
	}
}