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
    final boolean DEBUG = true, MULTIPLE_TC = false;

    FastReader sc;
    PrintWriter out;

    int N, pow2[];
    ArrayList<Integer> arr;

    void init(){
        N = ni();
        arr = new ArrayList<>();
        pow2 = new int[32];
        pow2[0] = 1;
        for(int i = 1; i <= 31; i++){
            pow2[i] = 2 * pow2[i - 1];
        }
        for(int i = 1; i <= N; i++){
            arr.add(ni());
        }
    }

    ArrayList<Integer> pickNumbersWithThisBitOn(int bitPos, ArrayList<Integer> li){
        ArrayList<Integer> ret= new ArrayList<>();
        for(int x : li){
            if((pow2[bitPos] & x) != 0){
                ret.add(x);
            }
        }
        return ret;
    }

    ArrayList<Integer> pickNumbersWithThisBitOff(int bitPos, ArrayList<Integer> li){
        ArrayList<Integer> ret = new ArrayList<>();
        for(int x : li){
            if((pow2[bitPos] & x) == 0){
                ret.add(x);
            }
        }
        return ret;
    }

    boolean allBitsAtThisPosAreSame(int bitPos, ArrayList<Integer> li){
        int cntOff = 0, cntOn = 0;
        for(int x : li){
            if((x & pow2[bitPos]) != 0){
                cntOn += 1;
            }else{
                cntOff += 1;
            }
        }

        return cntOff == li.size()  || cntOn == li.size();
    }
    
    int f(int bit, boolean on, ArrayList<Integer> li){
        if(bit < 0){
            return 0;
        }
        ArrayList<Integer> consider = 
            on ? pickNumbersWithThisBitOn(bit + 1, li) : pickNumbersWithThisBitOff(bit + 1, li);
        
        int res = 0;
        if(allBitsAtThisPosAreSame(bit, consider)){
            res = f(bit - 1, (consider.get(0) & pow2[bit]) != 0, consider);
        }else{
            res = pow2[bit] + Math.min(f(bit - 1, false, consider), f(bit - 1, true, consider));
        }
        return res;
    }

    void process(int testNumber){
        init();
        int res = f(30, false, arr);
        pn(res);
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