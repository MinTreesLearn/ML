import java.util.*;

public class Hello {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int matrix[][] = new int[R][C];
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                matrix[row][col] = sc.nextInt();
                matrix[row][col]--;
            }
        }

        long result = 0;
        for (int col = 0; col < C; col++) {
            int count[] = new int[R];
            for (int row = 0; row < R; row++) {
                if (matrix[row][col] % C == col) {
                    int pos = matrix[row][col] / C;
                    if (pos < R) {
                        ++count[(row - pos + R) % R];
                    }
                }
            }
            int cur = R - count[0];
            for (int row = 1; row < R; row++) {
                cur = Math.min(cur, R - count[row] + row);
            }
            result += cur;
        }
        System.out.println(result);
    }
}