import java.util.ArrayList;
import java.util.Scanner;
public class Lesson7ProductOf3Numbers {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tcc = sc.nextInt();
		while (tcc-- > 0) {
			int n = sc.nextInt();
			int a = 0;
			int b = 0;
			for (int i = 2; i * i < n; i++) {
				if (n % i == 0) {
					a = i;
					n /= i;
					break;
				}
			}
			for (int i = 2; i * i < n; i++) {
				if (n % i == 0 && i != a) {
					b = i;
					n /= i;
					break;
				}
			}
			if (a != 0 && b != 0 && n != 1) {
				System.out.println("yes");
				System.out.println(a + " " + b + " " + n);
			} else {
				System.out.println("no");
			}
		}

	}

}
