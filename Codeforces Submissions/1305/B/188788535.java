import java.io.*;
import java.util.*;

public class CF1305B extends PrintWriter {
	CF1305B() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1305B o = new CF1305B(); o.main(); o.flush();
	}

	void main() {
		byte[] cc = sc.next().getBytes();
		int n = cc.length;
		int[] ii = new int[n];
		int k = 0;
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			while (i < n && cc[i] != '(')
				i++;
			while (j >= 0 && cc[j] != ')')
				j--;
			if (i < j) {
				ii[k] = i;
				ii[n - 1 - k] = j;
				k++;
			}
		}
		if (k == 0) {
			println(0);
			return;
		}
		println(1);
		println(k * 2);
		for (int h = 0; h < k; h++)
			print(ii[h] + 1 + " ");
		for (int h = n - k; h < n; h++)
			print(ii[h] + 1 + " ");
		println();
	}
}
