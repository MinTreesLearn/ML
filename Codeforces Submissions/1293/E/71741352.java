//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {
        int n;
        List<Integer>[] tree;
        int[][] size;
        int[][] parent;
        long[][] dp;

        int dfs1(int r, int u, int p) {
            parent[r][u] = p;
            size[r][u] = 1;
            for (int v: tree[u]) if (v != p) {
                size[r][u] += dfs1(r, v, u);
            }
            return size[r][u];
        }

        int hash(int a, int b) {
            if (a > b) return hash(b, a);
            return a * 3000 + b;
        }

        public long dfsCalc(int a, int b) {
            if (dp[a][b] != -1) return dp[a][b];
            if (parent[b][a] == b) {
                return dp[a][b] = dp[b][a] = (long) size[b][a] * size[a][b];
            } else {
                return dp[a][b] = dp[b][a] = Math.max(dfsCalc(parent[b][a], b), dfsCalc(a, parent[a][b])) + (long) size[b][a] * size[a][b];
            }
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            n = sc.nextInt();
            tree = new List[n];
            size = new int[n][n];
            parent = new int[n][n];
            for (int i = 0; i < n; i++) {
                tree[i] = new ArrayList<>();
            }
            Set<Integer> edges = new HashSet<>();
            for (int i = 0; i < n - 1; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                tree[a].add(b);
                tree[b].add(a);
                edges.add(hash(a, b));
            }
            for (int i = 0; i < n; i++) {
                dfs1(i, i, -1);
            }
            dp = new long[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(dp[i], -1);
            }
            long ret = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) if (j != i) {
                    ret = Math.max(ret, dfsCalc(i, j));
                }
            }
            pw.println(ret);
        }
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("input"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("output"));


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