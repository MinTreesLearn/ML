import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
import java.io.*;
public class Main {
    // Graph
    // prefix sums
    //inputs
    public static void main(String args[])throws Exception{
        Input sc=new Input();
        precalculates p=new precalculates();
        StringBuilder sb=new StringBuilder();

            int d[]=sc.readArray();
            int n=d[0],m=d[1],pp=d[2];
            int a[]=sc.readArray();
            int b[]=sc.readArray();
            int x=0;
            int y=0;
            for(int i=0;i<n;i++){
                if(p.gcd(a[i],pp)==1){
                    x=i;
                    break;
                }
            }
            for(int i=0;i<m;i++){
                if(p.gcd(b[i],pp)==1){
                    y=i;
                    break;
                }
            }
            sb.append(x+y+"\n");

        System.out.print(sb);
    }
}
/*
1
qwerty
2
qwerty -> wqerty -> weqrty -> werqty -> wertqy -> wertyq
3
qwerty -> ewqrty -> erqwty -> ertwqy -> ertyqw
4
qwerty -> rewqty -> rtqwey -> rtyewq
5
qwerty -> trewqy -> tyqwer
 */
class Input{
    BufferedReader br;
    StringTokenizer st;
    Input(){
        br=new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer("");
    }
    public int[] readArray() throws Exception{
        st=new StringTokenizer(br.readLine());
        int a[]=new int[st.countTokens()];
        for(int i=0;i<a.length;i++){
            a[i]=Integer.parseInt(st.nextToken());
        }
        return a;
    }
    public long[] readArrayLong() throws Exception{
        st=new StringTokenizer(br.readLine());
        long a[]=new long[st.countTokens()];
        for(int i=0;i<a.length;i++){
            a[i]=Long.parseLong(st.nextToken());
        }
        return a;
    }
    public int readInt() throws Exception{
        st=new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }
    public long readLong() throws Exception{
        st=new StringTokenizer(br.readLine());
        return Long.parseLong(st.nextToken());
    }
    public String readString() throws Exception{
        return br.readLine();
    }
    public int[][] read2dArray(int n,int m)throws Exception{
        int a[][]=new int[n][m];
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                a[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        return a;
    }
}
class precalculates{
    public long gcd(long p, long q) {
        if (q == 0) return p;
        else return gcd(q, p % q);
    }
    public int[] prefixSumOneDimentional(int a[]){
        int n=a.length;
        int dp[]=new int[n];
        for(int i=0;i<n;i++){
            if(i==0)
                dp[i]=a[i];
            else
                dp[i]=dp[i-1]+a[i];
        }
        return dp;
    }
    public int[] postSumOneDimentional(int a[]) {
        int n = a.length;
        int dp[] = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                dp[i] = a[i];
            else
                dp[i] = dp[i + 1] + a[i];
        }
        return dp;
    }
    public int[][] prefixSum2d(int a[][]){
        int n=a.length;int m=a[0].length;
        int dp[][]=new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=a[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        return dp;
    }
    public long pow(long a,long b){
        long mod=1000000007;
        long ans=1;
        if(b<=0)
            return 1;
        if(b%2==0){
            ans=pow(a,b/2)%mod;
            return ((ans%mod)*(ans%mod))%mod;
        }else{
            ans=pow(a,b-1)%mod;
            return ((a%mod)*(ans%mod))%mod;
        }
    }

}
class GraphInteger{
    HashMap<Integer,vertex> vtces;
    class vertex{
        HashMap<Integer,Integer> children;
        public vertex(){
            children=new HashMap<>();
        }
    }
    public GraphInteger(){
        vtces=new HashMap<>();
    }
    public void addVertex(int a){
        vtces.put(a,new vertex());
    }
    public void addEdge(int a,int b,int cost){
        if(!vtces.containsKey(a)){
            vtces.put(a,new vertex());
        }
        if(!vtces.containsKey(b)){
            vtces.put(b,new vertex());
        }
        vtces.get(a).children.put(b,cost);
//        vtces.get(b).children.put(a,cost);
    }
    public boolean isCyclicDirected(){
        boolean isdone[]=new boolean[vtces.size()+1];
        boolean check[]=new boolean[vtces.size()+1];
        for(int i=1;i<=vtces.size();i++) {
            if (!isdone[i] && isCyclicDirected(i,isdone, check)) {
                return true;
            }
        }
        return false;
    }
    private boolean isCyclicDirected(int i,boolean isdone[],boolean check[]){
        if(check[i])
            return true;
        if(isdone[i])
            return false;
        check[i]=true;
        isdone[i]=true;
        Set<Integer> set=vtces.get(i).children.keySet();
        for(Integer ii:set){
            if(isCyclicDirected(ii,isdone,check))
                return true;
        }
        check[i]=false;
        return false;
    }
}
class union_find {
    int n;
    int[] sz;
    int[] par;

    union_find(int nval) {
        n = nval;
        sz = new int[n + 1];
        par = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int root(int x) {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    boolean find(int a, int b) {
        return root(a) == root(b);
    }

    int union(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb)
            return 0;
        if(a==b)
            return 0;
        if (sz[a] > sz[b]) {
            int temp = ra;
            ra = rb;
            rb = temp;
        }
        par[ra] = rb;
        sz[rb] += sz[ra];
        return 1;
    }
}







