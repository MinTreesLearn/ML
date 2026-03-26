import java.util.Scanner;

public class Task1288A {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int par = Integer.parseInt(in.nextLine());
        int[][] value = new int[par][2];
        for (int i = 0; i < par; i++) {
            value[i] = parser(in.nextLine());
        }
        for (int i = 0; i < par; i++) {
            System.out.println(task(value[i]));
        }
    }

    public static int[] parser(String str) {
        String[] strArr = str.split(" ");
        int[] numArr = new int[strArr.length];
        for (int i = 0; i < strArr.length; i++) {
            numArr[i] = Integer.parseInt(strArr[i]);
        }
        return numArr;
    }

    public static String task(int[] value) {
        if (value[0] >= value[1]) {
            return "YES";
        }
        int i =  value[0];
        while (i != 0 && i + Math.ceil((double) value[1] / (i + 1)) > value[0]) {
            i /= 2;
        }
        if (i > 0) {
            return "YES";
        } else {
            return "NO";
        }
    }

}