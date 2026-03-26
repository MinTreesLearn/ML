//package com.rajan.codeforces.level_1500;

import java.io.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class YetAnotherWalkingRobot {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tt = Integer.parseInt(reader.readLine());
        while (tt-- > 0) {
            int n = Integer.parseInt(reader.readLine());
            String s = reader.readLine();
            int[] ans = null;
            Map<List<Integer>, Integer> positionToIndex = new HashMap<>();
            int x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                List<Integer> pos = List.of(x, y);
                if (positionToIndex.containsKey(pos)) {
                    int lastIdx = positionToIndex.get(pos);
                    if (ans == null || (i - lastIdx) < (ans[1] - ans[0])) {
                        ans = new int[]{lastIdx, i};
                    }
                }
                positionToIndex.put(pos, i);
                if (s.charAt(i) == 'L') {
                    x--;
                } else if (s.charAt(i) == 'R')
                    x++;
                else if (s.charAt(i) == 'U')
                    y++;
                else
                    y--;
            }
            List<Integer> pos = List.of(x, y);
            if (positionToIndex.containsKey(pos)) {
                int lastIdx = positionToIndex.get(pos);
                if (ans == null || (n - lastIdx) < (ans[1] - ans[0])) {
                    ans = new int[]{lastIdx, n};
                }
            }

            if (ans == null)
                writer.write("-1\n");
            else
                writer.write(String.format("%d %d\n", ans[0] + 1, ans[1]));
        }
        writer.flush();
    }
}
