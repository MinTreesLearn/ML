

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class StringModification {
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

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a < b ? a : b;
    }

    static long maxSum(int arr[], int n, int k) {
        long res = 0;
        for (int i = 0; i < k; i++)
            res += arr[i];


        long curr_sum = res;
        for (int i = k; i < n; i++) {
            curr_sum += arr[i] - arr[i - k];
            res = Math.max(res, curr_sum);
        }

        return res;
    }

    static boolean check(int n,int k,char s[],StringBuffer max[])
    {
        StringBuffer sa=new StringBuffer();
        for(int i=k-1;i<n;i++)
            sa.append(s[i]);
        if(((n-k)&1)==0)
        {
            for(int i=k-2;i>=0;i--)
                sa.append(s[i]);
        }
        else //ans==3
        {
            for(int i=0;i<k-1;i++)
                sa.append(s[i]);
        }
        if(sa.compareTo(max[0])<0) {
            max[0] = sa;
            return true;
        }

return false;
    }

    public static void main(String args[]) throws IOException {
        Fast sc = new Fast();
        PrintWriter out = new PrintWriter(System.out);
        int t1 = sc.nextInt();
        while (t1-- > 0) {
            int n = sc.nextInt();
            String s1 = sc.next();
            char s[] = s1.toCharArray();
            StringBuffer max[]=new StringBuffer[1];
            max[0]=new StringBuffer(s1);
            int ans1=1;
            for (int k = 2; k <= n; k++)
            {
                    if(check(n,k,s,max))
                    {
                        ans1=k;
                    }
            }
            out.println(max[0]);
              out.println(ans1);
        }
        out.close();
    }
}
      /*  public static void main(String args[]) throws IOException {
            Fast sc = new Fast();
            PrintWriter out = new PrintWriter(System.out);
            int t1 = sc.nextInt();
            while (t1-- > 0) {
                int n=sc.nextInt();
               String s1=sc.next();
               char s[]=s1.toCharArray();
               TreeMap<Integer, TreeSet<Integer>> tm=new TreeMap<>();
               for(int i=0;i<n;i++)
               {
                   char ch=s[i];
                   if(tm.get(ch-97)==null)
                   {
                       TreeSet<Integer> ts1=new TreeSet<>();
                       ts1.add(i);
                       tm.put(ch-97,ts1);
                   }
                   else
                   {
                       TreeSet ts1=tm.get(ch-97);
                       ts1.add(i); tm.put(ch-97,ts1);
                   }
               }

               TreeSet<Integer> ts1=null;
               for(Map.Entry<Integer,TreeSet<Integer>> en:tm.entrySet())
               {
                   ts1=en.getValue();
                   break;
               }


               if(ts1.size()==1)
               {
                   int ans=ts1.first()+1;
                   String sa="";
                   for(int i=ans-1;i<n;i++)
                       sa+=s[i];
                   if(((n-ans)&1)==0)
                   {
                       for(int i=ans-2;i>=0;i--)
                           sa+=s[i];
                   }
                   else //ans==3
                   {
                       for(int i=0;i<ans-1;i++)
                           sa+=s[i];
                   }
                   out.println(sa);
                   out.println(ans);
               }
            else
               {
              //     out.println(-1);
                   int ans=-1;
                   int comp=Integer.MAX_VALUE;
                   for(int ne:ts1)
                   {
                       if(ne!=0)
                       {
                         if(comp>s[ne-1])
                         {
                             comp=s[ne-1];
                             ans=ne+1;
                         }
                       }
                   }
                   String sa="";
                   for(int i=ans-1;i<n;i++)
                       sa+=s[i];
                   if(((n-ans)&1)==0)
                   {
                       for(int i=ans-2;i>=0;i--)
                           sa+=s[i];
                   }
                   else //ans==3
                   {
                       for(int i=0;i<ans-1;i++)
                           sa+=s[i];
                   }
                   if(sa.equals(s1))
                   {
                       out.println(sa);out.println(1);
                   }
                   else
                   {
                       out.println(sa);out.println(ans);
                   }
               }

            }
            out.close();
        }
    }
*/




