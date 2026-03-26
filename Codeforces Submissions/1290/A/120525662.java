import java.util.*;
// import java.lang.*;
import java.io.*;

//           THIS TEMPLATE MADE BY AKSH BANSAL.

public class Solution {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    private static boolean[] isPrime;
    private static void primes(){
        int num = (int)1e6; // PRIMES FROM 1 TO NUM
        isPrime = new boolean[num];
     
        for (int i = 2; i< isPrime.length; i++) {
           isPrime[i] = true;
        }
        for (int i = 2; i< Math.sqrt(num); i++) {
           if(isPrime[i] == true) {
              for(int j = (i*i); j<num; j = j+i) {
                 isPrime[j] = false;
              }
           }
        }
    }
    static void sort(int a[]){
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=0;i<a.length;i++)
        arr.add(a[i]);
        Collections.sort(arr);
        for(int i=0;i<a.length;i++)
        a[i]=arr.get(i);
        
    }
    static void sort(long a[]){
        ArrayList<Long> arr=new ArrayList<>();
        for(int i=0;i<a.length;i++)
        arr.add(a[i]);
        Collections.sort(arr);
        for(int i=0;i<a.length;i++)
        a[i]=arr.get(i);
        
    }
    private static long gcd(long a, long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    private static long pow(long x,long y){
        if(y==0)return 1;
        long temp = pow(x, y/2);
        if(y%2==1){
            return x*temp*temp;
        }
        else{
            return temp*temp;
        }
    }
    // static ArrayList<Integer>[] adj;
    // static void getAdj(int n,int q, FastReader sc){
    //     adj = new ArrayList[n+1];
    //     for(int i=1;i<=n;i++){
    //         adj[i] = new ArrayList<>();
    //     }
    //     for(int i=0;i<q;i++){
    //         int a = sc.nextInt();
    //         int b = sc.nextInt();

    //         adj[a].add(b);
    //         adj[b].add(a);
    //     }
    // }
    static PrintWriter out;
    static FastReader sc ;
    public static void main(String[] args) throws IOException {
        sc = new FastReader();
        out = new PrintWriter(System.out);
        // primes();
        // ________________________________

        int t = sc.nextInt();
        StringBuilder output = new StringBuilder();

        while (t-- > 0) {
            int n= sc.nextInt();
            int m= sc.nextInt();
            int k= sc.nextInt();
            int[] arr =new int[n];
            for(int i=0;i<n;i++){
                arr[i] =sc.nextInt();
            }
            output.append(solver(arr, n, m, k)).append("\n");
        }

        out.println(output);
        // _______________________________

        // int n = sc.nextInt();
        // out.println(solver());
        // ________________________________
        out.flush();
    }

    public static int solver(int[]arr, int n, int m, int k) {
        if(k>=m-1){
            int max = 0;
            for(int i=0;i<m;i++){
                max = Math.max(max, arr[i]);
            }
            for(int i=n-1;i>=n-m;i--){
                max = Math.max(max, arr[i]);
            }
            return max;
        }
        else{
            int best = -1;
            for(int kk=0;kk<=k;kk++){
                int min =Integer.MAX_VALUE; 
                for(int i=0;i<m-k;i++){
                    // System.out.println(arr[kk+i]+"_"+kk+"_"+ (arr[n+1-k+kk-m+k+i]));

                    int temp = Math.max(arr[kk+i], arr[n-k+kk-m+k+i]);
                    min = Math.min(min, temp);
                    // System.out.println(kk+"__"+ min);
                }
                best = Math.max(best, min);
            }
            return best;
        }
    }
}