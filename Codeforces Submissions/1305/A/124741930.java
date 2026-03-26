import java.util.*;
 
public class practice {


    public static void main(String[] args) {
 
		Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();

        while (t --> 0) {

            int n = scan.nextInt();
            int a[] = new int[n];
            int b[] = new int[n];

            for (int i = 0; i < n; i++) a[i] = scan.nextInt();
            for (int i = 0; i < n; i++) b[i] = scan.nextInt();
            
            Arrays.sort(a);
            Arrays.sort(b);

            for (int i = 0; i < n; i++) System.out.print(a[i] + " ");
            System.out.println();
            for (int i = 0; i < n; i++) System.out.print(b[i] + " ");
            System.out.println();
        }

        scan.close();
    }
}