import java.util.Scanner;

public class CodeForces_1312A_TwoRegularPolygon {

	private static final Scanner STDIN_SCANNER = new Scanner(System.in);

	private static void solve() {
		int n = STDIN_SCANNER.nextInt();
		int m = STDIN_SCANNER.nextInt();
		if(n%m == 0) System.out.println("YES");
		else System.out.println("NO");
	}
	
	public static void main(String[] args) {
		int t = STDIN_SCANNER.nextInt();
		while((t--) >0) {
			solve();
		}
	}
}