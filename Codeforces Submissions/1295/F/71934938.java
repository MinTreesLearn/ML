//package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static class Task {

        int mod = 998244353;
        int add(int a, int b) {
            int c = a + b;
            if (c >= mod) return c - mod;
            if (c < 0) return c + mod;
            return c;
        }

        int mult(int a, int b) {
            return (int) ((long) a * b % mod);
        }

        int pow(int a, int b) {
            int r = 1;
            while (b != 0) {
                if (b % 2 == 1) r = mult(r, a);
                a = mult(a, a);
                b >>= 1;
            }
            return r;
        }

        private static final int N = 55;
        private final int inv2 = pow(2, mod - 2);
        int[] bernoli;
        int[][] cnk;
        int[] factorial;
        int[] invfact;
        void gen() {
            bernoli = new int[N];
            cnk = new int[N][N];
            for (int i = 0; i < N; i++) {
                cnk[i][0] = cnk[i][i] = 1;
            }
            for (int i = 2; i < N; i++) {
                for (int j = 1; j < i; j++) {
                    cnk[i][j] = add(cnk[i - 1][j - 1], cnk[i - 1][j]);
                }
            }
            factorial = new int[N];
            invfact = new int[N];
            factorial[0] = 1;
            for (int i = 1; i < N; i++) {
                factorial[i] = mult(i, factorial[i - 1]);
            }
            for (int i = 0; i < N; i++) {
                invfact[i] = pow(factorial[i], mod - 2);
            }
            bernoli[0] = 1;
            for (int m = 1; m < N; m++) {
                int tmp = 0;
                for (int k = 0; k < m; k++) {
                    int z = cnk[m][k];
                    z = mult(z, bernoli[k]);
                    z = mult(z, pow(m - k + 1, mod - 2));
                    tmp = add(tmp, z);
                }
                bernoli[m] = add(1, -tmp);
            }
            if (bernoli[1] != inv2) throw new RuntimeException();
        }

        public class Polynomial {
            int[] coef;
            public Polynomial(int[] coef) {
                this.coef = coef;
                if (coef.length != N) throw new RuntimeException();
            }
            int evalAt(int x) {
                int r = 0;
                for (int i = 0; i < coef.length; i++) {
                    r = add(r, mult(coef[i], pow(x, i)));
                }
                return r;
            }
            Polynomial integrate(int L) {
                int[] newCoef = new int[N];
                for (int m = 0; m < N; m++) {
                    for (int k = 0; k <= m; k++) {
                        if (m + 1 - k < N) {
                            int co = mult(factorial[m], invfact[k]);
                            co = mult(co, invfact[m + 1 - k]);
                            co = mult(co, bernoli[k]);
                            newCoef[m + 1 - k] = add(newCoef[m + 1 - k], mult(coef[m], co));
                        }
                    }
                }
                int invL = pow(L, mod - 2);
                for (int i = 0; i < N; i++) {
                    newCoef[i] = mult(newCoef[i], invL);
                }
                return new Polynomial(newCoef);
            }
            void addFrom(Polynomial p) {
                for (int i = 0; i < coef.length; i++) {
                    coef[i] = add(coef[i], p.coef[i]);
                }
            }
        }

        Polynomial uniform(int totalProb, int L) {
            int[] coef = new int[N];
            coef[1] = mult(totalProb, pow(L, mod - 2));
            return new Polynomial(coef);
        }

        public class Segment {
            int l, r;
            Polynomial p;
            public Segment(int l, int r, Polynomial p) {
                this.l = l;
                this.r = r;
                this.p = p;
            }
        }

        Segment[] get(List<Integer> breakDown) {
            Segment[] probs = new Segment[breakDown.size() - 1];
            for (int i = 0; i < breakDown.size() - 1; i++) {
                probs[i] = new Segment(breakDown.get(i), breakDown.get(i + 1), new Polynomial(new int[N]));
            }
            return probs;
        }

        List<Integer> activeSegs(List<Integer> breakDown, int L, int R) {
            List<Integer> ret = new ArrayList<>();
            for (int i = 0; i < breakDown.size() - 1; i++) {
                if (breakDown.get(i) >= L && breakDown.get(i + 1) <= R) {
                    ret.add(i);
                }
            }
            return ret;
        }

        void checkFind(int p) {
            for (int i = 1; i < 2000; i++) {
                for (int j = i; j < 2000; j++) {
                    if (mult(i, pow(j, mod - 2)) == p) {
                        System.err.println("Found for " + p + ": " + i + "/" + j);
                        return;
                    }
                }
            }
            System.err.println("Not Found " + p);
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
//            checkFind(578894053);
//            int p1 =  mult(917, pow(1296, mod - 2));
//            int p2 = mult(mult(379, pow(1296, mod - 2)), mult(29, pow(408, mod - 2)));
//            int p3 = add(578894053, -add(p1, p2));
//            int mp3 = mult(95, pow(648, mod - 2));
//            System.err.println(add(p1, add(p2, mp3)));
//            checkFind(add(578894053, -p1));
//            checkFind(p3);
            gen();
            int n = sc.nextInt();
            int[][] lr=  new int[n][2];
            TreeSet<Integer> critical = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    lr[i][j] = sc.nextInt();
                    if (j == 1) lr[i][j]++;
                    critical.add(lr[i][j]);
                }
            }
            List<Integer> breakDown = new ArrayList<>();
            while (critical.size() > 0) {
                breakDown.add(critical.first());
                critical.pollFirst();
            }
            Segment[] segs = get(breakDown);
            int tp = 0;
            for (int i = 0; i < n; i++) {
                List<Integer> active = activeSegs(breakDown, lr[i][0], lr[i][1]);
                int LL = lr[i][1] - lr[i][0];
                if (i == 0) {
                    for (int s: active) {
                        int sz = segs[s].r - segs[s].l;
                        segs[s].p = uniform(mult(pow(LL, mod - 2), sz), sz);
                    }
                } else {
                    Segment[] nextSegs = get(breakDown);
                    for (Segment s: segs) {
                        if (s.p.evalAt(1) == 0) continue;
//                        System.err.println(s.l + " " + s.r);
//                        int zrf = 0;
                        for (int ss: active) {
                            if (segs[ss].r == s.r) {
                                Polynomial np = s.p.integrate(LL);
//                                System.err.println("adwdqwdqw");
//                                checkFind(np.evalAt(segs[ss].r - segs[ss].l));
                                nextSegs[ss].p.addFrom(np);
                            } else if (segs[ss].r < s.r) {
                                int totalProb = s.p.evalAt(s.r - s.l);
//                                System.err.println(s.l + " " + s.r + " " + segs[ss].l + " " + segs[ss].r);
//                                checkFind(totalProb);
                                // 917 / 1296 * (43 - 13) / (421 - 13)
                                Polynomial np = uniform(mult(totalProb, mult(pow(LL, mod - 2), segs[ss].r - segs[ss].l)), segs[ss].r - segs[ss].l);
//                                int ntf = np.evalAt(segs[ss].r - segs[ss].l);
//                                zrf = add(zrf, ntf);
                                nextSegs[ss].p.addFrom(np);
                            }
                        }
//                        checkFind(zrf);
                    }
                    segs = nextSegs;
                }
                tp = 0;
                for (Segment ss: segs) {
                    tp = add(tp, ss.p.evalAt(ss.r - ss.l));
                }
//                System.err.println(tp);
//                checkFind(tp);

            }
            pw.println(tp);
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