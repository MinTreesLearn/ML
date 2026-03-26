import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Rustam Musin (t.me/musin_acm)
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    BPodarok solver = new BPodarok();
    solver.solve(1, in, out);
    out.close();
  }

  static class BPodarok {
    Random rnd = new Random(239);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      if (false) {
        test3();
      }
      int n = in.readInt();
      int[] a = in.readIntArray(n);
//    out.print(naive(a));
      out.print(newSolve(a));
    }

    int newSolve(int[] a) {
      int res = 0;
      for (int b = 0; b < 30; b++) {
        if (newSolve(a, b) % 2 == 1) {
          res |= 1 << b;
        }
      }
      return res;
    }

    long newSolve(int[] a, int bit) {
      int[] b = new int[a.length];
      for (int i = 0; i < a.length; i++) {
        b[i] = a[i] % (1 << (bit + 1));
      }
      Arrays.sort(b);
      int L1 = 1 << bit;
      int R1 = (L1 << 1) - 1;
      int L2 = (L1 << 1) | L1;
      int R2 = (L1 << 1) | R1;
      long count = 0;
      for (int x : b) {
        count += getCount(b, L1 - x, R1 - x);
        count += getCount(b, L2 - x, R2 - x);
        if (inside(L1 - x, R1 - x, x)) {
          count--;
        }
        if (inside(L2 - x, R2 - x, x)) {
          count--;
        }
      }
      return count >> 1;
    }

    boolean inside(int l, int r, int x) {
      return l <= x && x <= r;
    }

    int getCount(int[] a, int l, int r) {
      return getCount(a, r) - getCount(a, l - 1);
    }

    int getCount(int[] a, int x) {
      int l = -1;
      int r = a.length;
      while (r - l > 1) {
        int m = l + r >> 1;
        if (a[m] <= x) {
          l = m;
        } else {
          r = m;
        }
      }
      return l;
    }

    int naive(int[] a) {
      int res = 0;
      for (int i = 0; i < a.length; i++) {
        for (int j = i + 1; j < a.length; j++) {
          res ^= a[i] + a[j];
        }
      }
      return res;
    }

    void test3() {
      for (int t = 0; ; t++) {
        int n = 10;
        int m = 5;
        int[] a = genArray(n, m);
        int naive = naive(a);
        int sol = newSolve(a);
        if (naive != sol) {
          System.err.println("FF");
          naive = naive(a);
          sol = newSolve(a);
        }
      }
    }

    int[] genArray(int n, int m) {
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = rnd.nextInt(m);
      }
      return a;
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

    public void print(int i) {
      writer.print(i);
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

    public int[] readIntArray(int size) {
      int[] array = new int[size];
      for (int i = 0; i < size; i++) {
        array[i] = readInt();
      }
      return array;
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

    public int readInt() {
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

