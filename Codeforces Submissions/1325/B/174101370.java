import java.io.*;
import java.util.*;

public class CopyCopyCopyCopyCopy {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // try {
        //     scanner = new Scanner(new FileInputStream("input.txt"));
        // }
        // catch (Exception e) {
        //     System.out.println("Error");
        // }


        int t = scanner.nextInt();

        for (int x = 0; x < t; x++) {
            int n = scanner.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }
            Arrays.sort(arr);

            n = removeduplicates(arr, n);

            System.out.println(n);
        }
    }

    public static int removeduplicates(int a[], int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int[] temp = new int[n];
        int j = 0;
 
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) {
                temp[j++] = a[i];
            }
        }
 
        temp[j++] = a[n - 1];
        for (int i = 0; i < j; i++) {
            a[i] = temp[i];
        }
 
        return j;
    }
}
