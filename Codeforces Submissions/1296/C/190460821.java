
import java.awt.image.AreaAveragingScaleFilter;
import java.awt.image.MemoryImageSource;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.StringTokenizer;

public class cf799 {
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

    public static int fast(){
        FastReader sc = new FastReader();

        return sc.nextInt();
    }
    static int []   parent=new int[100001];
    static int [] rank=new int[100001];

    public static void makeSet(){
for(int i=0;i<parent.length;i++){
    parent[i]=i;
    rank[i]=0;
}
}


public static int findParent(int num){
        if(parent[num]==num)return num;
        return parent[num]=findParent(parent[num]);
}
public static void union(int a,int b){
        int ff=findParent(a);
        int ss=findParent(b);
        if(rank[ff]<rank[ss]){
            parent[ff]=ss;
        }
        else if(rank[ss]<rank[ff]){
            parent[ss]=ff;
        }

        else{
            parent[ff]=ss;
            rank[ss]++;
        }

}



    public static void main(String[] args) {
        try {
            FastReader sc = new FastReader();
            FastWriter out = new FastWriter();

int t=sc.nextInt();
while(t-->0){
    int n=sc.nextInt();
    String s=sc.next();
int st=0;
int en=0;
int min=Integer.MAX_VALUE;

    HashMap<ArrayKey, Integer> map=new HashMap<>();
    map.put(new ArrayKey(new int[]{0,0}),0);
    int ff=0;
    int ss=0;
    for(int i=0;i<n;i++){
        char ch=s.charAt(i);
        if(ch=='L')ff++;
        if(ch=='R')ff--;
        if(ch=='U')ss++;
        if(ch=='D')ss--;


        if(map.containsKey(new ArrayKey(new int[]{ff,ss}))){
            if(i-map.get(new ArrayKey(new int[]{ff,ss}))+1<min){
                min=i-map.get(new ArrayKey(new int[]{ff,ss}))+1;
st=map.get(new ArrayKey(new int[]{ff,ss}));
en=i;


            }
        }


map.put(new ArrayKey(new int[]{ff,ss}), i+1);

    }
    if(min==Integer.MAX_VALUE){
        System.out.println(-1);
    }else{
        System.out.println((st+1)+" "+(en+1));
    }


}

     }catch (Exception e) {
            return;
        }
    }
    public static int codeventure(int n , int [] dp){
        if(n==0){
            return 1;

        }
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=codeventure(n-1,dp)+codeventure(n-2,dp);
    }
    public  static void swap(int [] arr,int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    public static void dfs(ArrayList<Integer> temp , HashMap<Integer,Integer> map,ArrayList<ArrayList<Integer>> adjancy_list   ,int num){

temp.add(num);
map.put(num,1);


for(int child:adjancy_list.get(num)){
if(!map.containsKey(child))
    dfs(temp,map,adjancy_list,child);

}


    }


  public static long yup(long number,int [] arr){

        long ans=0;
        int n=arr.length;
        int running_sum=0;
        int ff=0;
        int ss=0;
        for(int i=0;i<n;i++){
            running_sum+=arr[i];

            if(running_sum==number){
                ans+=ss-ff;
                ff=i+1;
                running_sum=0;
            }
            else if(running_sum>number){
                return -1;
            }
            ss++;
        }
        if(running_sum==0)return ans;
        else return -1;




    }

    private static StringBuilder integerToBinary(int n) {

        StringBuilder sb=new StringBuilder();
        while(n>0){
            if((n&1)==1)sb.append('1');
            else sb.append('0');
            n=n>>1;
        }
        return sb.reverse();


    }




    static  boolean isPrime(int num)
    {
        if(num<=1)
        {

            return true;
        }
        for(int i=2;i*i<=num;i++)
        {
            if((num%i)==0)
                return  false;
        }
        return true;
    }
    public static long kadane(int [] arr,int i,int j){
        long ans=0;
        long max=0;
        for(int f=i;f<j;f++){
            max+=arr[f];
            if(max<0){
                max=0;
            }
            ans=Math.max(ans,max);
        }
        return ans;
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
    static   class ArrayKey {
        private int[] array;

        public ArrayKey(int[] array) {
            this.array = array;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            ArrayKey arrayKey = (ArrayKey) o;
            return Arrays.equals(array, arrayKey.array);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(array);
        }
    }

}