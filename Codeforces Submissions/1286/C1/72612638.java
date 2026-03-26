//package com.company;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static class Task {

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


        public void solve(Scanner sc) throws IOException {
            int n = sc.nextInt();
            System.out.println("? 1 " + n);
            System.out.flush();
            Map<String, Integer> mp = new HashMap<>();
            for (int i = 0; i < n * (n + 1) / 2; i++) {
                String s = sc.next();
                s = sor(s);
                mp.put(s, mp.getOrDefault(s, 0) + 1);
            }
            if (n == 1) {
                for (String s: mp.keySet()) {
                    System.out.println("! " + s);
                    return;
                }
            }
            System.out.println("? 2 " + n);
            System.out.flush();
            for (int i = 0; i < n * (n - 1) / 2; i++) {
                String s = sc.next();
                s = sor(s);
                mp.put(s, mp.get(s) - 1);
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
            System.out.println("! " + sol.toString());
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