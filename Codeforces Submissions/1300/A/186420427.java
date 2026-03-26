import java.util.*;
import java.io.*;

public class Codeforces_Nonzero {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        in.nextLine();
        for(int i=0; i<t; i++) {
            int n = in.nextInt();
            in.nextLine();
            int[] arr = new int[n];
            int sum = 0;
            int numZero = 0;
            for(int j=0; j<n; j++) {
                arr[j] = in.nextInt();
                sum+=arr[j];
                if(arr[j]==0)
                    numZero++;
            }
            in.nextLine();
            if(sum!=0 && numZero==0)
                System.out.println(0);
            else if(numZero>0) {
                sum+=numZero;
                if(sum!=0)
                    System.out.println(numZero);
                else
                    System.out.println(numZero+1);
            }
            else { //sum==0 and numZero==0
                System.out.println(1);
            }
        }
    }
}
