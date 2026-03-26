import java.io.*;
import java.util.StringTokenizer;

public class JavaApplication {
    static BufferedReader in;
    static BufferedWriter out;
    static StringTokenizer st;
    static String token;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out=new BufferedWriter(new OutputStreamWriter(System.out));
        new JavaApplication().Solve();
        out.flush();
    }
    public String getLine() throws IOException {
        return in.readLine();
    }
    private String getToken() throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(getLine(), "\n ");
        return st.nextToken();
    }
    public int getInt() throws IOException {
        return Integer.parseInt(getToken());
    }
    public long getLong() throws IOException {
        return Long.parseLong(getToken());
    }

    //    public char getChar() throws IOException {
////        if (token == null || token.length() == 0)
////            token = getToken();
////        char r = token.charAt(0);
////        token = token.substring(1);
////        return r;
//    }
    public void println() throws IOException {
        out.newLine();
    }
    public void println(Object obj) throws IOException {
        if (obj == null)
            return;
        out.write(String.valueOf(obj));
        out.newLine();
    }
    public void print(Object obj) throws IOException {
        if (obj == null)
            return;
        out.write(String.valueOf(obj));
    }

    class Pair{
        int a;
        int b;

        boolean flag;
        public Pair(int a,int b){
            this.a=a;
            this.b=b;
            flag=false;
        }

        @Override
        public String toString() {
            String s="";
            s=a+" "+b+", ";
            return s;
        }
    }

    private void Solve() throws IOException {
        int t = getInt();
        while (t-- > 0) {
            int n=getInt();
            long spend=0;
            while(n>=10){
                spend+=10*(n/10);
                n=(n%10)+(n/10);
            }
            spend+=n;
            println(spend);
        }
    }

    private int lcm(int n,int m){
        return n*m/gcd(Math.max(n,m),Math.min(n,m));
    }
    private int gcd(int n,int m){
        if(m==0)
            return n;
        return gcd(m,n%m);
    }
}