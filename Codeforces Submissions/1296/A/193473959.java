import java.util.*;
public class acmp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            boolean even = false;
            boolean odd = false;
            int c = 0;
            for(int j = 0; j < n; j++){
                arr[j] = sc.nextInt();
                if(arr[j] % 2 == 0) even = true;
                else odd = true;
                c += arr[j];
            }
            if(c % 2 == 1) System.out.println("YES");
            else{
                if(even && odd) System.out.println("YES");
                else System.out.println("NO");
            }
        }
    }
}