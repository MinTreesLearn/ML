import java.util.*;
import java.io.*;
import java.math.*;


public class Main{
    public static void main(String[]args){ 
        long s = System.currentTimeMillis();
        new Solver().run();
        System.err.println(System.currentTimeMillis()-s+"ms");
    }
        
}

class Solver{
    final long mod = (long)1e9+7l;
    final boolean DEBUG = true, MULTIPLE_TC = true;

    FastReader sc;
    PrintWriter out;

    long MAX_A = (long)1e16;
    
    int N, count[];
    long K, arr[];

    void init(){
        N = ni();
        K = ni();
        arr = new long[N + 1];
        count = new int[60];
        for(int i = 1; i <= N; i++){
            arr[i] = nl();
        }
    }

    int findLargestRequiredIndexOfK(){
        long powK = 1l;
        int indexK = 0;
        for( ; powK * K <= MAX_A; indexK += 1, powK *= K);
        return indexK;
    }

    void process(int testNumber){
        init();
        int indexK = findLargestRequiredIndexOfK();
        long powK = (long)Math.pow(K, indexK);
        for(int i = 1; i <= N; i++){
            long tmp = powK;
            for(int j = indexK; j >= 0; j--){
                if(arr[i] >= tmp){ 
                    arr[i] -= tmp;
                    if(count[j] != 0){
                        pn("NO"); return;
                    }
                    count[j] += 1;
                }
                tmp /= K;
            }
            if(arr[i] != 0){
                pn("NO"); return;
            }
        }
        pn("YES");
    }

    void run(){
        sc = new FastReader();
        out = new PrintWriter(System.out);
        int t = MULTIPLE_TC ? ni() : 1;
        for(int test = 1; test <= t; test++){
            process(test);
        }
        out.flush();
    }

    void trace(Object... o){ if(!DEBUG) return; System.err.println(Arrays.deepToString(o)); };    
    void pn(Object o){ out.println(o); }
    void p(Object o){ out.print(o); }
    int ni(){ return Integer.parseInt(sc.next()); }
    long nl(){ return Long.parseLong(sc.next()); }
    double nd(){ return Double.parseDouble(sc.next()); }
    String nln(){ return sc.nextLine(); }
    long gcd(long a, long b){ return (b==0)?a:gcd(b,a%b);}
    int gcd(int a, int b){ return (b==0)?a:gcd(b,a%b); }

    class FastReader{ 
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


class pair implements Comparable<pair> {
    int first, second;
    public pair(int first, int second){
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(pair ob){
        if(this.first != ob.first)
            return this.first - ob.first;
        return this.second - ob.second;
    }

    @Override
    public String toString(){
        return this.first + " " + this.second;
    }

    static public pair from(int f, int s){
        return new pair(f, s);
    }
}