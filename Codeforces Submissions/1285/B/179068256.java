


import java.util.*;
import java.io.*;


public class Main{
    static  class pair{
        long x ;long y ;
        pair(long x ,long y )
        {
            this.x=x;
            this.y =y;
        }

    }
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
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
    public static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    //dsu
    static int[] parent,rank;
    public static void dsu(int n){
        parent = new int[n]; rank = new int[n];
        for(int i =0;i<n;i++){
            parent[i]=i; rank[i]=1;
        }
    }
    public static int find(int i){
        if(i==parent[i] ) return i;
        return parent[i]=find(parent[i]);
    }
    static int f(int arr[],int i )
    {
        if(i==arr[i])
            return i ;
        return arr[i]=f(arr,arr[i]);

    }
    public static void merge(int i, int j){
        i=find(i);
        j=find(j);
        if(rank[i]>=rank[j]){
            rank[i]+=rank[j];
            parent[j]=i;
        }
        else {
            rank[j]+=rank[i];
            parent[i]=j;
        }
    }









    public static int help(boolean[] v){
        HashSet<Integer> s = new HashSet<>();
        for(int e=1;e<v.length;e++){
            int i=find(e);
            if(v[i]) s.add(i);
        }
        //    System.out.print(Arrays.toString(parent));
        return s.size();
    }


    static int  help(int[][] arr, int i, int n, int[] heigh) {
        if(arr[i][0]==-1&&arr[i][1]==-1)
            return 0;
        if(arr[i][0]==-1)
        {
            return heigh[arr[i][1]]-1;

        }
        else if(arr[i][1]==-1)
            return heigh[arr[i][0]]-1;
        else
        {

            int op1 =heigh[arr[i][1]]-1+help(arr, arr[i][0], n, heigh);
            int op2 =heigh[arr[i][0]]-1+help(arr, arr[i][1], n, heigh);

            return Math.max(op1,op2);

        }



    }

    static int heights(int arr[][], int i , int heig[])
    {
        if(arr[i][0]==-1&&arr[i][1]==-1)
            return 0;
        if(heig[i]!=-1)
            return heig[i];
        if(arr[i][0]==-1)
            return heig[i]=1+heights(arr,arr[i][1],heig);
        if(arr[i][1]==-1)
            return  heig[i]=1+heights(arr,arr[i][0],heig);
        else return heig[i]= 1+heights(arr,arr[i][1],heig)+heights(arr,arr[i][0],heig);

    }

    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();

            long testCases =in.nextLong();

            fl:
            while (testCases-- > 0) {

long n =in.nextLong();
long arr[]=new long[(int) n];
long sum =0;
for(int i =0;i<n;i++) {
    arr[i] = in.nextLong();
    sum=sum+arr[i];
}long curr=0;
long max =0;

for(int i =1;i<n;i++)
{
    curr=curr+arr[i];
    if(curr<0)
        curr=0;
    max=Math.max(curr,max);



}curr=0;
                for(int i =0;i<n-1;i++)
                {
                    curr=curr+arr[i];
                    if(curr<0)
                        curr=0;
                    max=Math.max(curr,max);



                }

if(max<sum)
                System.out.println("Yes");
else
    System.out.println("No");





            }

            out.close();
        } catch (Exception e) {
            return;
        }
    }









}