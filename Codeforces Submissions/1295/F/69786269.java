
import java.util.*;
import java.io.*;

public class Good {
    public static void main(String [] args) {
        Solver s = new Solver();
        s.solve();
    }
}

class Solver {
    Reader in = new Reader ();
    Writer out = new Writer ();
    int l[], r[];
    int n;
    int b[], e[];
    int range;
    long invfac[];

    final int inf = 1000000000;
    final int mod = 998244353;

    long power(long b, int e) {
        if(e == 0) return 1;
        if(e % 2 == 1) return (power(b, e - 1) * b) % mod;
        long m = power(b, e >> 1);
        return (m * m) % mod;
    }

    long nCr(int n, int k) {
        long ans = invfac[k];
        for(int i = n; i > n - k; i--) {
            ans = (ans * i) % mod;
        }
        return ans;
    }
    class Data {
        int value, type;
        Data () {}
        Data (int value, int type) {
            this.value = value;
            this.type = type;
        }
        boolean equalTo(Data t) {
            return (value == t.value && type == t.type);
        }
    }
    long mem[][];
    long dp(int pos, int cur) {
        if(pos == n + 1) return 1;
        if(cur <= 0) return 0;
        if(mem[pos][cur] != -1) return mem[pos][cur];
        long ans = dp(pos, cur - 1);
        for(int i = pos; i <= n; i++) {
            int sz = (i - pos + 1);
            if(l[i] <= b[cur] && e[cur] <= r[i]) {
                ans += dp(i + 1, cur - 1) * nCr(e[cur] - b[cur] + sz, sz);
                ans %= mod;
            } else break;   
        }
        return mem[pos][cur] = ans;
    }

    void solve () {
        n = in.nextInt();
        l = new int [n + 1];
        r = new int [n + 1];
        b = new int [5 * n + 1];
        e = new int [5 * n + 1];

        ArrayList <Data> arr = new ArrayList <> ();
        arr.add(new Data(-inf, 0));
        arr.add(new Data(inf, 1));
        for(int i = 1; i <= n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            arr.add(new Data(l[i], 0)); arr.add(new Data(l[i] - 1, 1));
            arr.add(new Data(r[i], 1)); arr.add(new Data(r[i] + 1, 0));
        }    
        Collections.sort(arr, (p, q) ->  {if(p.value == q.value) return p.type - q.type;
                                          else return p.value - q.value; });
        ArrayList <Integer> unq = new ArrayList <> ();
        for(int i = 0; i < arr.size(); i++) {
            if(i > 0 && arr.get(i - 1).equalTo(arr.get(i))) continue;
            unq.add(arr.get(i).value);
        }
        range = 0;
        for(int i = 0; i < unq.size(); i += 2) {
            b[++range] = unq.get(i);
            e[range] = unq.get(i + 1);
            // System.out.println(b[range] + " " + e[range]);
        }
        invfac = new long [n + 1];
        long fac = 1;
        invfac[0] = fac;
        for(int i = 1; i <= n; i++) {
            fac = (fac * i) % mod;
            invfac[i] = power(fac, mod - 2);
        }
        mem = new long [n + 1][range + 1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= range; j++) {
                mem[i][j] = -1;
            }
        }
        long res = dp(1, range);
        for(int i = 1; i <= n; i++) {
             res = (res * power(r[i] - l[i] + 1, mod - 2)) % mod;
        }
        System.out.println(res);
    }   
}

class Reader {
    private StringTokenizer a;
    private BufferedReader b;
    Reader () {
        a = null;
        try {
            b = new BufferedReader (new InputStreamReader (System.in)); // for file IO, replace this with new FileReader ("in.txt")
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public String next () {
        while(a == null || !a.hasMoreTokens()) {
            try {
                a = new StringTokenizer (b.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return a.nextToken();
    }
    public int nextInt() {
        return Integer.parseInt(this.next());
    }
    public long nextLong () {
        return Long.parseLong(this.next());
    }
    public double nextDouble () {
        return Double.parseDouble(this.next());
    }
    public String nextLine() {
        try {
            return b.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }
}
class Writer {
    private PrintWriter a;
    private StringBuffer b;
    Writer () {
        try {
            a = new PrintWriter (System.out); // for file IO, replace this with new FileWriter ("out.txt")
        } catch (Exception e) {
            e.printStackTrace();
        }
        b = new StringBuffer ("");
    }
    public void write (Object s) {
        b.append(s);
    }
    public void writeln(Object s) {
        b.append(s).append('\n');
    }
    public void flush () {
        a.print(b);
        a.flush();
        a.close();
    }
}
