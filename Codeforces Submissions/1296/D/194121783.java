//package com.company;//Read minute details if coming wrong for no idea questions


import java.math.BigInteger;
import java.util.*;
import java.io.*;


public  class Main {

    public static class Suffix implements Comparable<Suffix>
    {
        int index;
        int rank;
        int next;
        public Suffix(int ind, int r, int nr)
        {
            index = ind;
            rank = r;
            next = nr;
        }
        public int compareTo(Suffix s)
        {
            if (rank != s.rank) return Integer.compare(rank, s.rank);
            return Integer.compare(next, s.next);
        }
    }
    public static int[] suffixArray(String s)
    {
        int n = s.length();
        Suffix[] su = new Suffix[n];
        for (int i = 0; i < n; i++)
        {
            su[i] = new Suffix(i, s.charAt(i) - '$', 0);
        }
        for (int i = 0; i < n; i++)
            su[i].next = (i + 1 < n ? su[i + 1].rank : -1);
        Arrays.sort(su);
        int[] ind = new int[n];
        for (int length = 4; length < 2 * n; length <<= 1)
        {
            int rank = 0, prev = su[0].rank;
            su[0].rank = rank;
            ind[su[0].index] = 0;
            for (int i = 1; i < n; i++)
            {
                if (su[i].rank == prev &&
                        su[i].next == su[i - 1].next)
                {
                    prev = su[i].rank;
                    su[i].rank = rank;
                }
                else
                {
                    prev = su[i].rank;
                    su[i].rank = ++rank;
                }
                ind[su[i].index] = i;
            }
            for (int i = 0; i < n; i++)
            {
                int nextP = su[i].index + length / 2;
                su[i].next = nextP < n ?
                        su[ind[nextP]].rank : -1;
            }
            Arrays.sort(su);
        }

        int[] suf = new int[n];

        for (int i = 0; i < n; i++)
            suf[i] = su[i].index;
        return suf;
    }




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
        public boolean equals(Object o) {
            if (o instanceof pair) {
                pair p = (pair) o;
                return p.a == a && p.b == b;
            }
            return false;
        }

        public int hashCode() {
            return (Long.valueOf(a).hashCode()) * 31 + (Long.valueOf(b).hashCode());
        }
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


    public static void buildtreemin( long a[], long tr[],int st , int end , int node,int yo,int x  )
    {

        if(st==end)
        { tr[node]=a[st];

            return ;}

        int mid =(st+end)/2;

        buildtreemin(a,tr,st,mid,2*node,1+yo,x);
        buildtreemin(a,tr,mid+1,end,2*node+1,1+yo,x);

      tr[node] = Math.min(tr[2 * node] ,tr[2 * node + 1]);

    }
    public static void buildtreemax( long a[], long tr[],int st , int end , int node,int yo,int x  )
    {

        if(st==end)
        { tr[node]=a[st];

            return ;}

        int mid =(st+end)/2;

        buildtreemax(a,tr,st,mid,2*node,1+yo,x);
        buildtreemax(a,tr,mid+1,end,2*node+1,1+yo,x);

        tr[node] = Math.max(tr[2 * node] ,tr[2 * node + 1]);

    }
    public  static  long qtreemin(long tr[],int node ,  int l , int r , int beg ,int end )
    {
        if(l>end||r<beg)
            return Integer.MAX_VALUE;
        if(l<=beg&&end<=r)
            return tr[node];
        int mid =(beg+end)/2;
        long op1 =qtreemin(tr,2*node,l,r,beg,mid);
        long op2 =qtreemin(tr,2*node+1,l,r,mid+1,end);
        return Math.min(op1,op2);
    }
    public  static  long qtreemax(long tr[],int node ,  int l , int r , int beg ,int end )
    {
        if(l>end||r<beg)
            return Integer.MIN_VALUE;
        if(l<=beg&&end<=r)
            return tr[node];
        int mid =(beg+end)/2;
        long op1 =qtreemax(tr,2*node,l,r,beg,mid);
        long op2 =qtreemax(tr,2*node+1,l,r,mid+1,end);
        return Math.max(op1,op2);
    }

    public static int sumof(long a)
    {
        String s =a+"";
        int x =0;
        for(int i =0;i<s.length();i++)
            x=x+(s.charAt(i)-'0');
        return x;

    }


    public static void upd(long a[],long tr[], int node ,int beg , int end , int idx, long val,int yo,int x)
    {

        if(beg==end)
        {
            a[beg]=sumof(a[beg]);
            tr[node]=sumof(a[beg]);
            return ;
        }
        int mid =(beg+end)/2;
        if(idx>mid)
        {
            upd(a,tr,2*node+1,mid+1,end,idx,val,1+yo,x);
        }
        else
        {
            upd(a,tr,2*node,beg,mid,idx,val,1+yo,x);
        }


        { tr[node] = (tr[2 * node] + tr[2 * node + 1]);

        }


    }

    public static int  upper_bound(long arr[], int key)
    {
        int mid, N = arr.length;
        int low = 0;
        int high = N;
        while (low < high && low != N) {
            mid = low + (high - low) / 2;
            if (key > arr[mid]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        if (low == N ) {
            return -1;
        }


        return low ;
    }
    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
//            int mx=1000000;
//            boolean isPrime[] = new boolean[mx+5]; int primeDiv[] = new int[mx+5];
//            for (int i = 0; i <= mx; i++) {
//                isPrime[i] = true;
//            }
//            for(int i =0;i<primeDiv.length;i++)
//                primeDiv[i]=i;
//            isPrime[0] = isPrime[1] = false;
//            for (long i = 2; i <= mx; i++) {
//                if (isPrime[(int)i]) {
//                    for (long j = i*i; j <= mx; j += i) {
//                        if (primeDiv[(int)j] == j) {
//                            primeDiv[(int)j] = (int)i;
//                        }
//                        isPrime[(int)j] = false;
//                    }
//                }
//            }
//
//            ArrayList<Integer>[] divisors = new ArrayList[(int) 1e5 + 5];
//            for (int i = 0; i < divisors.length; i++) {
//                divisors[i] = new ArrayList<>();
//            }
//            for (int i = 1; i < divisors.length; i++) {
//                for (int j = 1; j <= Math.sqrt(i); j++) {
//                    if (i % j == 0) {
//                        divisors[i].add(j);
//                        if (i / j != j)
//                            divisors[i].add(i / j);
//                    }
//                }
//            }
//            System.out.println(
//                    String.format("%.12f", x));


            int testCases=1;


            long mod =1000000007;



            // System.out.println(c);






            long fact[]=new long[300001];
            fact[0]=1;
            for(int i =1;i<fact.length;i++)
            {
                fact[i]=fact[i-1]*(long) i;
                fact[i]=fact[i]%998244353;

            }


            fl:
            while (testCases-- > 0) {

int n =in.nextInt();

long pa=in.nextLong();
long pb=in.nextLong();
long k =in.nextLong();
long a[]=new long[n];

for(int i =0;i<n;i++)
    a[i]=in.nextLong();




long pq[]=new long[n];


for(int i =0;i<n;i++)
{

    long curr =a[i];

    long yo =0;
    //System.out.println(curr%(pa+pb));

   long x =curr%(pa+pb);
   if(x==0)
       x+=pa+pb;

   yo=(x+pa-1)/pa-1;


 //   System.out.println();

  // System.out.println(yo);

    pq[i]=yo;




}

sort(pq);

long sum =0;
int ans =0;
for(long i :pq)
{
    sum+=i;
    if(sum>k)
    {
        System.out.println(ans);
        continue fl;
    }
    ans++;
}

                System.out.println(ans);




            }
            out.close();
        } catch (Exception e) {
            return;
        }
    }
//    ///DFS To calculate the number of child nodes and depth in tree kind of structure
//    public static int dfs(ArrayList<ArrayList<Integer>> adj, int s, int d, int child[], int depth[]) {
//        depth[s] = d;
//        for(int v: adj.get(s)) {
//            if(depth[v] == -1) {
//                child[s] += dfs(adj, v, d+1, child, depth);
//            }
//        }
//        return child[s]+1;
//    }

    public static int dfs(ArrayList<ArrayList<Integer>> adj , int node,int dp[],int vis[]) {

        int ans=1;
        vis[node]=-1;
        if(dp[node]!=-1)
           return ans;
        for(int i :adj.get(node)) {
            if(vis[i]==-1)
            {
                return Integer.MIN_VALUE;
            }
else
    ans = ans +dfs(adj, i, dp,vis);
        }
        return dp[node]= ans ;



    }












    public static void sortby(int arr[][])
    {
        Arrays.sort(arr, new Comparator<int[]>() {

            @Override
            // Compare values according to columns
            public int compare(final int[] entry1,
                               final int[] entry2) {

                // To sort in descending order revert
                // the '>' Operator
                if (entry1[1] >entry2[1])
                    return 1;
                else if(entry1[1]<entry2[1])
                    return -1;
                else if(entry1[2]>entry2[2])
                    return 1;
                else return -1;
            }
        });  // End of function call sort().
    }

    static long comb(int r, int n)
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