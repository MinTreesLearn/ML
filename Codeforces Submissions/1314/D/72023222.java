import java.util.*;
import java.io.*;
import java.text.*;
public class Main{
    //SOLUTION BEGIN
    //Into the Hardware Mode
    void pre() {}
    void solve(int TC){
        int n = ni(), K = ni()/2;
        int[][] g = new int[n][n];
        for(int i = 0; i< n; i++)
            for(int j = 0; j< n; j++)
                g[i][j] = ni();

        ArrayList<Integer>[][] min = new ArrayList[n][n];
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                PriorityQueue<Pair> q = new PriorityQueue<Pair>();
                for(int x = 0; x< n; x++){
                    if(x == i || x == j)continue;
                    q.add(new Pair(x, g[i][x]+g[x][j]));
                }
                min[i][j] = new ArrayList<>();
                for(int x = 0; x <= K && !q.isEmpty(); x++)min[i][j].add(q.poll().u);
            }
        }
        int[] node = new int[5];
        node[0] = 0;
        long ans = IINF;
        long[] di = new long[5], nd = new long[5];
        long[][] delta = new long[5][5];
        int[] val = new int[n];
        val[0]++;
        for(int i = 0; i< n; i++) {
            node[1] = i;
            val[i]++;
            for (int j = i ; j < n; j++) {
                node[2] = j;
                val[j]++;
                for (int k = j; k < n; k++) {
                    node[3] = k;
                    val[k]++;
                    for (int l = k ; l < n; l++) {
                        node[4] = l;
                        val[l]++;
                        Arrays.fill(di, IINF);
                        di[0] = 0;
                        for(int ii = 0; ii< 5; ii++)Arrays.fill(delta[ii], IINF);
                        for(int ii = 0; ii< 5; ii++){
                            for(int jj = 0; jj< 5; jj++){
                                for(int cand:min[node[ii]][node[jj]])
                                    if(val[cand] == 0){
                                        delta[ii][jj] = Math.min(delta[ii][jj], g[node[ii]][cand]+g[cand][node[jj]]);
                                        break;
                                    }
                            }
                        }
                        for(int KK = 0; KK < K; KK++){

                            Arrays.fill(nd, IINF);
                            for(int ii = 0; ii< 5; ii++)
                                if(di[ii] != IINF)
                                    for(int jj = 0; jj< 5; jj++)
                                        nd[jj] = Math.min(nd[jj], di[ii]+delta[ii][jj]);
                            for(int ii = 0; ii< 5; ii++)di[ii] = nd[ii];
                        }
                        ans = Math.min(ans, di[0]);
                        val[l]--;
                    }
                    val[k]--;
                }
                val[j]--;
            }
            val[i]--;
        }
        pn(ans);
    }
    class Pair implements Comparable<Pair>{
        int u, cost;
        public Pair(int U, int C){
            u = U;cost = C;
        }
        public int compareTo(Pair pair) {
            return Integer.compare(cost, pair.cost);
        }
    }
    int[][] makeU(int n, int[] from, int[] to){
        int[][] g = new int[n][];
        int[] cnt = new int[n];
        for(int i:from)cnt[i]++;for(int i:to)cnt[i]++;
        for(int i = 0; i< n; i++)g[i] = new int[cnt[i]];
        for(int i = 0; i< n-1; i++){
            g[from[i]][--cnt[from[i]]] = to[i];
            g[to[i]][--cnt[to[i]]] = from[i];
        }
        return g;
    }
    //SOLUTION END
    //void hold(boolean b){if(!b)throw new Exception("Hold right there, Sparky!");}
    void exit(boolean b){if(!b)System.exit(0);}
    long IINF = (long)1e15;
    final int INF = (int)1e9+2, MX = (int)2e6+5;
    DecimalFormat df = new DecimalFormat("0.00000000000");
    double PI = 3.141592653589793238462643383279502884197169399, eps = 1e-8;
    static boolean multipleTC = false, memory = false, fileIO = false;
    FastReader in = new FastReader();PrintWriter out = new PrintWriter(System.out);
    void run(){
        try{
            long ct = System.currentTimeMillis();
            if (fileIO) {
                in = new FastReader("");
                out = new PrintWriter("");
            } else {
                in = new FastReader();
                out = new PrintWriter(System.out);
            }
            //Solution Credits: Taranpreet Singh
            int T = (multipleTC) ? ni() : 1;
            pre();
            for (int t = 1; t <= T; t++) solve(t);
            out.flush();
            out.close();
            System.err.println(System.currentTimeMillis() - ct);
        }catch (Exception e){

        }

    }
    public static void main(String[] args){
        if(memory)new Thread(null, new Runnable() {public void run(){try{new Main().run();}catch(Exception e){e.printStackTrace();}}}, "1", 1 << 28).start();
        else new Main().run();
    }
//    int find(int[] set, int u){return set[u] = (set[u] == u?u:find(set, set[u]));}
    int digit(long s){int ans = 0;while(s>0){s/=10;ans++;}return ans;}
    long gcd(long a, long b){return (b==0)?a:gcd(b,a%b);}
    int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    void p(Object o){out.print(o);}
    void pn(Object o){out.println(o);}
    void pni(Object o){out.println(o);out.flush();}
    String n(){return in.next();}
    String nln(){return in.nextLine();}
    int ni(){return Integer.parseInt(in.next());}
    long nl(){return Long.parseLong(in.next());}
    double nd(){return Double.parseDouble(in.next());}

    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
//                    throw new Exception(e.toString());
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{
                str = br.readLine();
            }catch (IOException e){
//                throw new Exception(e.toString());
            }
            return str;
        }
    }
}

