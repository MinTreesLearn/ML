//package javaapplication3;

import java.util.Scanner;

public class JavaApplication3 {

    static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();

        int[] q = new int[n - 1];

        int upper = 0, qSum = 0;

        for (int i = 0; i < n - 1; i++) {
            q[i] = scan.nextInt();
            qSum += q[i];

            if (qSum > 0)
                upper++;
        }

        int[] p = new int[n];
        int[] sorted = new int[n];
        p[0] = n - upper;

        try {
            sorted[p[0] - 1] = p[0];

            for (int i = 1; i < n; i++) {
                p[i] = p[i - 1] + q[i - 1];

                if (sorted[p[i] - 1] != 0) {
                    System.out.println(-1);
                    return;
                }
                sorted[p[i] - 1] = p[i];
            }
        } catch (Exception e) {
            System.out.println(-1);
            return;
        }

        for (int i = 0; i < n; i++) {
            System.out.print(p[i] + " ");
        }
    }
}
