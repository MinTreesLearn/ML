// Problem: C. Primitive Primes
// Contest: Codeforces - CodeCraft-20 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1316/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

import java.io.*;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collections;
import java.io.InputStreamReader;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {


   
         


    public static void main(String[] args) throws IOException {

//        try {
//             Scanner in = new Scanner(System.in) ;
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);



        int n = in.nextInt() ;
        int m = in.nextInt() ;
        int p = in.nextInt() ;
        int a[] = in.readArray(n) ;
        int b[] = in.readArray(m) ;	

		int n1=0 , n2=0 ;
		for(int i=0 ; i<n ; i++){
			if(a[i]%p != 0){
				n1 = i ;
				break ;
			}
		}
		
		for(int i=0 ; i<m ; i++){
			if(b[i]%p != 0){
				n2 = i ;
				break ;
			}
		}
		
		 
		System.out.println(n1+n2) ;


















        out.flush();
        out.close();


//        } catch (Exception e) {
//            return;
//        }

    }

// solution END 
// template start :
    static long gcd(long a, long b) {return (b == 0) ? a : gcd(b, a % b);}
    static int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a % b);}

    static void sort(int ar[]) {
        int n = ar.length;
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++)ar[i] = a.get(i);
    }

    static void sort1(long ar[]) {
        int n = ar.length;
        ArrayList<Long> a = new ArrayList<>();
        for (int i = 0; i < n; i++)a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++)ar[i] = a.get(i);
    }

  
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try { st = new StringTokenizer(br.readLine());
                } catch (IOException e) {e.printStackTrace();}
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next());}

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {return Long.parseLong(next());}
    }

 
}
// template end






