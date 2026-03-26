////package com.company;
import com.sun.source.tree.ArrayAccessTree;

import javax.swing.*;
import java.beans.IntrospectionException;
import java.math.BigInteger;
import java.util.*;
import java.io.*;


public class Main {


    static class pair implements Comparable<pair> {
        long a = 0;
        long b = 0;
        // int cnt;

        pair(long b, long a) {
            this.a = b;
            this.b = a;
            // cnt = x;
        }

        @Override
        public int compareTo(pair o) {

            if(this.a != o.a)
                return (int) (this.a - o.a);
            else
                return (int) (this.b - o.b);
        }
//        public boolean equals(Object o) {
//            if (o instanceof pair) {
//                pair p = (pair) o;
//                return p.a == a && p.b == b;
//            }
//            return false;
//        }
//
//        public int hashCode() {
//            return (Long.valueOf(a).hashCode()) * 31 + (Long.valueOf(b).hashCode());
//        }
    }
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void prlong(Object object) throws IOException {

            bw.append("" + object);
        }

        public void prlongln(Object object) throws IOException {
            prlong(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    public static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }



    //HASHsET COLLISION AVOIDING CODE FOR STORING STRINGS

//    HashSet<Long> set = new HashSet<>();
//                for(int i = 0; i < s.length(); i++){
//        int b = 0;
//        long h = 1;
//        for(int j=i; j<s.length(); j++){
//            h = 131*h + (int)s.charAt(j);
//            b += bad[(int)(s.charAt(j)-'a')];
//            if(b<=k){
//                set.add(h);
//            }
//        }
//    }
//                System.out.println(set.size());



    //dsu
    static int[] par, rank;

    public static void dsu(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    static int find(int u) {
        return par[u] == -1 ? -1 : par[u] == u ? u : (par[u] = find(par[u]));
    }

    static void union(int u, int v) {
        int a = find(u), b = find(v);
        if (a != b && a != -1 && b != -1) {
            par[b] = a;
            rank[a] += rank[b];
        }
    }

    static void disunion(int u, int v) {
        int a = find(u), b = find(v);
        if (a != -1 && a == b) {
            par[a] = -1;
        }
    }












    static class Calc_nCr {
        private final long[] fact;
        private final long[] invfact;
        private final int p;

        Calc_nCr(int n, int prime) {
            fact = new long[n + 5];
            invfact = new long[n + 5];
            p = prime;

            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = (i * fact[i - 1]) % p;
            }

            invfact[n] = pow(fact[n], p - 2, p);
            for (int i = n - 1; i >= 0; i--) {
                invfact[i] = (invfact[i + 1] * (i + 1)) % p;
            }
        }

        private long nCr(int n, int r) {
            if (r > n || n < 0 || r < 0) return 0;
            return (((fact[n] * invfact[r]) % p) * invfact[n - r]) % p;
        }
        private static long pow(long a, long b, int mod) {
            long result = 1;
            while (b > 0) {
                if ((b & 1L) == 1) {
                    result = (result * a) % mod;
                }
                a = (a * a) % mod;
                b >>= 1;
            }

            return result;
        }
    }

    static void sort(long[] a ) {
        ArrayList<Long> l = new ArrayList<>();
        for(long i: a) {
            l.add(i);
        }
        Collections.sort(l);
        for(int i =0;i<a.length;++i) {
            a[i] = l.get(i);
        }
    }





    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
            int mx=10000000;
            boolean isPrime[] = new boolean[mx+5]; int primeDiv[] = new int[mx+5];
            for (int i = 0; i <= mx; i++) {
                isPrime[i] = true;
            }
            for(int i =0;i<primeDiv.length;i++)
                primeDiv[i]=i;
            isPrime[0] = isPrime[1] = false;
            for (long i = 2; i <= mx; i++) {
                if (isPrime[(int)i]) {
                    for (long j = i*i; j <= mx; j += i) {
                        if (primeDiv[(int)j] == j) {
                            primeDiv[(int)j] = (int)i;
                        }
                        isPrime[(int)j] = false;
                    }
                }
            }


//            System.out.println(
//                    String.format("%.12f", x));
            int testCases=in.nextInt();

//            int n =in.nextInt();
//            long  arr[]=new long[n];
//            ArrayList<Long>ans=new ArrayList<>();
//            for(int i =0;i<n;i++)
//
//
//            }       ans.add(in.nextLong());
//            Collections.sort(ans);
//            for(int i =0;i<n;i++)
//                arr[i]=ans.get(i);






            fl:
            while (testCases-- > 0) {



                int n =in.nextInt();
                long k =in.nextLong();
                long arr[]=new long[n];

                for(int i =0;i<n;i++)
                    arr[i]=in.nextLong();

                int c[]=new int[60];
int ans[][]=new int[n][60];
                for(int i =0;i<n;i++)
                {
                    int j=0;
                    if(arr[i]==0)
                        continue ;
                    while(arr[i]!=0) {
                        c[j]+=arr[i]%k;
//                        System.out.println(arr[i]);
if(arr[i]%k>1)
{
    System.out.println("NO");
    continue fl;
}
                        ++j;
                        if(arr[i]%k==1&&arr[i]!=1)
{
    ans[i][j]++;
}
                        arr[i]/=k;
                    }

                    ans[i][j]++;
                }
for(int j =0;j<60;j++)
{int sum =0;
    for(int i =0;i<n;i++)
    {
        sum+=(ans[i][j]);
    }
if(sum>1)
{
    System.out.println("NO");
     continue fl;
}
}
//                for(int i :c)
//                {
//                    if(i>1)
//                    {
//                        System.out.println("NO");
//                        continue fl;
//                    }
//                }
                System.out.println("YES");

            }
            out.close();
        } catch (Exception e) {
            return;
        }
    }


    static long comb(int r,int n)
    {
        long result;

        result = factorial(n)/(factorial(r)*factorial(n-r));

        return result;

    }



    static long factorial(int n) {
        int c;
        long result = 1;

        for (c = 1; c <= n; c++)
            result = result*c;

        return result;
    }

    static void  LongestPalindromicPrefix(String str,int lps[]){

//        String temp = str + '/';
//        str = reverse(str);
//        temp += str;
        String temp =str;
        int n = temp.length();


        for(int i = 1; i < n; i++)
        {
            int len = lps[i - 1];
            while (len > 0 && temp.charAt(len) !=
                    temp.charAt(i))
            {
                len = lps[len - 1];
            }
            if (temp.charAt(i) == temp.charAt(len))
            {
                len++;
            }
            lps[i] = len;
        }

//        return temp.substring(0, lps[n - 1]);
    }

    static String reverse(String input)
    {
        char[] a = input.toCharArray();
        int l, r = a.length - 1;

        for(l = 0; l < r; l++, r--)
        {
            char temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
        return String.valueOf(a);
    }
}




/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *   ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　┃      JACKS PET FROM ANOTHER WORLD
 *　　　┃　　┃
 *　　　┃　 　 ┗━━━┓
 *　　　┃ 　　　　　　 ┣┓-------
 *　　  ┃ 　　　　　 　┏┛-------
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */

//RULES
//TAKE INPUT AS LONG IN CASE OF SUM OR MULITPLICATION OR CHECK THE CONTSRaint of the array
//Always use stringbuilder of out.println for strinof out.println for string or high level output


// IMPORTANT TRs1 TO USE BRUTE FORCE TECHNIQUE TO SOLVE THE PROs1 OTHER CERTAIN LIMIT IS GIVENIT IS GIVEN

//Read minute details if coming wrong for no idea questions