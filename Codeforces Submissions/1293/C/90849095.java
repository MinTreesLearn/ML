import java.io.*;
import java.util.*;
public class noob {
    InputReader in;
    final long mod=1000000007;
    StringBuilder sb;
    public static void main(String[] args) throws java.lang.Exception {
        new noob().run();
    }
    void run() throws Exception {
        in=new InputReader(System.in);
        sb = new  StringBuilder();
        int t=1;
        for(int i=1;i<=t;i++) {
            solve();
        }
        System.out.print(sb);
    } 
    void solve() {
        int i,j;
        int n=i(), q=i();
        int[][] vis = new int[2][n + 1];
        int cnt1 = 0, cnt2 = 0;
        for(i = 0; i < q; i++){
            int x = i() - 1;
            int y = i();
            if(vis[x][y] == 0){
                if(vis[x ^ 1][y] == 1)
                        cnt1++;
                    if(y > 1 && vis[x ^ 1][y - 1] == 1)
                        cnt2++;
                    if(y < n && vis[x ^ 1][y + 1] == 1)
                        cnt2++;
            }
            else{
                if(vis[x ^ 1][y] == 1)
                        cnt1--;
                    if(y > 1 && vis[x ^ 1][y - 1] == 1)
                        cnt2--;
                    if(y < n && vis[x ^ 1][y + 1] == 1)
                        cnt2--;
            }
            vis[x][y] ^= 1;
            if(cnt1 == 0 && cnt2 == 0)
                sb.append("Yes\n");
            else
                sb.append("No\n");
        }
        
    }
    long power(long x, long y, long p) { 
        long res = 1;       
        x = x % p;  
        if (x == 0) return 0;   
        while (y > 0) {
            if((y & 1)==1) 
                res = (res * x) % p;  
            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res%p; 
    } 
    int gcd(int a, int b) {
        return (b==0)?a:gcd(b,a%b);
    }
    String s(){return in.next();}
    int i(){return in.nextInt();}
    long l(){return in.nextLong();}
    double d(){return in.nextDouble();}
    class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
        public int peek() {
            if (numChars == -1)
                return -1;
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar];
        }
        public void skip(int x) {
            while (x-->0)
                read();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public String nextString() {
            return next();
        }
        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
 
            return res.toString();
        }
        public String nextLine() {
            StringBuffer buf = new StringBuffer();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r')
                    buf.appendCodePoint(c);
                c = read();
            }
            return buf.toString();
        }
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        public boolean hasNext() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1)
                read();
            return value != -1;
        }
        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}