
import java.util.*;

public class Training1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int arr[]=new int[3];
            arr[0] = sc.nextInt();
            arr[1] = sc.nextInt();
            arr[2] = sc.nextInt();
            Arrays.sort(arr);
            int res = 0;
            if (arr[0] > 0) {
                arr[0]--;
                res++;
            }
            if (arr[1] > 0) {
                arr[1]--;
                res++;
            }
            if (arr[2] > 0) {
                arr[2]--;
                res++;
            }
            if (arr[2] > 0 && arr[0] > 0) {
                arr[2]--;
                arr[0]--;
                res++;
            }
            if (arr[2] > 0 && arr[1] > 0) {
                arr[2]--;
                arr[1]--;
                res++;
            }
            if (arr[0] > 0 && arr[1] > 0) {
                arr[0]--;
                arr[1]--;
                res++;
            }
            if (arr[0] > 0 && arr[1] > 0&& arr[2]>0) {
                res++;
            }
            System.out.println(res);
        }

    }

}
