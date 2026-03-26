//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {
        public class Number {
            int factNum;
            int[] primeFactorCounts;
            int largestFactor;
            int S = 0;
            public Number(int f, int[] primeFactorCounts) {
                this.factNum = f;
                this.primeFactorCounts = primeFactorCounts;
                for (largestFactor = primeFactorCounts.length - 1; largestFactor >= 0; largestFactor--) {
                    if (primeFactorCounts[largestFactor] != 0) break;
                }
                for (int y: primeFactorCounts)S += y;
            }
            int getL() {
                if (largestFactor == -1) return -1;
                int r = largestFactor;
                primeFactorCounts[r]--;
                if (primeFactorCounts[r] == 0) largestFactor--;
                return r;
            }
        }

        List<Integer> primes;
        int[] factor;

        public void precompute() {
            int n = 5001;
            primes = new ArrayList<>();
            factor = new int[n];
            Arrays.fill(factor, -1);
            for (int i = 2; i < n; ++i) {
                if (factor[i] == -1) {
                    factor[i] = primes.size();
                    primes.add(i);
                }
                for (int j = 0; j < primes.size () && i * primes.get(j) < n; ++j) {
                    int p = primes.get(j);
                    factor[i * p] = j;
                    if (i % p == 0) {
                        break;
                    }
                }
            }
        }

        List<Integer> fact(int x) {
            List<Integer> retL = new ArrayList<>();
            while (x != 1) {
                retL.add(factor[x]);
                x /= primes.get(factor[x]);
            }
            return retL;
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            precompute();
            int[] primeF = new int[700];
            Number[] numbers = new Number[5001];
//            numbers[0] = new Number(1, Arrays.copyOf(primeF, 700));
            numbers[1] = new Number(1, Arrays.copyOf(primeF, 700));
            for (int i = 2; i <= 5000; i++) {
                List<Integer> f = fact(i);
                for (int y: f) primeF[y]++;
                numbers[i] = new Number(i, Arrays.copyOf(primeF, 700));
            }
//            pw.println(Arrays.toString(numbers[5000].primeFactorCounts));
//            System.err.println(numbers[5000].S);
            Map<Integer, Integer> numToCount = new HashMap<>();
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                a = Math.max(a, 1);
                numToCount.put(a, numToCount.getOrDefault(a, 0) + 1);
            }
            long total = 0;
            for (Map.Entry<Integer, Integer> en : numToCount.entrySet()) {
                total += (long) en.getValue() * numbers[en.getKey()].S;
            }
            outer:
            while (true) {
                Map<Integer, Integer> kG = new HashMap<>();
                for (Map.Entry<Integer, Integer> en : numToCount.entrySet()) {
                    int k = en.getKey();
                    int v = en.getValue();
                    int lf = numbers[k].largestFactor;
                    if (lf == -1) continue ;
                    kG.put(lf, kG.getOrDefault(lf, 0) + v);
                }
                for (Map.Entry<Integer, Integer> en: kG.entrySet()) {
                    if (n - en.getValue() < en.getValue()) {
                        total -= en.getValue() - (n - en.getValue());
                        Map<Integer, Integer> nC = new HashMap<>();
                        for (Map.Entry<Integer, Integer> en1 : numToCount.entrySet()) {
                            int lf = numbers[en1.getKey()].getL();
                            if (lf == en.getKey()) {
                                nC.put(en1.getKey(), en1.getValue());
                            }
                        }
                        numToCount = nC;
                        continue outer;
                    }
                }
                pw.println(total);
                return;
            }
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