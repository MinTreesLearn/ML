import java.util.Scanner;

public class E1299A {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int n = scn.nextInt();
        int[] arr = new int[n];
        int[] prefix = new int[n + 1];
        int[] suffix = new int[n + 1];
        suffix[n] = prefix[0] = -1;
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
            prefix[i + 1] = prefix[i] & ~arr[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] & ~arr[i];
        }
        int max = 0;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            int f = arr[i] & prefix[i] & suffix[i + 1];
            if (max < f) {
                ind = i;
                max = f;
            }
        }
        sb.append(arr[ind]);
        sb.append(" ");
        for (int i = 0; i < n; i++) {
            if (i == ind) continue;
            sb.append(arr[i]);
            sb.append(" ");
        }

        System.out.println(sb);


    }
}
