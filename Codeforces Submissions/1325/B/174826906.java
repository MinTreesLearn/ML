import java.util.Arrays;
import java.util.Scanner;

import static java.sql.Types.NULL;

public class CopyCopyCopyCopyCopy_v2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int[][] array = new int[t][];

        for (int i=0; i<t; i++) {
            int l = scanner.nextInt();
            array[i] = new int[l];

            for (int j=0; j<l; j++) {
                array[i][j] = scanner.nextInt();
            }
        }

        for (int i=0; i<t; i++) {
            Arrays.sort(array[i]);
            deleteDuplicated(array[i]);
            System.out.println(count(array[i]));
            //System.out.println(Arrays.toString(array[i]));
        }
    }

    private static void deleteDuplicated(int[] array) {
        for (int i=0; i<array.length-1; i++) {
            if (array[i] == array[i+1]) {
                array[i] = NULL;
            }
        }
    }

    private static int count(int[] array) {
        int count=array.length;

        for (int i=0; i<array.length; i++) {
            if (array[i] == 0) {
                count--;
            }
        }

        return count;
    }
}
