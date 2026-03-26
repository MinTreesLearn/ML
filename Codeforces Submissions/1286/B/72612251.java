//package com.company;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static class Task {
        int n;
        List<Integer>[] child;
        int[] bigger;
        int[] valueToVertex;
        int mx = 0;
        boolean find = true;
        int dfs(int u) {
            int valueStart = mx;
            for (int v: child[u]) {
                valueStart = Math.min(dfs(v), valueStart);
            }
            int processed = mx - valueStart;
            if (!find || bigger[u] > processed) {
                find = false;
                return -1;
            }
            for (int i = mx - 1; i >= valueStart + bigger[u]; i--) {
                valueToVertex[i + 1] = valueToVertex[i];
            }
            mx++;
            valueToVertex[valueStart + bigger[u]] = u;
            return valueStart;
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            n = sc.nextInt();
            child = new List[n];
            for (int i = 0; i < n; i++) {
                child[i] = new ArrayList<>();
            }
            bigger = new int[n];
            valueToVertex = new int[n + 1];
            int r = -1;
            for (int i = 0; i < n; i++) {
                int p = sc.nextInt() - 1;
                bigger[i] = sc.nextInt();
                if (p == -1) r = i;
                else child[p].add(i);
            }
            dfs(r);
            if (!find) {
                pw.println("NO");
                return;
            }
            pw.println("YES");
            int[] go = new int[n];
            for (int i = 0; i < n; i++) {
                go[valueToVertex[i]] = i + 1;
            }
            for (int i = 0; i < n; i++) {
                pw.print(go[i] + " ");
            }
            pw.println();
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