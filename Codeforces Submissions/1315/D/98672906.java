//package cf;
import java.io.*;
import java.util.*;

public class T_class {
    static int m=2147483647;///this is 2^32 -1 (is prime number) and should be used for hashing
    static int p=1000000007;
    static int max=(int)2e3+10;
    static boolean prime[]=new boolean[max+5];
    static  int dp[][]=new int[(int)max][max];
    static  List<Integer> total_prime=new ArrayList<>();
    public static class pr
    {
        int ai;
        int ti;
        pr(int a,int b)
        {
            ai=a;
            ti=b;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(FileDescriptor.out), "ASCII"), 512);
        FastReader sc=new FastReader();
        int t=1;
        StringBuilder sb2=new StringBuilder();

        while(t-- >0) {
            int n=sc.nextInt();
            List<pr> l1=new ArrayList<>();
            int ar[]=new int[n];
            int br[]=new int[n];
            for(int i=0;i<n;i++) {
            ar[i]=sc.nextInt();
            }
            for(int i=0;i<n;i++) {
                br[i]=sc.nextInt();
            }
            long s=0;
            for(int i=0;i<n;i++)
            {
                    pr cur = new pr(ar[i], br[i]);
                    l1.add(cur);
                //set.put(a,set.getOrDefault(a,0)+1);
            }
            Collections.sort(l1, new Comparator<pr>() {
                @Override
                public int compare(pr o1, pr o2) {
                    return o1.ai-o2.ai;
                }
            });/*
            for(pr i:l1)
            {
                System.out.println(i.ai+" "+i.ti);
            }*/
            PriorityQueue<pr> pq=new PriorityQueue<>(new Comparator<pr>() {
                @Override
                public int compare(pr o1, pr o2) {
                    return -(o1.ti-o2.ti);
                }
            });
            int i=0,nxt=l1.get(0).ai;
            while(i<n)
            {
                pr cur=l1.get(i);
                while(i<n&&l1.get(i).ai==cur.ai)
                {
                    pq.add(l1.get(i));
                    i++;
                }
                 nxt=cur.ai;
                while(i<n&&nxt!=l1.get(i).ai&&pq.isEmpty()==false)
                {
                    pr in_cur=pq.poll();
                  //  System.out.println(in_cur.ai+" "+nxt+" "+in_cur.ti);
                    s+=(nxt-in_cur.ai)*(1l)*(in_cur.ti);
                    nxt++;
                }
            }

            while(pq.isEmpty()==false)
            {
                pr in_cur=pq.poll();
                s+=(nxt-in_cur.ai)*(1l)*(in_cur.ti);
                nxt++;
            }
            sb2.append(s+"\n");
        }
        System.out.println(sb2.toString());
        out.flush();
    }
    public static long gethash(long pow[], long hash[], int l, int r) {

        return (hash[r+1] - (hash[l ] * pow[r - l +1]) % m + m) % m;
    }
    private static String long_pre(char[] ch) {
        int n=ch.length;
        char cpy[]=new char[n];
        for(int i=n-1;i>=0;i--)
        {
            cpy[n-1-i]=ch[i];
        }
        long pow[] = new long[n + 1];
        long hash[] = new long[n + 1];
        pow[0] = 1;
        int p = 31;
        for (int i = 1; i <= n; i++) {
            pow[i] = (pow[i - 1] % m * p % m) % m;
        }

        for (int i = 1; i <= n; i++) {
            hash[i] = (hash[i - 1] * p % m + (ch[i - 1]) % m) % m;
        }

        long pow1[] = new long[n + 1];
        long hash1[] = new long[n + 1];
        pow1[0] = 1;
        //int p = 31;
        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] % m * p % m) % m;
        }

        for (int i = 1; i <= n; i++) {
            hash1[i] = (hash1[i - 1] * p % m + (cpy[i - 1]) % m) % m;
        }


        int l=0,r=n-1,lst=0;
        for(int i=n-1;i>=1;i--)
        {
        int mid=i%2;
        int midp=i/2;
        if(mid==0&&gethash(pow,hash,0,midp-1)==gethash(pow1,hash1,n-1-i,n-1-(midp+1)))
        {
            lst=i;
            break;
        }
        else if(mid==1&&gethash(pow,hash,0,midp)==gethash(pow1,hash1,n-1-i,n-1-(midp+1)))
        {
            lst=i;
            break;
        }
        }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<=lst;i++)
        {
            sb.append(ch[i]);
        }
        return sb.toString();
    }

    private static int Solve(int n, int l, int r,int h, int i, int s, int[] ar) {
        if(i==n)
            return 0;
        if(dp[i][s]!=-1)
            return dp[i][s];

        int ans=Math.max(con((s+ar[i])%h,l,r)+Solve(n,l,r, h,i+1,(s+ar[i])%h,ar)
                ,con((s+ar[i]-1)%h,l,r)+Solve(n,l,r,h,i+1,(s+ar[i]-1+h)%h,ar));
        dp[i][s]=ans;
        return dp[i][s];
    }

    private static int con(int i,int l,int r) {
        if(l<=i&&i<=r)
            return 1;
        else
            return 0;
    }

    static  long childs[]=new long[max];
    static long tot=0;
    public static void dfs_val(List<Integer> adj[],int u,int p,long val) {
        int in_max=-1;
        val=val+childs[u]+1;
        for(int v:adj[u])
        {
            if(v!=p)
            {
                in_max=v;
                dfs_val(adj,v,p,val);
            }
        }
        if(in_max==-1)
        {
            tot=Math.max(tot,val);
        }
    }
    public static void dfs(List<Integer> adj[],int u,int p)
    {

        for(int v:adj[u])
        {
            if(v!=p)
            {
                childs[u]++;
                dfs(adj,v,u);
                childs[u]+=childs[v];
            }
        }
    }
    public static int ans(int ar[],int i,int n,int t)
    {
        if(i>=n)
            return 0;
        if(t>=410)
            return 200000;
        if(dp[i][t]!=-1)
            return dp[i][t];
        //System.out.println(t+" "+i);
        int cur=Math.min(Math.abs(ar[i]-t)+ans(ar,i+1,n,t+1),ans(ar,i,n,t+1));
        dp[i][t]=cur;
        return dp[i][t];
    }

    private static long ncr(int n, int r, long[] fact) {
        if(r>n||n < 0 || r < 0)
            return 0;

        if(n==1||n==0)
            return 1;
        // System.out.println(n+" c "+r);

        return (((fact[n]*pow_inverse(fact[n-r],p))%p)*pow_inverse(fact[r],p))%p;
    }
    static class BIT {
        long[] tree;
        public BIT(int size) {
            tree = new long[size + 1];
        }
        public long sum(int i) {
            long ans = 0;
            while (i > 0) {
                ans += tree[i];
                i -= i & -i;
            }
            return ans;
        }

        public long query(int i, int j) {
            return sum(j) - sum(i - 1);
        }

        public void add(int i, long val) {
            while (i < tree.length) {
                tree[i] += val;
                i += i & -i;
            }
        }

        public void set(int i, long val) {
            add(i, val - query(i, i));
        }
    }
    static class  vert implements Comparator<vert>
    {
        int v;
        TreeSet<Integer> set;

        public vert(int v, TreeSet<Integer> set) {
            this.v = v;
            this.set = set;
        }

        @Override
        public int compare(vert o1, vert o2) {
            return -(o1.set.size()-o2.set.size());
        }
    }
    public static long pow(long a,long b,long m)
    {
        long r=1;
        while(b!=1)
        {
            if(b%2!=0)
                r=(r*a)%m;
            b=b>>1;
            a=(a*a)%m;
        }
        return (r*a)%m;
    }
    public static long pow_inverse(long a,long m)
    {
        return pow(a,m-2,m);
    }public static long gcd(long a,long b)
    {
        if(b>a)
        {
            a=a^b;
            b=a^b;
            a=a^b;
        }
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    public static void extgcd(long a,long b)
    {/*
            if(a==0)
            {
                x=0;
                y=1;
                d=b;
                // return ;
            }
            else
            {

                extgcd(b%a,a);

                long t=y;
                y=x;
                x=t-(b/a)*x;
            }*/
    }

    public static void seive()
    {
        for(int i=0;i<max;i++)
            prime[i] = true;

        for(int p = 2; p*p <=max; p++)
        {
            // If prime[p] is not changed, then it is a prime
            if(prime[p] == true)
            {
                // Update all multiples of p
                for(int i = p*p; i <=max; i += p)
                    prime[i] = false;
            }
        }

        // Print all prime numbers
        for(int i = 2; i <= max; i++)
        {
            if(prime[i] == true)
            {
                total_prime.add(i);
            }
        }
    }
    public static boolean union(int a, int b, int p[], int r[]){
        // add your code here
        int pa=find(a,p,r);
        int pb=find(b,p,r);
        if(pa==pb)
            return true;
        if(pa!=pb)
        {
            if(r[pa]<r[pb])
            {
                p[pa]=pb;
            }
            else if(r[pa]>r[pb])
            {
                p[pb]=pa;
            }
            else
            {
                p[pa]=pb;
                r[pb]++;
            }
        }
        return false;
    }
    public static int find(int x,int p[],int r[])
    {
        if(p[x]==x)
            return x;
        p[x]=find(p[x],p,r);
        return p[x];
    }
    public static int binary_Search_upper(Integer[] ar, Integer x,int l,int r)
    {
        int res=-1,f=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(ar[mid]==x)
            {
                f=1;
                res=mid;
                l=mid+1;
            }
            else if(ar[mid]>x)
            {
                res=res!=-1&&ar[res]==x?res:mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return f==1?res:res+1;
    }
    public static int binary_Search_lower(int[] ar, long x, int l, int r)
    {
        int res=0,f=0;
        //int l=0;int r=ar.length-1;
        /*public static int binary(Long[] ar, int l, int r, long v)
        {
            int n=r;
            int m=(l+r)/2;
            int re=-1;
            while(l<=r)
            {
                if(ar[m]>=v)
                {

                    re=m;
                    r=m-1;
                }
                else if(ar[m]<v)
                {
                    l=m+1;
                }
                m=(l+r)/2;
            }
            if(l<=n&&ar[l]==v)
                return l;
            return re;
        }*/
        //   System.out.println(Arrays.toString(ar)+" "+x);
        while(l<=r)
        {
            int mid=(l+r)>>1;
            //   System.out.println(l+" "+r+" "+mid+" = "+ar[mid]);
            if(ar[mid]==x)
            {
                f=1;
                res=mid;
                r=mid-1;
            }
            else if(ar[mid]>x)
            {
                r=mid-1;
            }
            else
            {
                res=res!=0&&ar[res]==x?res:mid;
                l=mid+1;
            }
        }

        //  System.out.println(res);
        return f==1?res:res+1;
    } public static int binary_Search_lower_suf(int[] ar, int x,int l,int r)
    {
        int res=-1,f=0;
        //int l=0;int r=ar.length-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(ar[mid]==x)
            {
                f=1;
                res=mid;
                r=mid-1;
            }
            else if(ar[mid]<x)
            {
                r=mid-1;
            }
            else
            {
                //      res=mid;
                l=mid+1;
            }
        }
        return f==0?res+1:res;
    }
    int bit[]=new int[(int)1e6];
    public void update(int n,int val,int i)
    {
        i++;
        while(i<n)
        {
            bit[i]+=val;
            i+=(i)&(-i);
        }

    }
    public long query(int n,int i)
    {
        i++;
        long sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i)&(-i);
        }
        return sum;
    }


    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////
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


}