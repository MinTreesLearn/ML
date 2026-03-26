//package com.example.practice.codeforces.below2000;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

//A. Garland
public class Solution112 {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        final BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        // input file name goes above
        StringTokenizer st = new StringTokenizer(input.readLine());
        final int n = Integer.parseInt(st.nextToken());
        final int[] ns = readArrayInt(n, input);
        out.println(calc(n, ns));
        out.close();       // close the output file
    }

    private static int calc(final int n, final int[] ns) {
        int[] rd = new int[n];
        boolean[] seen = new boolean[n+1];
        int pre = 0, odd = 0, even = 0;
        for (int i=0;i<n;++i){
            rd[i] = pre;
            if (ns[i]==0)pre++;
            seen[ns[i]] = true;
        }
        for (int i=1;i<=n;++i){
            if (!seen[i]){
                if (i%2==0)even++;
                else odd++;
            }
        }
        Integer[][][] dp = new Integer[2][n][odd+1];
        return todo(dp, 0, 0, odd, rd, odd, even, ns);
    }

    private static int todo(Integer[][][] dp, int st, int idx, final int c, int[] rd, final int odd, final int even, int[] ns){
        if (idx >= rd.length)return 0;
        if (dp[st][idx][c] != null){
            return dp[st][idx][c];
        }
        if (ns[idx] > 0){
            dp[st][idx][c] = todo(dp, ns[idx]%2, idx+1, c, rd, odd, even, ns) + (idx==0 || st==(ns[idx]%2) ? 0 : 1);
        }else {
            dp[st][idx][c] = rd.length;
            if (c > 0){
                dp[st][idx][c] = todo(dp, 1, idx+1, c-1, rd, odd, even, ns) + (idx==0 || st==1 ? 0 : 1);
            }
            if (rd[idx]-(odd-c) < even){
                dp[st][idx][c] = Math.min(dp[st][idx][c], todo(dp, 0, idx+1, c, rd, odd, even, ns) + (idx==0 || st==0 ? 0 : 1));
            }
        }
        return dp[st][idx][c];
    }

    private static void printArray(long[] ns, final PrintWriter out){
        for (int i=0;i<ns.length;++i){
            out.print(ns[i]);
            if (i+1<ns.length)out.print(" ");
            else out.println();
        }
    }

    private static void printArrayInt(int[] ns, final PrintWriter out){
        for (int i=0;i<ns.length;++i){
            out.print(ns[i]);
            if (i+1<ns.length)out.print(" ");
            else out.println();
        }
    }

    private static void printArrayVertical(long[] ns, final PrintWriter out){
        for (long a : ns){
            out.println(a);
        }
    }

    private static void printArrayVerticalInt(int[] ns, final PrintWriter out){
        for (int a : ns){
            out.println(a);
        }
    }

    private static void printArray2D(long[][] ns, final int len, final PrintWriter out){
        int cnt = 0;
        for (long[] kk : ns){
            cnt++;
            if (cnt > len)break;
            for (int i=0;i<kk.length;++i){
                out.print(kk[i]);
                if (i+1<kk.length)out.print(" ");
                else out.println();
            }
        }
    }

    private static void printArray2DInt(int[][] ns, final int len, final PrintWriter out){
        int cnt = 0;
        for (int[] kk : ns){
            cnt++;
            if (cnt > len)break;
            for (int i=0;i<kk.length;++i){
                out.print(kk[i]);
                if (i+1<kk.length)out.print(" ");
                else out.println();
            }
        }
    }

    private static long[] readArray(final int n, final BufferedReader input) throws IOException{
        long[] ns = new long[n];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for (int i=0;i<n;++i){
            ns[i] = Long.parseLong(st.nextToken());
        }
        return ns;
    }

    private static int[] readArrayInt(final int n, final BufferedReader input) throws IOException{
        int[] ns = new int[n];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for (int i=0;i<n;++i){
            ns[i] = Integer.parseInt(st.nextToken());
        }
        return ns;
    }

    private static long[] readArrayVertical(final int n, final BufferedReader input) throws IOException{
        long[] ns = new long[n];
        for (int i=0;i<n;++i){
            ns[i] = Long.parseLong(input.readLine());
        }
        return ns;
    }

    private static long[][] readArray2D(final int n, final int len, final BufferedReader input) throws IOException{
        long[][] ns = new long[len][];
        for (int i=0;i<n;++i){
            StringTokenizer st = new StringTokenizer(input.readLine());
            ArrayList<Long> al = new ArrayList<>();
            while (st.hasMoreTokens()){
                al.add(Long.parseLong(st.nextToken()));
            }
            long[] kk = new long[al.size()];
            for (int j=0;j<kk.length;++j){
                kk[j] = al.get(j);
            }
            ns[i] = kk;
        }
        return ns;
    }

    private static int[][] readArray2DInt(final int n, final int len, final BufferedReader input) throws IOException{
        int[][] ns = new int[len][];
        for (int i=0;i<n;++i){
            StringTokenizer st = new StringTokenizer(input.readLine());
            ArrayList<Integer> al = new ArrayList<>();
            while (st.hasMoreTokens()){
                al.add(Integer.parseInt(st.nextToken()));
            }
            int[] kk = new int[al.size()];
            for (int j=0;j<kk.length;++j){
                kk[j] = al.get(j);
            }
            ns[i] = kk;
        }
        return ns;
    }
}