//package com.example.practice.codeforces.below2000;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

//A. Recommendations
public class Solution16 {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        final BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        // input file name goes above
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("inflate.out")));
        int n = Integer.parseInt(input.readLine());
        int[][] ns = new int[n][];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for (int i=0;i<n;++i){
            ns[i] = new int[]{Integer.parseInt(st.nextToken()), 0};
        }
        st = new StringTokenizer(input.readLine());
        for (int i=0;i<n;++i){
            ns[i][1] = Integer.parseInt(st.nextToken());
        }
        out.println(calc(n, ns));
        out.close();       // close the output file
    }

    private static long calc(final int n, final int[][] ns) {
        if (n<2)return 0;
        Arrays.sort(ns, Comparator.comparingInt(a -> a[0]));
        int pre = ns[0][0];
        long res = 0;
        for (int i=0,j=1;j<n;++j){
            pre++;
            if (ns[j][0] >= pre){
                res += calcGroup(ns, i, j-1);
                pre = ns[j][0];
                i = j;
            }else if (j+1==n){
                res += calcGroup(ns, i, j);
            }
        }
        return res;
    }

    private static long calcGroup(final int[][] ns, int l, int r){
        if (l>=r)return 0;
        long res = 0;
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return ns[o2][1] - ns[o1][1];
            }
        });
        int p = l;
        for (int i=ns[l][0],j=i+(r-l);i<=j;++i){
            while (p<=r && ns[p][0]<=i){
                heap.offer(p++);
            }
            int t = heap.poll();
            res += ((long)(i-ns[t][0])) * ns[t][1];
        }
        return res;
    }
}

