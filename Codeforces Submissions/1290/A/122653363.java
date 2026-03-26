import java.util.*;
import java.lang.*;
import java.io.*;

// Created by @thesupremeone on 16/07/21
public class MindControl {
    int getMin(int[] arr, int m){
        int min = Integer.MAX_VALUE;
        for (int x = 0; x <= m-1; x++) {
            int y = arr.length-(m-1-x)-1;
            min = Math.min(min, Math.max(arr[x], arr[y]));
        }
        return min;
    }
    void solve() throws IOException {
        int ts = getInt();
        for (int t = 1; t <= ts; t++){
            int n = getInt();
            int m = getInt();
            int k = getInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++){
                a[i] = getInt();
            }
            int max = Integer.MIN_VALUE;
            if(k<m-1){
                for (int x = 0; x <= k; x++) {
                    int y = k-x;
                    int[] arr = new int[n-k];
                    for (int i = x; i < n-y; i++)
                        arr[i-x] = a[i];
                    int min = getMin(arr, m-k);
                    max = Math.max(max, min);
                }
            }else {
                for (int i = 0; i < m; i++) {
                    max = Math.max(max, a[i]);
                    max = Math.max(max, a[n-1-i]);
                }
            }
            println(max);
        }
    }

    public static void main(String[] args) throws Exception {
        if (isOnlineJudge()) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            new MindControl().solve();
            out.flush();
        } else {
            localJudge = new Thread();
            in = new BufferedReader(new FileReader("input.txt"));
            out = new BufferedWriter(new FileWriter("output.txt"));
            localJudge.start();
            new MindControl().solve();
            out.flush();
            localJudge.suspend();
        }
    }
    static boolean isOnlineJudge(){
        try {
            return System.getProperty("ONLINE_JUDGE")!=null
                    || System.getProperty("LOCAL")==null;
        }catch (Exception e){
            return true;
        }
    }
    // Fast Input & Output
    static Thread localJudge = null;
    static BufferedReader in;
    static StringTokenizer st;
    static BufferedWriter out;
    static String getLine() throws IOException{
        return in.readLine();
    }
    static String getToken() throws IOException{
        if(st==null || !st.hasMoreTokens())
            st = new StringTokenizer(getLine());
        return st.nextToken();
    }
    static int getInt() throws IOException {
        return Integer.parseInt(getToken());
    }
    static long getLong() throws IOException {
        return Long.parseLong(getToken());
    }
    static void print(Object s) throws IOException{
        out.write(String.valueOf(s));
    }
    static void println(Object s) throws IOException{
        out.write(String.valueOf(s));
        out.newLine();
    }
}