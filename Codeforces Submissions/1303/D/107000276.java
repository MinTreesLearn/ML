import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static PrintWriter pw;
    static Scanner sc;
    static long ceildiv(long x, long y) { return (x+y-1)/y; }
    static int mod(long x, int m) { return (int)((x%m+m)%m); }
    static void put(HashMap<Integer, Integer> map, Integer p){if(map.containsKey(p)) map.replace(p, map.get(p)+1); else map.put(p, 1); }
    static void rem(HashMap<Integer, Integer> map, Integer p){ if(map.get(p)==1) map.remove(p);else map.replace(p, map.get(p)-1); }
    static void printf(double x, int dig){ String s="%."+dig+"f"; pw.printf(s, x); }
    static int Int(boolean x){ return x?1:0; }
    static final int inf=(int)1e9, mod=998244353;
    static final long infL=inf*1l*inf;
    static final double eps=1e-9;
    public static long gcd(long x, long y) { return y==0? x: gcd(y, x%y); }
    public static void main(String[] args) throws Exception{
        sc=new Scanner(System.in);
        pw=new PrintWriter(System.out);
        int t=sc.nextInt();
        while(t-->0)
            testcase();
        pw.close();
    }
    static void testcase() throws IOException{
        long x=sc.nextLong();
        int n=sc.nextInt(), cnt[]=new int[63];
        double log2=Math.log(2);
        for (int i = 0; i < n; i++)
            cnt[round(Math.log(sc.nextInt())/log2)]++;
        int ans=0;
        for (int i = 0; i < 63; i++) {
            long bit=(1l<<i)&x;
            if(less(bit, cnt, i))
                continue;
            int cost=more(bit, cnt, i);
            if(cost==-1){
                ans=-1;
                break;
            }
            ans+=cost;
            cnt[i]--;
        }
        pw.println(ans);
    }
    static boolean less(long x, int[] cnt, int idx){
        if(x==0)
            return true;
        for (int i = idx; i >=0 && x>0; i--) {
            long bit=1l<<i, need=x/bit, min=Math.min(need, cnt[i]);
            cnt[i]-=(int)min;
            x-=min*bit;
        }
        return x==0;
    }
    static int more(long x, int[] cnt, int idx){
        int ans=0;
        for (int i = idx+1; i < 63; i++) {
            if(cnt[i]>0){
                for (int j = i-1; j >= idx; j--) {
                    cnt[j+1]--;
                    cnt[j]+=2;
                    ans++;
                }
                break;
            }
        }
        return ans>0 ? ans : -1;
    }
    static int round(double x){
        if(x%1>0.9)
            return (int) x+1;
        return (int) x;
    }
    static void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i] + " ");
        pw.println();
    }
    static void printArr(long[] arr) {
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i] + " ");
        pw.println();
    }
    static void printArr(double[] arr) {
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i] + " ");
        pw.println();
    }
    static void printArr(Integer[] arr) {
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i] + " ");
        pw.println();
    }
    static void printArr(ArrayList list) {
        for (int i = 0; i < list.size(); i++)
            pw.print(list.get(i)+" ");
        pw.println();
    }
    static void printArr(boolean[] arr) {
        StringBuilder sb=new StringBuilder();
        for(boolean b: arr)
            sb.append(Int(b));
        pw.println(sb);
    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public int[] nextDigits() throws IOException{
            String s=nextLine();
            int[] arr=new int[s.length()];
            for(int i=0; i<arr.length; i++)
                arr[i]=s.charAt(i)-'0';
            return arr;
        }
        public int[] nextArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < arr.length; i++)
                arr[i] = nextInt();
            return arr;
        }
        public Integer[] nextsort(int n) throws IOException{
            Integer[] arr=new Integer[n];
            for(int i=0; i<n; i++)
                arr[i]=nextInt();
            return arr;
        }
        public Pair nextPair() throws IOException{
            return new Pair(nextInt(), nextInt());
        }
        public long[] nextLongArr(int n) throws IOException{
            long[] arr=new long[n];
            for (int i = 0; i < n; i++)
                arr[i]=sc.nextLong();
            return arr;
        }
        public Pair[] nextPairArr(int n) throws IOException{
            Pair[] arr=new Pair[n];
            for(int i=0; i<n; i++)
                arr[i]=nextPair();
            return arr;
        }
        public boolean ready() throws IOException {
            return br.ready();
        }
    }
    static class Pair implements Comparable<Pair>{
        int x;
        int y;
        public Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
        public boolean contains(int a){
            return x==a || y==a;
        }
        public int hashCode() {
            return (this.x*1000000000+this.y);
        }
        public int compareTo(Pair p){
            if(x==p.x)
                return y-p.y;
            return x-p.x;
        }
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (this.getClass() != obj.getClass()) {
                return false;
            }
            Pair p = (Pair) obj;
            return this.x==p.x && this.y==p.y;
        }
        public Pair clone(){
            return new Pair(x, y);
        }
        public String toString(){
            return this.x+" "+this.y;
        }
        public void add(Pair p){
            x+=p.x;
            y+=p.y;
        }
        public Pair negative(){
            return new Pair(-x, -y);
        }
    }
    static class LP implements Comparable<LP>{
        long x, y;
        public LP(long a, long b){
            x=a;
            y=b;
        }
        public void add(LP p){
            x+=p.x;
            y+=p.y;
        }
        public boolean equals(LP p){
            return p.x==x && y==p.y;
        }
        public String toString(){
            return this.x+" "+this.y;
        }
        public int compareTo(LP p){
            int a=Long.compare(x, p.x);
            if(a!=0)
                return a;
            return Long.compare(y, p.y);
        }
    }
    static class Triple implements Comparable<Triple>{
        int x, y, z;
        public Triple(int a, int b, int c){
            x=a;
            y=b;
            z=c;
        }
        public int compareTo(Triple t){
            if(this.y!=t.y)
                return y-t.y;
            return x-t.x;
        }
        public String toString(){
            return x+" "+y+" "+z;
        }
    }
    //    static class MaxSegmentTree{
//        int n;
//        long[] tree;
//        public MaxSegmentTree(int len, long[] arr){
//            n=len;
//            build(0, 0, n-1, arr);
//        }
//        public void build(int i, int l, int r, long[] arr){
//            if(l==r){
//                tree[i]=arr[l];
//                return;
//            }
//            int mid=(l+r)/2, left=2*i+1, right=2*i+2;
//            build(left, l, mid, arr);
//            build(right, mid+1, r, arr);
//            tree[i]=Math.max(left, right);
//        }
//        public int query(int i){
//            return query(0, 0, n-1, 0, i);
//        }
//        public int query(int node, int i, int j, int l, int r){
//            if(l>j || r<i)
//                return -1;
//
//        }
//    }
    static class SegmentTree {
        int n, size[];
        long[] tree;
        public SegmentTree(int len) {
            n = len;
            tree=new long[2*n-1];
            size=new int[2*n-1];
        }
        public void set(int i, long x){
            i+=n-1;
            tree[i]=x;
            size[i]++;
            i=(i-1)/2;
            while(true){
                size[i]++;
                tree[i]=tree[i*2+1] + tree[i*2+2];
                if(i==0)
                    break;
                i=(i-1)/2;
            }
        }
        public long query(int x){
            return query(0, 0, n-1, x+1, n-1);
        }
        public long query(int node, int i, int j, int l, int r){
            if(j<l || i>r)
                return 0;
            if(i>=l && j<=r)
                return tree[node];
            int mid=(i+j)/2, left=node*2+1, right=node*2+2;
            return query(left, i, mid, l, r) + query(right, mid+1, j, l, r);
        }
        public int size(int idx){
            return size(0, 0, n-1, idx+1, n-1);
        }
        public int size(int node, int i, int j, int l, int r){
            if(i>r || j<l)
                return 0;
            if(i>=l && j<=r)
                return size[node];
            int mid=(i+j)/2, left=node*2+1, right=node*2+2;
            return size(left, i, mid, l, r)+size(right, mid+1, j, l, r);
        }
    }
}