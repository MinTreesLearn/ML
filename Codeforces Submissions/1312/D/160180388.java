import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    DCountTheArrays solver = new DCountTheArrays();
    solver.solve(1, in, out);
    out.close();
  }

  static class DCountTheArrays {
    int n;
    int m;
    int mod = 998244353;
    int N = (int) (2e5 + 5);

    public void solve(int testNumber, InputReader in, OutputWriter out) {


      n = in.nextInt();
      m = in.nextInt();
      long[][] fif = enumFAndIf(N);

      long res = 0;

      long base = (n - 2) * c(m, n - 1, fif) % mod;
      for (int i = 2; i <= n - 1; i++) {
        res = (res + base * (c(n - 3, i - 2, fif))) % mod;
      }
      out.println(res);
    }

    long[][] enumFAndIf(int n) {
      long[] f = new long[n + 1];
      long[] invf = new long[n + 1];
      f[0] = 1;
      for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
      }
      invf[n] = invl(f[n], mod);
      for (int i = n - 1; i >= 0; i--) {
        invf[i] = invf[i + 1] * (i + 1) % mod;
      }
      return new long[][]{f, invf};
    }

    long invl(long a, long mod) {
      long b = mod;
      long p = 1, q = 0;
      while (b > 0) {
        long c = a / b;
        long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
      }
      return p < 0 ? p + mod : p;
    }

    long c(int a, int b, long[][] fif) {
      if (b < 0 || b > a) {
        return 0;
      }
      return fif[0][a] * fif[1][b] % mod * fif[1][a - b] % mod;
    }

  }

  static class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void close() {
      writer.close();
    }

    public void println(long i) {
      writer.println(i);
    }

  }

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int read() {
      if (numChars == -1) {
        throw new InputMismatchException();
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars <= 0) {
          return -1;
        }
      }
      return buf[curChar++];
    }

    public int nextInt() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public boolean isSpaceChar(int c) {
      if (filter != null) {
        return filter.isSpaceChar(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
      public boolean isSpaceChar(int ch);

    }

  }
}

