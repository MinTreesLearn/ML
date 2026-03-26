import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
//https://codeforces.com/problemset/problem/1304/D

public class ShortestandLongestLIS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            solve(sc, pw);
        }
        pw.close();
    }

    static void solve(Scanner in, PrintWriter out){
        int n = in.nextInt();
        String s = in.next();
        char[] cs = s.toCharArray();
        int[] l1 = findMinLength(n, cs);
        int[] l2 = findMaxLength(n, cs);
        for(int x : l1){
            out.print(x+" ");
        }
        out.println();
        for(int x : l2){
            out.print(x+" ");
        }
        out.println();
    }

    static int[] findMinLength(int n, char[] cs){
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        for (int i = 0; i < n - 1; i++) {
            int j = i;
            while (j < cs.length && cs[j] == '<') j++;
            rev(i, j, arr);
            if (j > i) i = j - 1;
        }
        return arr;
    }

    static int[] findMaxLength(int n, char[] cs){
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int j = i;
            while (j < cs.length && cs[j] == '>') j++;
            rev(i, j, arr);
            if (j > i) i = j - 1;
        }
        return arr;
    }

    static void rev(int l, int r, int[] arr){
        while (l < r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;r--;
        }
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
