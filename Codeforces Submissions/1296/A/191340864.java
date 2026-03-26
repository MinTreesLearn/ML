import java.util.*;
import java.io.*;
// import static java.lang.Math.max;
//import static java.lang.Math.min;
// import static java.lang.Math.abs;

public class A_Array_with_Odd_Sum {

    static PrintWriter out;

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    static final Scanner in = new Scanner(System.in);
    public static void main(String[] args) {

        out = new PrintWriter(System.out);
        int tcas = in.nextInt();
        while (tcas-- > 0) {
            int n = in.nextInt();
            int a[] = readIntArray(n);
            int sum=0;
            int ce=0;
            int co=0;
            for (int i = 0; i < n; i++) {
                if(a[i]%2==0){
                    ce++;
                }
                else{
                    co++;
                }
                sum+=a[i];
            }
            if((ce>0 && co>0 && sum%2==0) || (sum%2!=0)){
                out.println("YES");
            }
            else{
                out.println("NO");
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


