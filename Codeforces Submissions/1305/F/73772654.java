import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class C1305F {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var a = new long[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = scanner.nextLong();
        }
        var distinct = Arrays.stream(a).boxed().collect(Collectors.toList());
        Collections.shuffle(distinct);
        var ans = countOps(2, a, n);
        for (int guess = 0; guess < 20 && guess < distinct.size(); guess++) {
            for (int j = -1; j <= 1; j++) {
                var factors = factor(distinct.get(guess) + j);
                for (var factor : factors) {
                    var ops = countOps(factor, a, ans);
                    ans = Math.min(ans, ops);
                }
            }
        }
        writer.println(ans);

        scanner.close();
        writer.flush();
        writer.close();
    }

    private static long countOps(long factor, long[] a, long already) {
        var ans = 0L;
        for (var x : a) {
            if (x < factor) {
                ans += factor - x;
            } else {
                var remain = x % factor;
                ans += Math.min(remain, factor - remain);
//                if (remain < factor / 2) {
//                    ans += remain;
//                } else {
//                    ans += factor - remain;
//                }
            }
            if (ans >= already) {
                break;
            }
        }
        return ans;
    }

    private static List<Long> factor(long a) {
        if (a <= 1) {
            return List.of();
        }
        var limit = (long) Math.sqrt(a);
        var ans = new ArrayList<Long>();
        for (long i = 2; i <= limit; i++) {
            var count = 0;
            while (a % i == 0) {
                a /= i;
                count++;
            }
            if (count > 0) {
                ans.add(i);
            }
        }
        if (a > 1) {
            ans.add(a);
        }
        return ans;
    }

    public static class BufferedScanner {
        BufferedReader br;
        StringTokenizer st;

        public BufferedScanner(Reader reader) {
            br = new BufferedReader(reader);
        }

        public BufferedScanner() {
            this(new InputStreamReader(System.in));
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

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }

    static long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        }
        while (b > 0) {
            long tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    static long inverse(long a, long m) {
        long[] ans = extgcd(a, m);
        return ans[0] == 1 ? (ans[1] + m) % m : -1;
    }

    private static long[] extgcd(long a, long m) {
        if (m == 0) {
            return new long[]{a, 1, 0};
        } else {
            long[] ans = extgcd(m, a % m);
            long tmp = ans[1];
            ans[1] = ans[2];
            ans[2] = tmp;
            ans[2] -= ans[1] * (a / m);
            return ans;
        }
    }

    private static List<Integer> primes(double upperBound) {
        var limit = (int) Math.sqrt(upperBound);
        var isComposite = new boolean[limit + 1];
        var primes = new ArrayList<Integer>();
        for (int i = 2; i <= limit; i++) {
            if (isComposite[i]) {
                continue;
            }
            primes.add(i);
            int j = i + i;
            while (j <= limit) {
                isComposite[j] = true;
                j += i;
            }
        }
        return primes;
    }


}
