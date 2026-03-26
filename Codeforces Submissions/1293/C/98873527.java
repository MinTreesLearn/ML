

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[][] map = new int[3][n + 1];
        for (int i = 0; i <3; i++) {
            for (int j = 0; j <n+1 ; j++) {
                map[i][j]=0;
            }
        }
        int flag = 0;
        while (q-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            map[x][y] = 1 - map[x][y];
            int x1 = 3 - x;
            int y1 = y + 1;
            int y2 = y - 1;
            if (map[x][y] == 1) {
                if (y1 <= n) {
                    if (map[x1][y1] == 1) {
                        flag++;
                    }
                }
                if (y2 >= 1) {
                    if (map[x1][y2] == 1) {
                        flag++;
                    }
                }
                if (map[x1][y]==1){
                    flag++;
                }
            } else {
                if (y1 <= n) {
                    if (map[x1][y1] == 1) {
                        flag--;
                    }
                }
                if (y2 >= 1) {
                    if (map[x1][y2] == 1) {
                        flag--;
                    }
                }
                if (map[x1][y]==1){
                    flag--;
                }
            }

            if (flag==0){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }


        }
    }
}
