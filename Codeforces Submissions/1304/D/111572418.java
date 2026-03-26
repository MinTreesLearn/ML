// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1304D extends PrintWriter {
	CF1304D() { super(System.out); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1304D o = new CF1304D(); o.main(); o.flush();
	}

	void reverse(int[] aa, int i, int j) {
		while (i < j) {
			int tmp = aa[i]; aa[i] = aa[j]; aa[j] = tmp;
			i++; j--;
		}
	}
	void main() {
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			byte[] cc = sc.next().getBytes();
			int[] aa = new int[n];
			int[] bb = new int[n];
			for (int i = 0; i < n; i++) {
				aa[i] = n - i;
				bb[i] = i + 1;
			}
			for (int i = 0, j; i < n - 1; i = j) {
				byte c = cc[i];
				j = i + 1;
				while (j < n - 1 && cc[j] == c)
					j++;
				reverse(c == '<' ? aa : bb, i, j);
			}
			for (int i = 0; i < n; i++)
				print(aa[i] + " ");
			println();
			for (int i = 0; i < n; i++)
				print(bb[i] + " ");
			println();
		}
	}
}
