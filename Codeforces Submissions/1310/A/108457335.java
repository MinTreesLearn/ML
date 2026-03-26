import java.util.*;
import java.io.*;
import java.math.*;
 
public class Main
{
    static class Publication{
        int num;
        long t;
        public Publication(int num, long t){
            this.num = num;
            this.t = t;
        }
    }

    public static void process(int test_number)throws IOException
    {
        int n = ni();
        Publication arr[] = new Publication[n];
        for(int i = 0; i < n; i++){
            int num = ni();
            arr[i] = new Publication(num, 0l);
        }

        for(int i = 0; i < n; i++){
            arr[i].t = nl();
        }

        Arrays.sort(arr, (A, B)-> (A.num  != B.num) ? (Integer.compare(A.num, B.num)) : 
                                                        (Long.compare(A.t, B.t)));

        PriorityQueue<Publication> pq = new PriorityQueue<>((A, B)->(
                                                                (-Long.compare(A.t, B.t))
                                                            ));
        long res = 0l, cummulativeSum = 0l;
        int idx = 0, newPublicationNum = arr[0].num;
        while(idx < n){
            if(pq.isEmpty())
                newPublicationNum = arr[idx].num;

            while(idx < n && arr[idx].num == newPublicationNum){
                pq.add(arr[idx]);
                cummulativeSum += arr[idx].t;
                ++idx;
            }

            while(!pq.isEmpty()){
                if(idx < n && arr[idx].num == newPublicationNum)
                    break;

                Publication ob = pq.poll();
                cummulativeSum -= ob.t;
                res += cummulativeSum;
                ++newPublicationNum;
            }
        }

        pn(res);
    }
 
    static final long mod = (long)1e9+7l;
    static boolean DEBUG = true;
    static FastReader sc;
    static PrintWriter out;
    public static void main(String[]args)throws IOException
    {
        out = new PrintWriter(System.out);
        sc = new FastReader();
 
        long s = System.currentTimeMillis();
        int t = 1;
        // t = ni();
        for(int i = 1; i <= t; i++)
            process(i);
 
        out.flush();
        System.err.println(System.currentTimeMillis()-s+"ms");
    }

    static void trace(Object... o){ if(!DEBUG) return; System.err.println(Arrays.deepToString(o)); };    
    static void pn(Object o){ out.println(o); }
    static void p(Object o){ out.print(o); }
    static int ni()throws IOException{ return Integer.parseInt(sc.next()); }
    static long nl()throws IOException{ return Long.parseLong(sc.next()); }
    static double nd()throws IOException{ return Double.parseDouble(sc.next()); }
    static String nln()throws IOException{ return sc.nextLine(); }
    static long gcd(long a, long b){ return (b==0)?a:gcd(b,a%b);}
    static int gcd(int a, int b){ return (b==0)?a:gcd(b,a%b); }
    
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 
    } 
}
