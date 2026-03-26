import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class Problems {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();

		while (t > 0) {

			int n = in.nextInt();
			System.out.println(1 + " " + (n - 1));
			
			t--;
		}
	}

}