
import java.io.*;
import java.util.*;

public class ozontechD
{
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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

    //  long start = System.currentTimeMillis();
//  long end = System.currentTimeMillis();
//  System.out.println((end - start) + "ms");
    static FastReader io;


    public static void main(String[] args)
    {   io = new FastReader();
        int n = io.nextInt();
        ArrayList<Integer>[] adjL = new ArrayList[n+1];
        for(int i=0;i<=n;i++){
            adjL[i] = new ArrayList<>();
        }
        for(int i=0;i<n-1;i++){
            int u = io.nextInt();
            int v = io.nextInt();
            adjL[u].add(v);
            adjL[v].add(u);
        }
        //now add all leaves
        TreeSet<Integer> hs = new TreeSet<>();
        for(int i=1;i<=n;i++){
            if(adjL[i].size()==1){
                hs.add(i);
            }
        }
        while (hs.size()>=2){
            int u =hs.pollFirst();
            int v = hs.pollFirst();
            int lca = query(u,v);
            if(lca==u||lca==v){
                answer(lca);
            }
            else {
                for(int parent:adjL[u]){
                    adjL[parent].remove(Integer.valueOf(u));
                    if(adjL[parent].size()==1){
                        hs.add(parent);
                    }
                }
                for(int parent:adjL[v]){
                    adjL[parent].remove(Integer.valueOf(v));
                    if(adjL[parent].size()==1){
                        hs.add(parent);
                    }
                }
            }
        }
        answer(hs.pollFirst());

    }

    public static int query(int u,int v){
        System.out.println("? "+u+" "+v);System.out.flush();
        return (io.nextInt());
    }
    public static void answer(int u){
        System.out.println("! "+u);System.out.flush();
        System.exit(0);
    }

    public static void print(String str,int val){
        System.out.println(str+"  "+val);
    }

    public static void print(Object[] obj){
        for(Object a:obj){
            System.out.println(a);
        }
    }

    public static void print(Object[][] obj){
        for(Object[] a:obj){
            System.out.println(a);
        }
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


//    OutputStream out = new BufferedOutputStream( System.out );
//        for(int i=1;i<n;i++){
//    out.write((max_divisor[i]+" ").getBytes());
//}
//        out.flush();



}
