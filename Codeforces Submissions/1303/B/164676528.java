//package javaapplication3;

import java.util.Scanner;

public class JavaApplication3 {

    static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int t = scan.nextInt();

        while (t-- > 0) {
            long n = scan.nextLong();
            long g = scan.nextLong();
            long b = scan.nextLong();

            long dis = (long) Math.ceil(n / 2.0);
            long round = g + b;
            long numOfRounds = dis / g;
            long ans;

            if (dis % g == 0) {
                ans = (round * numOfRounds) - b;
            } else {
                ans = (round * numOfRounds) + (dis % g);
            }

            if (ans < n) {
                ans = n;
            }

            System.out.println(ans);
        }

    }
}
