import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static int mod = (int) Math.pow(10, 9) + 7;
  public static void main(String[] args) {
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter o = new PrintWriter(System.out);
    long n = inplongarray(f,1)[0];
    var factors = new ArrayList<Long>();
    for(long i=1;i*i<=n;i+=(long) 1){
      if(n%i==0){
        factors.add(i);factors.add(n/i);
      }
    }
    Collections.sort(factors);
    int num = factors.size();
    int l = num/2-1,r=num/2;
    while(lcm(factors.get(l),factors.get(r))!=n){
      --l;++r;
    }
    out(o,factors.get(l)+" "+factors.get(r),false);
    o.close();
  }
  public static int logg2(int n) {
    return (int) (Math.log((double) n) / Math.log((double) 2));
  }
  public static long gcd(long a, long b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
  public static String LCS(String str1, String str2, int p, int q) {  
      
        // create a matrix which act as a table for LCS  
        int[][] tableForLCS = new int[p + 1][q + 1];  
  
        // fill the table in the bottom up way  
        for (int i = 0; i <= p; i++) {  
            for (int j = 0; j <= q; j++) {  
                if (i == 0 || j == 0)  
                    tableForLCS[i][j] = 0;  // Fill each cell corresponding to first row and first column with 0  
                else if (str1.charAt(i - 1) == str2.charAt(j - 1))  
                    tableForLCS[i][j] = tableForLCS[i - 1][j - 1] + 1;  // add 1 in the cell of the previous row and column and fill the current cell with it   
                else  
                    tableForLCS[i][j] = Math.max(tableForLCS[i - 1][j], tableForLCS[i][j - 1]); //find the maximum value from the cell of the previous row and current column and the cell of the current row and previous column    
            }  
        }  
      
        int index = tableForLCS[p][q];  
        int temp = index;  
  
        char[] longestCommonSubsequence = new char[index + 1];  
        longestCommonSubsequence[index] = '\0';  
  
        int i = p, j = q;  
        String lcs ="";  
        while (i > 0 && j > 0) {  
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {  
                  
                longestCommonSubsequence[index - 1] = str1.charAt(i - 1);  
                i--;  
                j--;  
                index--;  
            }  
            else if (tableForLCS[i - 1][j] > tableForLCS[i][j - 1])  
                i--;  
            else  
                j--;  
        }  
          
        for (int k = 0; k <= temp; k++)  
            lcs = lcs + longestCommonSubsequence[k];  
              
        return lcs;  
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
  public static long[] inplongarray(BufferedReader f, int n) {
    try {
      StringTokenizer st = new StringTokenizer(f.readLine());
      long[] out = new long[n];
      for (int i = 0; i < n; ++i)
        out[i] = Long.parseLong(st.nextToken());
      return out;
    } catch (Exception e) {
      return new long[] { 0, 0 };
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

  public static void pow(int a, int b, int mod) {
    BigInteger big1, big2, exp, result;
    // initialize all BigInteger objects
    big1 = new BigInteger(Integer.toString(a));
    big2 = new BigInteger(Integer.toString(mod));
    exp = new BigInteger(Integer.toString(b));
    // perform modPow operation on big1 using big2 and exp
    result = big1.modPow(exp, big2);
    String str = "" + result;
    System.out.println(str);
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
// Arrays.sort(a, new Comparator<int[]>() {
// public int compare(int[] frst, int[] scnd) {
// if (frst[2] > scnd[2]) {
// return -1;
// } else
// return 1;
// }
// });