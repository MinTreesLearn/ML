import java.io.*;
import java.sql.Array;
import java.util.*;

public class Contest1 {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////                                                                                                               /////////
////////                                                                                                               /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMMMM      MMMMMM      OOO      OOO        SSSS   SSS     EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEE           MMMM MMM  MMM MMMM    OOO          OOO    SSSS       SSS   EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM  MMMMMM  MMMM   OOO            OOO   SSSS             EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM  OOO              OOO   SSSSSSS         EEEEE          /////////
////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO      SSSSSS       EEEEEEEEEEE    /////////
////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO         SSSSSSS   EEEEEEEEEEE    /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM   OOO            OOO              SSSS  EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM    OOO          OOO     SSS       SSSS  EEEEE          /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM      OOO      OOO        SSS    SSSS    EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
////////                                                                                                               /////////
////////                                                                                                               /////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    static ArrayList<Integer>[]adj;
    static long mod= (int)1e9+9;
    static long base= (int)1e9+7;
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        long[]pow = new long[500001];
        pow[0]=1;
        for (int i =1;i<=500000;i++){
            pow[i]=base*pow[i-1];
            pow[i]%=mod;
        }
        while (t-->0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            adj = new ArrayList[n];
            for (int i = 0; i < n; i++){
                adj[i] = new ArrayList<>();
            }
            long[] gcds = new long[n];
            long[] vals = new long[n];
            long g = 0;
            for (int i = 0; i < n; i++) {
                vals[i] = sc.nextLong();
            }
            while (m-- > 0) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                adj[v].add(u);
            }
            TreeMap<ArrayList<Integer>,Long>ts = new TreeMap<>(new Comparator<ArrayList<Integer>>() {
                public int compare(ArrayList<Integer> t1, ArrayList<Integer> t2) {
                    if (t1.size()!=t2.size())
                        return t1.size()-t2.size();
                    return t1.get(t1.size()-1)-t2.get(t2.size()-1);
                }
            });
            for (int i =0;i<n;i++){
                Collections.sort(adj[i]);
                if (adj[i].isEmpty())continue;
                long hsv= 0;
                int id=0;
                for (int x:adj[i]){
                    hsv+=x*pow[id++];
                    hsv%=mod;
                }
                adj[i].add((int)hsv);
                ts.put(adj[i],ts.getOrDefault(adj[i],0l)+vals[i]);
            }

            while (!ts.isEmpty()) {
                g= gcd(g,ts.pollFirstEntry().getValue());
            }
            pw.println(g);
        }
        pw.flush();
    }
    static long gcd(long a,long b){
        if (a==0)return b;
        return gcd(b%a,a);
    }
    static class SparseTable {

        int A[], SpT[][];

        SparseTable(int[] A)
        {
            int n = A.length;	this.A = A;
            int k = (int)Math.floor(Math.log(n) / Math.log(2)) + 1;
            SpT = new int[n][k];

            for (int i = 0; i < n; i++)
                SpT[i][0] = i; 					// RMQ of sub array starting at index i and of length 2^0=1

            //overall time complexity = O(n log n)
            for (int j = 1; (1<<j) <= n; j++)
                for (int i = 0; i + (1<<j) - 1 < n; i++)
                    if (A[SpT[i][j-1]] > A[SpT[i+(1<<(j-1))][j-1]])
                        SpT[i][j] = SpT[i][j-1];    		// start at index i of length 2^(j-1)
                    else                  					// start at index i+2^(j-1) of length 2^(j-1)
                        SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
        }

        int query(int i, int j)
        {

            int k = (int)Math.floor(Math.log(j-i+1) / Math.log(2)); // 2^k <= (j-i+1)

            if (A[SpT[i][k]] >= A[SpT[j-(1<<k)+1][k]])
                return SpT[i][k];
            else
                return SpT[j-(1<<k)+1][k];
        }
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
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
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }



}