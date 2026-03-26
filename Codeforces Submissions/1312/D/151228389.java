import java.io.*;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.*;
import java.util.Scanner;
import java.util.StringTokenizer;




public class copy {

    static int log=18;
    static int[][] ancestor;
    static int[] depth;

    static void sieveOfEratosthenes(int n, ArrayList<Integer> arr) {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a
            // prime
            if (prime[p]) {

                // Update all multiples of p
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        // Print all prime numbers

        for (int i = 2; i <= n; i++) {
            if (prime[i]) {

                arr.add(i);


            }

        }

    }



    public static long fac(long N, long mod) {
        if (N == 0)
            return 1;
        if(N==1)
            return 1;
        return ((N % mod) * (fac(N - 1, mod) % mod)) % mod;
    }


    static long power(long x, long y, long p) {

        // Initialize result
        long res = 1;

        // Update x if it is more than or
        // equal to p
        x = x % p;

        while (y > 0) {

            // If y is odd, multiply x
            // with result
            if (y % 2 == 1)
                res = (res * x) % p;

            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }

        return res;
    }

    // Returns n^(-1) mod p
    static long modInverse(long n, long p) {
        return power(n, p - 2, p);
    }

    // Returns nCr % p using Fermat's
    // little theorem.
    static long nCrModPFermat(long n, long r,
                              long p) {

        if (n < r)
            return 0;
        // Base case
        if (r == 0)
            return 1;

        return ((fac(n, p) % p * (modInverse(fac(r, p), p)
                % p)) % p * (modInverse(fac(n - r, p), p)
                % p)) % p;
    }



    public static int find(int[] parent, int x) {
        if (parent[x] == x)
            return x;
        return find(parent, parent[x]);
    }

    public static void merge(int[] parent, int[] rank, int x, int y,int[] child) {
        int x1 = find(parent, x);
        int y1 = find(parent, y);

        if (rank[x1] > rank[y1]) {
            parent[y1] = x1;
            child[x1]+=child[y1];


        } else if (rank[y1] > rank[x1]) {
            parent[x1] = y1;
            child[y1]+=child[x1];

        } else {
            parent[y1] = x1;
            child[x1]+=child[y1];
            rank[x1]++;

        }


    }


    public static long gcd(long a, long b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }



    static int power(int x, int y, int p)
    {

        int res = 1;
        x = x % p;

        while (y > 0) {

            if (y % 2 == 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }

        return res;
    }

    // Returns n^(-1) mod p
    static int modInverse(int n, int p)
    {
        return power(n, p - 2, p);
    }

    // Returns nCr % p using Fermat's
    // little theorem.
    static int nCrModPFermat(int n, int r,
                             int p)
    {

        if (n<r)
            return 0;
        // Base case
        if (r == 0)
            return 1;

        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r
        int[] fac = new int[n + 1];
        fac[0] = 1;

        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;

        return (fac[n] * modInverse(fac[r], p)
                % p * modInverse(fac[n - r], p)
                % p)
                % p;
    }



    public static long[][] ncr(int n,int r)
    {
        long[][] dp=new long[n+1][r+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                if(j>i)
                    continue;
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }

        return dp;

    }


    public static boolean prime(long N)
    {
        int c=0;
        for(int i=2;i*i<=N;i++)
        {
            if(N%i==0)
                ++c;
        }

        return c==0;
    }


    public static int sparse_ancestor_table(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[] child)
    {

        int c=0;
        for(int i:arr.get(x))
        {
            if(i!=parent)
            {
//                System.out.println(i+" hello "+x);
                depth[i]=depth[x]+1;

                ancestor[i][0]=x;
//                if(i==2)
//                    System.out.println(parent+" hello");
                for(int j=1;j<log;j++)
                    ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
                c+=sparse_ancestor_table(arr,i,x,child);
            }
        }

        child[x]=1+c;
        return child[x];


    }


    public static int lca(int x,int y)
    {
        if(depth[x]<depth[y])
        {
            int temp=x;
            x=y;
            y=temp;
        }

        x=get_kth_ancestor(depth[x]-depth[y],x);
        if(x==y)
            return x;
//        System.out.println(x+" "+y);
        for(int i=log-1;i>=0;i--)
        {
            if(ancestor[x][i]!=ancestor[y][i])
            {
                x=ancestor[x][i];
                y=ancestor[y][i];
            }
        }

        return ancestor[x][0];

    }

    public static int get_kth_ancestor(int K,int x)
    {

        if(K==0)
            return x;
        int node=x;
        for(int i=0;i<log;i++)
        {
            if(K%2!=0)
            {
                node=ancestor[node][i];
            }
            K/=2;
        }

        return node;
    }

    public static ArrayList<Integer> primeFactors(int n)
    {
        // Print the number of 2s that divide n
        ArrayList<Integer> factors=new ArrayList<>();
        if(n%2==0)
            factors.add(2);
        while (n%2==0)
        {

            n /= 2;
        }

        // n must be odd at this point. So we can
        // skip one element (Note i = i +2)
        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            // While i divides n, print i and divide n
            if(n%i==0)
                factors.add(i);
            while (n%i == 0)
            {

                n /= i;
            }
        }

        // This condition is to handle the case when
        // n is a prime number greater than 2
        if (n > 2)
        {
            factors.add(n);

        }

        return factors;
    }

    static long ans=1,mod=1000000007;
    public static void recur(long X,long N,int index,ArrayList<Integer> temp)
    {
//        System.out.println(X);
        if(index==temp.size())
        {

            System.out.println(X);

            ans=((ans%mod)*(X%mod))%mod;
            return;
        }
        for(int i=0;i<=60;i++)
        {

            if(X*Math.pow(temp.get(index),i)<=N)
                recur(X*(long)Math.pow(temp.get(index),i),N,index+1,temp);
            else
            break;

        }





    }

    public static int upper(ArrayList<Integer> temp,int X)
    {
        int l=0,r=temp.size()-1;


        while(l<=r)
        {
            int mid=(l+r)/2;
            if(temp.get(mid)==X)
                return mid;
//            System.out.println(mid+" "+temp.get(mid));
            if(temp.get(mid)<X)
                l=mid+1;
            else
            {
                if(mid-1>=0 && temp.get(mid-1)>=X)
                    r=mid-1;
                else
                    return mid;
            }
        }

        return -1;
    }


    public static int lower(ArrayList<Integer> temp,int X)
    {
        int l=0,r=temp.size()-1;


        while(l<=r)
        {
            int mid=(l+r)/2;
            if(temp.get(mid)==X)
                return mid;
//            System.out.println(mid+" "+temp.get(mid));
            if(temp.get(mid)>X)
                r=mid-1;
            else
            {
                if(mid+1<temp.size() && temp.get(mid+1)<=X)
                    l=mid+1;
                else
                    return mid;
            }
        }

        return -1;
    }

    public static int[] check(String shelf,int[][] queries)
    {
        int[] arr=new int[queries.length];
        ArrayList<Integer> indices=new ArrayList<>();
        for(int i=0;i<shelf.length();i++)
        {
            char ch=shelf.charAt(i);
            if(ch=='|')
                indices.add(i);
        }

        for(int i=0;i<queries.length;i++)
        {
            int x=queries[i][0]-1;
            int y=queries[i][1]-1;
            int left=upper(indices,x);
            int right=lower(indices,y);

            if(left<=right && left!=-1 && right!=-1)
            {
                arr[i]=indices.get(right)-indices.get(left)+1-(right-left+1);
            }
            else
                arr[i]=0;

        }

        return arr;


    }




    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
//        int T=Reader.nextInt();
//        for(int m=1;m<=T;m++)
//        {
            int N=Reader.nextInt();

            int M=Reader.nextInt();
            if(N==2)
            output.write(0+"\n");
            else
        {
            long mod = 998244353;
            long ans = nCrModPFermat(M, N - 1, mod) % mod;
            ans = ((ans % mod) * ((N - 2) % mod)) % mod;
            ans = ((ans % mod) * ((power(2, N - 3, mod)) % mod)) % mod;
            output.write(ans + "");
        }












            output.flush();

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
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(
                    reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}






class TreeNode
{
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode(int data)
    {
        left=null;
        right=null;
        this.data=data;
    }
}


class div {
    long x;
    long y;


    div(long x,long y) {
        this.x = x;
        this.y=y;


    }
}



