
import java.util.Scanner;
 
public class ArrayWithOddSum {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t>0) {
            t--;
            int n = in.nextInt();
            int[] a = new int[n];
            int odd = 0;
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                if(a[i]%2==1) odd++;
            }
            if(odd%2==1 || (n-odd>0 && odd>0)) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
