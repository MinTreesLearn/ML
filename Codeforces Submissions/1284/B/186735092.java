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


            int t=sc.nextInt();
            long ans=0;
            ArrayList<Integer> small=new ArrayList<>();
            ArrayList<Integer> greatest=new ArrayList<>();
            int count=t;
            while(t-->0){
                int n=sc.nextInt();
                int [] arr=new int[n];
                //count=n;
                boolean issame=false;
                for(int i=0;i<n;i++){
                    arr[i]=sc.nextInt();
                    if(i>0 && arr[i]!=arr[i-1])issame=true;
                }
                if(n==1 || !issame){
                    small.add(arr[0]);
                    greatest.add(arr[0]);
                }else{
                    int min=arr[0];
                    int max=arr[0];
                    int ff=0;
                    boolean check=false;
                    int ss=0;
                    for(int i=1;i<n;i++){
                        if(arr[i]<=min ){
                            min=arr[i];
                            ff=i;
                        }
                        if(arr[i]>=max || arr[i]>min){
                            max=arr[i];
                            ss=i;
                        }
                        if(max>min && ss>ff){
                            check=true;
                            break;
                        }

                    }
                    if(check){
                        ans+=(count-1)*2L+1;
                        count--;
                    }else{
                        small.add(min);
                        greatest.add(max);
                    }
                }
            }
          //System.out.println(ans);
            Collections.sort(greatest);
int length=greatest.size();
            for(int  i=0;i<small.size();i++){
                int num=small.get(i);
                int ff=0;
                int ss=length-1;
                while(ff<=ss){
                    int mid=ff-(ff-ss)/2;

                    if(greatest.get(mid)>num){
                        ss=mid-1;
                    }else{
                        ff=mid+1;
                    }


                }
                ans+=length-ff;



            }
            System.out.println(ans);



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