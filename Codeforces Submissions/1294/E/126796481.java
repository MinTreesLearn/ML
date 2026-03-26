// package codeforce.Training1900;

import java.io.PrintWriter;
import java.util.*;

public class ObtainaPermutation {
    //    MUST SEE BEFORE SUBMISSION
//    check whether int part would overflow or not, especially when it is a * b!!!!
//    check if top down dp would cause overflow or not !!!!!!!!!!!!!!!!!!!!!!
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
        int n = in.nextInt(), m = in.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = in.nextInt();
            }
        }
        int ans = 0;

        for(int i = 1; i <= m; i++){
            Map<Integer, Integer> mp = new HashMap<>();
            for(int j = 0; j < n; j++){
                int v = i + j * m;
                mp.put(v, j);
            }
//            System.out.println(mp);
            int[] cnt = new int[n];
            for (int j = 0; j < n; j++) {
                if (!mp.containsKey(arr[j][i - 1])) continue;
                int pos = mp.get(arr[j][i - 1]);
                if (pos <= j){
                    cnt[j - pos]++;
                }else{
                    cnt[n - Math.abs(pos - j)]++;
                }
            }
//            System.out.println(Arrays.toString(cnt));
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                min = Math.min(min, n - cnt[j] + j);
            }
//            System.out.println(min);
            ans += min;
        }
        out.println(ans);
    }


    //      credits to SecondThread
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
