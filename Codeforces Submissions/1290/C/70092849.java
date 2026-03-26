//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {

        public class DJS {
            int n;
            int[] arr;
            int[] sizes;
            int unAssign;
            public DJS(int n) {
                this.n = n;
                arr = new int[n * 2 + 2];
                sizes = new int[n * 2 + 2];
                Arrays.fill(arr, -1);
                Arrays.fill(sizes, 0);
                for (int i = 0; i < n; i++) {
                    sizes[i] = 1;
                }
                unAssign = n;
            }
            int find(int u) {
                return arr[u] < 0 ? u: (arr[u] = find(arr[u]));
            }
            int size(int u) {
                return arr[u] < 0 ? sizes[u]: 0;
            }
            void link(int a, int b) { // b -> a
                int ra = find(a);
                int rb = find(b);
                if (ra == rb) return;
                sizes[ra] += sizes[rb];
                arr[rb] = ra;
            }
            int getOther(int k) {
                if (k < n) throw new RuntimeException();
                int v = k - (n + 2);
                return v % 2 == 0 ? k + 1: k - 1;
            }
            int vv(int k) {
                if (k < n) {
                    throw new RuntimeException();
                }
                if (k == n || k == n + 1) return 0;
                return Math.min(size(k), size(getOther(k)));
            }
            int getEmp() {
                return (unAssign += 2);
            }

        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();
            List<Integer>[] vs = new List[n];
            for (int i = 0; i < n; i++) {
                vs[i] = new ArrayList<>();
            }
            for (int i = 0; i < k; i++) {
                int c = sc.nextInt();
                for (int j = 0; j < c; j++) {
                    int q = sc.nextInt() - 1;
                    vs[q].add(i);
                }
            }
            DJS djs = new DJS(k);
            int better = 0;
            for (int i = 0; i < n; i++) {
//                System.err.print(s.charAt(i) + " ");
                if (vs[i].size() == 1) {
                    int u = vs[i].get(0);
                    int ru = djs.find(u);
//                    System.err.println(u + " " + ru);
                    if (ru == k || ru == k + 1) {

                    } else if (ru < k) {
                        djs.link(s.charAt(i) == '0' ? k: k + 1, u);
                    } else {
                        int rup = djs.getOther(ru);
                        better -= djs.vv(ru);
                        djs.link(s.charAt(i) == '0' ? k: k + 1, ru);
                        djs.link(s.charAt(i) != '0' ? k: k + 1, rup);
                    }
                } else if (vs[i].size() == 2) {
                    int u = vs[i].get(0), v = vs[i].get(1);
                    int ru = djs.find(u), rv = djs.find(v);
//                    System.err.println(u + " " + v + " " + ru + " " + rv);
                    if (ru < k && rv < k) {
                        int y = djs.getEmp();
                        if (s.charAt(i) == '1') {
                            djs.link(ru, rv);
                            djs.link(y, ru);
                        } else {
                            djs.link(y, ru);
                            djs.link(djs.getOther(y), rv);
                        }
                        better += djs.vv(y);
                    } else if (ru < k) {
                        better -= djs.vv(rv);
                        if (s.charAt(i) == '1') {
                            djs.link(rv, ru);
                        } else {
                            djs.link(djs.getOther(rv), ru);
                        }
                        better += djs.vv(rv);
                    } else if (rv < k) {
                        better -= djs.vv(ru);
                        if (s.charAt(i) == '1') {
                            djs.link(ru, rv);
                        } else {
                            djs.link(djs.getOther(ru), rv);
                        }
                        better += djs.vv(ru);
                    } else {// ru -> rv;
                        if (ru == rv || ru == djs.getOther(rv)) {

                        } else {
                            if (rv > ru) {
                                int tt = rv; rv = ru; ru = tt;
                            }
                            better -= djs.vv(ru);
                            better -= djs.vv(rv);
                            if (s.charAt(i) == '1') {
                                djs.link(rv, ru);
                                djs.link(djs.getOther(rv), djs.getOther(ru));
                            } else {
                                djs.link(djs.getOther(rv), ru);
                                djs.link(rv, djs.getOther(ru));
                            }
                            better += djs.vv(rv);
                        }

                    }
                }
                pw.println(djs.size(k) + better);
            }
        }
    }
    static long TIME_START, TIME_END;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("joker.in"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("joker.out"));

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