
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.*;
import java.util.StringTokenizer;

public class RemoveAdjacent {

    static class Pair {
        int f;
        int s; //

        Pair() {
        }

        Pair(int f, int s) {
            this.f = f;
            this.s = s;
        }
    }

    static class Fast {
        BufferedReader br;
        StringTokenizer st;

        public Fast() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int[] readArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] readArray1(int n) {
            long a[] = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine().trim();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    /*  static long noOfDivisor(long a)
      {
          long count=0;
          long t=a;
          for(long i=1;i<=(int)Math.sqrt(a);i++)
          {
              if(a%i==0)
                  count+=2;
          }
          if(a==((long)Math.sqrt(a)*(long)Math.sqrt(a)))
          {
              count--;
          }
              return count;
      }*/
    static boolean isPrime(long a) {
        for (long i = 2; i <= (long) Math.sqrt(a); i++) {
            if (a % i == 0)
                return false;
        }
        return true;
    }

    static void primeFact(int n) {
        int temp = n;
        HashMap<Integer, Integer> h = new HashMap<>();
        for (int i = 2; i * i <= n; i++) {
            if (temp % i == 0) {
                int c = 0;
                while (temp % i == 0) {
                    c++;
                    temp /= i;
                }
                h.put(i, c);
            }
        }
        if (temp != 1)
            h.put(temp, 1);

    }

    static void reverseArray(int a[]) {
        int n = a.length;
        for (int i = 0; i < n / 2; i++) {
            a[i] = a[i] ^ a[n - i - 1];
            a[n - i - 1] = a[i] ^ a[n - i - 1];
            a[i] = a[i] ^ a[n - i - 1];

        }
    }

    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a) l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++) a[i] = l.get(i);
    }

    static void sort(long[] a) {
        ArrayList<Long> l = new ArrayList<>();
        for (long i : a) l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++) a[i] = l.get(i);
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static int[] constructST(int arr[], int n) {
        // Add your code here
        int st[] = new int[4 * n];
        build(arr, 0, n - 1, 0, st);
        return st;
    }

    static int build(int arr[], int l, int r, int idx, int st[]) {
        if (l == r) {
            return st[idx] = arr[l] & 1;
        }
        int mid = (l + r) / 2;
        int p1 = build(arr, l, mid, 2 * idx + 1, st);
        int p2 = build(arr, mid + 1, r, 2 * idx + 2, st);
        if (p1 == p2 && p1 != -1)
            return st[idx] = p1 & p2;
        else if (p1 == -1 || p2 == -1)
            return st[idx] = -1;
        else
            return st[idx] = -1;

    }


    /* The functions returns the
      min element in the range
      from l and r */
    public static int RMQ(int st[], int n, int l, int r) {
        // Add your code here
        return solve(st, l, r, 0, n - 1, 0);
    }

    static int solve(int st[], int l, int r, int low1, int high1, int idx) {
        if (low1 >= l && high1 <= r)//lies    // we need to find min number in range [l,r]   low,high is range in segment tree.. consider the first case
            return st[idx];
        if (high1 < l || low1 > r)//not lie
            return Integer.MAX_VALUE;
        int mid = (low1 + high1) / 2;
        int left = solve(st, l, r, low1, mid, 2 * idx + 1);
        int right = solve(st, l, r, mid + 1, high1, 2 * idx + 2);
        if (left == right && left != -1 && left != Integer.MAX_VALUE)
            return left;
        else if (left == -1 || right == -1)
            return -1;
        else if (left != right && left != Integer.MAX_VALUE && right != Integer.MAX_VALUE)
            return -1;
        else if (left == Integer.MAX_VALUE)
            return right;
        else
            return left;
    }

    static int rec(char s[], int i, int prev, int next, int n) {
        if (i == n) {
            return 0;
        }
        // if(dp[i][prev][next]!=-1)
        //      return dp[i][prev][next];
        int f = 0;
        if (prev != -1 && s[prev] - s[i] == -1)
            f = 1;
        else if (next != n && s[next] - s[i] == -1)
            f = 1;
        int l = Integer.MIN_VALUE;
        int r = Integer.MIN_VALUE;
        if (f == 1) {
            //  int ans=1+rec(s,next,prev,next+1,n);
            if (prev != -1) {
                int t = prev - 1;
                while (t != -1 && s[t] != s[prev])
                    t--;
                l = 1 + rec(s, prev, t, next, n);
            } else
                l = 1 + rec(s, next, prev, next + 1, n);
        }
        r = rec(s, next, i, next + 1, n);
        return max(l, r);
    }

    static int rec(char s[], int i, int prev, int next, int n, int dp[][][]) {
        if (i > n) {
            return 0;
        }
        if (dp[i][prev][next] != -1)
            return dp[i][prev][next];
        int f = 0;
        if (prev != 0 && s[prev - 1] - s[i - 1] == -1)
            f = 1;
        else if (next != n + 1 && s[next - 1] - s[i - 1] == -1)
            f = 1;
        int l = Integer.MIN_VALUE;
        int r = Integer.MIN_VALUE;
        if (f == 1) {
            //  int ans=1+rec(s,next,prev,next+1,n);
            if (prev != 0)
                l = 1 + rec(s, prev, prev - 1, next, n, dp);
            else
                l = 1 + rec(s, next, prev, next + 1, n, dp);
        }
        r = rec(s, next, i, next + 1, n, dp);
        return dp[i][prev][next] = max(l, r);
    }

    /*     public static void main(String args[]) throws IOException {
             Fast sc = new Fast();
             PrintWriter out = new PrintWriter(System.out);
             int n=sc.nextInt();
             char s[]=sc.next().toCharArray();
             int dp[][][]=new int[n+1][n+1][n+2];
             for(int row[][]:dp)
             {
                 for(int row1[]:row)
                     Arrays.fill(row1,-1);
             }
            // int ans=rec(s,1,0,2,n,dp);
             int ans=rec(s,0,-1,1,n);

         out.println(ans);
             out.close();
         }
     }*/
    public static void main(String args[]) throws IOException {
        Fast sc = new Fast();
        PrintWriter out = new PrintWriter(System.out);
        int n = sc.nextInt();
        StringBuffer s = new StringBuffer(sc.next());
        for (int i = 0; i < n; i++) {
            int id = -1;
            int le = -1;int l1=s.length();
            for (int j = 0; j < l1; j++)
            {
                char ch = s.charAt(j);
                if ((j!=l1-1 && ch-s.charAt(j + 1) == 1 )||(j!=0&& ch - s.charAt(j - 1) == 1) )
                {
                    if (le < ch)
                    {
                        le = ch;
                        id = j;
                    }
                }
            }
            if (id == -1)
                break;
            s.delete(id, id + 1);
        //    out.println(s);
        }
     //   out.println(s);
        out.println(n - s.length());
        out.close();
    }
}



/*
100
aaaaaabbcccccccddffffhhhhhhhhiiiiiikkkkkkkkmmmmmmooooooopppprrrrrrrrrttttttvvvvvvvvvvvvxxxxxxxzzzzzz
 p-4 i-6 d-2 c-7 b-2
 a-6 f-4
 */
