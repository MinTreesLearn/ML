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
    DThreeIntegers solver = new DThreeIntegers();
    int testCount = Integer.parseInt(in.next());
    for (int i = 1; i <= testCount; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class DThreeIntegers {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      int max = 0;
      max = Math.max(max, a);
      max = Math.max(max, b);
      max = Math.max(max, c);
      int min = (int) 1e9;
      int[] res = new int[3];
      for (int i = 1; i <= max; i++) {
        for (int j = 1; i * j <= 2e4; j++) {
          for (int k = 1; i * j * k <= 2e4; k++) {
            int d = Math.abs(a - i) + Math.abs(i * j - b) + Math.abs(i * j * k - c);
            if (d < min) {
              min = d;
              res[0] = i;
              res[1] = i * j;
              res[2] = i * j * k;
            }
          }
        }
      }
      out.println(min);
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

    public String nextString() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        if (Character.isValidCodePoint(c)) {
          res.appendCodePoint(c);
        }
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
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

    public String next() {
      return nextString();
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

    public void print(int[] array) {
      for (int i = 0; i < array.length; i++) {
        if (i != 0) {
          writer.print(' ');
        }
        writer.print(array[i]);
      }
    }

    public void println(int[] array) {
      print(array);
      writer.println();
    }

    public void close() {
      writer.close();
    }

    public void println(int i) {
      writer.println(i);
    }

  }
}

