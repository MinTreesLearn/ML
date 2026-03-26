// package codeforce.cf617;

import java.io.PrintWriter;
import java.util.*;

public class E2 {
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
        char[] cs = in.next().toCharArray();
        int[] dp = new int[26];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = cs[i] - 'a';
            int state = 0;
            for (int j = idx + 1; j < 26; j++) {
                state |= dp[j];
            }
            for (int j = 0; j < 26; j++) {
                if ((state | (1 << j)) != state){
                    ans.add(j + 1);
                    dp[idx] |= (1 << j);
                    break;
                }
            }
        }
        int st = 0;
        for (int i = 0; i < 26; i++) {
            st |= dp[i];
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if ((st | (1 << i)) == st){
                cnt++;
            }
        }
        out.println(cnt);
        for(int x : ans){
            out.print(x+" ");
        }
        out.println();
    }

    // Use this instead of Arrays.sort() on an array of ints. Arrays.sort() is n^2
    // worst case since it uses a version of quicksort. Although this would never
    // actually show up in the real world, in codeforces, people can hack, so
    // this is needed.
    static void ruffleSort(int[] a) {
        //ruffle
        int n=a.length;
        Random r=new Random();
        for (int i=0; i<a.length; i++) {
            int oi=r.nextInt(n), temp=a[i];
            a[i]=a[oi];
            a[oi]=temp;
        }

        //then sort
        Arrays.sort(a);
    }

}
