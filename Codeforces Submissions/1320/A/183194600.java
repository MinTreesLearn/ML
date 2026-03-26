import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class edu130 {
    //private static Object m;

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

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    public static boolean func(long x,long k){
        return (k-((x*x)+(x)+1))%(2*x)==0;
    }
    public static void gg(int [] arr, int l, int r, int count , int[] ans){
        if(r<l){
            return;
        }
        if(r==l){
            ans[l]=count;

            return;
        }
        int m=l;
        for(int i=l+1;i<=r;i++){
            if(arr[i]>arr[m]){
                m=i;
            }
        }
        ans[m]=count;
        gg(arr,l,m-1,count+1,ans);
        gg(arr,m+1,r,count+1,ans);



    }

    public static void main(String[] args) {
        //RSRRSRSSSR
        try {
            FastReader sc = new FastReader();
            FastWriter out = new FastWriter();



            int n=sc.nextInt();
         int [] arr=new int[n];
         HashMap<Integer,Long> map=new HashMap<>();
         for(int i=0;i<n;i++){
             arr[i]=sc.nextInt();
             map.put(i-arr[i],map.getOrDefault(i-arr[i],0L)+arr[i]);
         }
        long max=Long.MIN_VALUE;
         for(int keys:map.keySet()){
             max=Math.max(max,map.get(keys))
;         }
            System.out.println(max);









        }catch(Exception e){

            return;
        }

    }
    public static int gfg(int [] arr,int n,int index,int i,int [] dp){
        if(i>=n)return 0;
//        if(i==n-1){
//            if(index==-1)return arr[i];
//            if(arr[i]<=arr[index])return 0;
//            if(index-arr[index]!=i-arr[i])return 0;
//            return arr[i];
//        }

if(index!=-1)
        if(dp[i]!=-1 && index-arr[index]==i-arr[i] )return dp[i];
        int nottake= gfg(arr, n, index, i + 1, dp);
        int take=0;
        if(index==-1 || (arr[i]>arr[index]) && (index-arr[index]==i-arr[i])){
            take=arr[i]+gfg(arr,n,i,i+1,dp);
        }
        return dp[i]=Math.max(dp[i],Math.max(take,nottake));

    }





    private static void swap(int[] arr, int i, int ii) {
        int temp=arr[i];
        arr[i]=arr[ii];
        arr[ii]=temp;
    }

    public static int lcm(int a,int b){
        return (a/gcd(a,b))*b;
    }

    private static int gcd(int a, int b) {
        if(b==0)return a;
        return gcd(b,a%b);
    }

    static class Pair {
        int a;
        int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;

        }
    }
}