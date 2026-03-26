import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int arr[] = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int inc = 0;
            int dec = n - 1;

            for (int i = 0; i < n; i++) {
                if (arr[i] >= i) {
                    inc = i;
                } else {
                    break;
                }
            }
            int cnt = 0;
            for(int i = n -1; i>= 0; i--){
                if(arr[i] >= cnt){
                    dec = i;
                } else {
                    break;
                }
                cnt++;
            }

            if (inc >= dec) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

}
