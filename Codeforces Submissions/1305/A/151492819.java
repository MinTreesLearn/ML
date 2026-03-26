import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

public class CP {

    static class FastScanner {

        BufferedReader br;
        StringTokenizer st;

        FastScanner()  {

            br=new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {

            while(st==null || !st.hasMoreTokens()) {

                try {

                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {

                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        String nextLine() {

            String str="";

            try {

                str=br.readLine();
            } catch (IOException e) {

                e.printStackTrace();
            }

            return str;
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
    }

    static void ruffleSort(int[] a) {

        Random rnd=new Random();

        for(int i=0;i<=a.length-1;i++) {

            int temp=a[i];
            int rndPos=i+rnd.nextInt(a.length-i);
            a[i]=a[rndPos];
            a[rndPos]=temp;
        }
        Arrays.sort(a);
    }

    static void testCase(FastScanner sc) {

        long mod1=(long)1e9+7, mod2=998244353;
        long inf=(long)1e18+5;

        int n=sc.nextInt();
        ArrayList<Integer> a=new ArrayList<Integer>(), b=new ArrayList<Integer>();

        for(int i=0;i<=n-1;i++) {

            a.add(sc.nextInt());
        }

        for(int i=0;i<=n-1;i++) {

            b.add(sc.nextInt());
        }

        Collections.sort(a);
        Collections.sort(b);

        for(int val: a) {

            System.out.print(val+" ");
        }

        System.out.println();

        for(int val: b) {

            System.out.print(val+" ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        FastScanner sc=new FastScanner();

        boolean test=true;
        int t=1;

        if(test) {

            t=sc.nextInt();
        }

        for(int i=0;i<=t-1;i++) {

            testCase(sc);
        }
    }
}