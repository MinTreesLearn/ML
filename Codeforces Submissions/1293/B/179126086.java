
import java.util.*;

public class JoeTv {
	public static void main(String[] args) {
		Scanner console = new Scanner(System.in);
		int n = console.nextInt();
		
		double money = 0.0;
		
		for (int i = n; i > 0; i--) {
			money += (1.0/i);
		}
		
		System.out.print(money);
	}
}