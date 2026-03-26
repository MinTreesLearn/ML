//package com.rajan.codeforces.level_1500;

import java.io.*;
import java.util.Arrays;

public class FightWithMonsters {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] temp = reader.readLine().split("\\s+");
        int n = Integer.parseInt(temp[0]), a = Integer.parseInt(temp[1]), b = Integer.parseInt(temp[2]), k = Integer.parseInt(temp[3]);
        temp = reader.readLine().split("\\s+");
        int[][] h = new int[n][2];
        for (int i = 0; i < n; i++) {
            int pow = Integer.parseInt(temp[i]);
            long leftForA = pow % (a + 0L + b);
            if (leftForA == 0)
                leftForA = a + 0L + b;
            if (leftForA <= a)
                h[i] = new int[]{pow, 0};
            else {
                int aTurnNeeded = (int) Math.ceil(leftForA / (a * 1.0));
                h[i] = new int[]{pow, aTurnNeeded - 1};
            }
        }
        Arrays.sort(h, (x, y) -> Integer.compare(x[1], y[1]));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (h[i][1] == 0) {
                ans++;
            } else {
                if (h[i][1] <= k) {
                    k -= h[i][1];
                    ans++;
                }
            }
        }
        writer.write(ans + "\n");
        writer.flush();
    }
}
