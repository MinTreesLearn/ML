import java.io.*;
import java.util.StringTokenizer;

public class MinimumPunishment {
    // A composite number not greater than 10**12 must have a prime factor
    // less than PRIME_LIMIT.
    final static int PRIME_LIMIT = 1000000;
    // s[i] tells whether i is composite for i >= 2
    final static boolean[] isPrime = new boolean[PRIME_LIMIT];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static {
        isPrime[2] = true;
        for (int i = 3; i < PRIME_LIMIT; i += 2) {
            isPrime[i] = true;
        }

        final int SQUARE_ROOT = (int) Math.sqrt(PRIME_LIMIT);
        for (int i = 3; i <= SQUARE_ROOT; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < PRIME_LIMIT; j += i * 2) {
                    isPrime[j] = false;
                }
            }
        }
    }

    static long readLong() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        int n = (int) readLong();

        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = readLong();
        }

        // Each integer can be changed to an even number by at most one operation.
        long min = n;
        for (int i = 2; i < PRIME_LIMIT; i++) {
            if (isPrime[i]) {
                int ops = 0;
                for (long aa : a) {
                    if (aa <= i) {
                        ops += i - aa;
                    } else {
                        long remainder = aa % i;
                        ops += Math.min(remainder, i - remainder);
                    }

                    if (min <= ops) break;
                }

                if (min > ops) {
                    min = ops;
                }
            }
        }

        final long left = Math.max(a[0] - (min - 1), 3);
        final long right = a[0] + (min - 1);
        final int size = (int) (right - left + 1);

        if (size > 0) {
            long[] b = new long[size];
            for (int i = 0; i < size; i++) {
                b[i] = left + i;
            }

            for (int i = 2; i < PRIME_LIMIT; i++) {
                if (isPrime[i]) {
                    // remove the highest power of i from b[j]
                    long f = i;
                    while (true) {
                        // the smallest multiple of f that is no less than left
                        long start = (left + f - 1) / f * f;
                        if (start > right) break;

                        for (long j = start - left; j < size; j += f) {
                            b[(int) j] /= i;
                        }

                        f *= i;
                    }
                }
            }

            for (long i : b) {
                if (i != 1) {
                    // Since i is a factor of b[i] that has no prime factor smaller than
                    // PRIME_LIMIT, i must be a prime greater than PRIME_LIMIT
                    int ops = 0;
                    for (long aa : a) {
                        if (aa <= i) {
                            ops += i - aa;
                        } else {
                            long remainder = aa % i;
                            ops += Math.min(remainder, i - remainder);
                        }

                        if (min <= ops) break;
                    }

                    if (min > ops) {
                        min = ops;
                    }
                }
            }
        }

        System.out.println(min);
    }
}

