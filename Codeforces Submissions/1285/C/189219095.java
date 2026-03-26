import java.util.*;
import java.io.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


@SuppressWarnings("unchecked")
public class Main {
    public static PrintWriter pw = new PrintWriter(System.out);

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }


    public static int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    
    public static class Tree
    {
        Node root;
    }
    
    public static class Node
    {
        int v;
        ArrayList<Node> children;
        
        Node(int v, ArrayList<Node> children)
        {
            this.v = v;
            this.children = children;
        }
        
    }
    
    public static void dfs(int v , Set<Integer> ss)
    {
        
        ss.add(v);
        
        ans++;
        for(int x : graph[v])
        {
            if(!ss.contains(x))
            {
                dfs(x,ss);
            }
        }
        ss.remove(v);
    }
    
    public static void sieveOfEratosthenes(int n)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        boolean prime[] = new boolean[n+1];
        for(int i=0;i<=n;i++)
            prime[i] = true;
         
        for(int p = 2; p*p <=n; p++)
        {
            // If prime[p] is not changed, then it is a prime
            if(prime[p] == true)
            {
                // Update all multiples of p
                for(int i = p*p; i <= n; i += p)
                    prime[i] = false;
            }
        }
         
        // Print all prime numbers
        for(int i = 2; i <= n; i++)
        {
            if(prime[i] == true)
                System.out.print(i + " ");
        }
    }
    
    // dsu
    public static int find(int x)
    {
        
        if (parent[x] != x) {
            
            parent[x] = find(parent[x]);
        }
 
        return parent[x];
    }
    public static void union(int x, int y)
    {
        // Find representatives of two sets
        int xRoot = find(x), yRoot = find(y);
 
        // Elements are in the same set, no need
        // to unite anything.
        if (xRoot == yRoot)
            return;
 
        // If x's rank is less than y's rank
        if (rank[xRoot] < rank[yRoot])
 
        {// Then move x under y  so that depth
            // of tree remains less
            parent[xRoot] = yRoot;
            rank[yRoot] +=rank[xRoot];
            rank[xRoot]=1;
        }
 
        // Else if y's rank is less than x's rank
        else if (rank[yRoot] < rank[xRoot])
        {
            // Then move y under x so that depth of
            // tree remains less
            parent[yRoot] = xRoot;
            rank[xRoot] +=rank[yRoot];
            rank[yRoot]=1;
        }
 
        else // if ranks are the same
        {
            // Then move y under x (doesn't matter
            // which one goes where)
            parent[yRoot] = xRoot;
 
            // And increment the result tree's
            // rank by 1
            rank[xRoot] = rank[xRoot] + rank[yRoot];
            rank[yRoot]=1;
        }
    }
    
    public static void makegraph(int n , int m)
    {
        for(int a=0;a<n;a++)
        {
            graph[a] = new ArrayList<>();
        }
        
        for(int a=0;a<m;a++)
        {
            int v1 = scn.nextInt()-1;
            int v2 = scn.nextInt()-1;
            
            graph[v1].add(v2);
            graph[v2].add(v1);
        }
    }
    
    public static int[] arrInt()
    {
        int n = scn.nextInt();
        int [] arr = new int[n];
        for(int a=0;a<n;a++)
        {arr[a] = scn.nextInt();}
        return arr;
    }
    
    public static long[] arrLong()
    {
        int n = scn.nextInt();
        long [] arr = new long[n];
        for(int a=0;a<n;a++)
        {arr[a] = scn.nextLong();}
        return arr;
    }
    
    public static void display(int [] arr)
    {
        for(int i : arr)
        {pw.print(i+" ");}
        pw.println();
    }
    
    public static void display(long [] arr)
    {
        for(long i : arr)
        {pw.print(i+" ");}
        pw.println();
    }


    // ==================== MATHEMATICAL FUNCTIONS ===========================

    private static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    private static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    private static int mod_pow(long a, long b, long mod) {
        if (b == 0)
            return 1;
        int temp = mod_pow(a, b >> 1, mod);
        temp %= mod;
        temp = (int) ((1L * temp * temp) % mod);
        if ((b & 1) == 1)
            temp = (int) ((1L * temp * a) % mod);
        return temp;
    }

    private static long multiply(long a, long b,long mod) {
        return (((a % mod) * (b % mod)) % mod);
    }

    private static long divide(long a, long b,long mod) {
        return multiply(a, mod_pow(b, mod - 2, mod),mod);
    }

    private static boolean isPrime(long n) {
        for (long i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    public static long fact(long n)
    {
 
        return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
    }

public static long ncr(long n, long k)
    {
        long res = 1;
 
        // Since C(n, k) = C(n, n-k)
        if (k > n - k)
            k = n - k;
 
        // Calculate value of
        // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
        for (long i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
 
        return res;
    }

    private static List<Integer> factors(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; 1L * i * i <= n; i++)
            if (n % i == 0) {
                list.add(i);
                if (i != n / i)
                    list.add(n / i);
            }
        return list;
    }

    private static List<Long> factors(long n) {
        List<Long> list = new ArrayList<>();
        for (long i = 1; i * i <= n; i++)
            if (n % i == 0) {
                list.add(i);
                if (i != n / i)
                    list.add(n / i);
            }
        return list;
    }
    
    
    //public static ArrayList<ArrayList<Integer>> fans = new ArrayList<>();
    public static int [] parent = null;
    public static int [] rank = null;
    public static ArrayList<Integer>[] graph = null;
    public static int ans = 0;
    public static FastReader scn = new FastReader();
    public static long c = 1000000007;
    public static long mod = 1000000007;
    
    
    public static void main(String[] args)
    {
        int t = 1;
        z:for(int w=1;w<=t;w++)
        {
            
            long n = scn.nextLong();
            long ans=0;
            for(long a=1;a*a<=n;a++)
            {
                if(n%a==0 && lcm(a,n/a)==n)
                {
                    ans = a;
                }
            }
            pw.println(ans+" "+n/ans);

            
        }
        
        
        pw.close();
    }
    
    
}