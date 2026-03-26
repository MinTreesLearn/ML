import java.io.*;
import java.util.Scanner;
import java.util.*;
 
public class Solution {
    static int mod = (int) 1e9 + 7;
    static Kattio io = new Kattio();
    static int h = (int) 1e5 * 2 + 2;
 
    public static void main(String[] args) {
        int n = io.nextInt();
        int[] arr = new int[n];
        boolean[] vis = new boolean[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = io.nextInt();
            vis[arr[i]] = true;
        }

        new Solution().solve(n, vis, arr);
        io.close();
    }
 
    public void solve(int n, boolean[] vis, int[] arr) {
        int odd = 0;
        int even = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (i % 2 == 0) even++;
                else odd++;
            }
        }
        int cur = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] == 0 || arr[i - 1] == 0) continue;
            if((arr[i] + arr[i - 1]) % 2 == 1) cur++;
        }

        List<int[]> blocks = new ArrayList();
        int cnt = 0;
        int l = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                if (i > 0 && arr[i - 1] != 0) {
                    l = arr[i - 1] % 2;
                }
                cnt++;
            } else {
                if (cnt == 0) continue;
                blocks.add(new int[]{cnt, l, arr[i] % 2});
                cnt = 0;
            }
        }
        if (cnt > 0) {
            blocks.add(new int[]{cnt, l, -1});
        }

        List<int[]> same = new ArrayList();
        List<int[]> edge = new ArrayList();

        for (int[] block : blocks) {
            if (block[1] == -1 || block[2] == -1) {
                int x = -1;
                if (block[1] != -1) x = block[1];
                else x = block[2];

                edge.add(new int[]{block[0], x});
            } else if ((block[1] + block[2]) % 2 == 0) {
                same.add(new int[]{block[0], block[1]});
            }
        }

        int ans = blocks.size() - edge.size() - same.size();
        same.sort((a, b) -> a[0] - b[0]);
        for (int[] f : same) {
            if (f[1] == 1) {
                if (odd >= f[0]) odd -= f[0];
                else ans += 2;
            } else {
                if (even >= f[0]) even -= f[0];
                else ans += 2;
            }
        }
        for (int[] f : edge) {
            if (f[1] == -1) {
                if (n != 1) ans++;
            } else if (f[1] == 1) {
                if (odd >= f[0]) {
                    odd -= f[0];
                } else ans++;
            } else {
                if (even >= f[0]) {
                    even -= f[0];
                } else ans++;
            }
        }
        io.println(ans + cur);
    }
 
    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
 
    public int countbit(long n) {
        int count = 0;
        for (int i = 0; i < 64; i++) {
            if (((1L << i) & n) != 0) count++;
        }
        return count;
    }
 
    public int firstbit(int n) {
        for (int i = 31; i >= 0; i--) {
            if (((1 << i) & n) != 0) return i;
        }
        return -1;
    }
}
 
 
class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    // 标准 IO
    public Kattio() { this(System.in, System.out); }
    public Kattio(InputStream i, OutputStream o) {
        super(o);
        r = new BufferedReader(new InputStreamReader(i));
    }
    // 文件 IO
    public Kattio(String intput, String output) throws IOException {
        super(output);
        r = new BufferedReader(new FileReader(intput));
    }
    // 在没有其他输入时返回 null
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(r.readLine());
            return st.nextToken();
        } catch (Exception e) {}
        return null;
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public long nextLong() { return Long.parseLong(next()); }
}