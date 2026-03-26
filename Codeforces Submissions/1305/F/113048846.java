import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

import static java.lang.Math.min;
import static java.lang.Math.sqrt;

public class SolutionF extends Thread {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                                            InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    private static final FastReader scanner = new FastReader();
    private static final PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        solve();
        out.close();
    }

    private static void solve() {
        int n = scanner.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        long minOps = Long.MAX_VALUE;
        for (int it = 0; it < 20; it++) {
            int index = (int) (Math.random() * n);
            long ai = a[index];

            for (long x = Math.max(2, ai-1); x <= ai+1; x++) {
                List<PowerPair> primeFactors = getPrimeFactorsOfNumber(x);
                for (PowerPair p: primeFactors) {
                    long ops = 0;
                    for (int i = 0; i < n; i++) {
                        if (a[i] < p.base) {
                            ops += p.base - a[i];
                        } else {
                            ops += Math.min(a[i] % p.base, p.base - (a[i] % p.base));
                        }
                    }
                    minOps = Math.min(minOps, ops);
                }
            }
        }
        out.println(minOps);
    }


    static class PowerPair {
        public long base;
        int exp;

        public PowerPair(long base, int exp) {
            this.base = base;
            this.exp = exp;
        }

        @Override
        public String toString() {
            return base + "^" + exp;
        }
    }

    public static List<PowerPair> getPrimeFactorsOfNumber(long n) {
        List<PowerPair> result = new ArrayList<>();

        for (int i = 2; i <= sqrt(n); i++) {
            PowerPair pair = new PowerPair(i, 0);
            while (n % i == 0) {
                pair.exp++;
                n /= i;
            }

            if (pair.exp > 0) {
                result.add(pair);
            }
        }

        if (n != 1) {
            result.add(new PowerPair(n, 1));
        }

        return result;
    }

    //REMINDERS:
    //- CHECK FOR INTEGER-OVERFLOW BEFORE SUBMITTING

    //- CAN U BRUTEFORCE OVER SOMETHING, TO MAKE IT EASIER TO CALCULATE THE SOLUTION
}