import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.nio.channels.ClosedByInterruptException;
import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/*
@author kalZor
 */
public class TaskB {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = 1;
//        testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Solver {
        public void fastSort(int[] a){
            Random random = new Random();
            for(int i=0;i<a.length;i++){
                int nextInd = random.nextInt(a.length);
                int temp = a[nextInd];
                a[nextInd] = a[i];
                a[i] = temp;
            }
            Arrays.sort(a);
            return;
        }
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextArray(n);
            HashMap<Integer,Long> map = new HashMap<>();
            long ans = 0;
            for(int i=0;i<n;i++){
                long k = map.getOrDefault(a[i]-i,(long)(-1e8));
                if(k==-(long)(1e8)){
                    map.put(a[i]-i,(long)a[i]);
                }
                else map.put(a[i]-i,k+(long)a[i]);
                ans = Math.max(ans,map.get(a[i]-i));
            }
            out.println(ans);
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream stream){
            br = new BufferedReader(new
                    InputStreamReader(stream));
        }

        public String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt(){
            return Integer.parseInt(next());
        }

        public long nextLong(){
            return Long.parseLong(next());
        }

        public double nextDouble(){
            return Double.parseDouble(next());
        }

        public String nextLine(){
            String str = "";
            try{
                str = br.readLine();
            }
            catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }

        public int[] nextArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
    }
}

