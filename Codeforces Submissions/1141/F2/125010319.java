// package codeforce.Training1900;

import java.io.PrintWriter;
import java.util.*;
//https://codeforces.com/problemset/problem/1141/F2

public class SameSumBlocks {
    //    MUST SEE BEFORE SUBMISSION
//    check whether int part would overflow or not, especially when it is a * b!!!!

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
//        int t = sc.nextInt();
        int t = 1;
        for (int i = 0; i < t; i++) {
            solve(sc, pw);
        }
        pw.close();
    }

    static void solve(Scanner in, PrintWriter out){
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        Map<Long, List<int[]>> mp = new HashMap<>();
        long[] pre = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + arr[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long sz = pre[j + 1] - pre[i];
                if (!mp.containsKey(sz)) mp.put(sz, new ArrayList<>());
                mp.get(sz).add(new int[]{i, j});
            }
        }
        int max = 0;
        List<int[]> ans = new ArrayList<>();
        for(List<int[]> ls : mp.values()){
            Collections.sort(ls, (a, b) -> {
                if (a[1] == b[1]) return b[0] - a[0];
                return a[1] - b[1];
            });
            List<int[]> tt = new ArrayList<>();
            int cnt = 0;
            int pr = -1;
            for (int i = 0; i < ls.size(); i++) {
                int[] get = ls.get(i);
                if (get[0] <= pr) continue;
                cnt++;
                tt.add(get);
                pr = get[1];
            }
            if (max < cnt){
                ans = tt;
                max = cnt;
            }
        }
        out.println(max);
        for(int[] v : ans){
            out.println((v[0] + 1) + " " + (v[1] + 1));
        }
    }
}
