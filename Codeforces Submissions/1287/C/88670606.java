
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class c
{
    public static void print(String str,long val){
        System.out.println(str+"  "+val);
    }

    public long gcd(long a, long b) {
        if (b==0L) return a;
        return gcd(b,a%b);
    }

    public static void debug(long[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(int[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(arr[i]);
        }
    }

    public static void print(int[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }

    public static void print(Object[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(long[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
        public FastReader(String path) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(path));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int MAX_VALUE = (int)(1e5);
    public static void main(String[] args)
    {
        FastReader s=new FastReader();
        int n = s.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = s.nextInt();
        }
        int[][][] dp = new int[n+1][n+1][2];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                Arrays.fill(dp[i][j],MAX_VALUE);
            }
        }
        dp[0][0][0] =0;
        dp[0][0][1] =0;
        int idx =(n+1)/2;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(arr[i-1]==0){
                    dp[i][j][0] = Math.min(dp[i-1][j][0],1+dp[i-1][j][1]);
                    if(j>=1){
                        dp[i][j][1] = Math.min(dp[i-1][j-1][1],dp[i-1][j-1][0]+1);
                    }
                }
                else {
                    int mod = (arr[i-1]%2);
                    if(mod==0){
                        dp[i][j][0] = Math.min(dp[i-1][j][0],1+dp[i-1][j][1]);
                        dp[i][j][1] = MAX_VALUE;
                    }
                    else {
                        if(j>=1){
                            dp[i][j][1] = Math.min(dp[i-1][j-1][1],dp[i-1][j-1][0]+1);
                        }
                        dp[i][j][0] = MAX_VALUE;
                    }
                }
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                count++;
            }
        }
        System.out.println(Math.min(dp[n][idx][0],dp[n][idx][1]));
    }




//    OutputStream out = new BufferedOutputStream( System.out );
//        for(int i=1;i<n;i++){
//              out.write((arr[i]+" ").getBytes());
//         }
//        out.flush();
//  long start_time = System.currentTimeMillis();
//  long end_time = System.currentTimeMillis();
//  System.out.println((end_time - start_time) + "ms");



}
