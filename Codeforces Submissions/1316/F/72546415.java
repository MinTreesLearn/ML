//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {
        int mod = 1000000007;
        int add(int a, int b) {
            int c = a + b;
            if (c >= mod) return c - mod;
            return c;
        }

        int mul(int a, int b) {
            return (int) ((long) a * b % mod);
        }

        int pow(int a, int b) {
            int r = 1;
            while (b > 0) {
                if (b % 2 == 1) r = mul(r, a);
                a = mul(a, a);
                b >>= 1;
            }
            return r;
        }


        int[] pow2;

        public class SegTree {

            public class NodeVal {
                int len, leftVal, rightVal, totVal;
                public NodeVal(int len, int ini) {
                    this.len = len;
                    leftVal = rightVal = ini;
                    totVal = 0;
                }
                void set(int len, int ini) {
                    this.len = len;
                    leftVal = rightVal = ini;
                }
                public void from(NodeVal left, NodeVal right) {
                    this.len = left.len + right.len;
                    this.leftVal = add(right.leftVal, mul(left.leftVal, pow2[right.len]));
                    this.rightVal = add(left.rightVal, mul(right.rightVal, pow2[left.len]));
                    this.totVal = add(mul(left.rightVal, right.leftVal),
                            add(mul(left.totVal, pow2[right.len]), mul(right.totVal, pow2[left.len])));
                }
            }
            NodeVal[] nodes;
            int T;
            public SegTree(int n) {
                T = 1;
                while (T < n) T <<= 1;
                nodes = new NodeVal[T << 1];
                for (int i = 0; i < T << 1; i++) {
                    nodes[i] = new NodeVal(0, 0);
                }
            }

            void update(int index, int len, int val) {
                nodes[index += T].set(len, val);
                while (index > 1) {
                    int parent = index >> 1;
                    int left = parent << 1;
                    int right = parent << 1 | 1;
                    nodes[parent].from(nodes[left], nodes[right]);
                    index >>= 1;
                }
            }
        }

        int solve(int[] strength) {
            int n = strength.length;
            Arrays.sort(strength);
            int ret = 0;
            for (int i = 0; i < n; i++) {
                int ps = 0;
                for (int j = i - 1; j >= 0; j--) {
                    ps = mul(ps, 2);
                    ps = add(ps, strength[j]);
                }
                ps = mul(ps, pow(2, n - 1 - i));
                int ss = 0;
                for (int j = i + 1; j < n; j++) {
                    ss = mul(ss, 2);
                    ss = add(ss, strength[j]);
                }
                ss = mul(ss, pow(2, i));
                ret = add(ret, mul(add(ps, ss), strength[i]));
            }
            return mul(ret, pow(pow(2, n + 1), mod - 2));
        }

        public class Pair {
            int a, b;

            public Pair(int a, int b) {
                this.a = a;
                this.b = b;
            }
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] attachedIndex = new int[n];
            List<Pair> ps = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                ps.add(new Pair(a[i], -(i + 1)));
            }
            int q = sc.nextInt();
            int[][] queries = new int[q][2];
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < 2; j++) {
                    queries[i][j] = sc.nextInt();
                }
                queries[i][0]--;
                ps.add(new Pair(queries[i][1], i));
            }
            ps.sort(new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return o1.a - o2.a;
                }
            });
            int[] queryIndex = new int[q];
            int N = ps.size();
            for (int i = 0; i < N; i++) {
                if (ps.get(i).b < 0) {
                    attachedIndex[(-ps.get(i).b) - 1] = i;
                } else {
                    queryIndex[ps.get(i).b] = i;
                }
            }
            int inv2 = pow(pow(2, n), mod - 2);
            pow2 = new int[N + 1];
            pow2[0] = 1;
            for (int i = 1; i <= N; i++) {
                pow2[i] = mul(pow2[i - 1], 2);
            }
            SegTree st = new SegTree(N);
            for (int i = 0; i < n; i++) {
                st.update(attachedIndex[i], 1, a[i]);
            }
            int sol = mul(inv2, st.nodes[1].totVal);
//            System.err.println(Arrays.toString(attachedIndex));
//            System.err.println(sol);
//            System.err.println(solve(Arrays.copyOf(a, a.length)));
//            if (sol != solve(Arrays.copyOf(a, a.length))) throw new RuntimeException();
            pw.println(sol);
            for (int i = 0; i < q; i++) {
                int index = queries[i][0], value = queries[i][1];
                st.update(attachedIndex[index], 0, 0);
                st.update(attachedIndex[index] = queryIndex[i], 1, a[index] = value);
                sol = mul(inv2, st.nodes[1].totVal);
//                if (sol != solve(Arrays.copyOf(a, a.length))) throw new RuntimeException();
                pw.println(sol);
            }
        }
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("input"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("input"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
        System.err.println("Memory increased: " + (usedMemoryAfter - usedMemoryBefore) / 1000000);
        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}