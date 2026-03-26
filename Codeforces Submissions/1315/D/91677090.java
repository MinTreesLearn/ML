// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1315D extends PrintWriter {
	CF1315D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1315D o = new CF1315D(); o.main(); o.flush();
	}

	static class V implements Comparable<V> {
		int a, b;
		V(int a, int b) {
			this.a = a; this.b = b;
		}
		@Override
		public int compareTo(V v) {
			return b - v.b;
		}
	}
	void main() {
		int n = sc.nextInt();
		V[] vv = new V[n];
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			vv[i] = new V(a, 0);
		}
		for (int i = 0; i < n; i++)
			vv[i].b = sc.nextInt();
		Arrays.sort(vv);
		TreeSet<V> s = new TreeSet<>();
		s.add(new V(1, 2000000000));
		long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			V u = vv[i];
			int a = u.a, t = u.b; u.b = a;
			V v = s.ceiling(u);
			int l = v.a, r = v.b;
			s.remove(v);
			if (a <= l) {
				ans += (long) (l - a) * t;
				l++;
				if (l <= r)
					s.add(new V(l, r));
			} else if (a == r) {
				r--;
				if (l <= r)
					s.add(new V(l, r));
			} else {
				if (l < a)
					s.add(new V(l, a - 1));
				if (a < r)
					s.add(new V(a + 1, r));
			}
		}
		println(ans);
	}
}
