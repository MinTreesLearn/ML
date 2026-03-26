//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int k = sc.nextInt();
            if (n <= 2) {
                if (n == 1) {
                    if (k > 0) {
                        pw.println(-1);
                    } else {
                        pw.println(1);
                    }
                } else if (n == 2) {
                    if (k > 0) {
                        pw.println(-1);
                    } else {
                        pw.println(1 + " " + 2);
                    }
                }
                return;
            }
            List<Integer> out = new ArrayList<>();
            out.add(1);
            out.add(2);
            n -= 2;
            outer:
            while (n > 0 && k > 0) {
                int added = out.size() / 2;
                if (k >= added) {
                    n--;
                    out.add(out.size() + 1);
                    k -= added;
                } else {
                    for (int m = out.size() + 1; ; m++) {
                        int t = out.size();
                        int earn = (t - (m - t) + 1) / 2;
                        if (earn == k) {
                            n--;
                            out.add(m);
                            k -= earn;
                            break outer;
                        }
                    }
                }
            }
            if (n == 0 && k > 0) {
                pw.println(-1);
                return;
            }
            int z = out.size() + 10000;
            for (int i = 0; i < n; i++) {
                out.add(100000000 + i * z);
            }
            for (int x: out) pw.print(x + " ");
            pw.println();
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