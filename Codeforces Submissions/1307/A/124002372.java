import java.util.*;
 
public class practice {


    public static void main(String[] args) {
 
		Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();

        while (t --> 0) {

            int n = scan.nextInt();
            int d = scan.nextInt();
            int arr[] = new int[n];

            for (int i = 0; i < n; i++) arr[i] = scan.nextInt();

            

            int i = 1;

            while (d >= i && i < n) {

                while (arr[i] > 0) {

                    arr[0]++;
                    arr[i]--;
                    d -= i;
                    break;
                }

                if (arr[i] == 0) i++;
            }

            System.out.println(arr[0]);
        }

        scan.close();
    }
}