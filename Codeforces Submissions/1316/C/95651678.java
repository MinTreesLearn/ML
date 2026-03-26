
//package cf;
import java.io.*;
import java.util.*;
public class Temp_Class {
    static int p=1000000007;

    public static void main(String[] args) throws Exception{
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(java.io.FileDescriptor.out), "ASCII"), 512);
        FastReader sc=new FastReader();
        int t=1;
        StringBuilder sb=new StringBuilder();
        while(t-- >0)
        {
            int n=sc.nextInt();
            int m=sc.nextInt();
            int p=sc.nextInt();
            int ar[]=new int[n];
            int br[]=new int[m];
            String inp1[]=sc.nextLine().split(" ");
            String inp2[]=sc.nextLine().split(" ");
            for(int i=0;i<n;i++)
            {
                ar[i]=Integer.parseInt(inp1[i]);
            }
            for(int i=0;i<m;i++)
            {
                br[i]=Integer.parseInt(inp2[i]);
            }
            int ans=0;
            for(int i=0;i<n;i++)
            {
                if(ar[i]%p!=0)
                {
                    ans+=i;
                    break;
                }
            }
            for(int i=0;i<m;i++)
            {
                if(br[i]%p!=0)
                {
                    ans+=i;
                    break;
                }
            }
            System.out.println(ans);
        }
        //bwbwwbwbw*bwbwwbwbw
       // System.out.println(sb.toString());
        out.flush();
    }
    public static int binary_Search_upper(int ar[],int x)
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
