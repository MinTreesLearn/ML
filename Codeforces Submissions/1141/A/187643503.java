import java.util.*;
import java.io.*;
public class A_Game_23
{
static long mod = 1000000007;
public static void main(String[] args) {
var sc = new Kattio(System.in, System.out);
int t=1;
// t = sc.nextInt();
for (int i = 0; i < t; i++) solve(sc);
sc.close();
}
public static void solve(Kattio sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        if(m%n!=0) {sc.println(-1);return;}
        int d = m/n;
        int count=0;
        while(d!=1){
            if(d%2!=0 && d%3!=0){
                sc.println(-1);
                return;
            }
            if(d%2==0) {d/=2;count++;}
            if(d%3==0){
                d/=3;
                count++;
            }
        }
        sc.println(count);

    }
}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

    public String next() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}