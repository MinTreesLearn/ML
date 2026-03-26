import java.util.*;
import java.io.*;

public class cf_31 {
    public static void main(String[] args) {
        new Solution().solve();
    }
}

class Solution {
    public void solve() {
        FastScanner fs = new FastScanner();
        int tests = fs.nextInt();
        while (tests > 0) {
            tests--;
            int n = fs.nextInt(), m = fs.nextInt(), k = fs.nextInt();
            int[] arr = fs.readIntArray(n);
            if (k >= m-1) {
                k = m-1;
            }
            int max = Integer.MIN_VALUE;
            for (int i=k; i >= 0; i--) {
                int j=k-i;
                int d =m-1-k;
                int min = Integer.MAX_VALUE;
                for (int l=d; l >=0; l--) {
                    int t = d-l;
                    min = Math.min(min, Math.max(arr[l+i], arr[n-1-(j+t)]));
                }
                max = Math.max(max, min);
            }
            System.out.println(max);
        }
    }
}

class FastScanner {
    private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer st = new StringTokenizer("");
    
    // Below would return next string (delimited by space or new line)
    public String next() {
        while (!st.hasMoreTokens())
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        return st.nextToken();
    }

    // Below would return entire string in the line (including spaces)
    public String nextLineStr() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
    
    public int[] readIntArray(int n) {
        int[] arr = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }    
    
    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public float nextFloat() {
        return Float.parseFloat(next());
    }    
}