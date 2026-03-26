import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Queue;
import java.util.ArrayDeque;
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
    DKuroniAndTheCelebration solver = new DKuroniAndTheCelebration();
    solver.solve(1, in, out);
    out.close();
  }

  static class DKuroniAndTheCelebration {
    int N = 1010;
    int M = N * 2;
    int[] h = new int[N];
    int[] e = new int[M];
    int[] ne = new int[M];
    int idx;
    int n;
    int[] deg = new int[N];

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      Arrays.fill(h, -1);
      idx = 0;
      n = in.nextInt();
      for (int i = 0; i < n - 1; i++) {
        int a = in.nextInt();
        int b = in.nextInt();
        add(a, b);
        add(b, a);
        deg[a]++;
        deg[b]++;
      }

      Queue<Integer> queue = new ArrayDeque<>();
      for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
          queue.add(i);
        }
      }

      while (queue.size() >= 2) {
        int a = queue.poll();
        int b = queue.poll();
        out.println("?", a, b);
        out.flush();
        int x = in.nextInt();
        if (x == a || x == b) {
          out.println("!", x);
          out.flush();
          return;
        }
        for (int i = h[a]; i != -1; i = ne[i]) {
          int j = e[i];
          if (deg[j] > 1) {
            deg[j]--;
            if (deg[j] == 1) {
              queue.add(j);
            }
          }
        }
        for (int i = h[b]; i != -1; i = ne[i]) {
          int j = e[i];
          if (deg[j] > 1) {
            deg[j]--;
            if (deg[j] == 1) {
              queue.add(j);
            }
          }
        }
      }
      out.println("!", queue.poll());
      out.flush();

    }

    void add(int a, int b) {
      e[idx] = b;
      ne[idx] = h[a];
      h[a] = idx++;
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

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; i++) {
        if (i != 0) {
          writer.print(' ');
        }
        writer.print(objects[i]);
      }
    }

    public void println(Object... objects) {
      print(objects);
      writer.println();
    }

    public void close() {
      writer.close();
    }

    public void flush() {
      writer.flush();
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

