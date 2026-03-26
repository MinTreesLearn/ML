
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
    static int[] arr;
    public static void main(String[] args)
    {
        FastReader s=new FastReader();
        int n = s.nextInt();
        arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = s.nextInt();
        }
        dp=  new int[n+1][n+1][n+1][2];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    Arrays.fill(dp[i][j][k],-1);
                }
            }
        }
        int ans = recur(n,n/2,(n+1)/2,0);
        int ans1 = recur(n,n/2,(n+1)/2,1);
        System.out.println(Math.min(ans,ans1));
    }

    static int[][][][] dp;

    static int recur(int n,int even,int odd,int curr){

        if(n==0){
            if(even==0 && odd==0){
//                print(n+" "+even+" "+odd,curr);
//                print("return",0);
                return dp[0][0][0][0] = dp[0][0][0][1]= 0;
            }
            else {
//                print(n+" "+even+" "+odd,curr);
//                print("return",MAX_VALUE);
                return MAX_VALUE;
            }
        }
        else if(even<0 || odd<0){
//            print(n+" "+even+" "+odd,curr);
//            print("return",MAX_VALUE);
            return MAX_VALUE;
        }
        else if(even==0 && odd==0){
//            print(n+" "+even+" "+odd,curr);
//            print("return",MAX_VALUE);
            return MAX_VALUE;
        }
        else {
            if(arr[n-1]!=0){
                if(arr[n-1]%2!=curr){
//                    print(n+" "+even+" "+odd,curr);
//                    print("return",MAX_VALUE);
                    return dp[n][even][odd][curr] = MAX_VALUE;
                }
                else {
                    if(dp[n][even][odd][curr]!=-1){
//                        print(n+" "+even+" "+odd,curr);
//                        print("return",dp[n][even][odd][curr]);
                        return dp[n][even][odd][curr];
                    }
                    else {
                        if(curr==0){
                            int le = recur(n-1,even-1,odd,0);
                            int lo = 1+recur(n-1,even-1,odd,1);
//                            print(n+" "+even+" "+odd,curr);
//                            print("return "+le,lo);
                            return dp[n][even][odd][curr] = Math.min(le,lo);
                        }
                        else {
                            int lo = recur(n-1,even,odd-1,1);
                            int le = 1+recur(n-1,even,odd-1,0);
//                            print(n+" "+even+" "+odd,curr);
//                            print("return "+le,lo);
                            return dp[n][even][odd][curr] = Math.min(lo,le);
                        }
                    }
                }
            }
            else {
                if(dp[n][even][odd][curr]!=-1){
//                    print(n+" "+even+" "+odd,curr);
//                    print("return",dp[n][even][odd][curr]);
                    return dp[n][even][odd][curr];
                }
                else {
                    if(curr==0){
                        int le = recur(n-1,even-1,odd,0);
                        int lo = 1+recur(n-1,even-1,odd,1);
//                        print(n+" "+even+" "+odd,curr);
//                        print("return "+le,lo);
                        return dp[n][even][odd][curr] = Math.min(le,lo);
                    }
                    else {
                        int lo = recur(n-1,even,odd-1,1);
                        int le = 1+recur(n-1,even,odd-1,0);
//                        print(n+" "+even+" "+odd,curr);
//                        print("return "+le,lo);
                        return dp[n][even][odd][curr] = Math.min(lo,le);
                    }
                }
            }
        }
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
