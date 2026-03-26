//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int T = sc.nextInt();
            while (T-- > 0) {
                int n = sc.nextInt();
                int[][] events = new int[2 * n][];
                int[] prefixAns1 = new int[n + 1];
                int[] prefixAnsL = new int[n + 1];
                for (int i = 0; i < n; i++) {
                    int l = sc.nextInt();
                    int r = sc.nextInt();
                    events[i * 2] = new int[]{2 * l, i + 1};
                    events[i * 2 + 1] = new int[]{2 * r + 1, -i - 1};
                }
                Arrays.sort(events, new Comparator<int[]>() {
                    @Override
                    public int compare(int[] o1, int[] o2) {
                        if (o1[0] == o2[0]) return Integer.compare(o1[1], o2[1]);
                        return Integer.compare(o1[0], o2[0]);
                    }
                });
                int cnt = 0;
                int count0 = 0;
                int count1 = 0;
                int countL = 0;
                int eIdx = 0;
                while (eIdx < 2 * n) {
                    int iv = events[eIdx][0];
                    int tIdx = eIdx;
                    while (tIdx < 2 * n && events[tIdx][0] == iv && events[tIdx][1] < 0) {
                        prefixAns1[-events[tIdx][1]] += count1;
                        prefixAnsL[-events[tIdx][1]] += countL;
                        tIdx++;
                    }
                    if (tIdx == eIdx + 1 && cnt == 1){
                        tIdx = eIdx;
                        while (tIdx < 2 * n && events[tIdx][0] == iv && events[tIdx][1] < 0) {
                            prefixAns1[-events[tIdx][1]] -= 1;
                            tIdx++;
                        }
                    }
                    cnt -= tIdx - eIdx;
                    if (eIdx != tIdx) {
                        if (cnt == 0) count0++;
                        if (cnt == 1) count1++;
                    }
                    eIdx = tIdx;
                    while (tIdx < 2 * n && events[tIdx][0] == iv && events[tIdx][1] > 0) {
                        prefixAns1[events[tIdx][1]] -= count1;
                        prefixAnsL[events[tIdx][1]] -= countL;
                        tIdx++;
                    }
                    cnt += tIdx - eIdx;
                    if (eIdx != tIdx) {
                        if (cnt > 1) countL++;
                    }
                    eIdx = tIdx;
                }
                int best = 0;
                for (int i = 1; i <= n; i++) {
                    if (prefixAnsL[i] == 0) {
                        best = Math.max(best, count0 - 1);
                    } else {
                        best = Math.max(best, count0 + prefixAns1[i]);
                    }
                }
                pw.println(best);
            }
        }
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("input"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("input"));
//        int n = 200000;
//        pw.println("1 " + n);
//        Random rnd = new Random();
//        for (int i = 0; i < n; i++) {
//            int a = rnd.nextInt(2000000000) - 1000000000;
//            int b = rnd.nextInt(1000000000);
//            pw.println(a + " " + (a + b));
//        }
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