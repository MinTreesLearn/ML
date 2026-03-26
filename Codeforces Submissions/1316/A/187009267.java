
import java.io.PrintWriter;
import java.math.BigInteger;
import  java.util.HashSet;
import java.util.*;

public class meta {
    public static void main(String[] args) {
        Scanner real = new Scanner(System.in);
        int n= real.nextInt();
        while (n--!=0) {

            int sum=0;
            int a = real.nextInt();
            int k= real.nextInt();
            long[] arr = new long[a];
            for (int i = 0; i < a; i++) {
                arr[i] = real.nextInt();
                sum+=arr[i];
            }
            System.out.println(Math.min(k,sum));

        }
    }
}
