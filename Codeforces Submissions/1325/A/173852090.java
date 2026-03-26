import java.util.Scanner;

public class EhAb_AnD_gCd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int[] number = new int[t];

        for (int i=0; i<t; i++) {
            number[i] = scanner.nextInt();
        }

        for (int x : number) {
            System.out.println(x-1 +" " +1);
        }

    }

}
