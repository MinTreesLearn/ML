
import java.util.*;

public class Lesson4YetAnotherMemeProblem {
	public static void main(String[] args) {
		 
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
 
		while (cases-- > 0) {
			long A = scan.nextLong();
			long B = scan.nextLong();
			long count = 0;
			for(int i=10;i<=(B+1);i*=10) {
				count++;
			}
			System.out.println(count * A);
		}
	}

}