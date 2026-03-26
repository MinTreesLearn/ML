//package javaapplication3;

import java.util.Scanner;

public class JavaApplication3 {

    static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int t = scan.nextInt();

        for(int i=0;i<t;i++){
            long a = scan.nextLong();
            long b = scan.nextLong();

            System.out.println(a * numOf9(b));
        }
    }

    static int numOf9(long i){
        int num = String.valueOf(i).length();
        if(i < Math.pow(10,num)-1){
            num--;
        }
        return num;
    }
}
