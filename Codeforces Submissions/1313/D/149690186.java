//package com.example.practice.codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.StringTokenizer;
//D. Happy New Year
public class Solution {
    public static void main (String [] args) throws IOException {
        // Use BufferedReader rather than RandomAccessFile; it's much faster
        final BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        // input file name goes above
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("inflate.out")));

        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] ns = new int[n][2];
        for(int i=0;i<n;++i){
            st = new StringTokenizer(input.readLine());
            ns[i][0] = Integer.parseInt(st.nextToken());
            ns[i][1] = Integer.parseInt(st.nextToken());
        }
        System.out.println(calc(n, m, k, ns));
        //out.close();       // close the output file
    }

    private static int calc(final int n, final int m, final int k, int[][] ns) {
        HashMap<Integer, Node> map = new HashMap<>();
        int p = 0, pre = 0, finished = 0;
        for (int[] kk : ns){
            if (!map.containsKey(kk[0])){
                map.put(kk[0], new Node(kk[0]));
            }
            map.get(kk[0]).st.add(p);
            if (!map.containsKey(kk[1]+1)){
                map.put(kk[1]+1, new Node(kk[1]+1));
            }
            map.get(kk[1]+1).en.add(p++);
        }
        Node[] nds = new Node[map.size()];
        p = 0;
        for (Node nd : map.values()){
            nds[p++] = nd;
        }
        Arrays.sort(nds);
        final int ks = 1<<k;
        int[][] dp = new int[nds.length][ks];
        int[] mask = new int[n], bitCount = new int[ks];
        for (int i=1;i<ks;++i){
            if((i&1) == 1)bitCount[i]=bitCount[i-1]+1;
            else bitCount[i]=bitCount[i>>1];
        }
        for (int i=0;i<dp.length-1;++i){
            pre -= finished;
            int d = 1, added = 0;
            for (int a : nds[i].st){
                while((d&pre) != 0) {
                    d = d << 1;
                }
                mask[a] = d;
                added += d;
                pre += d;
            }
            finished = 0;
            for (int a : nds[i+1].en){
                finished += mask[a];
            }
            for (int j=0;j<ks;++j) {
                if ((j & pre) == j) {
                    int t = 0;
                    if ((bitCount[j] & 1) == 1) {
                        t += nds[i + 1].start - nds[i].start;
                    }
                    if (i > 0) {
                        t += dp[i - 1][j - (j & added)];
                    }
                    dp[i][j - (j & finished)] = Math.max(dp[i][j - (j & finished)], t);
                }
            }
        }
        return dp[dp.length-2][0];
    }

    static class Node implements Comparable<Node>{
        int start;
        ArrayList<Integer> st;
        ArrayList<Integer> en;
        public Node(int a){
            start = a;
            st = new ArrayList<>(4);
            en = new ArrayList<>(4);
        }
        @Override
        public int compareTo(Node nd){
            return this.start - nd.start;
        }
    }
}
