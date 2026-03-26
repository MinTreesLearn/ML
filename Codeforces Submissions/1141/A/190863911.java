import java.util.*;
import  static java.lang.System.out;

public class Main {
    static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);


//        int t = sc.nextInt();
//        for(int __ = 0; __ < t; __++){
            var n = sc.nextLong();
            var m = sc.nextLong();
            if(m % n != 0) out.println(-1);
            else{
                m /= n;
                int c = 0;
                while((m & 1) == 0) {
                    m >>= 1;
                    c++;
                }
                while( m % 3 == 0) {
                    m /= 3;
                    c++;
                }
                if(m != 1) out.println(-1);
               else out.println(c);
            }

        //}



        sc.close();
    }

    public static int[] intar(int n){
        var f = new int[n];
        for(int i = 0; i < n; i++) f [i] = sc.nextInt();
        return f;
    }

    public static void outintar(int[] a, String d){
        out.print(a[0]);
        for(int i = 1; i < a.length; i++)
        {
            out.print(" ");
            out.print(a[i]);
        }
        out.println();
    }
}

