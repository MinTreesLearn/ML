//package com.rajan.codeforces.level_1400;

import java.io.*;
import java.util.Arrays;

public class JourneyPlanning {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(reader.readLine());
        int[] a = new int[n];
        String[] temp = reader.readLine().split("\\s+");
        int[][] d = new int[n][];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(temp[i]);
            d[i] = new int[]{a[i] - i, a[i]};
        }
        Arrays.sort(d, (x, y) -> Integer.compare(x[0], y[0]));
        long ans = 0L;
        for (int i = 0; i < n; ) {
            int t = d[i][0];
            int j = i;
            long sum = 0L;
            while (j < n && d[j][0] == d[i][0]) {
                sum += d[j][1];
                j++;
            }
            i = j;
            ans = Math.max(ans, sum);
        }
        writer.write(ans + "\n");
        writer.flush();
    }
}
