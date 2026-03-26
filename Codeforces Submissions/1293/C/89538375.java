import java.util.Scanner;

public class Solution {

    static Integer[][] dp;

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int q = scn.nextInt();
        int arr[][] = new int[3][n + 1];
        for (int i = 1; i <= n; i++) {
            arr[1][i] = -1;
            arr[2][i] = -1;
        }
        int b = 0;
        for (int i = 0; i < q; i++) {
            int r = scn.nextInt();
            int c = scn.nextInt();
            if(arr[r][c] != -1){
                if (r == 1) {
                    if (arr[2][c] >= 0) {
                        arr[2][c] -= 2;
                        b -= 4;
                    }
                    if (c - 1 > 0 && arr[2][c - 1] >= 0) {
                        arr[2][c - 1] -= 3;
                        b -= 6;
                    }
                    if (c + 1 <= n && arr[2][c + 1] >= 0) {
                        arr[2][c + 1] -= 1;
                        b -= 2;
                    }
                } else {
                    if (arr[1][c] >= 0) {
                        arr[1][c] -= 2;
                        b -= 4;
                    }
                    if (c - 1 > 0 && arr[1][c - 1] >= 0) {
                        arr[1][c - 1] -= 1;
                        b -= 2;
                    }
                    if (c + 1 <= n && arr[1][c + 1] >= 0) {
                        arr[1][c + 1] -= 3;
                        b -= 6;
                    }
                }
                arr[r][c] = -1;
            }else{
                arr[r][c] = 0;
                if (r == 1) {
                    if (arr[2][c] >= 0) {
                        arr[2][c] += 2;
                        arr[1][c] += 2;
                        b += 4;
                    }
                    if (c - 1 > 0 && arr[2][c - 1] >= 0) {
                        arr[2][c - 1] += 3;
                        arr[1][c] += 3;
                        b += 6;
                    }
                    if (c + 1 <= n && arr[2][c + 1] >= 0) {
                        arr[2][c + 1] += 1;
                        arr[1][c] += 1;
                        b += 2;
                    }
                } else {
                    if (arr[1][c] >= 0) {
                        arr[1][c] += 2;
                        arr[2][c] += 2;
                        b += 4;
                    }
                    if (c - 1 > 0 && arr[1][c - 1] >= 0) {
                        arr[1][c - 1] += 1;
                        arr[2][c] += 1;
                        b += 2;
                    }
                    if (c + 1 <= n && arr[1][c + 1] >= 0) {
                        arr[1][c + 1] += 3;
                        arr[2][c] += 3;
                        b += 6;
                    }
                }
            }
            

            if (b == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

}