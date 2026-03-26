import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
    FAtakaNaKrasnoeKorolevstvo solver = new FAtakaNaKrasnoeKorolevstvo();
    solver.solve(1, in, out);
    out.close();
  }

  static class FAtakaNaKrasnoeKorolevstvo {
    Map<IntIntPair, Integer> g;
    int x;
    int y;
    int z;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
      if (false) {
        for (x = 1; x <= 5; x++) {
          for (y = 1; y <= 5; y++) {
            for (z = 1; z <= 5; z++) {
              int c = findCycleLen(x, y, z);
              System.err.println(x + " " + y + " " + z + " " + c);
            }
          }
        }
        return;
      }
      if (false) {
        test();
        return;
      }
      int t = in.readInt();
      while (t-- > 0) {
        int n = in.readInt();
        int x = in.readInt();
        int y = in.readInt();
        int z = in.readInt();
        int cycle = findCycleLen(x, y, z);
//      System.err.println(checkCycleLen(cycle, 100_000));
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
          long X = in.readLong();
          if (X > 1000) {
            X = ((X - 1000) % cycle) + 1000;
          }
          a[i] = (int) X;
        }
        int fullXor = 0;
        for (int hp : a) {
          fullXor ^= getGrundy(hp, 0);
        }
        int answer = 0;
        for (int hp : a) {
          if ((fullXor ^ getGrundy(hp, 0) ^ getGrundy(hp - x, 0)) == 0) {
            answer++;
          }
          if ((fullXor ^ getGrundy(hp, 0) ^ getGrundy(hp - y, 1)) == 0) {
            answer++;
          }
          if ((fullXor ^ getGrundy(hp, 0) ^ getGrundy(hp - z, 2)) == 0) {
            answer++;
          }
        }
//      out.printLine(answer, checkCycleLen(cycle, 100_000));
        out.printLine(answer);
      }
    }

    void test() {
      x = 1;
      y = 2;
      z = 3;
      test1();
    }

    void test1() {
      g = new HashMap<>();
      for (int hp = 0; hp <= 100; hp++) {
        System.err.print(hp);
        for (int last = 0; last <= 2; last++) {
          System.err.print(" " + getGrundy(hp, last));
        }
        System.err.println();
      }
    }

    int getGrundy(int hp, int last) {
      if (hp <= 0) {
        return 0;
      }
      IntIntPair p = IntIntPair.makePair(hp, last);
      if (g.containsKey(p)) {
        return g.get(p);
      }
      Set<Integer> res = new HashSet<>();
      res.add(getGrundy(hp - x, 0));
      if (last != 1) {
        res.add(getGrundy(hp - y, 1));
      }
      if (last != 2) {
        res.add(getGrundy(hp - z, 2));
      }
      for (int r = 0; ; r++) {
        if (!res.contains(r)) {
          g.put(p, r);
          return r;
        }
      }
    }

    int findCycleLen(int x, int y, int z) {
      this.x = x;
      this.y = y;
      this.z = z;
      this.g = new HashMap<>();
      for (int cycleLen = 1; ; cycleLen++) {
        if (checkCycleLen(cycleLen, 1000)) {
          return cycleLen;
        }
      }
    }

    boolean checkCycleLen(int cycleLen, int iters) {
      for (int hp = 1000; hp < 1000 + iters; hp++) {
        for (int t = 0; t < 3; t++) {
          if (getGrundy(hp, t) != getGrundy(hp - cycleLen, t)) {
            return false;
          }
        }
      }
      return true;
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

    public void printLine(int i) {
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

    public long readLong() {
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

  static class IntIntPair implements Comparable<IntIntPair> {
    public final int first;
    public final int second;

    public static IntIntPair makePair(int first, int second) {
      return new IntIntPair(first, second);
    }

    public IntIntPair(int first, int second) {
      this.first = first;
      this.second = second;
    }

    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      IntIntPair pair = (IntIntPair) o;

      return first == pair.first && second == pair.second;
    }

    public int hashCode() {
      int result = first;
      result = 31 * result + second;
      return result;
    }

    public String toString() {
      return "(" + first + "," + second + ")";
    }

    public int compareTo(IntIntPair o) {
      int value = Integer.compare(first, o.first);
      if (value != 0) {
        return value;
      }
      return Integer.compare(second, o.second);
    }

  }
}

