import java.util.*;
import java.io.*;

// @author : sam45jh

public class Main{
    /* declare some global variables */
    static FastReader scn;
    static FastWriter out;
    static int imax = Integer.MAX_VALUE;
    static int imin = Integer.MIN_VALUE;
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    static class FastWriter {
        BufferedWriter bw;
        List<String> list = new ArrayList<>();
        Set<String> set = new HashSet<>();
 
        FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }
 
        <T> void print(T obj) throws IOException {
            bw.write(obj.toString());
            bw.flush();
        }
 
        void println() throws IOException {
            print("\n");
        }
 
        <T> void println(T obj) throws IOException {
            print(obj.toString() + "\n");
        }
 
        void print(int[] arr) throws IOException {
            for (int x : arr) {
                print(x + " ");
            }
            println();
        }
 
        void print(long[] arr) throws IOException {
            for (long x : arr) {
                print(x + " ");
            }
            println();
        }
        
        void print(boolean[] arr) throws IOException{
            for(boolean x:arr)
            print(x+" ");
        }
 
        void print(double[] arr) throws IOException {
            for (double x : arr) {
                print(x + " ");
            }
            println();
        }
        
        void print(float[] nums) throws IOException{
            for(float x: nums){
                 print(x+" ");
            }
            println();
        }
        void printCharN(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
        }
    }
    
 
    /* print functions for primitives */
    
    private static void print(int s) throws IOException {
        out.println(s);
    }
    private static void print(long s) throws IOException {
        out.println(s);
    }
    private static void print(boolean s) throws IOException{
        out.println(s);
    }
    private static void print(double s) throws IOException {
        out.println(s);
    }
    private static void print(String s) throws IOException{
        out.println(s);
    }
    private static void print(float s) throws IOException{
        out.println(s);
    }
    
    /* Disclaimer */
    // note that if you want to use a function than uase IOException;
        // public static void call() throws IOException{
        //     print(10+"Abhishek Jha");
        // }
        
    
    /* Main function */
    
    public static void main(String[] hi) throws IOException{
        scn = new FastReader();
        out = new FastWriter();
        // String[] s = scn.nextLine().trim().split(" ");
        int n = scn.nextInt();
        int m = scn.nextInt();
        String[] s = scn.nextLine().trim().split(" ");
        String[] t = scn.nextLine().trim().split(" ");
        int tws = scn.nextInt();
        while(tws--!=0){
            int yr = scn.nextInt();
            int x = yr%(s.length);
            int y = yr%(t.length);
            if(x == 0)
            x=s.length;
            if(y==0)
            y=t.length;
            print(s[x-1].concat(t[y-1]));
        }
        
        
    }
    
    /* sorting an array in nlogn time */
    public static void sort(int[] nums){
        ArrayList<Integer> vals = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            vals.add(nums[i]);
        }
        Collections.sort(vals);
        for(int i=0;i<vals.size();i++){
            nums[i]=vals.get(i);
        }
    }
    // the reason I didnt use arrays.sort(nums) is that it uses quick sort and 
    // that has a TC of n2 in worst case. However, Collections sort uses merge sort
    // which is always nlogn even in worst case.
}

