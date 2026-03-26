import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
    BAromasSearch solver = new BAromasSearch();
    solver.solve(1, in, out);
    out.close();
  }

  static class BAromasSearch {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      long x0 = in.nextLong();
      long y0 = in.nextLong();
      long ax = in.nextLong();
      long ay = in.nextLong();
      long bx = in.nextLong();
      long by = in.nextLong();
      long xs = in.nextLong();
      long ys = in.nextLong();
      long t = in.nextLong();
      long lim = Long.MAX_VALUE / 2;
      List<Long> x = new ArrayList<>();
      List<Long> y = new ArrayList<>();
      x.add(x0);
      y.add(y0);
      int n = 1;
      while ((lim - bx) / ax >= x.get(n - 1) && (lim - by) / ay >= y.get(n - 1)) {
        x.add(ax * x.get(n - 1) + bx);
        y.add(ay * y.get(n - 1) + by);
        n++;
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          long len = x.get(j) - x.get(i) + y.get(j) - y.get(i);
          long left = Math.abs(xs - x.get(i)) + Math.abs(ys - y.get(i));
          long right = Math.abs(xs - x.get(j)) + Math.abs(ys - y.get(j));
          if (t - left >= len || t - right >= len) {
            res = Math.max(res, j - i + 1);
          }
        }
      }
      out.println(res);

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

    public long nextLong() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
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

    public void println(int i) {
      writer.println(i);
    }

  }
}

