import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

public class ArraySharpening {
    public static void main(String[] args) {
        ASSolution assolution = new ASSolution();
        assolution.solve();
    }
}

class ASSolution {

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
                throw new RuntimeException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String readString() {
            final StringBuilder stringBuilder = new StringBuilder();
            int c = read();
            while (isSpaceChar(c))
                c = read();
            do {
                stringBuilder.append((char) c);
                c = read();
            } while (!isSpaceChar(c));
            return stringBuilder.toString();
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }

    void solve() {
        var out = new PrintWriter(System.out);
        var ir = new InputReader(System.in);

        int t = ir.readInt();
        while (t-- > 0) {
            int n = ir.readInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = ir.readInt();

            int front = -1, back = n;
            for (int i = 0, j = n - 1; i < n; i++, j--) {
                if (arr[i] >= i)
                    front++;
                else
                    break;
            }
            for(int j = n - 1, i = 0; j >= 0; j--, i++) {
				if (arr[j] >= i)
                    back--;
                else
                    break;
			}
			
			if (front >= back)
                out.println("YES");
            else
                out.println("NO");
        }

        out.close();
    }
}
