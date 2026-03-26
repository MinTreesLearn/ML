import java.util.Scanner;

public class Collecting_Coins {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int p = sc.nextInt();
			
			int add = a+b+c+p;
			int max = Math.max(a, Math.max(b, c));
			int div = add/3;
			if(add%3==0 && div>=max) {
					System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}
	}
}