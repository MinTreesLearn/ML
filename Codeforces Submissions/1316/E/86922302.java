import java.io.*;
import java.util.*;

public class Main {
    FastScanner fastScanner = new FastScanner();
    PrintWriter out = new PrintWriter(System.out);

    int n, p, k;
    long[][] dp;
    long[] csum;

    List<Data> inp = new ArrayList<Data>();

    public void run() throws Exception {
        n = fastScanner.nextInt();
        p = fastScanner.nextInt();
        k = fastScanner.nextInt();
        for(int i = 0; i < n; i++){
            inp.add(new Data(fastScanner.nextLong()));
        }
        for(int i = 0; i < n; i++){
            long[] tmp = new long[p];
            for(int j = 0; j < p; j++){
                tmp[j] = fastScanner.nextLong();
            }
            inp.get(i).setP(tmp);
        }
        Collections.sort(inp, new Comparator<Data>() {
            @Override
            public int compare(Data o1, Data o2) {
                long diff = o1.getA() - o2.getA();
                if(diff > 0) return -1;
                else if(diff < 0) return 1;
                else {
                    return 0;
                }
            }
        });
        csum = new long[n];
        for(int i = 0; i < n; i++){
            csum[i] = inp.get(i).getA();
            if(i > 0) csum[i] += csum[i - 1];
        }
        dp = new long[n][1 << p];
        for(int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        out.println(go(0, 0));
        out.flush();
    }

    public long go(int pos, int mask){
        if(mask == (1 << p) - 1){
            int rem = allOk(pos, p);
            long extra = 0;
            if(pos + rem <= n && rem > 0){
                extra = csum[pos + rem - 1] - csum[pos - 1];
            }
            return extra;
        }
        if(pos >= n){
            return 0;
        }
        if(dp[pos][mask] != -1){
            return dp[pos][mask];
        }
        long c = allOk(pos, Integer.bitCount(mask)) > 0 ? inp.get(pos).getA() : 0, d = go(pos + 1, mask);
        c += go(pos + 1, mask);
        for(int i = 0; i < p; i++){
            if((mask & (1 << i)) == 0){
                d = Math.max(d, inp.get(pos).getP()[i] + go(pos + 1, mask | (1 << i)));
            }
        }
        return dp[pos][mask] = Math.max(c, d);
    }

    public int allOk(int pos, int taken){
        int lft = pos - taken;
        return k - lft;
    }

    class Data {
        long a;
        long[] p;

        public Data(long a){
            this.a = a;
        }

        public Data(long[] p){
            this.p = p;
        }

        public long getA(){
            return this.a;
        }

        public long[] getP(){
            return this.p;
        }

        public void setA(long a){
            this.a = a;
        }

        public void setP(long[] p){
            this.p = p;
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }

    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public FastScanner() {
            this.reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }

        public String next(){
            while (tokenizer == null || !tokenizer.hasMoreTokens()){
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e){
                    throw new RuntimeException();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt(){
            return Integer.parseInt(next());
        }

        public long nextLong(){
            return Long.parseLong(next());
        }

        public double nextDouble(){
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e){
                throw new RuntimeException();
            }
        }
    }
}
