import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collections;
import java.io.InputStreamReader;
import static java.lang.Math.*;
import static java.lang.System.*;
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collections;
import java.io.InputStreamReader;

public class Main {
 static int dp1[] ;
 static int dp2[] ;

    static void  solver(int curr, int parent, ArrayList<ArrayList<Integer>> list,int a[]){
        int temp= 0 ;
        for(int i : list.get(curr)){
            if (i == parent)continue;
            solver(i, curr, list, a) ;
            int tt = dp1[i];
            if (tt > 0)temp += tt ;
        }
        dp1[curr] = a[curr] + temp ;
    }

    static void solver2(int curr , int parent , ArrayList<ArrayList<Integer>> list , int a[]){

        if (parent != -1) {
            int val = dp1[parent] + dp2[parent];
            if (dp1[curr] >= 0) val -= dp1[curr];
            dp2[curr] = max(0, val);
        }

        for(int i : list.get(curr)){
            if (i == parent)continue;
            solver2(i,curr,list,a);
        }
    }

    public static void main(String[] args) throws IOException {

//        try {
        //Scanner in = new Scanner(System.in) ;
         FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder() ;

         int n = in.nextInt() ;
         int a[] = new int[n] ;
        for (int i = 0; i <n ; i++) {
            a[i] = in.nextInt() ;
            if (a[i] == 0)a[i] = -1 ;
        }
        dp1 = new int[n] ;
        dp2 = new int[n] ;

        ArrayList<ArrayList<Integer>> list = new ArrayList<>() ;
        for(int i=0 ; i<n ; i++)list.add(new ArrayList<>()) ;

        for (int i = 0; i <n-1 ; i++) {
            int src = in.nextInt()-1 ;
            int dest = in.nextInt()-1 ;
            list.get(src).add(dest);
            list.get(dest).add(src);

        }

        solver(0, -1, list, a);
        solver2(0, -1, list, a);
        for (int i = 0; i <n ; i++) {
            sb.append((dp1[i]+dp2[i]) + " ") ;
        }

        System.out.print(sb);




        out.flush();
        out.close();


//        } catch (Exception e) {
//            System.out.println(e);
//            return;
//        }

    }

    static long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    static void sort(int ar[]) {
        int n = ar.length;
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++) ar[i] = a.get(i);
    }

    static void sort1(long ar[]) {
        int n = ar.length;
        ArrayList<Long> a = new ArrayList<>();
        for (int i = 0; i < n; i++) a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++) ar[i] = a.get(i);
    }

    static long ncr(long n, long r, long mod) {
        if (r == 0)
            return 1;
        long val = ncr(n - 1, r - 1, mod);
        val = (n * val) % mod;
        val = (val * modInverse(r, mod)) % mod;
        return val;
    }

    static long fast_pow(long base, long n, long M) {
        if (n == 0)
            return 1;
        if (n == 1)
            return base % M;
        long halfn = fast_pow(base, n / 2, M);
        if (n % 2 == 0)
            return (halfn * halfn) % M;
        else
            return (((halfn * halfn) % M) * base) % M;
    }

    static long modInverse(long n, long M) {
        return fast_pow(n, M - 2, M);
    }


    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }


        long nextLong() {
            return Long.parseLong(next());
        }
    }

    static PrintWriter out = new PrintWriter(System.out);


}

