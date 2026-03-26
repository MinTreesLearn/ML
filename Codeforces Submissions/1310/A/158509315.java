import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
    ARecommendations solver = new ARecommendations();
    solver.solve(1, in, out);
    out.close();
  }

  static class ARecommendations {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      P[] a = new P[n];

      for (int i = 0; i < n; i++) {
        a[i] = new P(in.nextInt(), -1);
      }
      for (int i = 0; i < n; i++) {
        a[i].t = in.nextInt();
      }

      Arrays.sort(a, Comparator.comparingInt(x -> x.v));

      PriorityQueue<Integer> priorityQueue = new PriorityQueue<>((x, y) -> y - x);

      long sum = 0;
      long res = 0;
      int cur = -1;
      for (int i = 0; i < n || !priorityQueue.isEmpty(); ) {
        if (priorityQueue.isEmpty()) {
          cur = a[i].v;
        }
        while (i < n && a[i].v == cur) {
          priorityQueue.add(a[i].t);
          sum += a[i].t;
          i++;
        }

        sum -= priorityQueue.poll();
        res += sum;
        cur++;
      }
      out.println(res);

    }

    class P {
      int v;
      int t;

      public P(int v, int t) {
        this.v = v;
        this.t = t;
      }

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

