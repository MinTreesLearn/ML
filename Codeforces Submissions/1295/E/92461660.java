/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

import java.io.*;
import java.util.Arrays;

public class Main {
   private static long[] st, lazy;
   private static int n, h;

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

      n = Integer.parseInt(br.readLine());
      int[] p = new int[n], a = new int[n];
      String[] line = br.readLine().split(" ");
      for (int i = 0; i < n; ++i) {
         p[i] = Integer.parseInt(line[i]);
      }
      line = br.readLine().split(" ");
      for (int i = 0; i < n; ++i) {
         a[i] = Integer.parseInt(line[i]);
      }

      h = -1;
      for (int i = 1; i <= n; i <<= 1) {
         ++h;
      }
      st = new long[n << 1];
      lazy = new long[n];
      int[] indices = new int[n];
      for (int i = 0; i < n; ++i) {
         indices[p[i] - 1] = i;
         st[n + i] = st[n + i - 1] + a[i];
      }
      for (int i = n - 1; i > 0; --i) {
         st[i] = Math.min(st[i << 1], st[i << 1 | 1]);
      }
      int res = (int)query(0, n - 1);

      for (int i = 0; i < n; ++i) {
         int ind = indices[i];
         update(ind, n, -a[ind]);
         update(0, ind, a[ind]);
         res = (int)Math.min(query(0, n - 1), res);
      }

      bw.write(Integer.toString(res));
      bw.newLine();

      br.close();
      bw.close();
   }

   private static void apply(int pos, long val) {
      st[pos] += val;
      if (pos < n) {
         lazy[pos] += val;
      }
   }

   private static void build(int pos) {
      while (pos > 1) {
         pos >>= 1;
         st[pos] = Math.min(st[pos << 1], st[pos << 1 | 1]) + lazy[pos];
      }
   }

   private static void push(int pos) {
      for (int s = h; s > 0; --s) {
         int i = pos >> s;
         if (lazy[i] != 0) {
            apply(i << 1, lazy[i]);
            apply(i << 1 | 1, lazy[i]);
            lazy[i] = 0;
         }
      }
   }

   private static void update(int l, int r, long val) {
      l += n; r += n;
      for (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
         if ((l2 & 1) != 0) {
            apply(l2++, val);
         }
         if ((r2 & 1) != 0) {
            apply(--r2, val);
         }
      }
      build(l);
      build(r - 1);
   }

   private static long query(int l, int r) {
      l += n;
      r += n;
      push(l);
      push(r - 1);
      long res = Integer.MAX_VALUE;

      while (l < r) {
         if ((l & 1) != 0) {
            res = Math.min(res, st[l++]);
         }
         if ((r & 1) != 0) {
            res = Math.min(res, st[--r]);
         }
         l >>= 1;
         r >>= 1;
      }

      return res;
   }
}