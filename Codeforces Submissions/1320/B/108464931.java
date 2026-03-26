import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class B625 {

    static BufferedReader br;
    static long mod = 1000000000 + 7;
    static HashSet<Integer> p = new HashSet<>();

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int tc = 1;
       // tc = cinI();
        while (tc-- > 0) {
               int[] nm = readArray(2,0,0);
               HashSet<Integer>[] g = new HashSet[nm[0]+1];
            HashSet<Integer>[] g1 = new HashSet[nm[0]+1];

            long[] dist= new long[nm[0]+1];
            HashSet<Integer>[] next = new HashSet[nm[0]+1];

                for(int i=0;i<nm[1];i++){

                    int[]uv = readArray(2,0,0);
                    int  u  =uv[0];
                    int v = uv[1];
                    if(g[u]==null){
                        g[u]=new HashSet<Integer>();
                    }
                    if(g1[u]==null){
                        g[u]=new HashSet<Integer>();
                    }
                    if(g[v]==null){
                        g[v]=new HashSet<Integer>();
                    }
                    if(g1[v]==null){
                        g1[v]=new HashSet<Integer>();
                    }
                    g1[v].add(u);
                    g[u].add(v);
                }
                for(int i=0;i<=nm[0];i++){
                    next[i]=new HashSet<Integer>();
                }
                   int n =cinI();
                int[] arr  =readArray(n,0,0);
                Arrays.fill(dist,Long.MAX_VALUE);
                dist[arr[n-1]]=0;
                Queue<Integer> node = new LinkedList<>();
                node.add(arr[n-1]);
                while (node.isEmpty()==false){
                    int c = node.poll();

                    for(int cc : g1[c]){
                        if(dist[cc]==dist[c]+1){
                            next[cc].add(c);
                            continue;
                        }
                        if(dist[cc]>dist[c]+1){
                            dist[cc]=dist[c]+1;
                            next[cc].add(c);
                            node.add(cc);
                        }
                    }
                }
                long min=0;
            long max=0;

                for(int i=1;i<n;i++){
                    if(next[arr[i-1]].contains(arr[i])){
                       if(next[arr[i-1]].size()>1)
                        max+=1;
                       // System.out.println(arr[i]+" "+next[arr[i-1]]);
                    }
                    else{
                       // System.out.println(arr[i]+" elaee "+next[arr[i-1]]);
                        min+=1;
                        max+=1;
                    }
                }
            System.out.println(min +" "+max);
        }
    }


    private static int dfs(TreeMap<Integer, HashSet<Integer>> graph, boolean[] vis, Integer key, Stack<Integer> st) {
        if (st.size() == 0) {
            return 0;
        }
        int par = st.pop();

        HashSet<Integer> child = graph.get(par);
        vis[par] = true;
        int nodes = 1;
        for (int c : child) {
            if (vis[c] == false) {
                st.add(c);
                nodes += dfs(graph, vis, c, st);
            }
        }
        return nodes;
    }


    public static boolean isSorted(int[] arr) {

        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }


    private static long gcd(long a, long b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        // base case
        if (a == b)
            return a;

        // a is greater
        if (a > b)
            return gcd(a % b, b);
        return gcd(a, b % a);
    }


    public static long min(long a, long b) {
        return Math.min(a, b);
    }

    public static int min(int a, int b) {
        return Math.min(a, b);
    }


    public static void sieve() {
        int[] pf = new int[100000000 + 1];
        //0 prime //1 not prime
        pf[0] = 1;
        pf[1] = 1;
        for (int j = 2; j <= 10000; j++) {

            if (pf[j] == 0) {
                p.add(j);
                for (int k = j * j; k < pf.length; k += j) {
                    pf[k] = 1;
                }
            }
        }

    }


    public static int[] readArray(int n, int x, int z) throws Exception {
        int[] arr = new int[n];
        String[] ar = cinA();
        for (int i = x; i < n + x; i++) {
            arr[i] = getI(ar[i - x]);
        }
        return arr;
    }

    public static long[] readArray(int n, int x) throws Exception {
        long[] arr = new long[n];
        String[] ar = cinA();
        for (int i = x; i < n + x; i++) {
            arr[i] = getL(ar[i - x]);
        }
        return arr;
    }

    public static void arrinit(String[] a, long[] b) throws Exception {
        for (int i = 0; i < a.length; i++) {
            b[i] = Long.parseLong(a[i]);
        }
    }

    public static HashSet<Integer>[] Graph(int n, int edge, int directed) throws Exception {
        HashSet<Integer>[] tree = new HashSet[n];

        for (int j = 0; j < edge; j++) {

            String[] uv = cinA();
            int u = getI(uv[0]);
            int v = getI(uv[1]);
            if (directed == 0) {

                tree[v].add(u);
            }
            tree[u].add(v);
        }
        return tree;
    }

    public static void arrinit(String[] a, int[] b) throws Exception {
        for (int i = 0; i < a.length; i++) {
            b[i] = Integer.parseInt(a[i]);
        }
    }


    static double findRoots(int a, int b, int c) {
        // If a is 0, then equation is not
        //quadratic, but linear


        int d = b * b - 4 * a * c;
        double sqrt_val = Math.sqrt(Math.abs(d));


        // System.out.println("Roots are real and different \n");

        return Math.max((double) (-b + sqrt_val) / (2 * a),
                (double) (-b - sqrt_val) / (2 * a));


    }

    public static String cin() throws Exception {
        return br.readLine();
    }

    public static String[] cinA() throws Exception {
        return br.readLine().split(" ");
    }

    public static String[] cinA(int x) throws Exception {
        return br.readLine().split("");
    }

    public static String ToString(Long x) {
        return Long.toBinaryString(x);
    }

    public static void cout(String s) {
        System.out.println(s);
    }

    public static Integer cinI() throws Exception {
        return Integer.parseInt(br.readLine());
    }

    public static int getI(String s) throws Exception {
        return Integer.parseInt(s);
    }

    public static long getL(String s) throws Exception {
        return Long.parseLong(s);
    }

    public static long max(long a, long b) {
        return Math.max(a, b);
    }

    public static int max(int a, int b) {
        return Math.max(a, b);
    }

    public static void coutI(int x) {
        System.out.println(String.valueOf(x));
    }

    public static void coutI(long x) {
        System.out.println(String.valueOf(x));
    }

    public static Long cinL() throws Exception {
        return Long.parseLong(br.readLine());
    }

    public static void arrInit(String[] arr, int[] arr1) throws Exception {
        for (int i = 0; i < arr.length; i++) {
            arr1[i] = getI(arr[i]);
        }

    }
}