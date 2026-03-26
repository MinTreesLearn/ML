
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		short n, m;
		n = sc.nextShort();
		m = sc.nextShort();
		String[] s = new String[n];
		String[] t = new String[m];
		for (short b = 0; b < n; b++)
			s[b] = sc.next();
		for (short b = 0; b < m; b++)
			t[b] = sc.next();
		int q = sc.nextInt();
		long y;

		while (q-- > 0) {
			y = sc.nextLong();
			short index1 = (short) ((y - 1) % n);
			short index2 = (short) ((y - 1) % m);
			System.out.println(s[index1] + t[index2]);
		}

		sc.close();
	}
}
