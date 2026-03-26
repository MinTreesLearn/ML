import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
    AGarland solver = new AGarland();
    solver.solve(1, in, out);
    out.close();
  }

  static class AGarland {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int[] a = new int[n];
      int[] cnt = new int[2];
      cnt[0] = n / 2;
      cnt[1] = n - cnt[0];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();

      }
      int[][][][] dp = new int[n + 1][n + 1][n + 1][2];
      int inf = (int) 1e9;
      for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
          for (int k = 0; k < n + 1; k++) {
            Arrays.fill(dp[i][j][k], inf);
          }
        }
      }
      dp[0][0][0][0] = dp[0][0][0][1] = 0;

      for (int i = 1; i <= n; i++) {
        if (a[i - 1] == 0 || a[i - 1] % 2 == 1) {
          for (int j = 0; j < i; j++) {
            int k = i - j;
            dp[i][j][k][1] = Math.min(dp[i - 1][j][k - 1][1], dp[i - 1][j][k - 1][0] + 1);
          }
        }

        if (a[i - 1] == 0 || a[i - 1] % 2 == 0) {
          for (int j = 1; j <= i; j++) {
            int k = i - j;
            dp[i][j][k][0] = Math.min(dp[i - 1][j - 1][k][0], dp[i - 1][j - 1][k][1] + 1);
          }
        }

      }
      out.println(Math.min(dp[n][cnt[0]][cnt[1]][0], dp[n][cnt[0]][cnt[1]][1]));
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
        throw new UnknownError();
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new UnknownError();
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
          throw new UnknownError();
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

