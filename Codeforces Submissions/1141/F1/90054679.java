//package com.company;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static class Task {


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int[] arr = new int[n];
            int[] pref = new int[n + 1];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                pref[i + 1] = pref[i] + arr[i];
            }
            int best = 0;
            List<int[]> ret = new ArrayList<>();
            for (int L = 1; L <= n; L++) {
                for (int i = 0; i + L <= n; i++) {
                    int sum = 0;
                    for (int j = i; j < i + L; j++) {
                        sum += arr[j];
                    }
                    int cur = 1;
                    int stop = i + L;
                    List<int[]> cu = new ArrayList<>();
                    cu.add(new int[]{i, i + L - 1});
                    for (int j = i + L; j < n; j++) {
                        for (int k = stop; k <= j; k++) {
                            if (pref[j + 1] - pref[k] == sum) {
                                cur++;
                                cu.add(new int[]{k, j});
                                stop = j + 1;
                                break;
                            }
                        }
                    }
                    if (cur > best) {
                        best = cur;
                        ret = cu;
                    }
                }
            }
            pw.println(best);
            for (int[] x: ret) {
                pw.println(x[0] + 1 + " " + (x[1] + 1));
            }
        }
        
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("ans.txt"));
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