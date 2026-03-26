import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class C1311E_1 {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var t = scanner.nextInt();
        for (int tc = 0; tc < t; tc++) {
            var n = scanner.nextInt();
            var d = scanner.nextInt();
            var ans = solve(n, d);
            if (ans == null) {
                writer.println("NO");
            } else {
                writer.println("YES");
                for (int i = 2; i <= n; i++) {
                    writer.print(ans[i] + " ");
                }
                writer.println();
            }
        }

        scanner.close();
        writer.flush();
        writer.close();
    }

    private static int[] solve(int n, int d) {
        var maxD = (n - 1) * n / 2;
        if (d > maxD) {
            return null;
        }
        var parent = new int[n + 1];
        var childCount = new int[n + 1];
        var depth = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            parent[i] = i - 1;
            depth[i] = i - 1;
            childCount[i - 1] = 1;
        }
        var dToRemove = maxD - d;
        while (dToRemove > 0) {
            var leaf = 0;
            for (int i = 1; i <= n; i++) {
                if (childCount[i] == 0
                        && (leaf == 0 || depth[i] > depth[leaf])) {
                    leaf = i;
                }
            }
            var newParent = 0;
            for (int i = 1; i <= n; i++) {
                int delta = depth[leaf] - 1 - depth[i];
                if (childCount[i] < 2
                        && delta > 0
                        && delta <= dToRemove
                        && (newParent == 0 || depth[i] < depth[newParent])) {
                    newParent = i;
                }
            }
            if (newParent == 0) {
                return null;
            }
            var oldParent = parent[leaf];
            childCount[oldParent]--;
            var newDepth = depth[newParent] + 1;
            dToRemove -= (depth[leaf] - newDepth);
            depth[leaf] = newDepth;
            parent[leaf] = newParent;
            childCount[newParent]++;
        }
        return parent;
    }

    private static void add(int node, Map<Integer, List<Integer>> nodes, int[] depth, int[] childCount) {
        var hash = hash(depth[node], childCount[node]);
        nodes.putIfAbsent(hash, new LinkedList<>());
        nodes.get(hash).add(node);
    }

    private static void remove(Integer node, Map<Integer, List<Integer>> nodes, int[] depth, int[] childCount) {
        var hash = hash(depth[node], childCount[node]);
        nodes.get(hash).remove(node);
    }

    private static int hash(int depth, int childCount) {
        return depth * 3 + childCount;
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
