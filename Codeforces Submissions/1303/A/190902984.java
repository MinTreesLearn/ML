import java.util.*;
import java.io.*;
// import static java.lang.Math.max;
//import static java.lang.Math.min;
// import static java.lang.Math.abs;

public class A_Erasing_Zeroes {

    static PrintWriter out;

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    static final Scanner in = new Scanner(System.in);
    public static void main(String[] args) {

        out = new PrintWriter(System.out);
        int tcas = in.nextInt();
        while (tcas-- > 0) {
            String s = in.next();
            
            int res =0;
            int c0=0;
            int c1=0;
            int clz =0;
            int k =0;
            
            if(s.charAt(0)=='0')
            while(s.charAt(k++)!='1'&& k<s.length()){
                clz++;
            }
            dbg(clz);

            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i)=='0'){
                    c0++;
                }
                else if(s.charAt(i)=='1' && c0>0){
                    res+=c0;
                    c0=0;
                }
            }
            if(res>0)
            out.println(res-clz);

            else{
                out.println(0);
            }

        }

        in.close();
        out.close();
    }
    static long[] readLongArray(int n){
        
        long b[] = new long[n];

        for (int i = 0; i < n; i++) {
            b[i]= in.nextLong();
        }
        return b;
        
    }
    static int[] readIntArray(int n){
        
        int b[] = new int[n];

        for (int i = 0; i < n; i++) {
            b[i]= in.nextInt();
        }
        return b;
        
    }

}

