
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int[][][][][] f = new int[n + 1][n + 1][n / 2 + 1][3][3];//f[i][j][k]: 表示 [i, j] 取了 k 个2的最小答案数

        for (int i = 0; i < f.length; i++) {
            for (int j = 0; j < f[i].length; j++) {
                for (int k = 0; k < f[i][j].length; k++) {
                    for (int l = 0; l < f[i][j][k].length; l++) {
                        Arrays.fill(f[i][j][k][l], Integer.MAX_VALUE / 2);
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            if (x == 0) {
                f[i][i][0][1][1] = 0;
                if (1 < f[i][i].length)
                    f[i][i][1][2][2] = 0;
                continue;
            }
            if (x % 2 == 0) {
                a[i] = 2;
                f[i][i][1][2][2] = 0;
            }else {
                a[i] = 1;
                f[i][i][0][1][1] = 0;
            }
        }
        //(n / 2) 个 2
        //(n - n / 2) 个 1
        for (int len = 2; len <= n; len++) {
            for (int i = 1, j = i + len - 1; j <= n; i++, j++) {
                for (int k = 0; k <= Math.min(n / 2, len); k++) {
                    for (int l = 1; l <= 2; l++) {
                        if (a[i] != 0 && a[i] != l) continue;
                        for (int m = 1; m <= 2; m++) {
                            if (a[j] != 0 && a[j] != m) continue;
                            for (int o = 1; o <= 2; o++) {
                                if (a[i + 1] != 0 && a[i + 1] != o) {
                                    continue;
                                }
                                if (l != 2 || k - 1 >= 0)
                                    f[i][j][k][l][m] = Math.min(f[i + 1][j][l == 2 ? k - 1 : k][o][m] + (o != l ? 1 : 0), f[i][j][k][l][m]);
                            }
                            for (int o = 1; o <= 2; o++) {
                                if (a[j - 1] != 0 && a[j - 1] != o) {
                                    continue;
                                }
                                if (m != 2 || k - 1 >= 0)
                                    f[i][j][k][l][m] = Math.min(f[i][j - 1][m == 2 ? k - 1 : k][l][o] + (o != m ? 1 : 0), f[i][j][k][l][m]);
                            }
                        }
                    }
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 2; j++) {
                res = Math.min(res, f[1][n][n / 2][i][j]);
            }
        }
        System.out.println(res);
    }


}
