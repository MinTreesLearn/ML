//package com.company;
import java.io.*;
import java.util.*;

public class Main {
    public static class Task {


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int[] numbers = new int[n];
            for (int i = 0; i < n; i++) {
                numbers[i] = sc.nextInt();
            }
            long[] sum = new long[n];
            int[] count = new int[n];
            int idx = 0;
            for (int x: numbers) {
                long curSum = x;
                int curCount = 1;
                while (idx > 0) {
                    long p = sum[idx - 1];
                    int c = count[idx - 1];
                    if (p * curCount >= (long) c * curSum) {
                        curSum += p;
                        curCount += c;
                        idx--;
                    } else {
                        break;
                    }
                }
                sum[idx] = curSum;
                count[idx] = curCount;
                idx++;
            }
            for (int i = 0; i < idx; i++) {
                double avg = 1.0 * sum[i] / count[i];
                for (int j = 0; j < count[i]; j++) {
                    pw.println(avg);
                }
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