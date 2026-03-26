//package com.company;
import java.io.BufferedReader;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
//For submitting solution in KickStart change class name from C1 to Solution then submit it
//and for AtCoder class name should be Main


public class Solution{
    public static void sieve(int n,ArrayList<Integer>l) {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
                l.add(i);
            //System.out.print(i + " ");
        }
    }

    public static long check(long x)
    {

        // check for the set bits
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x ^ (x >> 1);

    }

    public static String sortString(String inputString)
    {
        // Converting input string to character array
        char tempArray[] = inputString.toCharArray();

        // Sorting temp array using
        Arrays.sort(tempArray);

        // Returning new sorted string
        return new String(tempArray);
    }
    public static int isSubstring(
            String s1, String s2)
    {
        int M = s1.length();
        int N = s2.length();

        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++)
                if (s2.charAt(i + j)
                        != s1.charAt(j))
                    break;

            if (j == M)
                return i;
        }

        return -1;
    }

    public static class DSU{

        // Declaring two arrays to hold
        // information about the parent and
        // rank of each node.
        private int parent[];
        private int rank[];

        // Constructor
        DSU(int n){

            // Defining size of the arrays.
            parent=new int[n];
            rank=new int[n];

            // Initializing their values
            // by is and 0s.
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                rank[i]=0;
            }
        }

        // Find function
        public int find(int node){

            // If the node is the parent of
            // itself then it is the leader
            // of the tree.
            if(node==parent[node]) return node;

            //Else, finding parent and also
            // compressing the paths.
            return parent[node]=find(parent[node]);
        }

        // Union function
        public void union(int u,int v){

            // Make u as a leader
            // of its tree.
            u=find(u);

            // Make v as a leader
            // of its tree.
            v=find(v);

            // If u and v are not equal,
            // because if they are equal then
            // it means they are already in
            // same tree and it does not make
            // sense to perform union operation.
            if(u!=v)
            {
                // Checking tree with
                // smaller depth/height.
                if(rank[u]<rank[v])
                {
                    int temp=u;
                    u=v;
                    v=temp;
                }
                // Attaching lower rank tree
                // to the higher one.
                parent[v]=u;

                // If now ranks are equal
                // increasing rank of u.
                if(rank[u]==rank[v])
                    rank[u]++;
            }
        }
    }

    public static class pair implements Comparable<pair>{
        int x;
        int y;
        pair(int x,int y){
            this.x=x;
            this.y=y;
        }
        @Override
        public int compareTo(pair o) {
            return this.y-o.y;
        }
        /* use when to compare two strings
        if(this.y.compareTo(o.y)<0){
                    return o.y.compareTo(this.y);
                }
                else{
                    return o.y.compareTo(this.y);
                }*/

    }

    static void printDivisors(int n,ArrayList<Integer>l,int check)
    {
        // Note that this loop runs till square root
        for (int i=2; i<=Math.sqrt(n); i++)
        {
            if (n%i==0) {
                // If divisors are equal, print only one
                if (n / i == i && i!=check) {
                    l.add(i);
                }
                else {
                        l.add(i);
                        l.add(n/i);
                }
            }
        }
    }

    static void printDivisors2(int n,ArrayList<Integer>l,int check)
    {
        // Note that this loop runs till square root
        for (int i=2; i<=Math.sqrt(n); i++)
        {
            if (n%i==0) {
                // If divisors are equal, print only one
                if (n / i == i && i!=check) {
                    l.add(i);
                }
                else {
                    if(check!=i) {
                        l.add(i);
                    }
                    else if(check!=n/i){
                        l.add(n/i);
                    }
                }
            }
        }
    }

    static long power(int x, int y, int p)
    {
        int res = 1; // Initialize result

        while (y > 0) {

            // If y is odd, multiply x with result
            if ((y & 1) != 0)
                res = res * x;

            // y must be even now
            y = y >> 1; // y = y/2
            x = x * x; // Change x to x^2
        }
        return res % p;
    }

    public static void main(String[] args) {
        FastScanner sc=new FastScanner();
        int t=sc.i();
        while(t-->0){
           int n=sc.i();
           ArrayList<Integer> l=new ArrayList<>();
           printDivisors(n,l,-1);
            //System.out.println(l);
           if(l.size()<=2){
               System.out.println("NO");
           }
           else{
               Collections.sort(l);
               int n1=l.get(0);
               l.clear();
               printDivisors2(n/n1,l,n1);
               //System.out.println(n1);
               Collections.sort(l);
               int n2=l.get(0);
               int n3=n/(n1*n2);
               //System.out.println(n1+" "+n2+" "+n3);
               if(n1==n3 || n2==n3 || n1==n2 || n!=n1*n2*n3 || n1<2 || n2<2 || n3<2){
                   System.out.println("NO");
               }
               else{
                   System.out.println("YES");
                   System.out.println(n1+" "+n2+" "+n3);
               }
           }
        }
    }
    static long gcd(long a,long b) {
        if(a==0) {
            return b;
        }
        return gcd(b%a,a);
    }
    static long lcm(long a, long b) {
        return (a*b)/gcd(a,b);
    }
    static boolean  isPrime(long n) {
        if(n <=1 )return false;
        if(n==2) return true;
        if(n%2==0) return false;
        for(int i=3;i<=Math.sqrt(n);i+=2)
            if(n%i==0) return false;
        return true;
    }
    private static int countDigits(int l) {
        if (l >= 1000000000) return 10;
        if (l >= 100000000) return 9;
        if (l >= 10000000) return 8;
        if (l >= 1000000) return 7;
        if (l >= 100000) return 6;
        if (l >= 10000) return 5;
        if (l >= 1000) return 4;
        if (l >= 100) return 3;
        if (l >= 10) return 2;
        return 1;
    }
    private static int countDigits(long l) {
        if (l >= 1000000000000000000L) return 19;
        if (l >= 100000000000000000L) return 18;
        if (l >= 10000000000000000L) return 17;
        if (l >= 1000000000000000L) return 16;
        if (l >= 100000000000000L) return 15;
        if (l >= 10000000000000L) return 14;
        if (l >= 1000000000000L) return 13;
        if (l >= 100000000000L) return 12;
        if (l >= 10000000000L) return 11;
        if (l >= 1000000000L) return 10;
        if (l >= 100000000L) return 9;
        if (l >= 10000000L) return 8;
        if (l >= 1000000L) return 7;
        if (l >= 100000L) return 6;
        if (l >= 10000L) return 5;
        if (l >= 1000L) return 4;
        if (l >= 100L) return 3;
        if (l >= 10L) return 2;
        return 1;
    }
    static boolean isPalindrome(String s,int start,int end) {
        int i = start, j = end;

        while (i < j) {

            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
}

class FastScanner {
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st=new StringTokenizer("");
    String n() {
        while (!st.hasMoreTokens())
            try {
                st=new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        return st.nextToken();
    }
    int[] ia(int n) {
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = i();
        return arr;
    }
    String[] sa(int n) {
        String[] arr = new String[n];
        for(int i=0;i<n;i++)
            arr[i] = n();
        return arr;
    }
    long[] la(int n) {
        long[] arr = new long[n];
        for(int i=0;i<n;i++)
            arr[i] = l();
        return arr;
    }
    String nl()
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

    int i() {
        return Integer.parseInt(n());
    }
    long l() {
        return Long.parseLong(n());
    }
}