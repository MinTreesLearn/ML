//package com.company;


import java.beans.IntrospectionException;
import java.math.BigInteger;
import java.util.*;
import java.io.*;


public class Main {
    static class pair {
       String a;
        String b;

        pair(String x, String y) {
            this.a = x;
            this.b = y;
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


    //uppper bound code
//    int beg =0;
//    int end =n;
//                  while(beg<end)
//    {
//        int mid =(beg+end)/2;
//        if(max[mid]>lim)
//        {
//            end=mid;
//        }
//        else beg=mid+1;
//
//    }

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


    public static int help(boolean[] v) {
        HashSet<Integer> s = new HashSet<>();
        for (int e = 1; e < v.length; e++) {
            int i = find(e);
            if (v[i]) s.add(i);
        }
        //    System.out.print(Arrays.toString(parent));
        return s.size();
    }

    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();

            long testCases = 1;

            fl:
            while (testCases-- > 0) {

                String s =in.next();
                int n =s.length();
                int arr[]=new int[n];

                for(int i =0;i<n;i++)
                {
                    arr[i]=s.charAt(i)-'a';
                }
               long ans =0;


             long dp[][]=new long[30][30];
                long fr[]=new long[30];

                for(int i =0;i<n;i++)
                {
                    for(int j =0;j<26;j++)
                        dp[j][arr[i]]+=fr[j];
                    fr[arr[i]]++;



                }
                for(long i :fr)
                    ans =Math.max(ans,i);
                for(int i =0;i<26;i++)
                    for(int j =0;j<26;j++)
                        ans =Math.max(ans,dp[i][j]);



                System.out.println(ans);







            }



            out.close();
        } catch (Exception e) {
            return;
        }
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
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃      JACKS PET FROM ANOTHER WORLD
 *　　　┃　　　┃
 *　　　┃　 　 ┗━━━┓
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */

//RULES
//TAKE INPUT AS LONG IN CASE OF SUM OR MULITPLICATION OR CHECK THE CONTSRaint of the array
//Always use stringbuilder of out.println for strinof out.println for string or high level output


// IMPORTANT TRY TO USE BRUTE FORCE TECHNIQUE TO SOLVE THE PROY OTHER CERTAIN LIMIT IS GIVENIT IS GIVEN