import java.util.Scanner;

public class Nonzero {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int j = 0; j < t; j++) {
            int  n= sc.nextInt();
            int[] arr = new int[n];
            int ans =0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                if (arr[i] == 0){
                    ans++;
                    arr[i] =1;
                }
            }
            int sum =0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }
            if (sum == 0){
                ans = ans+1;
            }
            System.out.println(ans);
        }
    }
}
