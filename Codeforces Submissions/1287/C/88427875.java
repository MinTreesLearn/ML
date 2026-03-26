//   package com.company;
import javax.swing.plaf.IconUIResource;
import java.util.*;
import java.io.*;
import java.lang.*;
/*
 ** @author jigar_nainuji
 */
public class Main{

    public static void main(String args[]){
        PrintWriter out=new PrintWriter(System.out);
        InputReader in=new InputReader(System.in);
        TASK solver = new TASK();
//        int t = in.nextInt();
        int t=1;
        for(int i=0;i<t;i++)
        {
            solver.solve(in,out,i);
        }
        out.close();
    }
    static class TASK {

        static int mod = 1000000007;
        void solve(InputReader in, PrintWriter out, int testNumber) {
          int n = in.nextInt();
          int a[] = new int[n];
          int o=0,e=0;
          for(int i=0;i<n;i++)
          {
              a[i]=in.nextInt();
              if(a[i]%2==0 && a[i]!=0)
                  e++;
              else if(a[i]%2==1 && a[i]!=0)
                  o++;
          }
          ArrayList<Integer> a1 = new ArrayList<>();
          ArrayList<Integer> a2 = new ArrayList<>();
          ArrayList<Integer> a3 = new ArrayList<>();
          int pre0=0,pre1=0,last0=0,last1=0,i1=n-1,i2=0,count=0;
          for(int i=0;i<n;i++)
          {
              if(a[i]!=0)
              {
                  i1=i;
                  if(a[i]%2==0)
                      pre0=count;
                  else
                      pre1=count;
                  break;
              }
              else
                  count++;
          }
          count=0;
          for(int i=n-1;i>=0;i--)
          {
              if(a[i]!=0)
              {
                  i2=i;
                  if(a[i]%2==0)
                      last0=count;
                  else
                      last1=count;
                  break;
              }
              else
                  count++;
          }
          if(i2<i1)
          {
              System.out.println(1);
              return;
          }
          int f=a[i1],l;
          count=0;
          for(int i=i1;i<=i2;i++)
          {
              if(a[i]!=0)
              {
                  if(count==0)
                  {
                      f=a[i];
                      continue;
                  }
                  if(f%2==0 && a[i]%2==0)
                  {
                      a2.add(count);
                      count=0;
                      f=a[i];
                      continue;
                  }
                  if(f%2==1 && a[i]%2==1)
                  {
                      a1.add(count);
                      f=a[i];
                      count=0;
                      continue;
                  }
                  a3.add(count);
                  f=a[i];
                  count=0;


              }
              else
                  count++;

          }
          int odd=n/2-o,even=n/2-e;
          if(n%2==1)
              odd++;
          Collections.sort(a1);
          Collections.sort(a2);
          int ans=0;
          for(int i=0;i<a1.size();i++)
          {
              int x = a1.get(i);
              if(x<=odd)
                  odd-=x;
              else
                  ans+=2;

          }
            for(int i=0;i<a2.size();i++)
            {
                int x = a2.get(i);
                if(x<=even)
                    even-=x;
                else
                    ans+=2;

            }
            if(odd<pre1 && pre1!=0) {
                ans++;
            }
            if(odd>=pre1)
                odd-=pre1;
            if(even<pre0 && pre0!=0) {
                ans++;
            }
            if(even>=pre0)
                even-=pre0;
            if(odd<last1 && last1!=0) {
                ans++;
            }
            if(even<last0 && last0!=0) {
                ans++;
            }
            ans+=a3.size();
            for(int i=1;i<n;i++)
            {
                if(a[i]!=0 && a[i-1]!=0 && a[i]%2!=a[i-1]%2)
                    ans++;

            }
            System.out.println(ans);









        }
    }
    static class Maths{
        static long gcd(long a, long b) {
            if (a == 0)
                return b;
            return gcd(b % a, a);
        }

        public  static long lcm(long a, long b)
        {
            return (a*b)/gcd(a, b);
        }

        public static long factorial(int n){
            long fact = 1;
            for(int i=1;i<=n;i++){
                fact *= i;
            }
            return fact;
        }
    }
    static class pair{
        int a;
        int b;
        pair(int a,int b)
        {
            this.a=a;
            this.b=b;
        }
    }
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String nextLine() {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public int nextInt() {
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
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public long nextLong() {
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
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));

            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}