import java.io.*;
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

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int [] steps = new int[n+1];
        if (n<3){
            if (m==0){
                int val =(int)1e9-100000;
                while (n-->0){
                    pw.println(val+" ");
                    val+=1000;
                }
            }
            else pw.println(-1);
            pw.flush();
            return;
        }
        steps[2]=1;
        for (int i =3;i<n;i++){
            steps[i]=steps[i-1];
            if (i%2==0)steps[i]++;
        }
        int last=0;
        while (last<n&&steps[last]<=m)m-=steps[last++];
        if (last>=n&&m!=0){
            pw.println(-1);
            pw.flush();
            return;
        }
        if (m==0)last--;
        int[] ans= new int[n+1];
        int i =0;
        while (i<last){
            ans[i]=(i+1);
            i++;
        }
        if (m==0){
            ans[last]=last+1;
            int val=(int)1e9;
            int id=n-1;
            while (id>last){
                ans[id]=val;
                val-=10000;
                id--;
            }
        }
        else {
            int low= ans[last-1]+1;
            int hi = 15000;
            while (low<=hi){
                int k = low+hi>>1;
                int size=0;
                HashSet<Integer>hs = new HashSet<>();
                for (int j=0;j<last;j++){
                    if (hs.contains(k-ans[j]))size++;
                    hs.add(ans[j]);
                }
                if (size>=m){
                    ans[last]=k;
                    low=k+1;
                }
                else hi=k-1;
            }
            int val =(int)1e9;
            i=n-1;
            while (i>last){
                ans[i--]=val;
                val-=10000;
            }
        }
        for (i =0;i<n;i++){
            pw.print(ans[i]+" ");
        }
        pw.flush();
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