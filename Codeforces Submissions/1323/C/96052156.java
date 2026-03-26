
    //package cf;
    import java.io.*;
    import java.util.*;
    import java.util.jar.JarOutputStream;

    public class Temp_Class {
        static int p=1000000007;
        static int max=(int)1e5;
        static List<Integer> l1=new ArrayList<>();
        static boolean prime[]=new boolean[max];

        public static void main(String[] args) throws Exception{
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(java.io.FileDescriptor.out), "ASCII"), 512);
            FastReader sc=new FastReader();
            int t=1;
            StringBuilder sb2=new StringBuilder();
            //
            // 12654
            while(t-- >0)
            {
                int n=sc.nextInt();
                char []ar=sc.nextLine().toCharArray();

                int opening=0;
                int close=0;
                int ans=0;
                int c=0;
                ArrayDeque<Character> stk=new ArrayDeque<>();
                for(int i=0;i<n;i++)
                {

                    if(ar[i]=='(')
                    {
                    opening++;
                    }
                    else if(ar[i]==')')
                    {
                        if(opening>close)
                        {
                            opening--;
                            continue;
                        }
                        close++;

                    }
                    if(opening==close)
                    {
                        ans+=close*2;
                        opening=0;
                        close=0;
                    }
                }
                opening=0;
                close=0;
                for(int i=0;i<n;i++)
                {

                    if(ar[i]=='(')
                    {
                        opening++;
                    }
                    else if(ar[i]==')')
                    {
                    close++;
                    }
                }
                if(opening!=close)
                {
                    sb2.append(-1+"\n");
                }
                else
                {
                    sb2.append(ans+"\n");
                }
            }
            System.out.println(sb2.toString());
            out.flush();
        }

        static  int ht[]=new int[max];

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
        public static long gcd(long a,long b)
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
        public static void dfs(List<Integer> adj[],int u,int p)
        {
            ht[u]=ht[p]==1?2:1;
            for(int v:adj[u])
            {
                if(v!=p)
                {
                    dfs(adj,v,u);
                }
            }
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
                    l1.add(i);
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
        public static int binary_Search_upper(Long ar[],Long x)
        {
            int res=-1;
            int l=0;int r=ar.length-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(ar[mid]==x)
                {
                    res=mid;
                    l=mid+1;
                }
                else if(ar[mid]>x)
                {
                    res=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            return res;
        }
        public static int binary_Search_lower(int ar[],int x)
        {
            int res=-1;
            int l=0;int r=ar.length-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(ar[mid]==x)
                {
                    res=mid;
                    r=mid-1;
                }
                else if(ar[mid]>x)
                {
                    r=mid-1;
                }
                else
                {
                    res=mid;
                    l=mid+1;
                }
            }
            return res;
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
