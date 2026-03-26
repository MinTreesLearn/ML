import java.util.*;

public class Main {

    public static void main(String[] args) {
        new Main();
    }

    public Main() {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        for (int i = 0; i < num; i++) {
            int size = scanner.nextInt();
            int[] arr = new int[size];
            for (int j = 0; j < size; j++) {
                arr[j] = scanner.nextInt();
            }
            Arrays.sort(arr);
            printArr(arr);
        }
    }

    void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[arr.length - 1 - i] + " ");
        }
        System.out.println();
    }

}