import java.io.*;
import java.math.*;
import java.util.*;


public class Main {

    static final int INF = 0x3f3f3f3f;
    static final long LNF = 0x3f3f3f3f3f3f3f3fL;


    public static void main(String[] args) throws IOException {
        initReader();
        int t=nextInt();
        while (t--!=0){
            int n=nextInt();
            int k=nextInt();
            long[]a=new long[n+1];
            for(int i=1;i<=n;i++){
                a[i]=nextLong();
            }
            int[]K=new int[101];
            boolean ans=true;
            for(int i=1;i<=n;i++) {
                long p = a[i];
                if (a[i] == 0) continue;
                ArrayList<Integer> arr = new ArrayList<>();
                for (int j = 100; j >= 0; j--) {
                    if (K[j] == 1) continue;
                    if ((long)Math.pow(k, j) <= p) {
                        p-= (long) Math.pow(k, j);
                        arr.add(j);
                    }
                }
                if (p == 0) {
                    for (int j = 0; j < arr.size(); j++) {
                        K[arr.get(j)] = 1;
                    }
                } else {
                    ans = false;
                    break;
                }
            }
            if(ans)pw.println("YES");
            else pw.println("NO");

        }


        pw.close();
    }


    /***************************************************************************************/

    static BufferedReader reader;
    static StringTokenizer tokenizer;
    static PrintWriter pw;

    public static void initReader() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

//        从文件读写
//        reader = new BufferedReader(new FileReader("test.in"));
//        tokenizer = new StringTokenizer("");
//        pw = new PrintWriter(new BufferedWriter(new FileWriter("test1.out")));
    }

    public static boolean hasNext() {
        try {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
        } catch (Exception e) {
            return false;
        }
        return true;
    }

    public static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public static String nextLine() {
        try {
            return reader.readLine();
        } catch (Exception e) {
            return null;
        }
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static char nextChar() throws IOException {
        return next().charAt(0);
    }
}



		  	 			   	 	 						 	   	 		