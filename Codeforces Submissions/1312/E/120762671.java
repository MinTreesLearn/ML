import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.function.BiFunction;
import java.util.function.Function;
 
public class Main {
  int a[];
  int n;
  int ddp[][];

  int getValue(int l, int r) {
    if(ddp[l][r] != 0) {
      return ddp[l][r];
    }

    if(l==r) {
      return a[l];
    }

    for(int i = l; i < r; i++) {
      int x1 = getValue(l, i);
      int x2 = getValue(i+1, r);
      if(x1 == x2 && x1 != -1) {
        ddp[l][r] = x1 +1;
        return x1 + 1;
      }
    }
    ddp[l][r] = -1;
    return -1;
  }

  void solve() {
    n = in.nextInt();
    ddp = new int[n][n];
    a = new int[n];
    for(int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
   
    int dp[] = new int[n];

    dp[0] = 1;
    for(int i = 1; i < n; i++) {
      dp[i] = Integer.MAX_VALUE;
      for(int l = 0; l <= i ; l++) {
        int x = getValue(l, i);
        if(x == -1) {
          continue;
        }

        x = 1;
        if (l > 0) {
          x += dp[l-1];
        }
        dp[i] = Integer.min(dp[i], x);

      }
    }
    out(dp[n-1]);


  }
    
    public static void main(String[] args)
    {
      new Main().solve();//.multiple();
    }
    
    final static  FastReader in = new FastReader();
    private void multiple() {
      int t = in.nextInt();
      for(; t >0; t--) {
        solve();
      }
    }
    
    private <T> void out(T s) {
      System.out.println(s);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}