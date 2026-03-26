//package Codeforce;

import java.util.Scanner;

public class TwoRegularPolygons {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int test = input.nextInt();
        while (test-- > 0){
            int n = input.nextInt(),m = input.nextInt();
            System.out.println((n%m == 0)?"YES":"NO");
        }
    }
}
