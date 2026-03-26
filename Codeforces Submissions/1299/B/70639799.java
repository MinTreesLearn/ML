//package com.company;
import java.io.*;
import java.util.*;

public class Main {
    public static class Task {


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            if (n % 2 != 0) {
                pw.println("NO");
                return;
            }
            int[][] pair = new int[n][2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    pair[i][j] = sc.nextInt();
                }
            }
            boolean same = true;
            for (int i = 0, j = n / 2; i < n / 2; i++, j++) {
                if (pair[i + 1][0] - pair[i][0] != pair[j][0] - pair[(j + 1) % n][0]) {
                    same=false;break;
                }
                if (pair[i + 1][1] - pair[i][1] != pair[j][1] - pair[(j + 1) % n][1]) {
                    same=false;break;
                }
            }
            pw.println(same? "YES": "NO");
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