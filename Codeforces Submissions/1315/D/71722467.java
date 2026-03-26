// @uthor -: puneet
// TimeStamp -: 23/02/20 

import java.io.*;
import java.util.*;

public class R622Q4 implements Runnable {

    private boolean testCases=false;
    private boolean console=false;
    
    public void solve() {
        int n=in.ni();
        TreeMap<Integer , ArrayList<Pair> > map=new TreeMap<>();
        Pair[] arr=new Pair[n];
        for(int i=0;i<n;++i){
            arr[i]=new Pair(in.ni(),0);
        }

        for(int i=0;i<n;++i){
            arr[i].cost=in.ni();
            if(!map.containsKey(arr[i].val)){
                map.put(arr[i].val,new ArrayList<>());
            }
            map.get(arr[i].val).add(arr[i]);
        }

        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());

        int start=map.ceilingKey(0);
        long cost=0;
        long currcost=0;

        while (true){

            if(pq.isEmpty()){
                start=map.ceilingKey(start)==null ? -1:map.ceilingKey(start);
                if(start==-1)
                    break;
            }


            if(map.containsKey(start)){
                for(Pair i:map.get(start)){
                    pq.add(i.cost);
                    currcost+=i.cost;
                }
            }

//            out.println(start+" "+cost);
//            out.println(pq);

            currcost-=pq.poll();
            cost+=currcost;
            start++;
        }

        out.println(cost);
    }

    class Pair{
        int val,cost;

        public Pair(int val, int cost) {
            this.val = val;
            this.cost = cost;
        }
    }

    /* -------------------- Templates and Input Classes -------------------------------*/

    @Override
    public void run() {
        try {
            init();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int t= testCases ? in.ni() : 1;
        while (t-->0) {
            solve();
            out.flush();
        }
    }

    private FastInput in;
    private PrintWriter out;
    public static void main(String[] args) throws Exception {
        new R622Q4().run();
//        new Thread(null, new R622Q4(), "Main", 1 << 27).start();
    }
    private void init() throws FileNotFoundException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        try {
            if (!console && System.getProperty("user.name").equals("puneet")) {
                outputStream = new FileOutputStream("/home/puneet/Desktop/output.txt");
                inputStream = new FileInputStream("/home/puneet/Desktop/input.txt");
            }
        } catch (Exception ignored) {
        }
        out = new PrintWriter(outputStream);
        in = new FastInput(inputStream);
    }
    private void sort(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for (int object : arr) list.add(object);
        Collections.sort(list);
        for (int i = 0; i < list.size(); ++i) arr[i] = list.get(i);
    }
    private void sort(long[] arr) {
        List<Long> list = new ArrayList<>();
        for (long object : arr) list.add(object);
        Collections.sort(list);
        for (int i = 0; i < list.size(); ++i) arr[i] = list.get(i);
    }
    public long ModPow(long x, long y, long MOD) {
        long res = 1L;
        x = x % MOD;
        while (y >= 1) {
            if ((y & 1) > 0) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }
    public int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    public long gcd(long a, long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    static class FastInput { InputStream obj;
        public FastInput(InputStream obj) {
            this.obj = obj;
        }
        byte inbuffer[] = new byte[1024];
        int lenbuffer = 0, ptrbuffer = 0;
        int readByte() { if (lenbuffer == -1) throw new InputMismatchException();
            if (ptrbuffer >= lenbuffer) { ptrbuffer = 0;
                try { lenbuffer = obj.read(inbuffer);
                } catch (IOException e) { throw new InputMismatchException(); } }
            if (lenbuffer <= 0) return -1;return inbuffer[ptrbuffer++]; }
        String ns() { int b = skip();StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) // when nextLine, (isSpaceChar(b) && b!=' ')
            { sb.appendCodePoint(b);b = readByte(); }return sb.toString();}
        int ni() {
            int num = 0, b;boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') { minus = true;b = readByte(); }
            while (true) { if (b >= '0' && b <= '9') { num = num * 10 + (b - '0'); } else {
                    return minus ? -num : num; }b = readByte(); }}
        long nl() { long num = 0;int b;boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') { minus = true;b = readByte(); }
            while (true) { if (b >= '0' && b <= '9') { num = num * 10L + (b - '0'); } else {
                    return minus ? -num : num; }b = readByte(); } }
        boolean isSpaceChar(int c) {
            return (!(c >= 33 && c <= 126));
        }
        int skip() { int b;while ((b = readByte()) != -1 && isSpaceChar(b)) ;return b; }
        float nf() {return Float.parseFloat(ns());}
        double nd() {return Double.parseDouble(ns());}
        char nc() {return (char) skip();}
    }

}