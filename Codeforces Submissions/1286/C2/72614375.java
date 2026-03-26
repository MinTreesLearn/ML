//package com.company;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static class Task {
        Scanner sc;
        String sor(String s) {
            char[] cc = new char[s.length()];
            for (int i = 0; i < s.length(); i++) {
                cc[i] = s.charAt(i);
            }
            Arrays.sort(cc);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cc.length; i++) {
                sb.append(cc[i]);
            }
            return sb.toString();
        }

        Map<String, Integer> get(int l, int r) throws IOException {
            System.out.println("? " + l + " " + r);
            System.out.flush();
            Map<String, Integer> mp = new HashMap<>();
            int n = (r - l) + 1;
            for (int i = 0; i < n * (n + 1) / 2; i++) {
                String s = sc.next();
                s = sor(s);
                mp.put(s, mp.getOrDefault(s, 0) + 1);
            }
            return mp;
        }

        String solveLen(int n) throws IOException {
            Map<String, Integer> mp = get(1, n);
            if (n == 1) {
                for (String s: mp.keySet()) {
                    System.out.println("! " + s);
                    System.exit(0);
                }
            }
            Map<String, Integer> mp2 = get(2, n);
            for (Map.Entry<String, Integer> en: mp2.entrySet()) {
                mp.put(en.getKey(), mp.get(en.getKey())-en.getValue());
            }
            List<String> ss = new ArrayList<>();
            for (Map.Entry<String, Integer> en: mp.entrySet()) {
                if (en.getValue() == 1) {
                    ss.add(en.getKey());
                }
            }
            StringBuilder sol = new StringBuilder();
            int[] con = new int[255];
            Collections.sort(ss, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return o1.length() - o2.length();
                }
            });
            for (int i = 0; i < ss.size(); i++) {
                for (int j = 0; j < ss.get(i).length(); j++) {
                    con[ss.get(i).charAt(j)]--;
                }
                for (int j = 0; j < 255; j++) {
                    if (con[j] < 0) sol.append((char) j);
                }
                Arrays.fill(con, 0);
                for (int j = 0; j < ss.get(i).length(); j++) {
                    con[ss.get(i).charAt(j)]++;
                }
            }
            return sol.toString();
        }

        void update(int[] cnt, String s, int p) {
            for (char c: s.toCharArray())cnt[c]+=p;
        }


        public void solve(Scanner sc) throws IOException {
            this.sc = sc;
            int n = sc.nextInt();
            if (n <= 2) {
                String s = solveLen(n);
                System.out.println("! " + s);return;
            }
            String s = solveLen(n / 2 + 1);
            Map<String, Integer> countMap = get(1, n);
            StringBuilder inv = new StringBuilder();
            for (int i = n - 1; i > n / 2; i--) {
                int[] cnt = new int[255];
                int searchLen = i;
                int maxRep = Math.min(searchLen, n - searchLen + 1);
                for (int j = n - 1; j >= i; j--) {
                    char c = s.charAt(n - 1 - j);
                    int kt = Math.min(maxRep, n - j);
                    cnt[c] += (maxRep - kt);
                    if (j > i) {
                        c = inv.charAt(n - 1 - j);
                        cnt[c] += (maxRep - kt);
                    }
                }
                for (Map.Entry<String, Integer> en: countMap.entrySet()) {
                    if (en.getKey().length() == n) update(cnt, en.getKey(), -en.getValue() * maxRep);
                    if (en.getKey().length() == searchLen) update(cnt, en.getKey(), en.getValue());
                }
                int on = -1;
                for (int j = 0; j < 255; j++) {
                    if (cnt[j] > 0) throw new RuntimeException();
                    if (cnt[j] == -1 && on != -1) throw new RuntimeException();
                    if (cnt[j] == -1) on = j;
                }
                if (on == -1) throw new RuntimeException();
                inv.append((char) on);
            }
            System.out.println("! " + s + inv.reverse().toString());
        }
    }

    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("nondec.in"));
//        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("nondec.out"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
//        pw.close();
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