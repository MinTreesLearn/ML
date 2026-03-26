import java.io.*;
import java.sql.Array;
import java.util.*;

public class Contest1 {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////                                                                                                               /////////
////////                                                                                                               /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMMMM      MMMMMM      OOO      OOO        SSSS   SSS     EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEE           MMMM MMM  MMM MMMM    OOO          OOO    SSSS       SSS   EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM  MMMMMM  MMMM   OOO            OOO   SSSS             EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM  OOO              OOO   SSSSSSS         EEEEE          /////////
////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO      SSSSSS       EEEEEEEEEEE    /////////
////////   HHHHHHHHHHHHHHHH  EEEEEEEEEEE     MMMM          MMMM  OOO              OOO         SSSSSSS   EEEEEEEEEEE    /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM   OOO            OOO              SSSS  EEEEE          /////////
////////   HHHH        HHHH  EEEEE           MMMM          MMMM    OOO          OOO     SSS       SSSS  EEEEE          /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM      OOO      OOO        SSS    SSSS    EEEEEEEEEEEEE  /////////
////////   HHHH        HHHH  EEEEEEEEEEEEE   MMMM          MMMM         OOOOOO             SSSSSSS      EEEEEEEEEEEEE  /////////
////////                                                                                                               /////////
////////                                                                                                               /////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    static long getnum(int[] a ,int val) {
        long sum = 0;
        for (int i = 0; i < a.length; i++) {
            int low = i + 1;
            int hi = a.length - 1;
            int a1 = -1, a2 = -1, a3 = -1, a4 = -1;
            while (low <= hi) {
                int mid = low + hi >> 1;
                if (a[mid] + a[i] >= 2 * val) {
                    hi = mid - 1;
                } else if (a[mid] + a[i] >= val) {
                    a1 = mid;
                    hi = mid - 1;
                } else low = mid + 1;
            }
            low = i + 1;
            hi = a.length - 1;
            while (low <= hi) {
                int mid = low + hi >> 1;
                if (a[mid] + a[i] >= 2 * val) {
                    hi = mid - 1;
                } else if (a[mid] + a[i] >= val) {
                    a2 = mid;
                    low = mid + 1;
                } else low = mid + 1;
            }
            low = i+1;
            hi = a.length - 1;
            while (low <= hi) {
                int mid = low + hi >> 1;
                if (a[mid] + a[i] >= 4 * val - 1) {
                    hi = mid - 1;
                } else if (a[mid] + a[i] >= 3 * val) {
                    a3 = mid;
                    hi = mid - 1;
                } else low = mid + 1;
            }
            low = i+1;
            hi = a.length - 1;
            while (low <= hi) {
                int mid = low + hi >> 1;
                if (a[mid] + a[i] >= 4 * val - 1) {
                    hi = mid - 1;
                } else if (a[mid] + a[i] >= 3 * val) {
                    a4 = mid;
                    low = mid + 1;
                } else low = mid + 1;
            }
            if (a1 != -1) {
                sum += a2 - a1 + 1;
            }
            if (a3 != -1) {
                sum += a4 - a3 + 1;
            }
        }
        return sum;
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[]a = new int[n];
        for (int i =0;i<n;i++)a[i]=sc.nextInt();
        int val=0;
        int[]ac= new int[n];
        for (int j =0;j<27;j++){
            int c = 1<<(j+1);
            for (int i =0;i<n;i++){
                ac[i]=a[i]%c;
            }
            suffle(ac);
            Arrays.sort(ac);
            long cc= getnum(ac,1<<j);
            cc%=2;
            if (cc==1){
                val+=1<<j;
            }
        }
        pw.println(val);
        pw.flush();
    }
    static void suffle(int[]a){
        for (int i =0;i<a.length;i++){
            int t = a[i];
            int idx= (int)(Math.random()*a.length);
            a[i]=a[idx];
            a[idx]=t;
        }
    }
    static long gcd(long a,long b){
        if (a==0)return b;
        return gcd(b%a,a);
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }



}