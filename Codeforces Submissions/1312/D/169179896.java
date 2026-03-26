import java.util.*;

public class countthearrays {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		int k = 998244353;
		long pow = 1;
		long[] fac = new long[m + 1];
		fac[0] = 1;
		fac[1] = 1;
		for (int i = 2; i <= m; i++) {
			fac[i] = ((long) fac[i - 1] * i) % k;
		}
		for (int i = 1; i < n - 2; i++) {
			pow = pow * 2 % k;
		}
		long ncr = 0;
		ncr = fac[m] * modInverse(fac[n - 1], k) % k * modInverse(fac[m - n + 1], k) % k;
		long ans = ncr * (n - 2) % k;
		ans = ans * pow % k;
		System.out.println(ans);

	}

	static long power(long x, long y, int p) {

		long res = 1;

		x = x % p;

		while (y > 0) {

			if (y % 2 == 1) {
				res = (res * x) % p;
			}

			y = y >> 1;
			x = (x * x) % p;

		}

		return res;
	}

	static long modInverse(long n, int p) {
		return power(n, p - 2, p);
	}
}