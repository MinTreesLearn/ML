import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var m = scanner.nextInt();
        var k = scanner.nextInt();
        var ans = solve(n, m, k);
        if (ans != null) {
            writer.println("YES");
            writer.println(ans.size());
            assert ans.size() <= 3000;
            for (Step step : ans) {
                writer.println(step.f + " " + step.s);
            }
        } else {
            writer.println("NO");
        }

        scanner.close();
        writer.flush();
        writer.close();
    }

    static final int[][] MOVE = {
            {0, 1}, // R
            {1, 0}, // D
            {-1, 0}, // U
            {0, -1} // L
    };
    static final char[] DIR = {0, 'R', 'D', 'U', 'L'};

    private static List<Step> solve(int n, int m, int k) {
        var atMost = 4 * n * m - 2 * n - 2 * m;
        if (k > atMost) {
            return null;
        }
        // 每条路只能走一遍，每个格子可以走多遍
        // atMost步是一定可以走通的。主要问题变成了怎么分组使得能够在3000步以内表达。
        var ans = new ArrayList<Step>();
        var current = 0;
        var r = 1;
        var c = 1;
        while (current < k) {
            // RDU...
            if (r < n) {
                var countRDU = Math.min(m - c, (k - current) / 3);
                if (countRDU > 0) {
                    ans.add(new Step(countRDU, "RDU"));
                    c += countRDU;
                    current += 3 * countRDU;
                    if (current == k) {
                        break;
                    }
                    if (k - current < 3 && c < m) {
//                    finishRDU(k - current, ans);
                        if (k - current == 2) {
                            ans.add(new Step(1, "R"));
                            ans.add(new Step(1, "D"));
                        } else {
                            ans.add(new Step(1, "R"));
                        }
                        break;
                    }
                }
            } else { // R...
                var countR = Math.min(k - current, m - c);
                if (countR > 0) {
                    ans.add(new Step(countR, "R"));
                    c += countR;
                    current += countR;
                    if (current == k) {
                        break;
                    }
                }
            }
            // L...
            {
                var countL = Math.min(k - current, c - 1);
                if (countL > 0) {
                    ans.add(new Step(countL, "L"));
                    c -= countL;
                    current += countL;
                    if (current == k) {
                        break;
                    }
                }
            }
            // D...
            if (r < n) {
                ans.add(new Step(1, "D"));
                r++;
                current++;
                if (current == k) {
                    break;
                }
            } else {
                var countU = k - current;
                ans.add(new Step(countU, "U"));
                r -= countU;
                current += countU;
            }
        }
        return ans;
    }

    static final boolean DEBUG = true;

    private static void log(Object... a) {
        if (DEBUG) {
            for (Object x : a) {
                System.out.println(x + " ");
            }
        }
    }

    static class Step {
        int f;
        String s;

        Step(int f, String s) {
            this.f = f;
            this.s = s;
            assert s.length() <= 4;
        }
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
