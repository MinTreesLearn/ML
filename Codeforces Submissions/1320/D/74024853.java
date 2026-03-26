import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C1320D {

    static long modulo1 = (long) 1e9 + 9;
    static long modulo2 = (long) 1e9 + 7;
    static long r1 = 2;
    static long r2 = 3;
    static int[] bits1 = new int[]{0, 1};
    static int[] bits2 = new int[]{1, 2};

    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var t = scanner.next();
        var count0 = new int[n + 1];
        {
            count0[0] = 0;
            for (int len = 1; len <= n; len++) {
                count0[len] = count0[len - 1] + (t.charAt(len - 1) == '0' ? 1 : 0);
            }
        }
        var power1 = new long[n + 1];
        var power2 = new long[n + 1];
        power1[0] = 1;
        power2[0] = 1;
        for (int i = 1; i <= n; i++) {
            power1[i] = power1[i - 1] * r1 % modulo1;
            power2[i] = power2[i - 1] * r2 % modulo2;
        }
        var hashEven1 = new long[n + 1][];
        var hashOdd1 = new long[n + 1][];
        calcHash(t, n, power1, hashEven1, hashOdd1, count0, modulo1, r1, bits1);
        var hashEven2 = new long[n + 1][];
        var hashOdd2 = new long[n + 1][];
        calcHash(t, n, power2, hashEven2, hashOdd2, count0, modulo2, r2, bits2);
        var q = scanner.nextInt();
        for (int qi = 0; qi < q; qi++) {
            var l1 = scanner.nextInt() - 1;
            var l2 = scanner.nextInt() - 1;
            var len = scanner.nextInt();
            var ans = false;
            // 首先，0的个数得一样多
            if (count0[l1 + len] - count0[l1] == count0[l2 + len] - count0[l2]) {
                // 其次，从各子串开头算起的0的下标得对应位同奇偶。
                var fp11 = fingerprint(l1, l1 + len - 1, power1, hashEven1, hashOdd1, count0, modulo1);
                var fp21 = fingerprint(l2, l2 + len - 1, power1, hashEven1, hashOdd1, count0, modulo1);
                var fp12 = fingerprint(l1, l1 + len - 1, power2, hashEven2, hashOdd2, count0, modulo2);
                var fp22 = fingerprint(l2, l2 + len - 1, power2, hashEven2, hashOdd2, count0, modulo2);
//                System.out.println(String.format("[%d] %d,%d %d,%d", qi + 1, fp11, fp21, fp12, fp22));
                if (fp11 == fp21 && fp12 == fp22) {
                    ans = true;
                }
            }
            writer.println(ans ? "Yes" : "No");
        }

        scanner.close();
        writer.flush();
        writer.close();
    }

    private static void calcHash(String t, int n, long[] power, long[][] hashEven, long[][] hashOdd, int[] count0,
            long modulo, long r, int[] bits) {
        var limit = r * modulo;
//        System.out.println(String.format("modulo=%d,r=%d,bits=%s", modulo, r, Arrays.toString(bits)));
        for (int len = 1; len <= n; len <<= 1) {
            hashEven[len] = new long[n];
            hashOdd[len] = new long[n];
            var he = 0L;
            var ho = 0L;
            for (int i = 0; i < n; i++) {
                if (t.charAt(i) == '0') {
                    var bitEven = bits[i & 1]; // 对偶数开头子字符串来说，i是偶数在子字符串也是偶数位，用0表示；否则用1。
                    var bitOdd = bits[1 - (i & 1)]; // 对奇数位开头的子字符串来说，i是偶数在子字符串是奇数位，用1表示；否则用0。
                    he = (he * r + bitEven) % modulo;
                    ho = (ho * r + bitOdd) % modulo;
                }
                if (i >= len && t.charAt(i - len) == '0') {
                    var bitEven0 = bits[(i - len) & 1];
                    var bitOdd0 = bits[1 - ((i - len) & 1)];
                    var cnt0 = count0[i + 1] - count0[i + 1 - len];
                    he = (he + limit - power[cnt0] * bitEven0) % modulo; // power[cnt0]*bitEven0<modulo*r
                    ho = (ho + limit - power[cnt0] * bitOdd0) % modulo; // power[cnt0]*bitOdd0<modulo*r
                }
                if (i >= len - 1) {
                    hashEven[len][i - len + 1] = he;
                    hashOdd[len][i - len + 1] = ho;
                }
                if (he < 0 || ho < 0) {
                    throw new RuntimeException("wtf");
                }
            }
        }
    }

    private static long fingerprint(int start, int end, long[] power, long[][] hashEven, long[][] hashOdd, int[] count0,
            long modulo) {
        if ((start & 1) == 0) {
            return fingerprint(start, end, power, hashEven, count0, modulo);
        } else {
            return fingerprint(start, end, power, hashOdd, count0, modulo);
        }
    }

    private static long fingerprint(int start, int end, long[] power, long[][] hash, int[] count0, long modulo) {
        var len = 1 << (int) (Math.log(end - start + 1) / Math.log(2));
        var fp = 0L;
        while (start <= end) {
            var cnt0 = count0[start + len] - count0[start];
            fp = (fp * power[cnt0] + hash[len][start]) % modulo;
            if (fp < 0) {
                throw new RuntimeException("wtf");
            }
            start += len;
            while (len > 0 && start + len - 1 > end) {
                len >>= 1;
            }
        }
        return fp;
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
