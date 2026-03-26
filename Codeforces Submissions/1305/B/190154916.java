import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter o = new PrintWriter(System.out);
    var s = inp(f,false);
    var pq = new PriorityQueue<Integer>(Collections.reverseOrder());
    int n = s.length();
    for(int i=0;i<n;++i){
      if(s.charAt(i)==')'){
        pq.add(i);
      }
    }
    var ans = new ArrayList<Integer>();
    for(int i=0;i<n;++i){
      if(s.charAt(i)=='('){
        if(pq.size()>0&&pq.peek()>i){
          ans.add(i+1);
          ans.add(pq.poll()+1);
        }
      }
    }
    Collections.sort(ans);
    if(ans.size()>0){
      out(o,"1\n"+ans.size()+"\n",true);
      for(var i:ans){
        out(o,i+" ",true);
      }
      out(o,"\n",true);
    }else {
      out(o,"0\n",true);
    }
    o.close();
  }

  public static long gcd(long a, long b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }

  public static long lcm(long a, long b) {
    long gcd = gcd(a, b);
    return (a * b) / gcd;
  }

  public static int[] inp(BufferedReader f, int n) {
    try {
      StringTokenizer st = new StringTokenizer(f.readLine());
      int[] out = new int[n];
      for (int i = 0; i < n; ++i)
        out[i] = Integer.parseInt(st.nextToken());
      return out;
    } catch (Exception e) {
      return new int[] { 0, 0 };
    }
  }

  public static String inp(BufferedReader f, boolean b) {
    try {
      return f.readLine();
    } catch (Exception e) {
      return "";
    }
  }

  public static void out(PrintWriter out, String s, boolean chk) {
    if (!chk)
      out.println(s);
    else
      out.print(s);
  }

  public static void nl() {
    System.out.print("\n");
  }

  public static void out(PrintWriter out, int[] a) {
    for (int i = 0; i < a.length; ++i)
      out.print(a[i] + " ");
    out.print("\n");
  }

  public static void out(PrintWriter out, long[] a) {
    for (int i = 0; i < a.length; ++i)
      out.print(a[i] + " ");
    out.print("\n");
  }

  public static void out(PrintWriter out, int n) {
    out.println(n);
  }

  public static void out(PrintWriter out, long n) {
    out.println(n);
  }

  public static void sort(int[] a) {
    int n = a.length;
    ArrayList<Integer> b = new ArrayList<Integer>();
    for (int i : a)
      b.add(i);
    Collections.sort(b);
    for (int i = 0; i < n; ++i) {
      a[i] = b.get(i);
    }
  }

  public static int lower_bound(int[] a, int n, int tar) {
    int k = -1;
    for (int b = n / 2; b >= 1; b /= 2)
      while (k + b < n && a[k + b] < tar)
        k += b;
    return k + 1;
  }

  public static int upper_bound(ArrayList<Integer> a, int n, int tar) {
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2)
      while (k + b < n && a.get(k + b) <= tar)
        k += b;
    return k;
  }

  static class Pair {
    int a;
    int b;

    Pair(int a, int b) {
      this.a = a;
      this.b = b;
    }

    public int a() {
      return b;
    }

    public int b() {
      return a;
    }

    public void b(int nv) {
      b = nv;
    }

    public void a(int nk) {
      a = nk;
    }
  }
}