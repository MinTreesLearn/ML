
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class f
{
    public static void print(String str,int val){
        System.out.println(str+"  "+val);
    }

    public long gcd(long a, long b) {
        if (b==0L) return a;
        return gcd(b,a%b);
    }

    public static void debug(long[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(int[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(arr[i]);
        }
    }

    public static void print(int[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(long[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
        public FastReader(String path) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(path));
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
    }


    public static void main(String[] args)
    {
        FastReader s=new FastReader();
//        int t = s.nextInt();
//        for(int tt=0;tt<t;tt++){
          int n = s.nextInt();
          int m = s.nextInt();
          int k = s.nextInt();
          solve(n,m,k) ;


    }

    static void print(ArrayList<String> list){
        System.out.println(list.size());
        for(String s:list){
            System.out.println(s);
        }
    }

    static void solve(long n,long m,long k){
        if(k>(4*n*m - 2*n-2*m)){
            System.out.println("NO");
            return ;
        }
        ArrayList<String> list =  new ArrayList<>();
        System.out.println("YES");
        for(int i=0;i<n-1;i++){
            if(k==0){
                print(list);
                return;
            }
            //frontwards
            if(k>=(m-1)){
                if((m-1)!=0)
                    list.add((m-1)+" R");
                k-=(m-1);
            }
            else {
                list.add(k+" R");
                print(list);
                return;
            }
            if(k==0){
                print(list);
                return;
            }
            //backwards
            if(k>=3*(m-1)){
                if((m-1)!=0)
                    list.add((m-1)+" DUL");
                k-=(3*(m-1));
            }
            else {
                long n_times = k/3;
                if(n_times!=0){
                    list.add(n_times+" DUL");
                }
                int rem = (int)(k%3);
                if(rem==1){
                    list.add(1+" D");
                }
                if(rem==2){
                    list.add(1+" DU");
                }
                print(list);
                return;
            }
            if(k==0){
                print(list);
                return;
            }
            if(k>=1){
                list.add(1+" D");
                k--;
            }
        }
        //now one down and (m-1) right
        if(k==0){
            print(list);
            return;
        }
        if(k>=(m-1)){
            if((m-1)!=0)
                list.add((m-1)+" R");
            k-=(m-1);
        }
        else {
            list.add((k)+" R");
            print(list);
            return;
        }
        if(k==0){
            print(list);
            return;
        }
        if(k>=(m-1)){
            if((m-1)!=0)
                list.add((m-1)+" L");
            k-=(m-1);
        }
        else {
            list.add((k)+" L");
            print(list);
            return;
        }
        if(k==0){
            print(list);
            return;
        }
        list.add(k+" U");
        print(list);
    }








//    OutputStream out = new BufferedOutputStream( System.out );
//        for(int i=1;i<n;i++){
//              out.write((arr[i]+" ").getBytes());
//         }
//        out.flush();
//  long start_time = System.currentTimeMillis();
//  long end_time = System.currentTimeMillis();
//  System.out.println((end_time - start_time) + "ms");



}
