// package com.company.Codeforces;

import java.util.*;
import java.lang.*;
import java.io.*;

public class aaaaaa
{
    public static void solve() {
        int n = sc.nextInt();
        double ans = 0;
        for(int i=1; i<=n; i++){
            ans += (1.0/i);
        }

        out.println(ans);
    }

    static PrintWriter out;
    static StringBuilder str;
    static Scanner sc;
    public static void main (String[] args) throws java.lang.Exception
    {
        sc = new Scanner();
        str = new StringBuilder();
        out = new PrintWriter(System.out);

//        int t = sc.nextInt();
        int t = 1;
        while(t-->0){
            solve();
//            str.append('\n');
        }

//        out.println(str);
        out.close();
    }

    static long modInverse(long num, long mod){
        return power(num, mod-2, mod);
    }

    private static long power(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1)==1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    private static long power(long a, long b, long m) {
        a %= m;
        long res = 1;
        while (b > 0) {
            if ((b & 1)==1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    private static long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
/*
            try {
                br = new BufferedReader(new
                        InputStreamReader(new FileInputStream(new File("file_i_o\\input.txt"))));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
*/
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextInt();
            }
            return array;
        }

        Integer[] nextIntegerArray(int n) {
            Integer[] array = new Integer[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextInt();
            }
            return array;
        }

        long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextLong();
            }
            return array;
        }

        String[] nextStringArray() {
            return nextLine().split(" ");
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++) {
                array[i] = next();
            }
            return array;
        }
    }
}
