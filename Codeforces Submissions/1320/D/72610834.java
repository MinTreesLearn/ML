//package com.company;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static class Task {
        String s;
        class SegTree {
            int n, mod, M, inv;
            int[] pow;
            Node[] nodes;
            public SegTree() {
                n = s.length();
                nodes = new Node[4 * n];
                pow = new int[n + 1];
                mod = BigInteger.valueOf((new Random()).nextInt(1000000) + 1000000000).nextProbablePrime().intValue();
                M = BigInteger.valueOf((new Random()).nextInt(100) + 100).nextProbablePrime().intValue();
                pow[0] = 1;
                inv = BigInteger.valueOf(M).modInverse(BigInteger.valueOf(mod)).intValue();
                for (int i = 1; i <= n; i++) {
                    pow[i] = mul(pow[i - 1], M);
                }
                build(0, n, 1);
            }
            void build(int l, int r, int idx) {
                if (l == r - 1) {
                    nodes[idx] = new Node();
                    nodes[idx].isStart1 = nodes[idx].isLast1 = s.charAt(l) == '1';
                    nodes[idx].len = 1;
                    nodes[idx].val = s.charAt(l) == '1' ? pow[0]: mul(2, pow[0]);
                    return;
                }
                int mid = (l + r) / 2;
                build(l, mid, idx << 1);
                build(mid, r, idx << 1 | 1);
                nodes[idx] = new Node();
                nodes[idx].fromChild(nodes[idx << 1], nodes[idx << 1 | 1]);
            }
            Node query(int l, int r, int idx, int L, int R) {
                if (L <= l && r <= R) return nodes[idx];
                if (L >= r || l >= R) return new Node();
                int mid = (l + r) / 2;
                Node left = query(l, mid, idx << 1, L, R);
                Node right = query(mid, r, idx << 1 | 1, L, R);
                Node me = new Node();
                me.fromChild(left, right);
                return me;
            }
            int add(int a, int b) {
                int c = a + b;
                if (c >= mod) return c - mod;
                if (c < 0) return c + mod;
                return c;
            }
            int mul(int a, int b) {
                return (int)((long)a * b % mod);
            }
            boolean eq(int l1, int l2, int len) {
                return query(0, n, 1, l1, l1 + len).val == query(0, n, 1, l2, l2 + len).val;
            }
            class Node {
                boolean isStart1;
                boolean isLast1;
                int len, val;
                public Node() {

                }
                void fromChild(Node left, Node right) {
                    if (left.len == 0) {
                        isStart1 = right.isStart1;
                        isLast1 = right.isLast1;
                        len = right.len;
                        val = right.val;
                        return;
                    }
                    if (right.len == 0) {
                        isStart1 = left.isStart1;
                        isLast1 = left.isLast1;
                        len = left.len;
                        val = left.val;
                        return;
                    }
                    isStart1 = left.isStart1;
                    isLast1 = right.isLast1;
                    len = left.len + right.len;
                    if (left.isLast1 && right.isStart1) {
                        if (left.len == 1) isStart1 = false;
                        if (right.len == 1) isLast1 = false;
                        len -= 2;
                        val = add(add(left.val, -pow[left.len - 1]), mul(mul(inv, add(right.val, -pow[0])), pow[left.len - 1]));
                    } else {
                        val = add(left.val, mul(right.val, pow[left.len]));
                    }
                }
            }
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            s = sc.next();
            SegTree st1 = new SegTree();
            SegTree st2 = new SegTree();
            int q = sc.nextInt();
            for (int i = 0; i < q; i++) {
                int l1 = sc.nextInt() - 1;
                int l2 = sc.nextInt() - 1;
                int len = sc.nextInt();
                if (st1.eq(l1, l2, len) && st2.eq(l1, l2, len)) {
                    pw.println("Yes");
                } else {
                    pw.println("No");
                }
            }


        }
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("nondec.in"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("nondec.out"));

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