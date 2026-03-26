import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.math.BigInteger;

import static java.lang.Math.max;

public class HelloWorld {

    public static void main(String[] args) throws IOException {
        Scanner input=new Scanner(System.in);
        //static FastReader input=new FastReader();
        //static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int t=input.nextInt();
        while(t>0) {
            int n,i,m,j,k,f;
            long count=0,a,b,x,y,s1,s2,s3,s4,s;
            a=input.nextInt();
            b=input.nextInt();
            x=input.nextInt();
            y=input.nextInt();
            x++;
            y++;
            //ArrayList<Long>ara= new ArrayList<>();
            //long ara[]=new long[i];
            //Collections.sort(ara1);
            s1=(x-1)*b;
            s2=a*(y-1);
            s3=(a-x)*b;
            s4=a*(b-y);
            s=max(s4,max(s3,max(s2,s1)));
            System.out.println(s);
            //System.out.println(s1+" "+s2+" "+s3+" "+s4);
            t--;
        }
        input.close();
        System.out.close();
    }


    /*static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        int[] readIntArray(int n)
        {
            int a[]=new int[n];
            for(int i=0;i<n;i++)a[i]=nextInt();
            return a;
        }

        long[] readLongArray(int n)
        {
            long a[]=new long[n];
            for(int i=0;i<n;i++)a[i]=nextLong();
            return a;
        }

        String nextLine()
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
    }*/
}