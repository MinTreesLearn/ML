//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {

        List<Integer> primes;
        int[] pF;
        int[] mobius;
        int[] cnt;
        boolean[] on;
        List<Integer>[] factors;
        void update(int x, int y) {
            for (int d: factors[x]) cnt[d] += y;
        }
        int count(int x) {
            int r = 0;
            for (int d: factors[x]) r += mobius[d] * cnt[d];
            return r;
        }

        public void precompute() {
            int n = 100001;
            primes = new ArrayList<>();
            pF = new int[n];
            mobius = new int[n];
            mobius[1] = 1;
            for (int i = 2; i < n; ++i) {
                if (pF[i] == 0) {
                    pF[i] = i;
                    primes.add(i);
                    mobius[i] = -1;
                }
                for (int j = 0; j < primes.size () && i * primes.get(j) < n; ++j) {
                    int p = primes.get(j);
                    pF[i * p] = p;
                    if (i % p == 0) {
                        mobius[i * p] = 0;
                        break;
                    } else {
                        mobius[i * p] = mobius[i] * mobius[p];
                    }
                }
            }
            cnt = new int[n];
            on = new boolean[n];
            factors = new List[n];
            for (int i = 0; i < n; i++) {
                factors[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; i++) {
                for (int j = i; j < n; j += i) factors[j].add(i);
            }
        }

        int gcd(int x, int y) {
            return y == 0 ? x: gcd(y, x % y);
        }
        long lcm(int x, int y) {
            int g = gcd(x, y);
            return (long) x * y / g;
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            precompute();
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                on[sc.nextInt()] = true;
            }
            long m = 0;
            int[] stack = new int[n];
            int sIdx = 0;
            for (int g = 1; g <= 100000; g++) {
                for (int i = 100000 / g; i > 0; i--) if (on[i * g]) {
                    m = Math.max(m, i * g);
                    int coprimes = count(i);
                    while (coprimes > 0) {
                        int x = stack[sIdx - 1];
                        int _g = gcd(i, x);
                        m = Math.max(m, (long) g * i * x / _g);
                        if (_g == 1) coprimes--;
                        update(stack[sIdx - 1], -1);
                        sIdx--;
                    }
                    update(i, 1);
                    stack[sIdx++] = i;
                }
                while (sIdx > 0) {
                    update(stack[sIdx - 1], -1);
                    sIdx--;
                }
            }
            pw.println(m);
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