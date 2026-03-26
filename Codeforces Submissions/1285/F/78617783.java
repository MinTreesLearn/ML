import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;


public class Solution {
    static ArrayList<Integer>[] pfactors, factors;
    static int sieve[];
    static int count[];
    static long ans;

    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static long lcm(long a, long b, long g) {
        long z = gcd(a, b);
        ans = Math.max(ans, ((a * b) / z) * g);
        if (z == 1)
            return 1;
        return 0;
    }

    static int get(int x) {
        int val = 0;
        int l = pfactors[x].size();
        for (int i = 0; i < (1 << l); i++) {
            int p = 1, c = 0;
            for (int j = 0; j < l; j++) {
                if ((i & (1 << j)) > 0) {
                    p = p * pfactors[x].get(j);
                    c++;
                }
            }
            if (c % 2 == 0)
                val = val + count[p];
            else
                val = val - count[p];
        }
        return val;
    }

    static void add(int x, int v) {
        for (int z : factors[x]) {
            count[z] += v;
        }
    }

    public static void main(String args[]) throws IOException {
        FastReader in = new FastReader(System.in);
        int i, j, MN = 100000;
        sieve = new int[MN + 1];
        pfactors = new ArrayList[MN + 1];
        factors = new ArrayList[MN + 1];
        for (i = 1; i <= MN; i++) {
            pfactors[i] = new ArrayList<>();
            factors[i] = new ArrayList<>();
        }
        sieve[1] = 1;
        for (i = 1; i <= MN; i++) {
            if (sieve[i] == 0) {
                for (j = i; j <= MN; j += i) {
                    sieve[j] = i;
                    factors[j].add(i);
                }

            } else {
                for (j = i; j <= MN; j += i) {
                    factors[j].add(i);
                }
            }
        }
        for (i = 2; i <= MN; i++) {
            int temp = i;
            while (temp != 1) {
                int x = sieve[temp];
                pfactors[i].add(x);
                while (temp % x == 0)
                    temp = temp / x;
            }
        }
        boolean pre[] = new boolean[MN + 1];
        ans = 0;
        int n = in.nextInt();
        for (i = 0; i < n; i++) {
            int x = in.nextInt();
            ans = Math.max(ans, x);
            pre[x] = true;
        }

        count = new int[MN + 1];
        for (int gcd = 1; gcd <= MN; gcd++) {
            ArrayList<Integer> list = new ArrayList<>();
            for (j = gcd; j <= MN; j += gcd) {
                if (pre[j]) {
                    list.add(j / gcd);
                }
            }
            Stack<Integer> st = new Stack<>();
            Collections.sort(list, Collections.reverseOrder());
            for (int x : list) {
                int z = get(x);
                if (z == 0) {
                    st.add(x);
                    add(x, 1);
                } else {
                    while (z != 0) {
                        int y = st.pop();
                        z -= lcm(x, y, gcd);
                        add(y, -1);
                    }

                }
            }
            while (!st.isEmpty()) {
                add(st.pop(), -1);
            }

        }


        System.out.println(ans);

    }
}

class FastReader {

    byte[] buf = new byte[2048];
    int index, total;
    InputStream in;

    FastReader(InputStream is) {
        in = is;
    }

    int scan() throws IOException {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0) {
                return -1;
            }
        }
        return buf[index++];
    }

    String next() throws IOException {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan()) {
            sb.append((char) c);
        }
        return sb.toString();
    }

    int nextInt() throws IOException {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }

    long nextLong() throws IOException {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+') {
            c = scan();
        }
        for (; c >= '0' && c <= '9'; c = scan()) {
            val = (val << 3) + (val << 1) + (c & 15);
        }
        return neg ? -val : val;
    }
}
