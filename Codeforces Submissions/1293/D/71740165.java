//package com.company;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static class Task {


        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            BigInteger x0 = BigInteger.valueOf(sc.nextLong());
            BigInteger y0 = BigInteger.valueOf(sc.nextLong());
            BigInteger ax = BigInteger.valueOf(sc.nextLong());
            BigInteger ay = BigInteger.valueOf(sc.nextLong());
            BigInteger bx = BigInteger.valueOf(sc.nextLong());
            BigInteger by = BigInteger.valueOf(sc.nextLong());
            long xs = sc.nextLong();
            long ys = sc.nextLong();
            long t = sc.nextLong();
            List<BigInteger[]> coord = new ArrayList<>();
            coord.add(new BigInteger[]{x0, y0});
            for (int i = 0; i < 100; i++) {
                BigInteger px = coord.get(coord.size() - 1)[0];
                BigInteger py = coord.get(coord.size() - 1)[1];
                BigInteger nx = px.multiply(ax).add(bx);
                BigInteger ny = py.multiply(ay).add(by);
                if (nx.compareTo(BigInteger.valueOf((long) 1e18)) > 0) break;
                if (ny.compareTo(BigInteger.valueOf((long) 1e18)) > 0) break;
                coord.add(new BigInteger[]{nx, ny});
            }
//            System.err.println(coord.get(1)[0] + " " + coord.get(1)[1]);
            int best = 0;
            for (int i = 0; i < coord.size(); i++) {
                for (int j = 0; j < coord.size(); j++) {
                    long dist1 = Math.abs(coord.get(i)[0].longValue() - xs) + Math.abs(coord.get(i)[1].longValue() - ys);
                    long dist2 = Math.abs(coord.get(j)[0].longValue() - coord.get(i)[0].longValue()) + Math.abs(coord.get(j)[1].longValue() - coord.get(i)[1].longValue());
//                    System.err.println(dist1 + dist2);
                    if (dist1 + dist2 <= t) {
                        best = Math.max(best, Math.abs(j - i) + 1);
                    }
                }
            }
            pw.println(best);
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