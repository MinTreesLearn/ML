import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Task1323A {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = Integer.parseInt(in.nextLine());
        int[] par = new int[t];
        int[][] value = new int[100][100];
        for (int i = 0; i < t; i++) {
            par[i] = Integer.parseInt(in.nextLine());
            value[i] = parser(in.nextLine());
        }
        task(par, value);
    }

    public static int[] parser(String str) {
        String[] strArr = str.split(" ");
        int[] numArr = new int[strArr.length];
        for (int i = 0; i < strArr.length; i++) {
            numArr[i] = Integer.parseInt(strArr[i]);
        }
        return numArr;
    }

    public static void task(int[] par, int[][] value) {
        int dp = 0;
        boolean f = true;
        for (int i = 0; i < par.length; i++) {
            f = true;
            dp = 0;
            for (int j = 0; j < par[i]; j++) {
                if (value[i][j] % 2 == 0) {
                    System.out.println(1);
                    System.out.println(j + 1);
                    f = false;
                    break;
                } else {
                    if (dp == 0) {
                        dp = j + 1;
                    } else {
                        System.out.println(2);
                        System.out.println(dp + " " + (j + 1));
                        f = false;
                        break;
                    }
                }

            }
            if (f) {
                System.out.println(-1);
            }
        }
    }
}
