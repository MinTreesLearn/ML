import java.io.*;
import java.util.*;
 
public class CF1301C extends PrintWriter {
	CF1301C() { super(System.out); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1301C o = new CF1301C(); o.main(); o.flush();
	}
 
	void main() {
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int q = (n - m) / (m + 1);
			int r = (n - m) % (m + 1);
			long ans = (long) n * (n + 1) / 2;
			long a0 = (long) q * (q + 1) / 2;
			long a1 = (long) (q + 1) * (q + 2) / 2;
			ans -= (m + 1 - r) * a0 + r * a1;
			println(ans);
		}
	}
}