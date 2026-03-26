import java.io.*;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {

    private static final String checkerSolutionOutput = "/home/quanvda/Main/Projects/MyProject/java-competitive-programming/src/_checker.solution.out";
    private static final String checkerInput = "/home/quanvda/Main/Projects/MyProject/java-competitive-programming/src/_checker.in";
    private static final String checkerBruteforcesOutput = "/home/quanvda/Main/Projects/MyProject/java-competitive-programming/src/_checker.bruteforces.out";
    private static final String fileInput = "/home/quanvda/Main/Projects/MyProject/java-competitive-programming/src/_in";
    private static final String fileOutput = "/home/quanvda/Main/Projects/MyProject/java-competitive-programming/src/_out";

    private static class Config {
        private static final boolean useInputFile = false;
        private static final boolean useOutputFile = false;
        private static final String inputFile = fileInput;
        private static final String outputFile = checkerSolutionOutput;
    }

    public static void main(String[] args) throws Exception {
        run();
    }

    public static void run() throws Exception {
        FastScanner sc = new FastScanner();
        int t = 1;
        BufferedWriter writer = getWriter();
        for (int i = 0; i < t; i++)
            solve(sc, writer);
        writer.flush();
    }

    static int n, a[];

    static int[] rise() {
        int b[] = new int[n];
        for (int i = 0; i < n; i++) b[i] = a[i];
        for (int i = n - 2; i >= 0; i--)
            if (b[i] > b[i + 1])
                b[i] = b[i + 1];
        return b;
    }

    static int[] fall() {
        int b[] = new int[n];
        for (int i = 0; i < n; i++) b[i] = a[i];
        for (int i = 1; i < n; i++)
            if (b[i] > b[i - 1])
                b[i] = b[i - 1];
        return b;
    }

    static class Node {
        int val;
        int occ;

        public Node(int val, int occ) {
            this.val = val;
            this.occ = occ;
        }
    }

    static long[] calcPrefix() {
        long[] res = new long[n];
        TreeSet<Node> tr = new TreeSet<>(Comparator.comparingInt(x -> x.val));
        Stack<Node> st = new Stack<>();
        long sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                Node v = new Node(a[i], 1);
                // push
                tr.add(v);
                st.add(v);
                // upd sum
                sum += a[i];
                res[i] = sum;
            } else {
                Node cur = new Node(a[i], 1);
                Node ceil = tr.ceiling(cur);
                while (true && ceil != null) {
                    // pop
                    Node top = st.pop();
                    tr.remove(top);
                    // upd sum
                    sum -= 1L * top.val * top.occ;
                    cur.occ += top.occ;
                    if (top.equals(ceil))
                        break;
                }
                // push
                tr.add(cur);
                st.add(cur);
                // upd sum
                sum += 1L * cur.val * cur.occ;
                res[i] = sum;
            }
        }
        return res;
    }

    static void rev() {
        int i = 0, j = n - 1;
        while (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    static int[] riseFall() {
        long[] pref = calcPrefix();
        rev();
        long[] postf = calcPrefix();
        rev();
        int i = 0, j = n - 1;
        while (i <= j) {
            long tmp = postf[i];
            postf[i] = postf[j];
            postf[j] = tmp;
            i++;
            j--;
        }
        int maxk = 0;
        long mx = 0;
        for (int k = 1; k < n - 1; k++) {
            long vl = pref[k] + postf[k] - a[k];
            if (vl > mx) {
                maxk = k;
                mx = vl;
            }
        }
        int b[] = new int[n];
        for (int k = 0; k < n; k++) b[k] = a[k];
        for (int k = maxk - 1; k >= 0; k--)
            if (b[k] > b[k + 1])
                b[k] = b[k + 1];
        for (int k = maxk + 1; k < n; k++)
            if (b[k] > b[k - 1])
                b[k] = b[k - 1];
        return b;
    }

    static long calc(int[] b) {
        long ans = 0;
        for (int x : b) ans += x;
        return ans;
    }

    private static void solve(FastScanner sc, BufferedWriter writer) throws Exception {
        n = sc.nextInt();
        a = sc.readArray(n);
        int[] res = new int[n];
        int[] ri = rise();
        if (calc(ri) > calc(res))
            res = ri;
        int[] fa = fall();
        if (calc(fa) > calc(res))
            res = fa;
        int[] rf = riseFall();
        if (calc(rf) > calc(res))
            res = rf;
        for (int x : res)
            writer.write(x + " ");
        writer.write("\n");
    }

    private static class Pair<A, B> {
        A first;
        B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }

        public Pair() {
        }
    }

    private static class FastScanner {

        BufferedReader br;
        StringTokenizer st;

        private FastScanner() throws FileNotFoundException {
            if (Config.useInputFile)
                this.br = new BufferedReader(new InputStreamReader(new FileInputStream(Config.inputFile)));
            else
                this.br = new BufferedReader(new InputStreamReader(System.in));
            this.st = new StringTokenizer("");
        }

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    private static BufferedWriter getWriter() throws Exception {
        if (Config.useOutputFile)
            return getFileWriter();
        return getConsoleWriter();
    }

    private static BufferedWriter getFileWriter() throws Exception {
        PrintWriter writer = new PrintWriter(Config.outputFile);
        writer.print("");
        writer.close();
        return new BufferedWriter(new OutputStreamWriter(new FileOutputStream(Config.outputFile)));
    }

    private static BufferedWriter getConsoleWriter() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }
}
