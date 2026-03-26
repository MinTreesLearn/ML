import java.math.BigInteger;
import java.sql.Array;
import java.util.*;


public class leet {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        for (int i = 0; i < x; i++) {
            int y = scan.nextInt();
            int[] arr = new int[y];
            for (int j = 0; j < arr.length; j++) {
                arr[j]= scan.nextInt();
            }
            int c = 0;
            for (int j = 0; j < arr.length; j++) {
                if(arr[j]%2!=0){
                    c++;
                }
            }
            if(c==y && y%2!=0){
                System.out.println("YES");
            }
            else if(c!=y && c>0){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }

    }
}