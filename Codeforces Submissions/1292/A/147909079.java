//package com.rajan.codeforces.level_1400;

import java.io.*;
import java.util.*;

public class NekosMazeGame {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] temp = reader.readLine().split("\\s+");
        int n = Integer.parseInt(temp[0]), q = Integer.parseInt(temp[1]);
        boolean[][] grid = new boolean[2][n];
        for (int i = 0; i < 2; i++)
            Arrays.fill(grid[i], true);

        Map<List<Integer>, Set<List<Integer>>> blockMap = new HashMap<>();
        for (int i = 0; i < q; i++) {
            temp = reader.readLine().split("\\s+");
            int r = Integer.parseInt(temp[0]) - 1, c = Integer.parseInt(temp[1]) - 1;
            grid[r][c] = !grid[r][c];
            List<Integer> idx = List.of(r, c);
            if (grid[r][c]) {
                if (blockMap.containsKey(idx)) {
                    Set<List<Integer>> blockers = blockMap.get(idx);
                    for (List<Integer> item : blockers) {
                        if (blockMap.getOrDefault(item, new HashSet<>()).size() <= 1) {
                            blockMap.remove(item);
                        } else {
                            blockMap.get(item).remove(idx);
                        }
                    }
                }
                blockMap.remove(idx);
                if (blockMap.isEmpty())
                    writer.write("YES\n");
                else
                    writer.write("NO\n");
            } else {
                if (!grid[1 - r][c]) {
                    List<Integer> item = List.of(1 - r, c);
                    blockMap.putIfAbsent(item, new HashSet<>());
                    blockMap.get(item).add(idx);
                    blockMap.putIfAbsent(idx, new HashSet<>());
                    blockMap.get(idx).add(item);
                }
                if (c > 0 && !grid[1 - r][c - 1]) {
                    List<Integer> item = List.of(1 - r, c - 1);
                    blockMap.putIfAbsent(item, new HashSet<>());
                    blockMap.get(item).add(idx);
                    blockMap.putIfAbsent(idx, new HashSet<>());
                    blockMap.get(idx).add(item);
                }
                if (c < n - 1 && !grid[1 - r][1 + c]) {
                    List<Integer> item = List.of(1 - r, c + 1);
                    blockMap.putIfAbsent(item, new HashSet<>());
                    blockMap.get(item).add(idx);
                    blockMap.putIfAbsent(idx, new HashSet<>());
                    blockMap.get(idx).add(item);
                }
                if (blockMap.isEmpty())
                    writer.write("YES\n");
                else
                    writer.write("NO\n");
//                System.out.println(blockMap);
            }
//            for (int j = 0; j < 2 && i == 58; j++) {
//                System.out.println(Arrays.toString(grid[j]));
//                System.out.println(blockMap);
//            }
        }
        writer.flush();
    }
}
