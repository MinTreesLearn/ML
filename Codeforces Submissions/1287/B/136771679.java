import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), K = sc.nextInt();
		String[] s = new String[N];
		HashSet<String> mp = new HashSet<String>(N);
		for (int i = 0; i < N; ++i) {
			s[i] = sc.next();
			mp.add(s[i]);
		}
		sc.close();

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i; ++j) {
				StringBuilder t = new StringBuilder(K);
				for (int k = 0; k < K; ++k) {
					char c1 = s[i].charAt(k);
					char c2 = s[j].charAt(k);
					char c3 = (c1 == c2) ? c1 : (char) ('S'+'E'+'T'-c1-c2);
					t.append(c3);
				}
				if (mp.contains(t.toString())) ++cnt;
			}
		}

		System.out.println(cnt/3);
	}
}