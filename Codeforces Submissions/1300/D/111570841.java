// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1300D extends PrintWriter {
	CF1300D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1300D o = new CF1300D(); o.main(); o.flush();
	}

	void main() {
		int n = sc.nextInt();
		if (n % 2 == 1) {
			println("NO");
			return;
		}
		int[] xx = new int[n];
		int[] yy = new int[n];
		for (int i = 0; i < n; i++) {
			xx[i] = sc.nextInt();
			yy[i] = sc.nextInt();
		}
		int i = 0, j = n / 2;
		int x = xx[i] + xx[j];
		int y = yy[i] + yy[j];
		while (j < n) {
			if (xx[i] + xx[j] != x || yy[i] + yy[j] != y) {
				println("NO");
				return;
			}
			i++; j++;
		}	
		println("YES");
	}
}
