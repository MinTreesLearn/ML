/*-----------                                 ---------------*
                    Author : Ryan Ranaut
            __Hope is a big word, never lose it__
-------------                                 --------------*/

import java.io.*;
import java.util.*;

public class Codeforces2 {
    static PrintWriter out = new PrintWriter(System.out);
    static final int mod = 1_000_000_007;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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

        int[] readIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
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

    /*-------------------------------------------------------------------------*/
    //Try seeing general case
    public static void main(String[] args) {
        FastReader s = new FastReader();
        int t = s.nextInt();
        while(t-->0)
        {
            int n = s.nextInt();
            int[] a = s.readIntArray(n);
            find(n, a);
        }

        out.close();
    }
    public static void find(int n, int[] a)
    {
        int low = 0, high = (int)(1e9);
        int diff = Integer.MAX_VALUE, k = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int r1 = find1(mid, a);
            int r2 = find1(mid+1, a);
            if(r1<=r2)
            {
                diff = r1;
                k = mid;
                high = mid-1;
            }
            else
            {
                diff = r2;
                k = mid+1;
                low = mid+1;
            }
        }
        out.println(diff+" "+k);
    }

    public static int find1(int x, int[] a)
    {
        int[] b = a.clone();
        for(int i=0;i<a.length;i++)
            b[i] = b[i]==-1 ? x : b[i];
        int res = Integer.MIN_VALUE;
        for(int i=1;i<a.length;i++)
        {
            res = Math.max(res, Math.abs(b[i]-b[i-1]));
        }
        return res;
    }














    /*-----------------------------------End of the road--------------------------------------*/

    static class DSU {
        int[] parent;
        int[] ranks;
        int[] groupSize;
        int size;

        public DSU(int n) {
            size = n;
            parent = new int[n];//0 based
            ranks = new int[n];
            groupSize = new int[n];//Size of each component
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                ranks[i] = 1; groupSize[i] = 1;
            }
        }

        public int find(int x)//Path Compression
        {
            if (parent[x] == x)
                return x;
            else
                return parent[x] = find(parent[x]);
        }

        public void union(int x, int y)//Union by rank
        {
            int x_rep = find(x);
            int y_rep = find(y);
            if (x_rep == y_rep)
                return;

            if (ranks[x_rep] < ranks[y_rep])
            {
                parent[x_rep] = y_rep;
                groupSize[y_rep] += groupSize[x_rep];
            }
            else if (ranks[x_rep] > ranks[y_rep])
            {
                parent[y_rep] = x_rep;
                groupSize[x_rep] += groupSize[y_rep];
            }
            else {
                parent[y_rep] = x_rep;
                ranks[x_rep]++;
                groupSize[x_rep] += groupSize[y_rep];
            }

            size--;//Total connected components
        }
    }
    public static int gcd(int x,int y)
    {
        return y==0?x:gcd(y,x%y);
    }
    public static long gcd(long x,long y)
    {
        return y==0L?x:gcd(y,x%y);
    }

    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    public static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static long pow(long a,long b)
    {
        if(b==0L)
            return 1L;
        long tmp=1;
        while(b>1L)
        {
            if((b&1L)==1)
                tmp*=a;
            a*=a;
            b>>=1;
        }
        return (tmp*a);
    }

    public static long modPow(long a,long b,long mod)
    {
        if(b==0L)
            return 1L;
        long tmp=1;
        while(b>1L)
        {
            if((b&1L)==1L)
                tmp*=a;

            a*=a;
            a%=mod;
            tmp%=mod;
            b>>=1;
        }
        return (tmp*a)%mod;
    }

    static long mul(long a, long b) {
        return a*b%mod;
    }

    static long fact(int n) {
        long ans=1;
        for (int i=2; i<=n; i++) ans=mul(ans, i);
        return ans;
    }

    static long fastPow(long base, long exp) {
        if (exp==0) return 1;
        long half=fastPow(base, exp/2);
        if (exp%2==0) return mul(half, half);
        return mul(half, mul(half, base));
    }

    static void debug(int ...a)
    {
        for(int x: a)
            out.print(x+" ");
        out.println();
    }

    static void debug(long ...a)
    {
        for(long x: a)
            out.print(x+" ");
        out.println();
    }

    static void debugMatrix(int[][] a)
    {
        for(int[] x:a)
            out.println(Arrays.toString(x));
    }
    static void debugMatrix(long[][] a)
    {
        for(long[] x:a)
            out.println(Arrays.toString(x));
    }

    static void reverseArray(int[] a) {
        int n = a.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[n - i - 1];
        for (int i = 0; i < n; i++)
            a[i] = arr[i];
    }

    static void reverseArray(long[] a) {
        int n = a.length;
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[n - i - 1];
        for (int i = 0; i < n; i++)
            a[i] = arr[i];
    }

    static void sort(int[] a)
    {
        ArrayList<Integer> ls = new ArrayList<>();
        for(int x: a) ls.add(x);
        Collections.sort(ls);
        for(int i=0;i<a.length;i++)
            a[i] = ls.get(i);
    }

    static void sort(long[] a)
    {
        ArrayList<Long> ls = new ArrayList<>();
        for(long x: a) ls.add(x);
        Collections.sort(ls);
        for(int i=0;i<a.length;i++)
            a[i] = ls.get(i);
    }

    static class Pair{
        int x, y;
        Pair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
}
