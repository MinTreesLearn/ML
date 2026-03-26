import jdk.dynalink.beans.StaticClass;

import java.util.*;
import java.io.*;

public class Hyperset {
    PrintWriter out;
    StringTokenizer st;
    BufferedReader br;
    final int imax = Integer.MAX_VALUE, imin = Integer.MIN_VALUE;
    final int mod = 1000000007;

    void solve() throws Exception {
        int tt = 1;
//        t = ni();
        // n<= 1500, k<= 30
        //no of ways to select three cards that form a set.
        for (int ii = 0; ii < tt; ii++) {
            int n = ni(), k = ni();
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) arr[i] = ns();

            Map<String, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) map.put(arr[i], map.getOrDefault(arr[i], 0)+ 1);

            long ans= 0l;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    char[] find= new char[k];
                    for (int l = 0; l < k; l++) {
                        if(arr[i].charAt(l)== arr[j].charAt(l)) find[l]= arr[i].charAt(l);
                        else find[l]= help(arr[i].charAt(l), arr[j].charAt(l));
                    }

                    map.put(arr[i], map.get(arr[i])-1);
                    map.put(arr[j], map.get(arr[j])-1);
                    ans+= map.getOrDefault(new String(find), 0);
                    map.put(arr[i], map.get(arr[i])+1);
                    map.put(arr[j], map.get(arr[j])+1);
                }
            }

            out.println(ans/3);
        }
    }

    private char help(char a, char b) {
        return a!= 'S' && b!= 'S'? 'S': a!= 'E' && b!= 'E'? 'E': 'T';
    }

    public static void main(String[] args) throws Exception {
        new Hyperset().run();
    }

    void run() throws Exception {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File file = new File("./input.txt");
            br = new BufferedReader(new FileReader(file));
            out = new PrintWriter("./output.txt");
        } else {
            out = new PrintWriter(System.out);
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        long ss = System.currentTimeMillis();
        st = new StringTokenizer("");
        while (true) {
            try {
                solve();
            } catch (Exception e) {
                e.printStackTrace(out);
            } catch (StackOverflowError e) {
                e.printStackTrace(out);
            }

            String s = br.readLine();
            if (s == null) break;
            else st = new StringTokenizer(s);
        }
        //out.println(System.currentTimeMillis()-ss+"ms");
        out.flush();
    }

    void read() throws Exception {
        st = new StringTokenizer(br.readLine());
    }

    int ni() throws Exception {
        if (!st.hasMoreTokens()) read();
        return Integer.parseInt(st.nextToken());
    }

    char nc() throws Exception {
        if (!st.hasMoreTokens()) read();
        return st.nextToken().charAt(0);
    }

    String nw() throws Exception {
        if (!st.hasMoreTokens()) read();
        return st.nextToken();
    }

    long nl() throws Exception {
        if (!st.hasMoreTokens()) read();
        return Long.parseLong(st.nextToken());
    }

    int[] ni(int n) throws Exception {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) ret[i] = ni();
        return ret;
    }

    long[] nl(int n) throws Exception {
        long[] ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = nl();
        return ret;
    }

    double nd() throws Exception {
        if (!st.hasMoreTokens()) read();
        return Double.parseDouble(st.nextToken());
    }

    String ns() throws Exception {
        String s = br.readLine();
        return s.length() == 0 ? br.readLine() : s;
    }

    void print(int[] arr) {
        for (int i : arr) out.print(i + " ");
        out.println();
    }

    void print(long[] arr) {
        for (long i : arr) out.print(i + " ");
        out.println();
    }

    void print(int[][] arr) {
        for (int[] i : arr) {
            for (int j : i) out.print(j + " ");
            out.println();
        }
    }

    void print(long[][] arr) {
        for (long[] i : arr) {
            for (long j : i) out.print(j + " ");
            out.println();
        }
    }

    long add(long a, long b) {
        if (a + b >= mod) return (a + b) - mod;
        else return a + b >= 0 ? a + b : a + b + mod;
    }

    long mul(long a, long b) {
        return (a * b) % mod;
    }

    void print(boolean b) {
        if (b) out.println("YES");
        else out.println("NO");
    }

    long binExp(long base, long power) {
        long res = 1l;
        while (power != 0) {
            if ((power & 1) == 1) res = mul(res, base);
            base = mul(base, base);
            power >>= 1;
        }
        return res;
    }

    long gcd(long a, long b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    // strictly smaller on left
    void stack_l(int[] arr, int[] left) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) stack.pop();
            if (stack.isEmpty()) left[i] = -1;
            else left[i] = stack.peek();
            stack.push(i);
        }
    }

    // strictly smaller on right
    void stack_r(int[] arr, int[] right) {
        Stack<Integer> stack = new Stack<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) stack.pop();
            if (stack.isEmpty()) right[i] = arr.length;
            else right[i] = stack.peek();
            stack.push(i);
        }
    }

    private void sort(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for (int i : arr) list.add(i);
        Collections.sort(list);
        for (int i = 0; i < arr.length; i++) arr[i] = list.get(i);
    }
}