// package Codeforce.cf615;

import java.io.PrintWriter;
import java.util.List;
import java.util.*;

public class F {
    //    MUST SEE BEFORE SUBMISSION
//    check whether int part would overflow or not, especially when it is a * b!!!!
//    check if top down dp would cause overflow or not !!!!!!!!!!!!!!!!!!!!!!
//    ------------consider only if you running into mistake--------
//    consider all the edge cases such as k > 0 or k >= 0
//    consider some edge case such as extreme situation
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
    static int[] maxLen = new int[]{-1, Integer.MIN_VALUE};
    static void solve(Scanner in, PrintWriter out){
        int n = in.nextInt();
        int[][] arr = new int[n - 1][2];
        for(int i = 0; i < n - 1; i++){
            arr[i] = new int[]{in.nextInt() - 1, in.nextInt() - 1};
        }
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for(int[] e : arr){
            if (!mp.containsKey(e[0])) mp.put(e[0], new ArrayList<>());
            if (!mp.containsKey(e[1])) mp.put(e[1], new ArrayList<>());
            mp.get(e[1]).add(e[0]);
            mp.get(e[0]).add(e[1]);
        }
        dfs1(mp, 0, -1, 0);
        int start = maxLen[0];
        maxLen = new int[]{-1, -1};
        dfs1(mp, start, -1, 0);
        int end = maxLen[0];
        int len = maxLen[1];
        LinkedList<Integer> q = new LinkedList<>();
        maxLen = new int[]{-1, -1};
        dfs2(mp, start, end, -1, q);
        Set<Integer> set = new HashSet<>(q);
        for(int v : q){
            if (v == start || v == end) continue;
            dfs3(mp, v, -1, set, 0);
        }
        int mx = len + maxLen[1];
        out.println(mx);
        out.println((start + 1) + " " + (end + 1) + " " + (maxLen[0] + 1));
    }
    static void dfs3(Map<Integer, List<Integer>> gra, int cur, int par, Set<Integer> set, int depth){
        if (maxLen[1] < depth){
            maxLen = new int[]{cur, depth};
        }
        for(int nxt : gra.get(cur)){
            if (nxt == par || set.contains(nxt)) continue;
            dfs3(gra, nxt, cur, set, depth + 1);
        }
    }

    static void dfs1(Map<Integer, List<Integer>> gra, int cur, int par, int depth){
        if (maxLen[1] < depth){
            maxLen = new int[]{cur, depth};
        }
        for(int nxt : gra.get(cur)){
            if (nxt == par) continue;
            dfs1(gra, nxt, cur, depth + 1);
        }
    }
    static boolean dfs2(Map<Integer, List<Integer>> gra, int cur, int tar, int par, LinkedList<Integer> q){
        if (cur == tar){
            q.add(tar);
            return true;
        }
        for(int nxt : gra.get(cur)){
            if (nxt == par){
                continue;
            }
            if (dfs2(gra, nxt, tar, cur, q)){
                q.add(cur);
                return true;
            }
        }
        return false;
    }

}
