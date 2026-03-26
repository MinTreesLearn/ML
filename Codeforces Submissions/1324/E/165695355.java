import javax.sound.midi.Soundbank;
import javax.swing.*;
import javax.swing.text.rtf.RTFEditorKit;
import java.awt.*;
import java.io.*;

import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.List;
import java.util.zip.InflaterInputStream;


public class Main {

    static int N = 100001;

    // Array to store inverse of 1 to N
    static long[] factorialNumInverse = new long[N + 1];

    // Array to precompute inverse of 1! to N!
    static long[] naturalNumInverse = new long[N + 1];

    // Array to store factorial of first N numbers
    static long[] fact = new long[N + 1];

    // Function to precompute inverse of numbers
    public static void InverseofNumber(int p)
    {
        naturalNumInverse[0] = naturalNumInverse[1] = 1;

        for(int i = 2; i <= N; i++)
            naturalNumInverse[i] = naturalNumInverse[p % i] * (long)(p - p / i) % p;
    }
    public static void InverseofFactorial(int p)
    {
        factorialNumInverse[0] = factorialNumInverse[1] = 1;

        // Precompute inverse of natural numbers
        for(int i = 2; i <= N; i++)
            factorialNumInverse[i] = (naturalNumInverse[i] *
                    factorialNumInverse[i - 1]) % p;
    }

    // Function to calculate factorial of 1 to N
    public static void factorial(int p)
    {
        fact[0] = 1;

        // Precompute factorials
        for(int i = 1; i <= N; i++)
        {
            fact[i] = (fact[i - 1] * (long)i) % p;
        }
    }

    public static long ncp(int N, int R, int p)
    {
        // n C r = n!*inverse(r!)*inverse((n-r)!)
        long ans = ((fact[N] * factorialNumInverse[R]) %
                p * factorialNumInverse[N - R]) % p;

        return ans;
    }

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = 1;
        while ( t > 0){
            int n = Reader.nextInt();
            int h = Reader.nextInt();
            int l = Reader.nextInt();
            int r = Reader.nextInt();
            int [] arr = new int[n];
            int i = 0;
            while ( i < n){
                arr[i] = Reader.nextInt();
                i++;
            }
            output.write(answer(arr,n,h,l,r)+"\n");
            t--;
        }
        output.flush();
    }

    private static int answer(int [] arr,int n,int h,int l,int r){
        int [][] dp = new int[n][h];
        boolean [][] dp2 = new boolean[n][h];
        int i = 0;
        int j = 0;
        while ( j < h){
            if ( j == arr[i] || (j == arr[i]-1)) {
                dp2[0][j] = true;
                if ( l <= j && j <= r){
                    dp[0][j] = 1;
                }
            }
            j++;
        }
        i = 1;
        while ( i < n){
            j = 0;
            while ( j < h){
                if ( dp2[i-1][j]){
                    int next = ( j + arr[i])%h;
                    int next2 = (j+(arr[i]-1))%h;
                    dp2[i][next] = true;
                    dp2[i][next2] = true;
                    if (  l <= next && r >= next){
                        dp[i][next] = (int)max(dp[i][next],1+dp[i-1][j]);
                    }
                    else{
                        dp[i][next] = (int)max(dp[i][next],dp[i-1][j]);
                    }
                    if ( l <= next2 && r >= next2){
                        dp[i][next2] = (int)max(dp[i][next2],1+dp[i-1][j]);
                    }
                    else{
                        dp[i][next2] = (int)max(dp[i][next2],dp[i-1][j]);
                    }
                }
                j++;
            }
            i++;
        }
        j = 0;
        int ans = 0;
        while ( j < h){
            if (dp[n-1][j] > ans){
                ans = dp[n-1][j];
            }
            j++;
        }
        return ans;
    }
    private static boolean knapsack01(ArrayList<Integer> arr,int size){
        boolean [][] dp = new boolean[arr.size()][size+1];
        int i  = 0;
        int j  = 0;
        while ( i <  arr.size() ){
            dp[i][0] = true;
            i++;
        }
        i = 0;
        while ( j <= size){
            if ( j == arr.get(0)){
                dp[0][j] = true;
            }
            j++;
        }
        i = 1;
        while ( i < arr.size()){
            j = 1;
            while ( j <= size){
                dp[i][j] = dp[i-1][j];
                if ( j >= arr.get(i)){
                    dp[i][j] = (dp[i][j] || dp[i-1][j-arr.get(i)]);
                }
                j++;
            }
            i++;
        }
        return dp[arr.size()-1][size];
    }

    public static void primeFactorisation(long n,HashMap<Long,Integer> map){
        long i = 2;
        while ( n%i == 0){
            if ( map.containsKey(i)){
                map.put(i,map.get(i)+1);
            }
            else{
                map.put(i,1);
            }
            n/=i;
        }
        i = 3;
        long last = (long)Math.pow(n,0.5);
        while ( i <= last){
            while ( n%i == 0){
                if ( map.containsKey(i)){
                    map.put(i,map.get(i)+1);
                }
                else{
                    map.put(i,1);
                }
                n/=i;
            }
            i++;
        }
        if ( n > 2){
            map.put(n,1);
        }
    }
    public  static  boolean prime(int n){
        int i = 2;
        int r = (int)Math.pow(n,0.5);
        boolean ans = true;
        while ( i<=r){
            if ( n%i == 0){
                ans = false;
                break;
            }
            i++;
        }
        return  ans;
    }
    public static long log2(long N)
    {
        long result = (long)(Math.log(N) / Math.log(2));
        return result;
    }
    private static int bs(int low,int high,int [] array,long find){
        if ( low <= high ){
            int  mid = low + (high-low)/2;
            if ( array[mid] > find){
                high = mid -1;
                return bs(low,high,array,find);
            }
            else if ( array[mid] < find){
                low = mid+1;
                return bs(low,high,array,find);
            }
            return mid;
        }
        return -1;
    }

    private static long max(long a, long b) {
        return  Math.max(a,b);
    }

    private static long min(long a,long b){
        return  Math.min(a,b);
    }

    public static long modularExponentiation(long a,long b,long mod){
        if ( b == 1){
            return a;
        }
        else{
            long ans = modularExponentiation(a,b/2,mod)%mod;
            if ( b%2 == 1){
                return (a*((ans*ans)%mod))%mod;
            }

            return ((ans*ans)%mod);
        }
    }

    public static long sum(long n){
        return  (n*(n+1))/2;
    }
    public static long abs(long a){
        return a < 0 ? (-1*a) : a;
    }
    public static long gcd(long a,long b){
        if ( a == 0){
            return b;
        }
        else{
            return gcd(b%a,a);
        }
    }


}



class DComparator implements Comparator<Integer>{
    @Override
    public int compare(Integer o1, Integer o2) {
        if ( o2 > o1){
            return 1;
        }
        else if ( o2 < o1){
            return -1;
        }
        else{
            return 0;
        }
    }
}

class NodeComparator implements Comparator<Node>{
    @Override
    public int compare(Node o1,Node o2){
        if ( o2.count < o1.count){
            return 1;
        }
        else{
            return -1;
        }
    }
}

class Node{
    int  value;
    int count;
    Node( int V,int C ){
        value = V;
        count = C;
    }

}

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;


    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {

            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    static long nextLong() throws IOException{
        return Long.parseLong(next());
    }
}

class SegTree{
    int [] min;
    int [] max;

    SegTree(int s){
        min  = new int[s];
        max  = new int[s];
    }

    public void build(int [] arr, int v,int l,int r){
        if ( l == r){
            min[v] = arr[l];
            max[v] = arr[r];
        }
        else{
            int mid = l +  (r-l)/2;
            build(arr,2*v+1,l,mid);
            build(arr,2*v+2,mid+1,r);
            min[v] = min[2*v+1];
            max[v] = max[2*v+1];
            if ( min[v]> min[2*v+2]){
                min[v] = min[2*v+2];
            }
            if ( max[v] < max[2*v+2]){
                max[v] = max[2*v+2];
            }
        }
    }

    public int findMin(int v,int l,int r,int x,int y){
        if ( x > r || y < l){
            return Integer.MAX_VALUE;
        }
        else if ( x <= l && r <= y){
            return min[v];
        }
        else{
            int mid = l + (r-l)/2;
            int a = findMin(2*v+1,l,mid,x,y);
            int b = findMin(2*v+2,mid+1,r,x,y);
            return a < b ? a: b;
        }
    }

    public int findMax(int v,int l,int r,int x,int y){
        if ( x > r || y < l){
            return Integer.MIN_VALUE;
        }
        else if ( x <= l && r <= y){
            return max[v];
        }
        else{
            int mid = l + (r-l)/2;
            int a = findMax(2*v+1,l,mid,x,y);
            int b = findMax(2*v+2,mid+1,r,x,y);
            return a < b ? b: a;
        }
    }


}